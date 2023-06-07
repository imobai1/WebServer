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
#ifndef WEBSERVER_SIGNAL_H
#define WEBSERVER_SIGNAL_H
#include <semaphore.h>
#include <exception>

//定义一个信号类
class sem{
public:
    //初始化信号量
    sem();
    //指定信号量的初始值
    sem(int num);
    //销毁信号量
    ~sem();
    //以原子操作的方式将信号量的值减1
    bool wait();
    //以原子操作的方式将信号量的值加1
    bool post();

protected:
    //信号量
    sem_t m_sem;
};

#endif //WEBSERVER_SIGNAL_H