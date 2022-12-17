/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifndef __FCHSCROLLBAR_H__
#define __FCHSCROLLBAR_H__
#pragma once
#include "stdafx.h"
#include "FCScrollBar.h"

/*
 * 横向滚动条
 */
namespace FaceCat{
    class FCHScrollBar:public FCScrollBar{
    public:
        /*
         * 构造函数
         */
        FCHScrollBar();
        /*
         * 析构函数
         */
        virtual ~FCHScrollBar();
        /*
        * 触摸事件
        */
        virtual void callTouchEvent(String eventName, Object sender, FCTouchInfo touchInfo, Object invoke);
        /**
         * 获取控件类型
         */
        virtual String getViewType();
        /**
         * 滚动条背景按钮触摸按下回调方法
         */
        void onBackButtonTouchDown(FCTouchInfo touchInfo);
        /**
         * 滚动条背景按钮触摸抬起方法
         */
        void onBackButtonTouchUp(FCTouchInfo touchInfo);
        /**
         * 拖动滚动方法
         */
        virtual void onDragScroll();
        /**
         * 添加控件方法
         */
        virtual void onLoad();
        /**
         * 重新布局方法
         */
        virtual void update();
    };
}

#endif
