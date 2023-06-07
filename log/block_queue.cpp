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
#include "block_queue.h"

template<class T>
block_queue<T>::block_queue(int max_size) {
    if (max_size <= 0){
        exit(-1);
    }

    m_max_size = max_size;
    m_array = new T[max_size];
    m_size = 0;
    m_front = -1;
    m_back = -1;
}

template <class T>
block_queue<T>::~block_queue() {
    m_mutex.lock();
    if (m_array != NULL)
        delete [] m_array;

    m_mutex.unlock();
}

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
    if (m_size >= m_max_size){

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
    if (0 == m_size){
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
    if (m_size >= m_max_size){

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
    while (m_size <= 0){
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
    if (m_size <= 0){
        t.tv_sec = now.tv_sec + ms_timeout / 1000;
        t.tv_nsec = (ms_timeout % 1000) * 1000;
        if (!m_cond.timewait(m_mutex.get_mutex(), t)){
            m_mutex.unlock();
            return false;
        }
    }

    if (m_size <= 0){
        m_mutex.unlock();
        return false;
    }

    m_front = (m_front + 1) % m_max_size;
    item = m_array[m_front];
    m_size--;
    m_mutex.unlock();
    return true;
}


