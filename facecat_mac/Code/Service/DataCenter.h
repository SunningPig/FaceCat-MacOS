/*
* FaceCat图形通讯框架
* 上海卷卷猫信息技术有限公司
*/

#ifndef __DATACENTER_H__
#define __DATACENTER_H__
#pragma once
#include "stdafx.h"

/*
 * 程序入口
 */
class DataCenter{
public:
    /*
     * 获取GUID
     */
    static std::string getGuid();
    /*
     * 获取程序路径
     */
    static std::string getUserPath();
    /*
     * 启动服务
     */
    static void startService();
};

#endif
