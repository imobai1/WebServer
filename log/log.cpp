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
    if (m_fp != NULL){
        fclose(m_fp);
    }
}

void *m_log::async_write_log() {
    std::string single_log;
  /*  while(m_log_queue->pop(single_log)){
        m_mutex.lock();
        fputs(single_log.c_str(),m_fp);
        m_mutex.unlock();
    }*/
}

m_log *m_log::get_instance() {
    static m_log instance;
    return &instance;
}

void *m_log::flush_log_thread(void *args) {
    m_log::get_instance()->async_write_log();
}

bool m_log::init(const char *file_name, int close_log, int log_buf_size, int split_lines, int max_queue_size) {
    return false;
}

void m_log::write_log(int level, const char *format, ...) {

}

void m_log::flush(void) {

}

