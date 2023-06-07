/*
 Copyright mobai. All rights reserved.

 @Author: mengHuan
 @Date: 2023/6/5

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
#include "condition.h"

condition::condition(){
    if (pthread_cond_init(&m_cond, NULL) != 0){
        throw std::exception();
    }
}

condition::~condition() {
    pthread_cond_destroy(&m_cond);
}

bool condition::wait(pthread_mutex_t *m_mutex) {
    int ret = 0;
    ret = pthread_cond_wait(&m_cond, m_mutex);
    return ret == 0;
}

bool condition::timewait(pthread_mutex_t *m_mutex, struct timespec t) {
    int ret = 0;
    ret = pthread_cond_timedwait(&m_cond, m_mutex, &t);
    return ret == 0;
}

bool condition::signal() {
    return pthread_cond_signal(&m_cond) == 0;
}

bool condition::broadcast() {
    return pthread_cond_broadcast(&m_cond) == 0;
}
