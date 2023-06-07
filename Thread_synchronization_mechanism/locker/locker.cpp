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
#include "locker.h"

locker::locker(){
    if(pthread_mutex_init(&m_mutex,NULL) != 0){
        throw std::exception();
    }
}

locker::~locker() {
    pthread_mutex_destroy(&m_mutex);
}

bool locker::lock() {
    return pthread_mutex_lock(&m_mutex) == 0;
}

bool locker::unlock() {
    return pthread_mutex_unlock(&m_mutex) == 0;
}

pthread_mutex_t *locker::get_mutex() {
    return &m_mutex;
}
