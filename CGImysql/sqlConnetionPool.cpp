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
#include "sqlConnetionPool.h"
#include "../log/log.h"

MYSQL *SqlConnectPool::GetConnection() {
    MYSQL *con = nullptr;
    if(connList.size() == 0){
        return nullptr;
    }
    reserve.wait();
    lock.lock();
    con = connList.front();
    connList.pop_front();
    m_FreeConn_count--;
    m_CurConn_count++;
    lock.unlock();
    return con;
}

int SqlConnectPool::GetFreeConnection() {
    return this->m_FreeConn_count;
}

void SqlConnectPool::DestroyPool() {
    lock.lock();
    if(connList.size() > 0){
        for(auto it = connList.begin();it != connList.end();it++){
            MYSQL *con = *it;
            mysql_close(con);
        }
        m_CurConn_count = 0;
        m_FreeConn_count = 0;
        connList.clear();
    }
    lock.unlock();
}

bool SqlConnectPool::ReleaseConnection(MYSQL *connection) {
    if(connection == nullptr) return false;

    lock.lock();
    connList.push_back(connection);
    m_FreeConn_count++;
    m_CurConn_count--;
    lock.unlock();

    reserve.post();
    return true;
}

SqlConnectPool *SqlConnectPool::GetInstance() {
    static SqlConnectPool SqlConnPool;
    return &SqlConnPool;
}

void SqlConnectPool::init(std::string url, std::string User, std::string Password, std::string DatabaseName, int Port,
                          int MacConn, int close_log) {
    this->m_url = url;
    this->m_Port = Port;
    this->m_User = User;
    this->m_Password = Password;
    this->m_DatabaseName =DatabaseName;
    this->m_close_log = close_log;
    for (int i = 0; i < MacConn; ++i) {
        MYSQL *con = nullptr;
        con = mysql_init(con);
        if(con == nullptr){
            LOG_ERROR("MySQL Init Error");
            exit(-1);
        }
        con = mysql_real_connect(con,url.c_str(),User.c_str(),Password.c_str(),DatabaseName.c_str(),Port, nullptr,0);
        if(con == nullptr){
            LOG_ERROR("MqSQL Connection Error");
            exit(-1);
        }
        connList.push_back(con);
        this->m_FreeConn_count++;
    }
    this->reserve = sem(m_FreeConn_count);
    this->m_MacConn_count = this->m_FreeConn_count;
}

SqlConnectPool::SqlConnectPool() {
    this->m_CurConn_count = 0;
    this->m_FreeConn_count = 0;
}

SqlConnectPool::~SqlConnectPool() {
    DestroyPool();
}


connectionRAII::connectionRAII(MYSQL **conn, SqlConnectPool *connectPool) {
    *conn = connectPool->GetConnection();
    conRAII = *conn;
    poolRAII = connectPool;
}

connectionRAII::~connectionRAII() {
    poolRAII->ReleaseConnection(conRAII);
}
