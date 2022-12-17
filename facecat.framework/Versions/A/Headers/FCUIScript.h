/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifndef __UISCRIPT_H__
#define __UISCRIPT_H__
#pragma once
#include "stdafx.h"
#include "FCUIEvent.h"
#include "FCUIScript.h"

namespace FaceCat{
    class FCUIEvent;
    class FCUIXml;
    
    /*
     * 脚本接口类
     */
    class FCUIScript{
    private:
        /*
         * xml对象
         */
        FCUIXml* m_xml;
    public:
        /*
         * 构造函数
         */
        FCUIScript(FCUIXml *xml);
        /*
         * 析构函数
         */
        virtual ~FCUIScript();
        /**
         * 获取XML对象
         */
        FCUIXml* getXml();
        /**
         * 设置XML对象
         */
        void setXml(FCUIXml *xml);
    public:
        /**
         * 调用方法
         */
        virtual String callFunction(const String& function);
        /**
         * 设置脚本
         */
        virtual void setText(const String& text);
    };
}
#endif
