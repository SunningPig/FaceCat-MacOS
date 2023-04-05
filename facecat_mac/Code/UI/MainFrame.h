/*
* FaceCat图形通讯框架
* 上海卷卷猫信息技术有限公司
*/

#ifndef __MAINFRAME_H__
#define __MAINFRAME_H__
#pragma once
#include "stdafx.h"
#include "UIXmlEx.h"

using namespace FaceCat;


//主框架
class MainFrame : public UIXmlEx
{
public:
    /*
     * 构造函数
     */
    MainFrame();
    /*
     * 析构函数
     */
    virtual ~MainFrame();
};

#endif
