/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifndef __PEXTEND_H__
#define __PEXTEND_H__
#pragma once
#include "stdafx.h"
#include "FCPlot.h"
#include "FCPlot.h"

namespace FaceCat{
    class FCPlot;
    

    /**
    * 安德鲁斯干草叉
    */
    class AndrewSpitchfork : public FCPlot{
    public:
        /**
         * 安德鲁斯干草叉
         */
        AndrewSpitchfork();
        /**
         * 获取动作类型
         */
        virtual ActionType getAction();
        /**
         * 初始化线条
         */
        virtual bool onCreate(const FCPoint& mp);
        /**
         * 开始移动画线工具
         */
        virtual void onMoveStart();
        /**
         * 绘制图像的方法
         */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 角度线
    */
    class AngleLine : public FCPlot{
    public:
        /**
         * 创建角度线
         */
        AngleLine();
        /**
         * 获取动作类型
         */
        virtual ActionType getAction();
        /**
         * 初始化线条
         */
        virtual bool onCreate(const FCPoint& mp);
        /**
         * 开始移动画线工具
         */
        virtual void onMoveStart();
        /**
         * 绘制图像的方法
         */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 外接圆
    */
    class CircumCircle : public FCPlot{
    public:
        /**
         * 外接圆
         */
        CircumCircle();
        /**
         * 获取动作类型
         */
        virtual ActionType getAction();
        /**
         * 初始化线条
         */
        virtual bool onCreate(const FCPoint& mp);
        /**
         * 开始移动画线工具
         */
        virtual void onMoveStart();
        /**
         * 绘制图像的方法
         */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 箭头线段
    */
    class ArrowSegment : public FCPlot{
    public:
        /**
         * 创建箭头线段
         */
        ArrowSegment();
        /**
         * 获取动作类型
         */
        virtual ActionType getAction();
        /**
         * 初始化线条
         */
        virtual bool onCreate(const FCPoint& mp);
        /**
         * 开始移动画线工具
         */
        virtual void onMoveStart();
        /**
         * 绘制图像的方法
         */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };

    /**
    * 下跌箭头
    */
    class DownArrow : public FCPlot{
    public:
        FCRect getDownArrowRect(float x, float y, float width);
    public:
        /**
         * 创建下跌箭头
         */
        DownArrow();
        /**
         * 获取动作类型
         */
        virtual ActionType getAction();
        /**
         * 初始化线条
         */
        virtual bool onCreate(const FCPoint& mp);
        /**
         * 开始移动画线工具
         */
        virtual void onMoveStart();
        /**
         * 绘制图像的方法
         */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };

