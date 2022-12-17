/*
* FaceCat图形通讯框架(非开源)
* 著作权编号:2015SR229355+2020SR0266727
* 上海卷卷猫信息技术有限公司
*/

#include "stdafx.h"
#include "FaceCatScript.h"

FaceCatScript::FaceCatScript(FCUIXml *xml) : FCUIScript(xml)
{
    m_script = 0;
    m_xml = xml;
}

FaceCatScript::~FaceCatScript()
{
    if(m_script)
    {
        delete m_script;
        m_script = 0;
    }
    m_xml = 0;
}

String FaceCatScript::callFunction(const String& function)
{
    if(m_script){
        int cindex = (int)function.find(L'(');
        String upperName = FCTran::toUpper(function.substr(0, cindex));
        if (m_script->m_tempFunctions.containsKey(upperName))
        {
            double value = m_script->callFunction(function);
            if (m_script->m_resultVar.m_type == 1)
            {
                if ((int)m_script->m_resultVar.m_str.length() > 0 && m_script->m_resultVar.m_str[0] == '\'')
                {
                    return m_script->m_resultVar.m_str.substr(1, (int)m_script->m_resultVar.m_str.length() - 2);
                }
                else
                {
                    return m_script->m_resultVar.m_str;
                }
            }
            return FCTran::doubleToStr(value);
        }
    }
    return L"";
}

String FaceCatScript::getAttribute(const String& name, const String& propertyName)
{
    if (m_xml)
    {
        FCView *view = m_xml->findView(name);
        if (view)
        {
            String value = L"", type = L"";
            view->getAttribute(propertyName, &value, &type);
            return value;
        }
    }
    return L"";
}

String FaceCatScript::getSender()
{
    if (m_xml)
    {
        FCUIEvent *uiEvent = m_xml->getEvent();
        if (uiEvent)
        {
            return uiEvent->getSender();
        }
    }
    return 0;
}

void FaceCatScript::setAttribute(const String& name, const String& propertyName, const String& propertyValue)
{
    if (m_xml)
    {
        FCView *view = m_xml->findView(name);
        if (view)
        {
            view->setAttribute(propertyName, propertyValue);
        }
    }
}

void FaceCatScript::setText(const String& text)
{
}
