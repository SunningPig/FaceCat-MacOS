/*
* FaceCat图形通讯框架
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

/*
* 绘图方法
 */
class ContextPaint:public FCPaint{
public:
    /*
    * 裁剪区域
     */
    FCRect m_clipRect;
    /*
    * 上下文
     */
    CGContextRef m_context;
    /*
    * 线段结束样式
     */
    int m_endLineCap;
    /*
    * 图片
     */
    std::map<String, NSImage*> m_images;
    /*
    * 是否裁剪
     */
    bool m_isClip;
    /*
    * 是否路径开始
     */
    bool m_isPathStart;
    /*
    * 我的颜色
     */
    MyColor *m_myColor;
    /*
    * 横向偏移距离
     */
    int m_offsetX;
    /*
    * 纵向偏移距离
     */
    int m_offsetY;
    /*
    * 透明度
     */
    float m_opacity;
    /*
    * 路径
     */
    CGMutablePathRef m_path;
    /*
    * 绘制区域
     */
    FCRect m_pRect;
    /*
    * 资源路径
     */
    String m_resourcePath;
    /*
    * 旋转角度
     */
    int m_rotateAngle;
    /*
    * 横向缩放
     */
    double m_scaleFactorX;
    /*
    * 纵向缩放
     */
    double m_scaleFactorY;
    /*
    * 是否路径结束
     */
    int m_startLineCap;
    /*
    * 文字质量
     */
    int m_textQuality;
    /*
    * 高度
     */
    int m_wHeight;
    /*
    * 画布大小
     */
    FCRect m_wRect;
    /**
     * 自动缩放矩形
     *
     * @param andriodRect 矩形
     */
    void affectScaleFactor(FCRect *rect);
    /**
     * 创建圆形的矩形路径
     */
    CGPathRef cQMPathCreateRoundingRect(CGRect rect, CGFloat blRadius, CGFloat brRadius, CGFloat trRadius, CGFloat tlRadius);
    /**
     * 获取颜色
     *
     * @param dwPenColor 颜色
     * @return 系统颜色
     */
    NSColor* getUIColor(Long dwPenColor);
    /**
     * 获取字体
     *
     * @param font 字体
     * @return 系统字体
     */
    NSFont* getUIFont(FCFont *font);
public:
    /**
     * 获取系统坐标
     *
     * @param point 坐标点
     * @return 系统坐标
     */
    static CGPoint getCGPoint(const FCPoint& point);
    /**
     * 获取系统矩形
     *
     * @param rect 矩形
     * @return 系统矩形
     */
    static CGRect getCGRect(const FCRect& rect);
    /**
     * 获取系统矩形
     *
     * @param rect 矩形
     * @return 系统矩形
     */
    static CGRect getCGRect(const FCRectF& rect);
    /**
     * 获取系统大小
     *
     * @param size 大小
     * @return 系统大小
     */
    static CGSize getCGSize(const FCSize& size);
    /**
     * 获取系统字符串
     *
     * @param str 字符串
     * @return 系统字符串
     */
    static NSString* getNSString(const wchar_t *str);
    /**
     * 获取坐标
     *
     * @param cgPoint 系统坐标
     * @return 坐标
     */
    static FCPoint getPoint(CGPoint cgPoint);
    /**
     * 获取矩形
     *
     * @param cgRect 系统矩形
     * @return 矩形
     */
    static FCRect getRect(CGRect cgRect);
    /**
     * 获取大小
     *
     * @param cgRect 系统大小
     * @return 大小
     */
    static FCSize getSize(CGSize cgSize);
public:
    /**
     * 构造函数
     */
    ContextPaint();
    /**
     * 析构函数
     */
    virtual ~ContextPaint();
public:
    /**
     * 添加曲线
     *
     * @param rect 矩形区域
     * @param startAngle 从 x 轴到弧线的起始点沿顺时针方向度量的角（以度为单位）
     * @param sweepAngle 从 startAngle 参数到弧线的结束点沿顺时针方向度量的角（以度为单位）
     */
    virtual void addArc(const FCRect& rect, float startAngle, float sweepAngle);
    /**
     * 添加贝赛尔曲线
     *
     * @param points 坐标数组
     */
    virtual void addBezier(FCPoint *apt, int cpt);
    /**
     * 添加曲线
     *
     * @param points 点阵
     */
    virtual void addCurve(FCPoint *apt, int cpt);
    /**
     * 添加椭圆
     *
     * @param rect 矩形
     */
    virtual void addEllipse(const FCRect& rect);
    /**
     * 添加直线
     *
     * @param x1 第一个点的横坐标
     * @param y1 第一个点的纵坐标
     * @param x2 第二个点的横坐标
     * @param y2 第二个点的纵坐标
     */
    virtual void addLine(int x1, int y1, int x2, int y2);
    /**
     * 添加矩形
     *
     * @param rect 区域
     */
    virtual void addRect(const FCRect& rect);
    /**
     * 添加扇形
     *
     * @param rect 矩形区域
     * @param startAngle 从 x 轴到弧线的起始点沿顺时针方向度量的角（以度为单位）
     * @param sweepAngle 从 startAngle 参数到弧线的结束点沿顺时针方向度量的角（以度为单位）
     */
    virtual void addPie(const FCRect& rect, float startAngle, float sweepAngle);
    /**
     * 添加文字
     *
     * @param text 文字
     * @param font 字体
     * @param rect 区域
     */
    virtual void addText(String strText, FCFont *font, const FCRect& rect, int width);
    /**
     * 开始导出
     *
     * @param exportPath 路径
     * @param rect 矩形
     */
    virtual void beginExport(const String& exportPath, const FCRect& rect);
    /**
     * 开始绘图
     *
     * @param hdc HDC
     * @param wRect 窗体区域
     * @param pRect 刷新区域
     */
    virtual void beginPaint(int hDC, const FCRect& wRect, const FCRect& pRect);
    /**
     * 开始一段路径
     */
    virtual void beginPath();
    /**
     * 清除缓存
     */
    virtual void clearCaches();
    /**
     * 裁剪路径
     */
    virtual void clipPath();
    /**
     * 闭合路径
     */
    virtual void closeFigure();
    /**
     * 结束一段路径
     */
    virtual void closePath();
    /**
     * 绘制弧线
     *
     * @param dwPenColor 颜色
     * @param width 宽度
     * @param style 样式
     * @param rect 矩形区域
     * @param startAngle 从 x 轴到弧线的起始点沿顺时针方向度量的角（以度为单位）
     * @param sweepAngle 从 startAngle 参数到弧线的结束点沿顺时针方向度量的角（以度为单位）
     */
    virtual void drawArc(Long dwPenColor, float width, int style, const FCRect& rect, float startAngle, float sweepAngle);
    /**
     * 绘制贝赛尔曲线
     *
     * @param dwPenColor 颜色
     * @param width 宽度
     * @param style 样式
     * @param points 坐标阵
     */
    virtual void drawBezier(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
    /**
     * 绘制曲线
     *
     * @param dwPenColor 颜色
     * @param width 宽度
     * @param style 样式
     * @param points 坐标阵
     */
    virtual void drawCurve(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
    /**
     * 绘制椭圆
     *
     * @param dwPenColor 颜色
     * @param width 宽度
     * @param style 样式
     * @param rect 矩形区域
     */
    virtual void drawEllipse(Long dwPenColor, float width, int style, const FCRect& rect);
    /**
     * 绘制椭圆
     *
     * @param dwPenColor 颜色
     * @param width 宽度
     * @param style 样式
     * @param left 左侧坐标
     * @param top 顶部左标
     * @param right 右侧坐标
     * @param bottom 底部坐标
     */
    virtual void drawEllipse(Long dwPenColor, float width, int style, int left, int top, int right, int bottom);
    /**
     * 绘制图片
     *
     * @param imagePath 图片路径
     * @param rect 绘制区域
     */
    virtual void drawImage(String imagePath, const FCRect& rect);
    /**
     * 绘制直线
     *
     * @param dwPenColor 颜色
     * @param width 宽度
     * @param style 样式
     * @param x1 第一个点的横坐标
     * @param y1 第一个点的纵坐标
     * @param x2 第二个点的横坐标
     * @param y2 第二个点的纵坐标
     */
    virtual void drawLine(Long dwPenColor, float width, int style, const FCPoint& x, const FCPoint& y);
    /**
     * 绘制直线
     *
     * @param dwPenColor 颜色
     * @param width 宽度
     * @param style 样式
     * @param x 第一个点坐标
     * @param y 第二个点的坐标
     */
    virtual void drawLine(Long dwPenColor, float width, int style, int x1, int y1, int x2, int y2);
    /**
     * 绘制路径
     *
     * @param dwPenColor 颜色
     * @param width 宽度
     * @param style 样式
     */
    virtual void drawPath(Long dwPenColor, float width, int style);
    /**
     * 绘制弧线
     *
     * @param dwPenColor 颜色
     * @param width 宽度
     * @param style 样式
     * @param rect 矩形区域
     * @param startAngle 从 x 轴到弧线的起始点沿顺时针方向度量的角（以度为单位）
     * @param sweepAngle 从 startAngle 参数到弧线的结束点沿顺时针方向度量的角（以度为单位）
     */
    virtual void drawPie(Long dwPenColor, float width, int style, const FCRect& rect, float startAngle, float sweepAngle);
    /**
     * 绘制多边形
     *
     * @param dwPenColor 颜色
     * @param width 宽度
     * @param style 样式
     * @param points 点的数组
     */
    virtual void drawPolygon(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
    /**
     * 绘制多边形
     *
     * @param dwPenColor 颜色
     * @param width 宽度
     * @param style 样式
     * @param points 点的数组
     */
    virtual void drawPolyline(Long dwPenColor, float width, int style, FCPoint *apt, int cpt);
    /**
     * 绘制矩形
     *
     * @param dwPenColor 颜色
     * @param width 宽度
     * @param style 样式
     * @param rect 矩形区域
     */
    virtual void drawRect(Long dwPenColor, float width, int style, int left, int top, int right, int bottom);
    /**
     * 绘制矩形
     *
     * @param dwPenColor 颜色
     * @param width 宽度
     * @param style 样式
     * @param left 左侧坐标
     * @param top 顶部左标
     * @param right 右侧坐标
     * @param bottom 底部坐标
     */
    virtual void drawRect(Long dwPenColor, float width, int style, const FCRect& rect);
    /**
     * 绘制圆角矩形
     *
     * @param dwPenColor 颜色
     * @param width 宽度
     * @param style 样式
     * @param rect 矩形区域
     * @param cornerRadius 边角半径
     */
    virtual void drawRoundRect(Long dwPenColor, float width, int style, const FCRect& rect, int cornerRadius);
    /**
     * 绘制文字
     *
     * @param text 文字
     * @param dwPenColor 颜色
     * @param font 字体
     * @param rect 矩形区域
     */
    virtual void drawText(String strText, Long dwPenColor, FCFont *font, const FCRect& rect, int width);
    /**
     * 绘制文字
     *
     * @param text 文字
     * @param dwPenColor 颜色
     * @param font 字体
     * @param rect 矩形区域
     */
    virtual void drawText(String strText, Long dwPenColor, FCFont *font, const FCRectF& rect, int width);
    /**
     * 绘制自动省略结尾的文字
     *
     * @param text 文字
     * @param dwPenColor 颜色
     * @param font 字体
     * @param rect 矩形区域
     */
    virtual void drawTextAutoEllipsis(String strText, Long dwPenColor, FCFont *font, const FCRect& rect);
    /**
     * 结束导出
     */
    virtual void endExport();
    /**
     * 结束绘图
     */
    virtual void endPaint();
    /**
     * 反裁剪区域
     */
    virtual void excludeClipPath();
    /**
     * 填充椭圆
     *
     * @param dwPenColor 颜色
     * @param rect 矩形区域
     */
    virtual void fillEllipse(Long dwPenColor, const FCRect& rect);
    /**
     * 绘制渐变椭圆
     *
     * @param dwFirst 开始颜色
     * @param dwSecond 结束颜色
     * @param rect 矩形
     * @param angle 角度
     */
    virtual void fillGradientEllipse(Long dwFirst, Long dwSecond, const FCRect& rect, int angle);
    /**
     * 填充渐变路径
     *
     * @param dwFirst 开始颜色
     * @param dwSecond 结束颜色
     * @param points 点的集合
     * @param angle 角度
     */
    virtual void fillGradientPath(Long dwFirst, Long dwSecond, const FCRect& rect, int angle);
    /**
     * 绘制渐变的多边形
     *
     * @param dwFirst 开始颜色
     * @param dwSecond 结束颜色
     * @param points 点的集合
     * @param angle 角度
     */
    virtual void fillGradientPolygon(Long dwFirst, Long dwSecond, FCPoint *apt, int cpt, int angle);
    /**
     * 绘制渐变矩形
     *
     * @param dwFirst 开始颜色
     * @param dwSecond 结束颜色
     * @param rect 矩形
     * @param cornerRadius 圆角半径
     * @param angle 角度
     */
    virtual void fillGradientRect(Long dwFirst, Long dwSecond, const FCRect& rect, int cornerRadius, int angle);
    /**
     * 填充路径
     *
     * @param dwPenColor 颜色
     */
    virtual void fillPath(Long dwPenColor);
    /**
     * 绘制扇形
     *
     * @param dwPenColor 颜色
     * @param rect 矩形区域
     * @param startAngle 从 x 轴到弧线的起始点沿顺时针方向度量的角（以度为单位）
     * @param sweepAngle 从 startAngle 参数到弧线的结束点沿顺时针方向度量的角（以度为单位）
     */
    virtual void fillPie(Long dwPenColor, const FCRect& rect, float startAngle, float sweepAngle);
    /**
     * 填充多边形
     *
     * @param dwPenColor 颜色
     * @param points 点的数组
     */
    virtual void fillPolygon(Long dwPenColor, FCPoint *apt, int cpt);
    /**
     * 填充矩形
     *
     * @param dwPenColor 颜色
     * @param rect 矩形区域
     */
    virtual void fillRect(Long dwPenColor, const FCRect& rect);
    /**
     * 填充矩形
     *
     * @param dwPenColor 颜色
     * @param left 左侧坐标
     * @param top 顶部左标
     * @param right 右侧坐标
     * @param bottom 底部坐标
     */
    virtual void fillRect(Long dwPenColor, int left, int top, int right, int bottom);
    /**
     * 填充圆角矩形
     *
     * @param dwPenColor 颜色
     * @param rect 矩形区域
     * @param cornerRadius 边角半径
     */
    virtual void fillRoundRect(Long dwPenColor, const FCRect& rect, int cornerRadius);
    /**
     * 获取颜色
     *
     * @param dwPenColor 输入颜色
     * @returns 输出颜色
     */
    virtual Long getColor(Long dwPenColor);
    /**
     * 获取要绘制的颜色
     *
     * @param dwPenColor 输入颜色
     * @returns 输出颜色
     */
    virtual Long getPaintColor(Long dwPenColor);
    /**
     * 获取偏移
     *
     * @return 偏移坐标
     */
    virtual FCPoint getOffset();
    /**
     * 获取要绘制的颜色
     *
     * @param scaleFactorX 横向缩放比例
     * @param scaleFactorY 纵向缩放比例
     */
    virtual void getScaleFactor(double *scaleFactorX, double *scaleFactorY);
    /**
     * 旋转角度
     *
     * @param op    圆心坐标
     * @param mp    点的坐标
     * @param angle 角度
     * @return 结果坐标
     */
    virtual FCPoint rotate(const FCPoint& op, const FCPoint& mp, int angle);
    /**
     * 设置裁剪区域
     *
     * @param rect 矩形区域
     */
    virtual void setClip(const FCRect& rect);
    /*
     * 设置直线两端的样式
     * @param lineCap 样式
     */
    virtual void setLineCap(int startLineCap, int endLineCap);
    /**
     * 设置偏移
     *
     * @param mp 偏移坐标
     */
    virtual void setOffset(const FCPoint& offset);
    /**
     * 设置透明度
     *
     * @param opacity 透明度
     */
    virtual void setOpacity(float opacity);
    /**
     * 设置资源的路径
     *
     * @param resourcePath 资源的路径
     */
    virtual void setResourcePath(const String& resourcePath);
    /**
     * 设置旋转角度
     *
     * @param rotateAngle 旋转角度
     */
    virtual void setRotateAngle(int rotateAngle);
    /**
     * 设置缩放因子
     *
     * @param scaleFactorX 横向因子
     * @param scaleFactorY 纵向因子
     */
    virtual void setScaleFactor(double scaleFactorX, double scaleFactorY);
    /**
     * 设置是否支持透明
     * * @return 是否支持
     */
    virtual bool supportTransparent();
    /**
     * 获取文字大小
     *
     * @param text 文字
     * @param font 字体
     * @return 字体大小
     */
    virtual FCSize textSize(String strText, FCFont *font, int width);
    /**
     * 获取文字大小
     *
     * @param text 文字
     * @param font 字体
     * @return 字体大小
     */
    virtual FCSizeF textSizeF(String strText, FCFont *font, int width);
    /**
     * 获取去除颜色后的图片
     */
    static NSImage* removeColorWithMaxR(float maxR, float minR, float maxG, float minG, float maxB, float minB, NSImage *image);
    /**
     * 设置角度
     *
     * @param angle 角度
     */
    static void setAngle(int angle);
};

#endif