    /**
    * 下降45度线
    */
    class DropLine:public FCPlot{
    public:
        /**
         *获取参数
         */
        float* getDropLineParams(HashMap<int, PlotMark*> *pList);
    public:
        /**
         * 创建下降45度线
         */
        DropLine();
        /**
         * 获取动作类型
         */
        virtual ActionType getAction();
        /**
         * 初始化线条
         */
        virtual bool onCreate(const FCPoint& mp);
        /**
         * 开始移动画线工具
         */
        virtual void onMoveStart();
        /**
         * 绘制图像的方法
         */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 椭圆
    */
    class Ellipse:public FCPlot{
    public:
        /**
         * 椭圆
         */
        Ellipse();
        /**
         * 获取动作类型
         */
        virtual ActionType getAction();
        /**
         * 初始化线条
         */
        virtual bool onCreate(const FCPoint& mp);
        /**
         * 开始移动画线工具
         */
        virtual void onMoveStart();
        /**
         * 绘制图像的方法
         */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
     * 斐波圆
     */
    class FiboEllipse:public FCPlot{
    public:
        ArrayList<float> m_values;
    public:
        /**
         * 斐波圆的参数
         */
        float* fibonacciEllipseParam(HashMap<Integer, PlotMark*> *pList, int *length);
    public:
        /**
         * 创建斐波圆
         */
        FiboEllipse();
        /**
         * 获取动作类型
         */
        virtual ActionType getAction();
        /**
         * 初始化图形
         */
        virtual bool onCreate(const FCPoint& mp);
        /**
         * 开始移动画线工具
         */
        virtual void onMoveStart();
        /**
         * 绘制图像的残影
         */
        virtual void onPaintGhost(FCPaint *paint);
        /**
         * 绘制图像的方法
         */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };

    
    /**
    * 斐波扇面
    */
    class FiboFanline:public FCPlot{
    public:
        /**
         * 斐波扇面
         */
        FiboFanline();
        /**
         * 获取动作类型
         */
        virtual ActionType getAction();
        /**
         * 初始化线条
         */
        virtual bool onCreate(const FCPoint& mp);
        /**
         * 开始移动画线工具
         */
        virtual void onMoveStart();
        /**
         * 绘制图像的残影
         */
        virtual void onPaintGhost(FCPaint *paint);
        /**
         * 绘制图像的方法
         */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 斐波周期线
    */
    class FiboTimeZone:public FCPlot{
    public:
        /**
         * 获取斐波周期线的参数
         */
        ArrayList<Integer> getFibonacciTimeZonesParam(HashMap<Integer,PlotMark*> *pList);
    public:
        /**
         * 创建斐波周期线
         */
        FiboTimeZone();
        /**
         * 获取动作类型
         */
        virtual ActionType getAction();
        /**
         * 初始化线条
         */
        virtual bool onCreate(const FCPoint& mp);
        /**
         * 开始移动画线工具
         */
        virtual void onMoveStart();
        /**
         * 绘制图像的方法
         */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 甘氏箱
    */
    class GannBox:public FCPlot{
    public:
        FCPoint m_oppositePoint;
    public:
        /**
         * 甘氏箱
         */
        GannBox();
        /**
         * 获取动作类型
         */
        virtual ActionType getAction();
        /**
         * 获取选中状态
         */
        ActionType getClickStatus();
        /**
         * 获取江恩箱的重要点
         */
        FCPoint* getGannBoxPoints(float x1, float y1, float x2, float y2);
        /**
         * 初始化线条
         */
        virtual bool onCreate(const FCPoint& mp);
        /**
         * 开始移动画线工具
         */
        virtual void onMoveStart();
        /**
         * 移动线条
         */
        virtual void onMoving();
        /**
         * 绘制图像的残影
         */
        virtual void onPaintGhost(FCPaint *paint);
        /**
         * 绘制图像的方法
         */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 甘氏线
    */
    class GannLine:public FCPlot{
    public:
        /**
         * 创建甘氏线
         */
        GannLine();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 绘制图像的残影
        */
        virtual void onPaintGhost(FCPaint *paint);
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
     * 黄金分割线
     */
    class GoldenRatio : public FCPlot{
    public:
        ArrayList<float> m_values;
    public:
        /**
         * 黄金分割线
         */
        GoldenRatio();
        /**
         * 获取动作类型
         */
        virtual ActionType getAction();
        /**
        * 获取黄金分割线的直线参数
        */
        float* goldenRatioParams(double value1, double value2, int *length);
        /**
         * 初始化线条
         */
        virtual bool onCreate(const FCPoint& mp);
        /**
         * 开始移动画线工具
         */
        virtual void onMoveStart();
        /*
        * 移动线条
        */
        virtual void onMoving();
        /**
         * 绘制图像的残影
         */
        virtual void onPaintGhost(FCPaint *paint);
        /**
         * 绘制图像的方法
         */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };

    
    /**
    * 水平线
    */
    class HLine:public FCPlot{
    public:
        /**
         * 创建水平线
         */
        HLine();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 移动线条
        */
        virtual void onMoving();
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 高低推档
    */
    class LevelGrading:public FCPlot{
    public:
        /**
         * 获取高低推档的直线参数
         */
        float* levelGradingParams(double value1, double value2);
    public:
        /**
         * 创建高低推档
         */
        LevelGrading();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 移动线条
        */
        virtual void onMoving();
        /**
        * 绘制图像的残影
        */
        virtual void onPaintGhost(FCPaint *paint);
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 直线
    */
    class Line:public FCPlot{
    public:
        /**
         * 创建直线
         */
        Line();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 线性回归带
    */
    class LrBand:public FCPlot{
    public:
        /**
         * 创建线性回归带
         */
        LrBand();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 移动线条
        */
        virtual void onMoving();
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 回归通道
    */
    class LrChannel:public FCPlot{
    public:
        /**
         * 创建回归通道
         */
        LrChannel();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 移动线条
        */
        virtual void onMoving();
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 线性回归
    */
    class LrLine:public FCPlot{
    public:
        /**
         * 创建线性回归
         */
        LrLine();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 移动线条
        */
        virtual void onMoving();
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 解消点
    */
    class NullPoint:public FCPlot{
    public:
        /**
         * 创建解消点
         */
        void nullPoint(float x1, float y1, float x2, float y2, float *nullX, float *nullY);
        /**
         * 获取解消点的参数
         */
        double* getNullPointParams(HashMap<Integer,PlotMark*> *pList);
    public:
        /**
         * 创建解消点
         */
        NullPoint();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 平行直线
    */
    class Parallel:public FCPlot{
    public:
        /**
         * 获取平行直线的参数
         */
        float* getParallelParams(HashMap<Integer,PlotMark*> *pList);
    public:
        /**
         * 创建平行线
         */
        Parallel();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 百分比线
    */
    class Percent:public FCPlot{
    public:
        float* getPercentParams(double value1, double value2);
    public:
        /**
         * 创建百分比线
         */
        Percent();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 移动线条
        */
        virtual void onMoving();
        /**
        * 绘制图像的残影
        */
        virtual void onPaintGhost(FCPaint *paint);
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 周期线
    */
    class Periodic:public FCPlot{
    public:
        int m_period;
        int m_beginPeriod;
    public:
        /**
         * 创建周期线
         */
        Periodic();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        ArrayList<Double> getPLParams(HashMap<Integer,PlotMark*> *pList);
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 移动线条
        */
        virtual void onMoving();
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 价格签条
    */
    class Price:public FCPlot{
    public:
        FCSize m_textSize;
    public:
        /**
         * 创建价格签条
         */
        Price();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };

