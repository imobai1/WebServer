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
#ifndef WEBSERVER_SQLCONNETIONPOOL_H
#define WEBSERVER_SQLCONNETIONPOOL_H
#include <stdio.h>
#include <list>
#include <mysql/mysql.h>
#include <error.h>
#include <string.h>
#include <iostream>
#include <string>
#include "../Thread_synchronization_mechanism/locker/locker.h"
#include "../Thread_synchronization_mechanism/signal/sem.h"

class SqlConnectPool{
public:
    //获得数据库连接
    MYSQL *GetConnection();
    //释放连接
    bool ReleaseConnection(MYSQL *connection);
    //获得链接
    int GetFreeConnection();
    //销毁所有链接
    void DestroyPool();
    //获得单例
    static SqlConnectPool *GetInstance();
    //初始化
    void init(std::string url,std::string User,std::string Password,std::string DatabaseName,int Port,int MacConn,int close_log);

    std::string m_url;              //主机地址
    std::string m_Port;             //数据库端口号
    std::string m_User;             //登录数据库用户名
    std::string m_Password;         //登录数据库密码
    std::string m_DatabaseName;     //使用数据库名
    int m_close_log;                //日志开关
private:
    SqlConnectPool();
    ~SqlConnectPool();

    int m_MacConn_count;    //最大连接数
    int m_CurConn_count;    //当前已使用的连接数
    int m_FreeConn_count;   //当前空闲的连接数
    locker lock;
    sem reserve;
    list<MYSQL *>connList;  //连接池
};

//辅助类，用于在作用域结束时自动释放数据库连接
class connectionRAII{
public:
    connectionRAII(MYSQL **conn,SqlConnectPool *connectPool);
    ~connectionRAII();
private:
    MYSQL *conRAII;
    SqlConnectPool *poolRAII;
};


#endif //WEBSERVER_SQLCONNETIONPOOL_H