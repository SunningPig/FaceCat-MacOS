/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifndef __FCTABPAGE_H__
#define __FCTABPAGE_H__
#pragma once
#include "stdafx.h"
#include "FCDiv.h"
#include "FCButton.h"
#include "FCTabView.h"

namespace FaceCat{
    class FCTabView;
    /**
     * 多页夹控件
     */
    class FCTabPage:public FCDiv{
    public:
        /**
         * 获取或设置页头按钮
         */
        FCButton *m_headerButton;
        /**
         * 获取或设置头部的位置
         */
        FCPoint m_headerLocation;
        /**
         * 多页夹控件
         */
        FCTabView *m_tabView;
    public:
        /*
         * 创建页
         */
        FCTabPage();
        /*
         * 删除页
         */
        virtual ~FCTabPage();
        /**
         * 获取页头按钮
         */
        virtual FCButton* getHeaderButton();
        /**
         * 设置页头按钮
         */
        virtual void setHeaderButton(FCButton *value);
        /**
         * 获取头部的位置
         */
        virtual FCPoint getHeaderLocation();
        /**
         * 设置头部的位置
         */
        virtual void setHeaderLocation(FCPoint value);
        /**
         * 获取头部是否可见
         */
        virtual bool isHeaderVisible();
        /**
         * 设置头部是否可见
         */
        virtual void setHeaderVisible(bool value);
        /**
         * 获取多页夹控件
         */
        virtual FCTabView* getTabView();
        /**
         * 设置多页夹控件
         */
        virtual void setTabView(FCTabView *value);
    public:
        /*
        * 触发事件
        */
        virtual void callEvent(String eventName, Object sender, Object invoke);
        /*
        * 触摸事件
        */
        virtual void callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke);
        /**
         * 获取控件类型
         */
        virtual String getViewType();
        /**
         * 获取属性值
         * @param  name  属性名称
         * @param  value  返回属性值
         * @param  type  返回属性类型
         */
        virtual void getAttribute(const String& name, String *value, String *type);
        /**
         * 获取属性名称列表
         */
        virtual ArrayList<String> getAttributeNames();
        /**
         * 添加控件方法
         */
        virtual void onLoad();
        /**
         * 文字改变方法
         */
        virtual void onTextChanged();
        /**
         * 设置属性
         * @param  name  属性名称
         * @param  value  属性值
         */
        virtual void setAttribute(const String& name, const String& value);
    };
}

#endif
