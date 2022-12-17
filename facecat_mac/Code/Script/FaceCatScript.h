/*
* FaceCat图形通讯框架(非开源)
* 著作权编号:2015SR229355+2020SR0266727
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

class FaceCatScript : public FCUIScript{
public:
    FCScript *m_script;
    FCUIXml *m_xml;
public:
    FaceCatScript(FCUIXml *xml);
    virtual ~FaceCatScript();
public:
    virtual String callFunction(const String& function);
    String getAttribute(const String& name, const String& propertyName);
    String getSender();
    void setAttribute(const String& name, const String& propertyName, const String& propertyValue);
    virtual void setText(const String& text);
};

#endif
