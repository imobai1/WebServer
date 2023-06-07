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
#ifndef WEBSERVER_COND_H
#define WEBSERVER_COND_H
#include <exception>
#include <pthread.h>
//定义一个条件变量
class condition{
public:
    //构造---初始化条件变量
    condition();
    //析构---销毁条件变量
    ~condition();
    //等待目标条件变量
    bool wait(pthread_mutex_t *m_mutex);
    //等待条件变量时设置超时
    bool timewait(pthread_mutex_t *m_mutex,struct timespec t);
    //唤醒一个等待目标条件变量的线程
    bool signal();
    //以广播的方式唤醒所有等待目标条件变量的线程
    bool broadcast();
private:
    //定义一个条件变量
    pthread_cond_t m_cond;
};

#endif //WEBSERVER_COND_H