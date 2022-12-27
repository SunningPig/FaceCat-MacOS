/*
* FaceCat图形通讯框架
* 上海卷卷猫信息技术有限公司
*/

#include "stdafx.h"
#include "RibbonButton.h"
#include "FCTabView.h"
#include "FCTabPage.h"

RibbonButton::RibbonButton(){
    m_arrowType = 0;
    m_isClose = false;
    m_isTabClose = false;
    m_selected = false;
    setBackColor(FCColor_None);
    setBorderColor(FCColor_None);
}

RibbonButton::~RibbonButton(){
}

int RibbonButton::getArrowType(){
    return m_arrowType;
}

void RibbonButton::setArrowType(int arrowType){
    m_arrowType = arrowType;
}

bool RibbonButton::isClose(){
    return m_isClose;
}

void RibbonButton::setClose(bool isClose){
    m_isClose = isClose;
}

bool RibbonButton::isTabClose(){
    return m_isTabClose;
}

void RibbonButton::setTabClose(bool isTabClose){
    m_isTabClose = isTabClose;
}

bool RibbonButton::isSelected(){
    FCView *parent = getParent();
    if (parent){
        FCTabView *tabView = dynamic_cast<FCTabView*>(parent);
        if (tabView){
            FCTabPage *selectedTabPage = tabView->getSelectedTabPage();
            if (selectedTabPage){
                if (this == selectedTabPage->getHeaderButton()){
                    return true;
                }
            }
        }
        else{
            return m_selected;
        }
    }
    return false;
}

void RibbonButton::setSelected(bool selected){
    m_selected = selected;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Long RibbonButton::getPaintingTextColor(){
    if (isPaintEnabled(this)) {
        return USERCOLOR3;
    }
    else {
        return USERCOLOR17;
    }
}

void RibbonButton::onPaintBackground(FCPaint *paint, const FCRect& clipRect){
    FCNative *native = getNative();
    int width = getWidth(), height = getHeight();
    int mw = width / 2, mh = height / 2;
    FCRect drawRect = {0, 0, width, height};
    int cornerRadius = 0;
    bool isTabHeader = false;
    if (m_isClose){
        Long lineColor = USERCOLOR17;
        FCRect ellipseRect = {1, 1, width - 2, height - 2};
        //paint->fillEllipse(FCCOLORS_BACKCOLOR7, ellipseRect);
        FCDraw::drawText(paint, L"关", lineColor, getFont(), 5, 4);
    }
    else{
        cornerRadius = 4;
        if (m_arrowType > 0){
            cornerRadius = 0;
        }
        FCView *parent = getParent();
        if (parent){
            FCTabView *tabView = dynamic_cast<FCTabView*>(parent);
            if (tabView){
                cornerRadius = 0;
                isTabHeader = true;
            }
        }
        if (isTabHeader)
        {
            drawRect.top = 1;
            drawRect.bottom -= 1;
            if (isSelected())
            {
                paint->fillRect(USERCOLOR86, drawRect);
            }
            else
            {
                paint->fillRect(USERCOLOR68, drawRect);
                paint->drawLine(USERCOLOR85, 1, 0, width - 3, height / 4, width - 3, height * 3 / 4);
            }
        }else{
            //paint->fillGradientRect(FCCOLORS_BACKCOLOR, FCCOLORS_BACKCOLOR2, drawRect, cornerRadius, m_angle);
            //paint->drawRoundRect(FCColor_Border, 1, 0, drawRect, cornerRadius);
            if (m_arrowType > 0){
                FCPoint point1 = {0};
                FCPoint point2 = {0};
                FCPoint point3 = {0};
                int ts = min(mw, mh) / 2;
                switch (m_arrowType){
                    case 1:
                        point1.x = mw - ts;
                        point1.y = mh;
                        point2.x = mw + ts;
                        point2.y = mh - ts;
                        point3.x = mw + ts;
                        point3.y = mh + ts;
                        break;
                    case 2:
                        point1.x = mw + ts;
                        point1.y = mh;
                        point2.x = mw - ts;
                        point2.y = mh - ts;
                        point3.x = mw - ts;
                        point3.y = mh + ts;
                        break;
                    case 3:
                        point1.x = mw;
                        point1.y = mh - ts;
                        point2.x = mw - ts;
                        point2.y = mh + ts;
                        point3.x = mw + ts;
                        point3.y = mh + ts;
                        break;
                    case 4:
                        point1.x = mw;
                        point1.y = mh + ts;
                        point2.x = mw - ts;
                        point2.y = mh - ts;
                        point3.x = mw + ts;
                        point3.y = mh - ts;
                        break;
                }
                FCPoint points[3];
                points[0] = point1;
                points[1] = point2;
                points[2] = point3;
                paint->fillPolygon(USERCOLOR, points, 3);
            }
            bool state = false;
            if (this == native->getPushedView()){
                state = true;
                paint->fillRoundRect(USERCOLOR58, drawRect, cornerRadius);
            }
            else if (this == native->getHoveredView()){
                state = true;
                paint->fillRoundRect(USERCOLOR6, drawRect, cornerRadius);
            }
            if(state){
                if(cornerRadius > 0){
                    paint->drawRoundRect(USERCOLOR9, 1, 0, drawRect, cornerRadius);
                }
                else{
                    paint->drawRect(USERCOLOR9, 1, 0, drawRect);
                }
            }
        }
    }
}
