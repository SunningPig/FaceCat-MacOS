/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifndef __FCGROUPBOX_H__
#define __FCGROUPBOX_H__
#pragma once
#include "stdafx.h"
#include "FCDiv.h"

namespace FaceCat{
    /**
     * 组控件
     */
    class FCGroupBox : public FCDiv{
    public:
        /**
         * 创建层控件
         */
        FCGroupBox();
        virtual ~FCGroupBox();
    public:
        /**
         * 获取控件类型
         */
        virtual String getViewType();
        /**
         * 重绘边线方法
         * @param  paint   绘图对象
         * @param  clipRect   裁剪区域
         */
        virtual void onPaintBorder(FCPaint *paint, const FCRect& clipRect);
        /**
         * 重绘前景方法
         * @param  paint   绘图对象
         * @param  clipRect   裁剪区域
         */
        virtual void onPaintForeground(FCPaint *paint, const FCRect& clipRect);
    };
}
#endif
