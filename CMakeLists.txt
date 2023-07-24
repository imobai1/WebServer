cmake_minimum_required(VERSION 3.5.1)
project(webServer)

set(CMAKE_CXX_STANDARD 11)

add_executable(webServer main.cpp
        http/httpConnection.cpp http/httpConnection.h
        CGImysql/sqlConnetionPool.cpp CGImysql/sqlConnetionPool.h
        Thread_synchronization_mechanism/signal/sem.cpp Thread_synchronization_mechanism/signal/sem.h
        Thread_synchronization_mechanism/condition/condition.cpp Thread_synchronization_mechanism/condition/condition.h
        Thread_synchronization_mechanism/locker/locker.cpp Thread_synchronization_mechanism/locker/locker.h
        log/log.cpp log/log.h log/block_queue.h Thread/threadPool.h timer/lst_timer.cpp timer/lst_timer.h config/config.cpp config/config.h webserver/webserver.cpp webserver/webserver.h)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(webServer pthread mysqlclient)