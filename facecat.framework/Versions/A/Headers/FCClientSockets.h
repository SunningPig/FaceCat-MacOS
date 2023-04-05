/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifndef __FCCLIENTSOCKETS_H__
#define __FCCLIENTSOCKETS_H__
#pragma once
#include "stdafx.h"

namespace FaceCat{
	typedef void (*RecvMsg)(int socketID, int localSID, const char *str, int len);
    
	typedef void (*WriteClientLog)(int socketID, int localSID, int state, const char *log);
    
    /*
     * 客户端套接字连接管理
     */
	class FCClientSockets{
	public:
		static void recvServerMsg(int socketID, int localSID, const char *str, int len);
		static void writeLog(int socketID, int localSID, int state, const char *log);
	public:
		static int close(int socketID);
		static int connect(int proxyType, const char *ip, int port, const char *proxyIp, int proxyPort, const char *proxyUserName, const char *proxyUserPwd, const char *proxyDomain, int timeout, char *token);
		static void registerLog(WriteClientLog writeLogCallBack);
		static void registerRecv(RecvMsg recvMsgCallBack);
		static int send(int socketID, const char *str, int len);
	};
}

#endif
