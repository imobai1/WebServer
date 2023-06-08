/*
 Copyright mobai. All rights reserved.

 @Author: mengHuan
 @Date: 2023/6/7

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "log.h"
m_log::m_log() {
    m_count = 0;
    m_is_async = false;
}

m_log::~m_log() {
    if (m_fp != nullptr){
        fclose(m_fp);
    }
}

// 异步写入日志函数，从日志队列中取出日志消息并写入文件
void *m_log::async_write_log() {
    std::string single_log;
    while(m_log_queue->pop(single_log)){
        m_mutex.lock();
        fputs(single_log.c_str(),m_fp);
        m_mutex.unlock();
    }
}

m_log *m_log::get_instance() {
    static m_log instance;
    return &instance;
}

void *m_log::flush_log_thread(void *args) {
    m_log::get_instance()->async_write_log();
}

bool m_log::init(const char *file_name, int close_log, int log_buf_size, int split_lines, int max_queue_size) {
    if(max_queue_size >= 1){
        m_is_async = true;
        m_log_queue = new block_queue<std::string>(max_queue_size);
        pthread_t tid;
        //创建线程异步写日志
        pthread_create(&tid, nullptr,flush_log_thread,nullptr);
    }
    m_close_log = close_log;
    m_log_buf_size = log_buf_size;
    m_buf = new char[m_log_buf_size];
    memset(m_buf,'\0',m_log_buf_size);
    m_split_lines = split_lines;
    // 获取当前时间
    time_t t = time(nullptr);
    struct tm* sys_tm = localtime(&t);
    struct tm my_tm = *sys_tm;

    const char *p = strrchr(file_name,'/');
    char log_full_name[256] = {0};

    if(p == nullptr){
        snprintf(log_full_name,255,"%d_%02d_%02d_%s",
                 my_tm.tm_year+1900,my_tm.tm_mon+1,my_tm.tm_mday,
                 file_name);
    } else {
        strcpy(log_name,p + 1);
        strncpy(dir_name,file_name,p - file_name + 1);
        snprintf(log_full_name, 255, "%s%d_%02d_%02d_%s",
                 dir_name, my_tm.tm_year + 1900, my_tm.tm_mon + 1, my_tm.tm_mday,
                 log_name);
    }
    m_today = my_tm.tm_mday;
    m_fp = fopen(log_full_name,"a");
    if(m_fp == nullptr){
        return false;
    }
    return true;
}

void m_log::write_log(int level, const char *format, ...) {
    // 获取当前时间,精确到分秒
    struct timeval now = {0, 0};
    gettimeofday(&now, nullptr);
    time_t t = now.tv_sec;
    struct tm *sys_tm = localtime(&t);
    struct tm my_tm = *sys_tm;

    char s[16] = {0};
    switch (level) {
        case 0:
            strcpy(s, "[debug]:");
            break;
        case 1:
            strcpy(s, "[info]:");
            break;
        case 2:
            strcpy(s, "[warn]:");
            break;
        case 3:
            strcpy(s, "[erro]:");
            break;
        default:
            strcpy(s, "[info]:");
            break;
    }
    m_mutex.lock();
    m_count++;
    if (m_today != my_tm.tm_mday || m_count % m_split_lines == 0) {
        fflush(m_fp);
        fclose(m_fp);
        char tail[16] = {0};
        snprintf(tail, 16, "%d_%02d_%02d_",
                 my_tm.tm_year + 1900, my_tm.tm_mon + 1, my_tm.tm_mday);
        char new_log[256] = {0};
        if (m_today != my_tm.tm_mday) {
            snprintf(new_log, 255, "%s%s%s",
                     dir_name, tail, log_name);
            m_today = my_tm.tm_mday;
            m_count = 0;
        } else {
            snprintf(new_log, 255, "%s%s%s.%lld",
                     dir_name, tail, log_name, m_count / m_split_lines);
        }
        m_fp = fopen(new_log, "a");
    }
    m_mutex.unlock();

    va_list valst;
    va_start(valst, format);

    std::string log_str;
    m_mutex.lock();

    //写入的具体时间内容格式
    int n = snprintf(m_buf, 48, "%d-%02d-%02d %02d:%02d:%02d.%06ld %s ",
                     my_tm.tm_year + 1900, my_tm.tm_mon + 1, my_tm.tm_mday,
                     my_tm.tm_hour, my_tm.tm_min, my_tm.tm_sec, now.tv_usec, s);
    int m = vsnprintf(m_buf + n,m_log_buf_size - 1,format,valst);
    m_buf[n + m] = '\n';
    m_buf[n + m + 1] = '\0';
    log_str = m_buf;

    m_mutex.unlock();
    if (m_is_async && !m_log_queue->full()){
        m_log_queue->push(log_str);
    } else {
        m_mutex.lock();
        fputs(log_str.c_str(), m_fp);
        m_mutex.unlock();
    }

    va_end(valst);
}

void m_log::flush() {
    m_mutex.lock();
    //强行刷新写入流缓冲区
    fflush(m_fp);
    m_mutex.unlock();
}

