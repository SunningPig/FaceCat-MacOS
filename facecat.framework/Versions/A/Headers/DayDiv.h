/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifndef __DAYDIV_H__
#define __DAYDIV_H__
#pragma once
#include "stdafx.h"
#include "DayButton.h"
#include "CYears.h"
#include "CMonth.h"
#include "CDay.h"
#include "HeadDiv.h"
#include "TimeDiv.h"

namespace FaceCat{
    class DayButton;
    class HeadDiv;
    class FCCalendar;
    class TimeDiv;
    /**
     * 创建日期层
     */
    class DayDiv{
    public:
        /**
         * 点击时的上月的行
         */
        int m_am_ClickRowFrom;
        /**
         * 点击时的当月的行
         */
        int m_am_ClickRowTo;
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
    public:
        /**
         * 日期层的集合
         */
        ArrayList<DayButton*> m_dayButtons;
        /**
         * 动画日期层的集合
         */
        ArrayList<DayButton*> m_dayButtons_am;
    public:
        /*
         * 构造函数
         */
        DayDiv(FCCalendar *calendar);
        /*
         * 析构函数
         */
        virtual ~DayDiv();
        /**
         * 获取日历控件
         */
        virtual FCCalendar* getCalendar();
        /**
         * 设置日历控件
         */
        virtual void setCalendar(FCCalendar *value);
    public:
        /**
         * 隐藏
         */
        virtual void hide();
        /**
         * 触摸点击事件
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
         * 选中日期
         * @param  selectedDay  日期
         */
        virtual void selectDay(CDay *selectedDay);
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
