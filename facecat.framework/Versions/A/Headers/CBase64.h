/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifndef __CBASE_H__
#define __CBASE_H__
#pragma once
#include "stdafx.h"
#include <string>
using namespace std;

namespace FaceCat{
	class CBase64{
	public:
		CBase64();
	public:
		virtual ~CBase64();
		static string encode(const unsigned char *Data,int DataByte);
		static string decode(const char *Data,int DataByte,int& OutByte);
	};
}

#endif