    /**
    * 文字签条
    */
    class TextTip:public FCPlot{
    public:
        FCSize m_textSize;
    public:
        /**
         * 创建价格签条
         */
        TextTip();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 幅度尺
    */
    class RangeRuler:public FCPlot{
    public:
        /**
         * 创建幅度尺
         */
        RangeRuler();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 上升45度线
    */
    class RaseLine:public FCPlot{
    public:
        /**
         * 创建上升45度线
         */
        RaseLine();
        float* getRaseLineParams(HashMap<Integer,PlotMark*> *pList);
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 射线
    */
    class Ray:public FCPlot{
    public:
        /**
         * 创建射线
         */
        Ray();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /*
     * 矩形
     */
    class RectLine:public FCPlot{
    public:
        FCPoint m_oppositePoint;
    public:
        /*
        * 创建矩形
        */
        RectLine();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 移动线条
        */
        virtual void onMoving();
        /**
        * 绘制图像的残影
        */
        virtual void onPaintGhost(FCPaint *paint);
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 线段
    */
    class Segment : public FCPlot{
    public:
        /**
         * 创建线段
         */
        Segment();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 正弦线
    */
    class Sine : public FCPlot{
    public:
        /**
         * 创建正弦线
         */
        Sine();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 移动线条
        */
        virtual void onMoving();
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 速阻线
    */
    class SpeedResist:public FCPlot{
    public:
        /**
         * 创建速阻线
         */
        SpeedResist();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 绘制图像的残影
        */
        virtual void onPaintGhost(FCPaint *paint);
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 标准误差通道
    */
    class SeChannel:public FCPlot{
    public:
        double getSEChannelSD(HashMap<Integer,PlotMark*> *pList);
    public:
        /**
         * 创建标准误差通道
         */
        SeChannel();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 移动线条
        */
        virtual void onMoving();
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 对称线
    */
    class SymmetricLine:public FCPlot{
    public:
        /**
         * 创建对称线
         */
        SymmetricLine();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /*
     * 对称三角形
     */
    class SymmetricTriangle:public FCPlot{
    public:
        float* getSymmetricTriangleParams(HashMap<Integer,PlotMark*> *pList);
    public:
        /*
        * 创建对称三角形
        */
        SymmetricTriangle();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 时间尺
    */
    class TimeRuler:public FCPlot{
    public:
        double* getTimeRulerParams(HashMap<Integer,PlotMark*> *pList);
    public:
        /**
         * 创建时间尺
         */
        TimeRuler();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 移动线条
        */
        virtual void onMoving();
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 三角形
    */
    class Triangle:public FCPlot{
    public:
        /**
         * 创建三角形
         */
        Triangle();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 绘制图像的残影
        */
        virtual void onPaintGhost(FCPaint *paint);
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };

