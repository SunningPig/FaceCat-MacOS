/*
* FaceCat图形通讯框架(非开源)
* 著作权编号:2015SR229355+2020SR0266727
* 上海卷卷猫信息技术有限公司
*/

#ifndef __UIXMLEX_H__
#define __UIXMLEX_H__
#pragma once
#include "stdafx.h"
#include "FCUIXml.h"

namespace FaceCat{
    class UIXmlEx;

    class IOutReWrite{
    public:
        virtual FCView* createView(UIXmlEx *uiXmlEx, xmlNodePtr node){return 0;}
        virtual bool moreAnalysis(FCView *view, UIXmlEx *uiXmlEx, xmlNodePtr node){return false;}
    };

    class UIXmlEx : public FCUIXml{
    public:
        map<String, FCView*> m_viewsMap;
        map<String, FCTabPage*> m_tempTabPages;
        HashMap<String, String> m_remoteScripts;
        String m_currentXml;
        String m_currentXmlFile;
        ArrayList<FCView*> m_newViews;
        xmlDocPtr m_xmlDoc;
    public:
        UIXmlEx();
        virtual ~UIXmlEx();
    public:
        //自动选中第一行
        void autoSelectFirstRow(FCGrid *grid);
        //自动选中最后一行
        void autoSelectLastRow(FCGrid *grid);
        //创建控件
        virtual FCView* createView(xmlNodePtr node, const String& type);
        //查找控件
        virtual FCView* findView(const String& name);
        //获取列的索引
        int getColumnsIndex(FCGrid *grid, map<int, FCGridColumn*> *columnsIndex);
        virtual void exit();
        //加载数据
        virtual void loadData();
        virtual void onDragIn(ArrayList<String> *files);
        //加载文件
        virtual void loadFile(const String& fileName, FCView *view);
        //控件被添加方法
        virtual void onAddView(FCView *view, xmlNodePtr node);
        virtual FCView* readNode(xmlNodePtr node, FCView* parent);
        static void addOutReWrite(String name, IOutReWrite *iOutReWrite);
    public:
        static bool isClickRunning();
        static void setClickRunning(bool value);
        static bool isOpenAll();
        static void setOpenAll(bool value);
        virtual bool goBack();
        virtual bool goForward();
        virtual bool canGoBack();
        virtual bool canGoForward();
        virtual String callCppFunction(String parameters){return L"";}
    };
}
#endif
