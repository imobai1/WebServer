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
#ifndef WEBSERVER_CONFIG_H
#define WEBSERVER_CONFIG_H
#include "../webserver/webserver.h"
using namespace std;

class Config
{
public:
    Config();
    ~Config(){};

    void parse_arg(int argc, char*argv[]);
    //端口号
    int PORT;
    //日志写入方式
    int LOGWrite;
    //触发组合模式
    int TRIGMode;
    //listenfd触发模式
    int LISTENTrigmode;
    //connfd触发模式
    int CONNTrigmode;
    //优雅关闭链接
    int OPT_LINGER;
    //数据库连接池数量
    int sql_num;
    //线程池内的线程数量
    int thread_num;
    //是否关闭日志
    int close_log;
    //并发模型选择
    int actor_model;
};

#endif //WEBSERVER_CONFIG_H