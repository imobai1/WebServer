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
#ifndef WEBSERVER_HTTPCONNECTION_H
#define WEBSERVER_HTTPCONNECTION_H
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <sys/stat.h>
#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/uio.h>
#include <map>
#include <mysql/mysql.h>


class http_connection{
public:
    static const int FILENAME_LEN = 200;
    static const int READ_BUFFER_SIZE = 2048;
    static const int WRITE_BUFFER_SIZE = 1024;
    //HTTP 协议中定义的不同请求方法
    enum METHOD{GET = 0,POST,HEAD,PUT,DELETE,TRACE,OPTIONS,CONNECT,PATH};
    //状态检查
    enum CHECK_STATE{
        CHECK_STATE_REQUESTLINE = 0,    //表示当前正在解析请求行
        CHECK_STATE_HEADER,             //表示当前正在解析请求头部
        CHECK_STATE_CONTENT};           //表示当前正在解析请求内容
    //HTTP 请求的不同状态或结果
    enum HTTP_CODE{
        NO_REQUEST,         //表示没有请求
        GET_REQUEST,        //表示收到了一个有效的 GET请求
        BAD_REQUEST,        //表示收到了一个无效的请求，请求格式错误
        NO_RESOURCE,        //表示请求的资源不存在。
        FORBIDDEN_REQUEST,  //表示请求的资源被禁止访问
        FILE_REQUEST,       //表示收到了一个针对文件的请求
        INTERNAL_ERROR,      //表示在处理请求时发生了内部错误
        CLOSED_CONNECTION}; //表示连接已关闭，无法继续处理请求
    enum LINE_STATUS{
        LINE_OK = 0,    //表示读取行成功，行的内容是有效的
        LINE_BAD,       //表示读取行失败，行的内容有错误或不合法
        LINE_OPEN};     //表示行尚未读取完整，需要继续读取更多数据

    int timer_flag;  // 定时器标志
    int improv;     // 是否改善
public:

    http_connection(){};
    ~http_connection(){};

    // 初始化函数，用于设置连接的套接字、地址信息和其他参数
    void init(int sockfd, const sockaddr_in &addr, char* root, int TRIGMode , int close_log,
              std::string user, std::string passwd,std::string sqlname);
    // 关闭连接函数
    void close_connection(bool real_close = true);
    // 处理函数，用于处理连接上的请求和响应
    void process();
    // 读取请求数据的函数，直到数据读取完整或者对方关闭连接
    bool read_once();
    // 发送响应数据的函数，将响应数据发送给客户端
    bool write();
    // 获取连接的地址信息
    sockaddr_in *get_address();
    // 初始化 MySQL 连接结果对象
    //void initmysql_result(connection_pool *connPool);

private:
    // 初始化新接受的连接
    void init();
    // 处理读取的请求数据，解析请求行、请求头和请求体
    HTTP_CODE process_read();
    // 处理发送的响应数据，根据返回的状态码进行相应的处理
    bool process_write(HTTP_CODE ret);
    // 解析请求行
    HTTP_CODE parse_request_line(char *text);
    // 解析请求头
    HTTP_CODE parse_headers(char *text);
    // 解析请求体
    HTTP_CODE parse_content(char *text);
    // 处理请求，根据请求内容执行相应的操作
    HTTP_CODE do_request();
    // 获取当前正在解析的行的起始位置
    char *get_line() { return m_read_buf + m_start_line; };
    // 解析一行数据
    LINE_STATUS parse_line();
    // 取消文件内存映射
    void unmap();
    // 添加响应内容
    bool add_response(const char *format, ...);
    // 添加响应正文内容
    bool add_content(const char *content);
    // 添加响应状态行
    bool add_status_line(int status, const char *title);
    // 添加响应头部
    bool add_headers(int content_length);
    // 添加响应内容类型
    bool add_content_type();
    // 添加响应内容长度
    bool add_content_length(int content_length);
    // 添加保持连接标志
    bool add_linger();
    // 添加空行
    bool add_blank_line();
public:
    static int m_epollfd;     // epoll 文件描述符
    static int m_user_count;  // 当前连接的用户数量
    MYSQL *mysql;             // MySQL 连接对象
    int m_state;              // 连接的状态（读为0，写为1）
private:
    int m_sockfd;                       // 套接字描述符
    sockaddr_in m_address;              // 地址信息结构体

    char m_read_buf[READ_BUFFER_SIZE];  // 读缓冲区
    int m_read_idx;                     // 读缓冲区中数据的索引
    int m_checked_idx;                  // 已经解析的字符在读缓冲区中的位置
    int m_start_line;                   // 当前正在解析的行的起始位置
    char m_write_buf[WRITE_BUFFER_SIZE];// 写缓冲区
    int m_write_idx;                    // 写缓冲区中待发送数据的索引

    CHECK_STATE m_check_state;          // 当前解析的状态
    METHOD m_method;                    // HTTP 请求的方法
    char m_real_file[FILENAME_LEN];     // 请求的真实文件路径
    char* m_url;                        // 请求的URL
    char* m_version;                    // HTTP版本号
    char* m_host;                       // 请求的主机名
    int m_content_length;               // 请求的内容长度
    bool m_linger;                      // 是否保持连接
    char* m_file_address;               // 文件映射的内存地址
    struct stat m_file_stat;            // 文件状态信息
    struct iovec m_iv[2];               // 写缓冲区的向量数组
    int m_iv_count;                     // 向量数组的计数
    int cgi;                            // 是否启用CGI
    char* m_string;                     // 存储请求头数据
    int bytes_to_send;                  // 需要发送的字节数
    int bytes_have_send;                // 已经发送的字节数
    char* doc_root;                     // Web 服务器的根目录

    std::map<std::string,std::string> m_users;        // 用户名和密码的映射表
    int m_TRIGMode;                     // 运行模式
    int m_close_log;                    // 是否关闭日志记录

    char sql_user[100];                 // 数据库用户名
    char sql_passwd[100];               // 数据库密码
    char sql_name[100];                 // 数据库名称

};



#endif //WEBSERVER_HTTPCONNECTION_H