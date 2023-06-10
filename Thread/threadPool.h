/*
 Copyright mobai. All rights reserved.

 @Author: mengHuan
 @Date: 2023/6/10

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
#ifndef WEBSERVER_THREADPOOL_H
#define WEBSERVER_THREADPOOL_H
#include <list>
#include <cstdio>
#include <exception>
#include <pthread.h>
#include "../CGImysql/sqlConnetionPool.h"


template<typename T>
//定义一个线程池类
class threadPool{
public:
    threadPool(int actor_model,SqlConnectPool *connectPool,int thread_num = 8,int max_request = 10000);
    ~threadPool();
    bool append(T *request,int state);
    bool append_p(T * request);
private:
    static void *worker(void *arg);
    void run();

    int m_thread_number;
    int m_max_requests;
    pthread_t *m_threads;
    std::list<T *> m_workQueue;
    locker m_queueLocker;
    sem m_queueSem;
    SqlConnectPool *m_connPool;
    int m_actor_model;
};

template<typename T>
threadPool<T>::threadPool(int actor_model, SqlConnectPool *connectPool, int thread_num, int max_request) {
    if(thread_num <= 0 ||max_request <= 0) throw std::exception();
    m_threads = new pthread_t[m_thread_number];
    if(!m_threads)  throw std::exception();
    for (int i = 0; i < thread_num; ++i) {
        if(pthread_create(m_threads + i, nullptr,worker,this) != 0){
            delete[] m_threads;
            throw std::exception();
        }
        if(pthread_detach(m_threads[i])){
            delete[] m_threads;
            throw std::exception();
        }
    }
}

template<typename T>
threadPool<T>::~threadPool() {
    delete[] m_threads;
}

template<typename T>
bool threadPool<T>::append(T *request, int state) {
    m_queueLocker.lock();
    if(m_workQueue.size() >= m_max_requests){
        m_queueLocker.unlock();
        return false;
    }
    request->m_state = state;
    m_workQueue.push_back(request);
    m_queueLocker.unlock();
    m_queueSem.post();
    return true;
}

template<typename T>
bool threadPool<T>::append_p(T *request) {
    m_queueLocker.lock();

    if(m_workQueue.size() >= m_max_requests){
        m_queueLocker.unlock();
        return false;
    }
    m_workQueue.push_back(request);
    m_queueLocker.unlock();
    m_queueSem.post();
    return true;
}

template<typename T>
void *threadPool<T>::worker(void *arg) {
    threadPool *pool = (threadPool *)arg;
    pool->run();
    return pool;
}

template<typename T>
void threadPool<T>::run() {
    while(true){
        m_queueSem.wait();
        m_queueLocker.lock();
        if(m_workQueue.empty()){
            m_queueLocker.unlock();
            continue;
        }
        T *request = m_workQueue.front();
        m_workQueue.pop_front();
        m_queueLocker.unlock();
        if(!request) continue;

        if(m_actor_model == 1){
            if(request->m_state == 0){
                if(request->read_oncce()){
                    request->improv = 1;
                    connectionRAII mysqlCon(&request->mysql,m_connPool);
                    request->process();
                }else{
                    request->improv = 1;
                    request->timer_flag = 1;
                }
            }else{
                if(request->write()){
                    request->improve = 1;
                }else{
                    request->improv = 1;
                    request->timer_flag = 1;
                }
            }
        }else{
            connectionRAII mysqlCon(&request->mysql,m_connPool);
            request->process();
        }
    }
}

#endif //WEBSERVER_THREADPOOL_H