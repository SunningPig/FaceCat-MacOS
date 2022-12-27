/*
* FaceCat图形通讯框架
* 上海卷卷猫信息技术有限公司
*/

#ifndef __RIBBONBUTTON_H__
#define __RIBBONBUTTON_H__
#pragma once
#include "stdafx.h"
#include "FCDraw.h"
#include "FCButton.h"

//透明按钮
class RibbonButton : public FCButton{
private:
    int m_arrowType;
    bool m_isClose;
    bool m_isTabClose;
    bool m_selected;
public:
    RibbonButton();
    virtual ~RibbonButton();
    //箭头形状
    int getArrowType();
    void setArrowType(int arrowType);
    //是否关闭按钮
    bool isClose();
    void setClose(bool isClose);
    //是否多页夹的关闭按钮
    bool isTabClose();
    void setTabClose(bool isTabClose);
    //是否选中
    void setSelected(bool selected);
    bool isSelected();
public:
    //获取要绘制的前景色
    virtual Long getPaintingTextColor();
    //重绘背景色方法
    virtual void onPaintBackground(FCPaint *paint, const FCRect& clipRect);
};
#endif
