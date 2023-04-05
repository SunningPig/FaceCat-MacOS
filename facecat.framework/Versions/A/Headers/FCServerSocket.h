/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifndef __FCSERVERSOCKET_H__
#define __FCSERVERSOCKET_H__
#pragma once
#include "stdafx.h"
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<fcntl.h>
#include "FCServerSockets.h"
#include "FCLock.h"

namespace FaceCat{
    class SOCKDATA{
    public:
        SOCKDATA();
        ~SOCKDATA();
        char *m_buffer;
        int m_bufferRemain;
        bool m_get;
        int m_head;
        int m_headSize;
        char m_headStr[4];
        int m_index;
        int m_len;
        int m_pos;
        int m_socket;
        char *m_str;
        int m_strRemain;
        bool m_submit;
        int m_readHead;
    };

    /*
    * 服务端套接字连接
    */
    class FCServerSocket{
    public:
        struct sockaddr_in m_servaddr;
        std::vector<SOCKDATA*> m_datas;
        int m_hSocket;
        int m_port;
        int m_state;
        RecvMsg m_recvEvent;
        WriteServerLog m_writeLogEvent;
        int m_newSocket;
        char m_token[4];
    public:
        /*
        * 创建服务端socket
        */
        FCServerSocket();
        /*
        * 销毁对象
        */
        virtual ~FCServerSocket();
        /*
        * 关闭服务端
        */
        int close(int socketID);
        /*
        * 关闭客户端
        */
        int closeClient(int socketID);
        /*
        * 接收数据
        */
        int recv(SOCKDATA *data);
        /*
        * 发送数据
        */
        static int send(int socketID, const char *str, int len);
        /*
        * 启动TCP
        */
        int startTCP(int port);
        /*
        * 写日志
        */
        void writeLog(int socketID, int localSID, int state, const char *log);
        /*
         * 获取最后的socketID
         */
        static int getLastSocket();
    public:
        /*
         * 清除缓存的间隔
         */
        int m_clearInterval;
        /*
         * 记录IP的缓存
         */
        std::map<std::string, int> m_ipCaches;
        /*
         * 记录缓存的锁
         */
        FCLock m_ipCachesLock;
        /*
         * 上次清理缓存的时间
         */
        double m_lastClearTime;
        /*
         * 限制连接IP的次数
         */
        int m_limitTimes;
        /*
         * IP黑名单
         */
        std::map<std::string, int> m_blackIPs;
        /*
         * 黑名单的锁
         */
        FCLock m_blackIPsLock;
        /*
         * 添加IP黑名单
         */
        void addBlackIP(std::string ip);
        /*
         * 移除IP黑名单
         */
        void removeBlackIP(std::string ip);
    };
}
#endif