    /**
    * 上涨箭头
    */
    class UpArrow:public FCPlot{
    public:
        FCRect getUpArrowRect(float x, float y, float width);
    public:
        /**
         * 创建上涨箭头
         */
        UpArrow();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 垂直线
    */
    class VLine:public FCPlot{
    public:
        /**
         * 创建垂直线
         */
        VLine();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 波浪尺
    */
    class WaveRuler:public FCPlot{
    public:
        float* getWaveRulerParams(double value1, double value2);
    public:
        /**
         * 创建波浪尺
         */
        WaveRuler();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 绘制图像的残影
        */
        virtual void onPaintGhost(FCPaint *paint);
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 泰龙水平线
    */
    class TironeLevels:public FCPlot{
    public:
        double* getTironelLevelsParams(HashMap<Integer,PlotMark*> *pList);
    public:
        /**
         * 创建泰龙水平线
         */
        TironeLevels();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 拉弗回归通道
    */
    class RaffChannel:public FCPlot{
    public:
        double getRRCRange(HashMap<Integer,PlotMark*> *pList, float *param);
    public:
        /**
         * 创建拉弗回归通道
         */
        RaffChannel();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 移动线条
        */
        virtual void onMoving();
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 四等分线
    */
    class QuadrantLines:public Percent{
    public:
        /**
         * 创建四等分线
         */
        QuadrantLines();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 移动线条
        */
        virtual void onMoving();
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 箱形线
    */
    class BoxLine:public RectLine{
    public:
        ActionType getAction(const FCPoint& mp);
    public:
        /**
         * 创建箱形线
         */
        BoxLine();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 移动线条
        */
        virtual void onMoving();
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /*
     * 平行线
     */
    class ParallelGram:public FCPlot{
    public:
        /*
        * 创建平行线
        */
        ParallelGram();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        FCPoint* getPLPoints(HashMap<Integer,PlotMark*> *pList);
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 绘制图像的残影
        */
        virtual void onPaintGhost(FCPaint *paint);
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 圆
    */
    class Circle:public FCPlot{
    public:
        /**
         * 创建圆
         */
        Circle();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 初始化线条
        */
        virtual bool onCreate(const FCPoint& mp);
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /**
    * 价格通道线
    */
    class PriceChannel:public Parallel{
    public:
        void getLine3Params(HashMap<Integer,PlotMark*> *pList, float *k, float *d, float *x4);
        void paintEx(FCPaint *paint, HashMap<Integer,PlotMark*> *pList,Long lineColor);
    public:
        /**
         * 创建价格通道线
         */
        PriceChannel();
        /**
        * 获取动作类型
        */
        virtual ActionType getAction();
        /**
        * 开始移动画线工具
        */
        virtual void onMoveStart();
        /**
        * 绘制图像的方法
        */
        virtual void onPaint(FCPaint *paint);
        /**
        * 绘制图像的残影
        */
        virtual void onPaintGhost(FCPaint *paint);
    };
    
/**
     * 黄金分割价位线
     */
    class Gp:public FCPlot{
    public:
        ArrayList<float> m_values;
    public:
        /**
         * 创建黄金分割价位线
         */
        Gp();
        /**
         * 获取动作类型
         */
        virtual ActionType getAction();
        /**
         * 初始化线条
         */
        virtual bool onCreate(const FCPoint& mp);
        /**
         * 开始移动画线工具
         */
        virtual void onMoveStart();
        /*
        * 移动线条
        */
        virtual void onMoving();
        /**
         * 绘制图像的方法
         */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };

    /**
     * 黄金分割目标线
     */
    class Ga:public Triangle{
    public:
        ArrayList<float> m_values;
    public:
        float* getGoldenRatioAimParams(HashMap<Integer,PlotMark*> *pList, int *length);
        /**
        * 获取黄金分割线的直线参数
        */
        float* goldenRatioParams(double value1, double value2, int *length);
    public:
        /**
         * 创建黄金分割目标线
         */
        Ga();
        /**
         * 获取动作类型
         */
        virtual ActionType getAction();
        /**
         * 开始移动画线工具
         */
        virtual void onMoveStart();
        /**
         * 绘制图像的方法
         */
        virtual void onPaint(FCPaint *paint, HashMap<Integer,PlotMark*> *pList, Long lineColor);
    };
    
    /*
     * 画线工厂
     */
    class PFactory{
    public:
        /*
         * 创建线条
         */
        static FCPlot* createPlot(const String& plotType);
    };
}
#endif
