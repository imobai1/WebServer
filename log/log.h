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
#ifndef WEBSERVER_LOG_H
#define WEBSERVER_LOG_H
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <stdarg.h>
#include <pthread.h>
#include "block_queue.h"

class m_log {
public:
    //C++11以后,使用局部变量懒汉不用加锁
    static m_log *get_instance();
    // 刷新日志的线程入口函数，调用了异步写入日志函数
    static void *flush_log_thread(void *args);
    // 初始化函数，用于初始化日志实例及相关参数，创建异步写入日志线程
    bool init(const char *file_name, int close_log, int log_buf_size = 8192, int split_lines = 5000000, int max_queue_size = 0);
    // 写入日志的函数，根据日志级别格式化日志内容并写入文件或放入日志队列
    void write_log(int level, const char *format, ...);
    // 强制刷新写入流缓冲区的函数
    void flush();
private:
    m_log();
    ~m_log();
    void* async_write_log();

private:
    char dir_name[128];                     //路径名
    char log_name[128];                     //log文件名
    int m_split_lines;                      //日志最大行数
    int m_log_buf_size;                     //日志缓冲区大小
    long long m_count;                      //日志行数记录
    int m_today;                            //因为按天分类,记录当前时间是那一天
    FILE *m_fp;                             //打开log的文件指针
    char *m_buf;
    block_queue<std::string> *m_log_queue;  //阻塞队列
    bool m_is_async;                        //是否同步标志位
    locker m_mutex;
    int m_close_log;                        //关闭日志
};

#define LOG_DEBUG(format, ...) \
if(0 == m_close_log) {         \
     m_log::get_instance()->write_log(0, format, ##__VA_ARGS__); \
     m_log::get_instance()->flush();  \
}\

#define LOG_INFO(format, ...) \
if(0 == m_close_log) {        \
    m_log::get_instance()->write_log(1, format, ##__VA_ARGS__); \
    m_log::get_instance()->flush();                             \
}\

#define LOG_WARN(format, ...) \
if(0 == m_close_log) {        \
     m_log::get_instance()->write_log(2, format, ##__VA_ARGS__); \
     m_log::get_instance()->flush(); \
}\

#define LOG_ERROR(format, ...) \
if(0 == m_close_log) {         \
     m_log::get_instance()->write_log(3, format, ##__VA_ARGS__); \
     m_log::get_instance()->flush();  \
}\


#endif //WEBSERVER_LOG_H