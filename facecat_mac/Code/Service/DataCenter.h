/*
* FaceCat图形通讯框架(非开源)
* 著作权编号:2015SR229355+2020SR0266727
* 上海卷卷猫信息技术有限公司
*/

#ifndef __DATACENTER_H__
#define __DATACENTER_H__
#pragma once
#include "stdafx.h"

class DataCenter{
public:
    static string getGuid();
    static string getUserPath();
    static void startService();
};

#endif
