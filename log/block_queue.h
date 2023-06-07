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
#ifndef WEBSERVER_BLOCK_QUEUE_H
#define WEBSERVER_BLOCK_QUEUE_H
#include <iostream>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include "../Thread_synchronization_mechanism/locker/locker.h"
#include "../Thread_synchronization_mechanism/condition/condition.h"
template <class T>
class block_queue{
public:
    block_queue(int max_size = 1000);
    ~block_queue();
    //清空队列，将size、front和back重置为初始状态
    void clear();
    //判断队列是否已满
    bool full();
    //判断队列是否为空
    bool empty();
    //获取队首元素
    bool front(T &value);
    //获取队尾元素
    bool back(T &value);
    //获取队列中元素的个数
    int size();
    //获取队列的最大容量
    int max_size();
    //往队列中添加元素
    bool push(const T &item);
    //从队列中取出元素
    bool pop(T &item);
    bool pop(T &item,int ms_timeout);
private:
    locker m_mutex;
    condition m_cond;
    //存储队列元素的数组指针
    T* m_array;
    //当前队列中的元素个数
    int m_size;
    //队列的最大容量
    int m_max_size;
    //队列头部的索引
    int m_front;
    //队列尾部的索引
    int m_back;
};





#endif //WEBSERVER_BLOCK_QUEUE_H