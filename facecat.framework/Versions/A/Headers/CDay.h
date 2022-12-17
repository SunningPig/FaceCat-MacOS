/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifndef __CDAY_H__
#define __CDAY_H__
#pragma once
#include "stdafx.h"

namespace FaceCat{
    /**
     * 创建日
     */
    class CDay{
    public:
        int m_day;
        int m_month;
        int m_year;
    public:
        /*
         * 构造函数
         */
        CDay(int year, int month, int day);
        /*
         * 析构函数
         */
        virtual ~CDay();
        /**
         * 获取日
         */
        int getDay();
        /**
         * 获取月
         */
        int getMonth();
        /**
         * 获取年
         */
        int getYear();
    };
}
#endif
