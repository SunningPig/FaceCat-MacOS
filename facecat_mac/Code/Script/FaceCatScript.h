/*
* FaceCat图形通讯框架
* 上海卷卷猫信息技术有限公司
*/

#ifndef __FACESCRIPT_H__
#define __FACESCRIPT_H__
#pragma once
#include "stdafx.h"
#include "FCUIXml.h"
#include "FCUIScript.h"
#include "FCUIEvent.h"
#include "FCScript.h"

/*
 * 脚本解析
 */
class FaceCatScript : public FCUIScript{
public:
    /*
     * 脚本对象
     */
    FCScript *m_script;
    /*
     * XML对象
     */
    FCUIXml *m_xml;
public:
    /*
     * 构造函数
     */
    FaceCatScript(FCUIXml *xml);
    /*
     * 析构函数
     */
    virtual ~FaceCatScript();
public:
    /*
     * 调用方法
     */
    virtual String callFunction(const String& function);
    /*
     * 获取属性
     */
    String getAttribute(const String& name, const String& propertyName);
    /*
     * 获取调用者
     */
    String getSender();
    /*
     * 设置属性
     */
    void setAttribute(const String& name, const String& propertyName, const String& propertyValue);
    /*
     * 设置文本
     */
    virtual void setText(const String& text);
};

#endif
