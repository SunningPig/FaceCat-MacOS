/*
* FaceCat图形通讯框架(非开源)
* 著作权编号:2015SR229355+2020SR0266727
* 上海卷卷猫信息技术有限公司
*/

#ifndef __CONTEXTPAINT_H__
#define __CONTEXTPAINT_H__
#pragma once
#include "stdafx.h"
#include "FCPaint.h"
#include "FCTran.h"
#include "FCDraw.h"
using namespace FaceCat;

class ContextPaint:public FCPaint{
public:
    FCRect m_clipRect;
    CGContextRef m_context;
    int m_endLineCap;
    map<String, NSImage*> m_images;
    bool m_isClip;
    bool m_isPathStart;
    MyColor *m_myColor;
    int m_offsetX;
    int m_offsetY;
    float m_opacity;
    CGMutablePathRef m_path;
    FCRect m_pRect;
    String m_resourcePath;
    int m_rotateAngle;
    double m_scaleFactorX;
    double m_scaleFactorY;
    int m_startLineCap;
    int m_textQuality;
    int m_wHeight;
    FCRect m_wRect;
    void affectScaleFactor(FCRect *rect);
    CGPathRef cQMPathCreateRoundingRect(CGRect rect, CGFloat blRadius, CGFloat brRadius, CGFloat trRadius, CGFloat tlRadius);
    NSColor* getUIColor(Long dwPenColor);
    NSFont* getUIFont(FCFont *font);
public:
    static CGPoint getCGPoint(const FCPoint& point);
    static CGRect getCGRect(const FCRect& rect);
    static CGRect getCGRect(const FCRectF& rect);
    static CGSize getCGSize(const FCSize& size);
    static NSString* getNSString(const wchar_t *str);
    static FCPoint getPoint(CGPoint cgPoint);
    static FCRect getRect(CGRect cgRect);
    static FCSize getSize(CGSize cgSize);
public:
    ContextPaint();
    virtual ~ContextPaint();
public:
    virtual void addArc(const FCRect& rect, float startAngle, float sweepAngle);
    virtual void addBezier(FCPoint *apt, int cpt);
    virtual void addCurve(FCPoint *apt, int cpt);
    virtual void addEllipse(const FCRect& rect);
    virtual void addLine(int x1, int y1, int x2, int y2);
    virtual void addRect(const FCRect& rect);
    virtual void addPie(const FCRect& rect, float startAngle, float sweepAngle);
    virtual void addText(String strText, FCFont *font, const FCRect& rect, int width);
    virtual void beginExport(const String& exportPath, const FCRect& rect);
    virtual void beginPaint(int hDC, const FCRect& wRect, const FCRect& pRect);
    virtual void beginPath();
    virtual void clearCaches();
    virtual void clipPath();
    virtual void closeFigure();
    virtual void closePath();
    virtual void drawArc(Long dwPenColor, float width, int style, const FCRect& rect, float startAngle, float sweepAngle);
    virtual void drawBezier(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
    virtual void drawCurve(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
    virtual void drawEllipse(Long dwPenColor, float width, int style, const FCRect& rect);
    virtual void drawEllipse(Long dwPenColor, float width, int style, int left, int top, int right, int bottom);
    virtual void drawImage(String imagePath, const FCRect& rect);
    virtual void drawLine(Long dwPenColor, float width, int style, const FCPoint& x, const FCPoint& y);
    virtual void drawLine(Long dwPenColor, float width, int style, int x1, int y1, int x2, int y2);
    virtual void drawPath(Long dwPenColor, float width, int style);
    virtual void drawPie(Long dwPenColor, float width, int style, const FCRect& rect, float startAngle, float sweepAngle);
    virtual void drawPolygon(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
    virtual void drawPolyline(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
    virtual void drawRect(Long dwPenColor, float width, int style, int left, int top, int right, int bottom);
    virtual void drawRect(Long dwPenColor, float width, int style, const FCRect& rect);
    virtual void drawRoundRect(Long dwPenColor, float width, int style, const FCRect& rect, int cornerRadius);
    virtual void drawText(String strText, Long dwPenColor, FCFont *font, const FCRect& rect, int width);
    virtual void drawText(String strText, Long dwPenColor, FCFont *font, const FCRectF& rect, int width);
    virtual void drawTextAutoEllipsis(String strText, Long dwPenColor, FCFont *font, const FCRect& rect);
    virtual void endExport();
    virtual void endPaint();
    virtual void excludeClipPath();
    virtual void fillEllipse(Long dwPenColor, const FCRect& rect);
    virtual void fillGradientEllipse(Long dwFirst, Long dwSecond, const FCRect& rect, int angle);
    virtual void fillGradientPath(Long dwFirst, Long dwSecond, const FCRect& rect, int angle);
    virtual void fillGradientPolygon(Long dwFirst, Long dwSecond, FCPoint *apt, int cpt, int angle);
    virtual void fillGradientRect(Long dwFirst, Long dwSecond, const FCRect& rect, int cornerRadius, int angle);
    virtual void fillPath(Long dwPenColor);
    virtual void fillPie(Long dwPenColor, const FCRect& rect, float startAngle, float sweepAngle);
    virtual void fillPolygon(Long dwPenColor, FCPoint *apt, int cpt);
    virtual void fillRect(Long dwPenColor, const FCRect& rect);
    virtual void fillRect(Long dwPenColor, int left, int top, int right, int bottom);
    virtual void fillRoundRect(Long dwPenColor, const FCRect& rect, int cornerRadius);
    virtual Long getColor(Long dwPenColor);
    virtual Long getPaintColor(Long dwPenColor);
    virtual FCPoint getOffset();
    virtual void getScaleFactor(double *scaleFactorX, double *scaleFactorY);
    virtual FCPoint rotate(const FCPoint& op, const FCPoint& mp, int angle);
    virtual void setClip(const FCRect& rect);
    virtual void setLineCap(int startLineCap, int endLineCap);
    virtual void setOffset(const FCPoint& offset);
    virtual void setOpacity(float opacity);
    virtual void setResourcePath(const String& resourcePath);
    virtual void setRotateAngle(int rotateAngle);
    virtual void setScaleFactor(double scaleFactorX, double scaleFactorY);
    virtual bool supportTransparent();
    virtual FCSize textSize(String strText, FCFont *font, int width);
    virtual FCSizeF textSizeF(String strText, FCFont *font, int width);
    static NSImage* removeColorWithMaxR(float maxR, float minR, float maxG, float minG, float maxB, float minB, NSImage *image);
    static void setAngle(int angle);
};

#endif
