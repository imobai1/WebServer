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
    block_queue(int max_size = 1000){
        if (max_size <= 0){
            exit(-1);
        }
        m_max_size = max_size;
        m_array = new T[max_size];
        m_size = 0;
        m_front = -1;
        m_back = -1;
    }
    ~block_queue(){
        m_mutex.lock();
        if (m_array != NULL)
            delete [] m_array;

        m_mutex.unlock();
    }
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
    T* m_array;         //存储队列元素的数组指针
    int m_size;         //当前队列中的元素个数
    int m_max_size;     //队列的最大容量
    int m_front;        //队列头部的索引
    int m_back;         //队列尾部的索引
};

template<class T>
void block_queue<T>::clear() {
    m_mutex.lock();
    m_size = 0;
    m_front = -1;
    m_back = -1;
    m_mutex.unlock();
}

template<class T>
bool block_queue<T>::full() {
    m_mutex.lock();
    if (m_size == m_max_size){
        m_mutex.unlock();
        return true;
    }
    m_mutex.unlock();
    return false;
}

template<class T>
bool block_queue<T>::empty() {
    m_mutex.lock();
    if (m_size == 0){
        m_mutex.unlock();
        return true;
    }
    m_mutex.unlock();
    return false;
}

template<class T>
bool block_queue<T>::front(T &value) {
    m_mutex.lock();
    if (m_size == 0){
        m_mutex.unlock();
        return false;
    }
    value = m_array[m_front];
    m_mutex.unlock();
    return true;
}

template<class T>
bool block_queue<T>::back(T &value) {
    m_mutex.lock();
    if (0 == m_size){
        m_mutex.unlock();
        return false;
    }
    value = m_array[m_back];
    m_mutex.unlock();
    return true;
}

template<class T>
int block_queue<T>::size() {
    int tmp = 0;
    m_mutex.lock();
    tmp = m_size;
    m_mutex.unlock();
    return tmp;
}

template<class T>
int block_queue<T>::max_size() {
    int tmp = 0;
    m_mutex.lock();
    tmp = m_max_size;
    m_mutex.unlock();
    return tmp;
}

template<class T>
bool block_queue<T>::push(const T &item) {
    m_mutex.lock();
    if (m_size == m_max_size){
        m_cond.broadcast();
        m_mutex.unlock();
        return false;
    }
    m_back = (m_back + 1) % m_max_size;
    m_array[m_back] = item;
    m_size++;
    m_cond.broadcast();
    m_mutex.unlock();
    return true;
}

template<class T>
bool block_queue<T>::pop(T &item) {
    m_mutex.lock();
    while (m_size == 0){
        if (!m_cond.wait(m_mutex.get_mutex())){
            m_mutex.unlock();
            return false;
        }
    }
    m_front = (m_front + 1) % m_max_size;
    item = m_array[m_front];
    m_size--;
    m_mutex.unlock();
    return true;
}

template<class T>
bool block_queue<T>::pop(T &item, int ms_timeout) {
    //用于设置超时时间。
    struct timespec t = {0, 0};
    //用于获取当前时间
    struct timeval now = {0, 0};
    //获取当前时间，存储在 now 变量中。
    gettimeofday(&now, NULL);
    m_mutex.lock();
    if (m_size == 0){
        //在timespec中，记录超时的绝对时间
        t.tv_sec = now.tv_sec + ms_timeout / 1000;
        t.tv_nsec = (ms_timeout % 1000) * 1000;
        if (!m_cond.timewait(m_mutex.get_mutex(), t)){
            m_mutex.unlock();
            return false;
        }
    }
    if (m_size == 0) {
        m_mutex.unlock();
        return false;
    }
    m_front = (m_front + 1) % m_max_size;
    item = m_array[m_front];
    m_size--;
    m_mutex.unlock();
    return true;
}

#endif //WEBSERVER_BLOCK_QUEUE_H