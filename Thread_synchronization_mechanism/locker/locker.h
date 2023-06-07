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
#ifndef WEBSERVER_LOCKER_H
#define WEBSERVER_LOCKER_H
#include <pthread.h>
#include <exception>
//定义一个互斥锁类
class locker{
public:
    //初始化互斥锁
    locker();
    //销毁互斥锁
    ~locker();
    //加锁
    bool lock();
    //解锁
    bool unlock();
    //获得互斥锁
    pthread_mutex_t *get_mutex();
private:
    //定义一个互斥锁
    pthread_mutex_t m_mutex;
};

#endif //WEBSERVER_LOCKER_H