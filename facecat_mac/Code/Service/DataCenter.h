/*
* FaceCat图形通讯框架
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
