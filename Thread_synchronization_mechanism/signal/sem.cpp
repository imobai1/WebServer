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
#include "sem.h"

sem::sem() {
    if (sem_init(&m_sem, 0, 0) != 0){
        throw std::exception();
    }
}

sem::sem(int num) {
    if (sem_init(&m_sem, 0, num) != 0){
        throw std::exception();
    }
}

sem::~sem() {
    sem_destroy(&m_sem);
}


bool sem::wait() {
    return sem_wait(&m_sem) == 0;
}

bool sem::post() {
    return sem_post(&m_sem) == 0;
}

