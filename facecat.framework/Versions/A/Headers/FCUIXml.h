/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */
#ifndef __FCUIXML_H__
#define __FCUIXML_H__
#pragma once
#include "stdafx.h"
#include "FCLib.h"
#include "FCUIEvent.h"
#include "FCUIScript.h"
#include <libxml2/libxml/parser.h>
#include <libxml2/libxml/tree.h>

namespace FaceCat{
    class FCUIEvent;
    class FCUIScript;
    
    class FCUIXml{
    public:
        /*
         * 是否允许名称
         */
        bool m_allowName;
        /*
        * 名称
        */
        String m_name;
        /**
         * 控件列表
         */
        ArrayList<FCView*> m_views;
        /**
         * 事件
         */
        FCUIEvent *m_event;
        /**
         * 方法库
         */
        FCNative *m_native;
        /**
         * 脚本
         */
        FCUIScript *m_script;
        /**
         * CSS样式
         */
        HashMap<String, String> m_styles;
        /*
         * 创建FCGridBand
         */
        virtual void createBandedGridBands(xmlNodePtr node, FCView *view);
        /*
         * 创建表格列
         */
        virtual void createBandedGridColumns(xmlNodePtr node, FCView *view);
        /*
         * 创建K线图
         */
        virtual void createChartSubAttribute(xmlNodePtr node, FCChart *chart);
        /**
         * 创建菜单项
         */
        virtual void createMenuItem(xmlNodePtr node, FCMenu *menu, FCMenuItem *parentItem);
        /*
         * 创建表格列
         */
        virtual void createGridColumns(xmlNodePtr node, FCView *view);
        /*
         * 创建表格行
         */
        virtual void createGridRow(xmlNodePtr node, FCView *view);
        /*
         * 创建表格行
         */
        virtual void createGridRows(xmlNodePtr node, FCView *view);
        /**
         * 创建分割布局控件
         */
        virtual void createSplitLayoutSubAttribute(xmlNodePtr node, FCSplitLayoutDiv *splitLayoutDiv);
        /**
         * 创建控件
         */
        virtual void createTableLayoutSubAttribute(xmlNodePtr node, FCTableLayoutDiv *tableLayoutDiv);
        /**
         * 创建多页夹的页
         */
        virtual void createTabPage(xmlNodePtr node, FCView *view);
        /**
         * 创建树的节点
         */
        virtual void createTreeNode(xmlNodePtr node, FCView *view, FCTreeNode *treeNode);
        /**
         * 创建树的节点
         */
        virtual void createTreeNodes(xmlNodePtr node, FCView *view);
        /**
         * 创建用户控件
         */
        virtual FCView* createCustomView(xmlNodePtr node);
    public:
        /*
         * 构造函数
         */
        FCUIXml();
        /*
         * 析构函数
         */
        virtual ~FCUIXml();
        /**
         * 获取事件
         */
        virtual FCUIEvent* getEvent();
        /**
         * 设置事件
         */
        virtual void setEvent(FCUIEvent *value);
        /**
         * 获取方法库
         */
        virtual FCNative* getNative();
        /**
         * 设置方法库
         */
        virtual void setNative(FCNative *value);
        /**
         * 获取脚本
         */
        virtual FCUIScript* getScript();
        /**
         * 设置脚本
         */
        virtual void setScript(FCUIScript *value);
    public:
        /**
         * 获取按钮
         * @params name   控件名称
         */
        virtual FCButton* getButton(const String& name);
        /**
         * 获取图形控件
         */
        virtual FCChart* getChart(const String& name);
        /**
         * 获取复选框
         */
        virtual FCCheckBox* getCheckBox(const String& name);
        /**
         * 获取下拉控件
         */
        virtual FCComboBox* getComboBox(const String& name);
        /**
         * 获取图层
         */
        virtual FCDiv* getDiv(const String& name);
        /**
         * 获取表格
         */
        virtual FCGrid* getGrid(const String& name);
        /**
         * 获取组控件
         */
        virtual FCGroupBox* getGroupBox(const String& name);
        /**
         * 获取标签
         */
        virtual FCLabel* getLabel(const String& name);
        /**
         * 获取布局层
         */
        virtual FCLayoutDiv* getLayoutDiv(const String& name);
        /**
         * 获取名称相似控件
         */
        virtual ArrayList<FCView*> getLikeViews(const String& name);
        /**
         * 获取菜单控件
         */
        virtual FCMenu* getMenu(const String& name);
        /**
         * 获取菜单项控件
         */
        virtual FCMenuItem* getMenuItem(const String& name);
        /**
         * 获取单选按钮
         */
        virtual FCRadioButton* getRadioButton(const String& name);
        /**
         * 获取数值控件
         */
        virtual FCSpin* getSpin(const String& name);
        /**
         * 获取分割层
         */
        virtual FCSplitLayoutDiv* getSplitLayoutDiv(const String& name);
        /**
         * 获取多页夹控件
         */
        virtual FCTabView* getTabView(const String& name);
        /**
         * 获取表格层
         */
        virtual FCTableLayoutDiv* getTableLayoutDiv(const String& name);
        /**
         * 获取夹控件
         */
        virtual FCTabPage* getTabPage(const String& name);
        /**
         * 获取文本框
         */
        virtual FCTextBox* getTextBox(const String& name);
        /**
         * 获取树控件
         */
        virtual FCTree* getTree(const String& name);
        /**
         * 获取窗体
         */
        virtual FCWindow* getWindow(const String& name);
        /*
        * 获取命名的Xml对象
        */
        static FCUIXml* getNameXml(const String& name);
    public:
        /**
         * 是否包含控件
         * @params view  控件
         */
        virtual bool containsView(FCView *view);
        /**
         * 创建控件
         */
        virtual FCView* createView(xmlNodePtr node, const String& type);
        /**
         * 创建控件框架
         */
        virtual void createNative();
        /**
         * 创建子属性
         */
        virtual void createSubAttribute(xmlNodePtr node, FCView *view);
        /**
         * 查找控件
         */
        virtual FCView* findView(const String& name);
        /**
         * 获取属性
         */
        virtual HashMap<String, String> getAttributes(xmlNodePtr node);
        /**
         * 获取所有的控件
         */
        virtual ArrayList<FCView*> getViews();
        /**
         * 判断是否后设置属性
         */
        virtual bool isAfterSetingAttribute(const String& name);
        /**
         * 读取文件，加载到控件中
         */
        virtual void loadFile(const String& fileName, FCView *view);
        /**
         * 添加控件
         */
        virtual void onAddView(FCView *view, xmlNodePtr node);
        /**
         * 读取文件体
         */
        virtual void readBody(xmlNodePtr node, FCView *view);
        /**
         * 读取子节点
         */
        virtual void readChildNodes(xmlNodePtr node, FCView *view);
        /**
         * 读取头部
         */
        virtual void readHead(xmlNodePtr node, FCView *view);
        /**
         * 读取XML
         */
        virtual FCView* readNode(xmlNodePtr node, FCView* parent);
        /**
         * 读取样式
         */
        virtual void readStyle(xmlNodePtr node, FCView *view);
        /**
         * 后设置属性
         */
        virtual void setAttributesAfter(xmlNodePtr node, FCAttribute *view);
        /**
         * 前设置属性
         */
        virtual void setAttributesBefore(xmlNodePtr node, FCAttribute *view);
        /**
         * 设置事件
         */
        virtual void setEvents(xmlNodePtr node, FCAttribute *view);
        /**
         * 设置CSS样式
         */
        virtual void setStyle(const String& style, FCAttribute *view);
    };
}
#endif
