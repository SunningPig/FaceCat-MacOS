/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifndef __YEARDIV_H__
#define __YEARDIV_H__
#pragma once
#include "stdafx.h"
#include "YearButton.h"
#include "HeadDiv.h"
#include "TimeDiv.h"

namespace FaceCat{
    class FCCalendar;
    class HeadDiv;
    class YearButton;
    class TimeDiv;
    
    /*
     * 年的层
     */
    class YearDiv{
    public:
        /**
         * 动画的方向
         */
        int m_am_Direction;
        /**
         * 动画当前帧数
         */
        int m_am_Tick;
        /**
         * 动画总帧数
         */
        int m_am_TotalTick;
        /**
         * 日历控件
         */
        FCCalendar *m_calendar;
        /**
         * 开始年份
         */
        int m_startYear;
    public:
        /**
         * 月的按钮
         */
        ArrayList<YearButton*> m_yearButtons;
        /**
         * 月的动画按钮
         */
        ArrayList<YearButton*> m_yearButtons_am;
    public:
        /*
         * 构造函数
         */
        YearDiv(FCCalendar *calendar);
        /*
         * 析构函数
         */
        virtual ~YearDiv();
        /**
         * 获取日历控件
         */
        virtual FCCalendar* getCalendar();
        /**
         * 设置日历控件
         */
        virtual void setCalendar(FCCalendar *value);
        /**
         * 获取开始年份
         */
        virtual int getStartYear();
    public:
        /**
         * 隐藏
         */
        virtual void hide();
        /**
         * 触摸点击方法
         * @param  touchInfo   触摸信息
         */
        virtual void onClick(FCTouchInfo touchInfo);
        /**
         * 添加控件方法
         */
        virtual void onLoad();
        /**
         * 重绘方法
         * @param  paint   绘图对象
         * @param  clipRect   裁剪区域
         */
        virtual void onPaint(FCPaint *paint, const FCRect& clipRect);
        /**
         * 重置日期图层
         * @param  state  状态
         */
        virtual void onResetDiv(int state);
        /**
         * 秒表触发方法
         */
        virtual void onTimer();
        /**
         * 选择开始年份
         * @param  startYear  开始年份
         */
        virtual void selectStartYear(int startYear);
        /**
         * 显示
         */
        virtual void show();
        /**
         * 更新布局方法
         */
        virtual void update();
    };
}
#endif
