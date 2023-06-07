cmake_minimum_required(VERSION 3.5.1)
project(webServer)

set(CMAKE_CXX_STANDARD 11)

add_executable(webServer main.cpp
        http/httpConnection.cpp http/httpConnection.h
        CGImysql/sqlConnetionPool.cpp CGImysql/sqlConnetionPool.h
        Thread_synchronization_mechanism/signal/sem.cpp Thread_synchronization_mechanism/signal/sem.h
        Thread_synchronization_mechanism/condition/condition.cpp Thread_synchronization_mechanism/condition/condition.h
        Thread_synchronization_mechanism/locker/locker.cpp Thread_synchronization_mechanism/locker/locker.h
        log/log.cpp log/log.h log/block_queue.cpp log/block_queue.h)

target_link_libraries(webServer pthread mysqlclient)