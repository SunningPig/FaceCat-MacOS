/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifndef __FCTABVIEW_H__
#define __FCTABVIEW_H__
#pragma once
#include "stdafx.h"
#include "FCTran.h"
#include "FCDiv.h"
#include "FCTabPage.h"

namespace FaceCat{
    /**
     * 页的布局位置
     */
    enum FCTabPageLayout{
        /**
         * 下方
         */
        FCTabPageLayout_Bottom,
        /**
         * 左侧
         */
        FCTabPageLayout_Left,
        /**
         * 右侧
         */
        FCTabPageLayout_Right,
        /**
         * 顶部
         */
        FCTabPageLayout_Top
    };
    
    class FCTabPage;
    
    /*
     * 多页夹控件
     */
    class FCTabView:public FCDiv{
    private:
        /**
         * 秒表ID
         */
        int m_timerID;
    public:
        /**
         * 动画状态
         */
        int m_animationState;
        /**
         * 页的布局位置
         */
        FCTabPageLayout m_layout;
        /**
         * 选中的索引
         */
        int m_selectedIndex;
        /**
         * 是否使用动画
         */
        bool m_useAnimation;
        /**
         * 绘制移动
         */
        void drawMoving();
        /*
         * 获取索引
         */
        int getTabPageIndex(FCTabPage *tabPage);
    public:
        /**
         * 所有页
         */
        ArrayList<FCTabPage*> m_tabPages;
        /*
         * 创建多页夹
         */
        FCTabView();
        /*
         * 删除多页夹
         */
        virtual ~FCTabView();
        /**
         * 获取页的布局位置
         */
        virtual FCTabPageLayout getLayout();
        /**
         * 设置页的布局位置
         */
        virtual void setLayout(FCTabPageLayout value);
        /**
         * 获取选中的索引
         */
        virtual int getSelectedIndex();
        /**
         * 设置选中的索引
         */
        virtual void setSelectedIndex(int value);
        /**
         * 获取选中的页
         */
        virtual FCTabPage* getSelectedTabPage();
        /**
         * 设置选中的页
         */
        virtual void setSelectedTabPage(FCTabPage *value);
        /**
         * 获取是否使用动画
         */
        virtual bool useAnimation();
        /**
         * 设置是否使用动画
         */
        virtual void setUseAnimation(bool value);
    public:
        /**
         * 添加控件方法
         */
        virtual void addView(FCView *view);
        /**
         * 获取控件类型
         */
        virtual String getViewType();
        /**
         * 清除控件
         */
        virtual void clearViews();
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
         * 获取方法列表
         */
        virtual ArrayList<String> getEventNames();
        /**
         * 插入控件
         * @param  index  索引
         * @param  view  控件
         */
        virtual void insertView(int index, FCView *view);
        /**
         * 开始拖动页头
         */
        virtual void onDragTabHeaderBegin(FCTabPage *tabPage);
        /**
         * 结束拖动页头
         */
        virtual void onDragTabHeaderEnd(FCTabPage *tabPage);
        /**
         * 页头拖动中
         */
        virtual void onDraggingTabHeader(FCTabPage *tabPage);
        /**
         * 添加控件方法
         */
        virtual void onLoad();
        /**
         * 页改变方法
         */
        virtual void onSelectedTabPageChanged();
        /**
         * 秒表方法
         */
        virtual void onTimer(int timerID);
        /**
         * 移除控件
         */
        virtual void removeView(FCView *view);
        /**
         * 设置属性
         * @param  name  属性名称
         * @param  value  属性值
         */
        virtual void setAttribute(const String& name, const String& value);
        /**
         * 重新布局
         */
        virtual void update();
    };
}

#endif
