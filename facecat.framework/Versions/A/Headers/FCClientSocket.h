/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifndef __FCCLIENTSOCKET_H__
#define __FCCLIENTSOCKET_H__
#pragma once
#include "stdafx.h"
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include<fcntl.h>
#include "CBase64.h"
#include "FCClientSockets.h"

namespace FaceCat{
	enum ConnectStatus{
		SUCCESS,
		CONNECT_PROXY_FAIL,
		NOT_CONNECT_PROXY,
		CONNECT_SERVER_FAIL
	};
    
    struct TSock4req1{
		char VN;
		char CD;
		unsigned short Port;
		unsigned long IPAddr;
		char other;
	};
    
	struct TSock4ans1{
		char VN;
		char CD;
	};
    
	struct TSock5req1{
		char Ver;
		char nMethods;
		char Methods;
	};
    
	struct TSock5ans1{
		char Ver;
		char Method;
	};
    
	struct TSock5req2{
		char Ver;
		char Cmd;
		char Rsv;
		char Atyp;
		char other;
	};
    
	struct TSock5ans2{
		char Ver;
		char Rep;
		char Rsv;
		char Atyp;
		char other;
	};
    
	struct TAuthreq{
		char Ver;
		char Ulen;
		char Name;
		char PLen;
		char Pass;
	};
    
	struct TAuthans{
		char Ver;
		char Status;
	};
    
    /*
     * 客户端套接字连接
     */
	class FCClientSocket{
	public:
		bool m_blnProxyServerOk;
        struct addrinfo hints;
        struct addrinfo *res;
        struct addrinfo *res0;
		std::string m_ip;
		u_short m_port;
		std::string m_proxyDomain;
		long m_proxyType;
		std::string m_proxyIp;
		u_short m_proxyPort;
		std::string m_proxyUserName;
		std::string m_proxyUserPwd;
        int m_timeout;
        char m_token[4];
    public:
		ConnectStatus connectStandard();
        ConnectStatus connectByHttp();
		ConnectStatus connectBySock4();
		ConnectStatus connectBySock5();
		void createSocket();
	public:
        struct sockaddr_in m_addr;
		int m_hSocket;
		RecvMsg m_recvEvent;
		WriteClientLog m_writeLogEvent;
	public:
		FCClientSocket(long proxyType, std::string ip, u_short port, std::string proxyIp, u_short proxyPort, std::string proxyUserName, std::string proxyUserPwd, std::string proxyDomain, int timeout, char *token);
		virtual ~FCClientSocket();
    public:
		int close(int socketID);
		ConnectStatus connect();
		ConnectStatus connectProxyServer();
        static std::string getHostIP(const char* ip);
		static int send(int socketID, const char *str, int len);
		void writeLog(int socketID, int localSID, int state, const char *log);
	};
}

#endif
