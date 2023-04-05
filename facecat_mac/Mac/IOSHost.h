/*
* FaceCat图形通讯框架
* 上海卷卷猫信息技术有限公司
*/

#ifndef __IOSHOST_H__
#define __IOSHOST_H__
#pragma once
#include "stdafx.h"
#include "FCHost.h"
#include "ContextPaint.h"
#include "ViewController.h"
#import <Cocoa/Cocoa.h>

/*
 * IOS秒表
 */
class IOSTimer{
public:
    /*
     * 构造函数
     */
    IOSTimer();
    /*
     * 析构函数
     */
    virtual ~IOSTimer();
    /*
     * 间隔
     */
    int m_interval;
    /*
     * 计数
     */
    int m_tick;
    /*
     * 秒表ID
     */
    int m_timerID;
};

/**
 * 滚动按钮
 */
class ScrollButtonM : public FCButton{
public:
    /*
     * 箭头类型
     */
    int m_arrowType;
public:
    /**
     * 创建透明按钮
     */
    ScrollButtonM();
    /**
     * 析构函数
     */
    virtual ~ScrollButtonM();
    /**
     重绘方法
     @param paint 绘图对象
     @param clipRect 裁剪区域
     */
    virtual void onPaint(FCPaint *paint, const FCRect& clipRect);
    /**
     重绘边线方法
     @param paint 绘图对象
     @param clipRect 裁剪区域
     */
    virtual void onPaintBorder(FCPaint *paint, const FCRect& clipRect);
};

/*
 * 设备对接
 */
class IOSHost : public FCHost{
public:
    /*
     * 允许操作
     */
    bool m_allowOperate;
    /*
     * 允许局部绘图
     */
    bool m_allowPartialPaint;
    /*
     * 是否可见
     */
    bool m_isViewAppear;
    /*
     * 锁
     */
    FCLock m_lock;
    /*
     * 鼠标坐标
     */
    FCPoint m_mousePoint;
    /*
     * 方法库
     */
    FCNative *m_native;
    /*
     * 秒表
     */
    std::map<int, IOSTimer*> m_timers;
    /*
     * 视图
     */
    NSView *m_view;
    /*
     * 唯一编号
     */
    int m_id;
public:
    /*
     * 构造函数
     */
    IOSHost();
    /*
     * 析构函数
     */
    virtual ~IOSHost();
    /*
     * 获取方法库
     */
    virtual FCNative* getNative();
    /*
     * 设置方法库
     */
    virtual void setNative(FCNative *native);
    /*
     * 获取视图
     */
    virtual NSView* getView();
    /*
     * 设置视图
     */
    virtual void setView(NSView *view);
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
    /*
     * 允许操作
     */
    virtual bool allowOperate();
    /*
     * 是否允许局部绘图
     */
    virtual bool allowPartialPaint();
    /*
     * 开始跨线程调用
     */
    virtual void beginInvoke(FCView *view, void *args);
    /*
     * 复制到剪贴板
     */
    virtual void copy(std::string text);
    /*
     * 创建内部视图
     * parent 父视图
     * clsid ID
     */
    virtual FCView* createInternalView(FCView *parent, const String& clsid);
    /*
     * 获取客户端大小
     */
    FCSize getClientSize();
    /*
     * 获取光标
     */
    virtual FCCursors getCursor();
    /*
     * 获取裁剪区域
     * lpDestRect 裁剪区域
     * lpSrc1Rect 区域1
     * lpSrc2Rect 区域2
     */
    virtual int getIntersectRect(FCRect *lpDestRect, const FCRect *lpSrc1Rect, const FCRect *lpSrc2Rect);
    /*
     * 获取点击坐标
     */
    virtual FCPoint getTouchPoint();
    /*
     * 获取大小
     */
    virtual FCSize getSize();
    /*
     * 获取合并区域
     * lpDestRect 裁剪区域
     * lpSrc1Rect 区域1
     * lpSrc2Rect 区域2
     */
    virtual int getUnionRect(FCRect *lpDestRect, const FCRect *lpSrc1Rect, const FCRect *lpSrc2Rect);
    /*
     * 全部绘图
     */
    virtual void invalidate();
    /*
     * 局部绘图
     * rect 区域
     */
    virtual void invalidate(const FCRect& rect);
    /*
     * 跨线程调用
     * view 视图
     * args 参数
     */
    virtual void invoke(FCView *view, void *args);
    /*
     * 特殊键是否按下
     * key 按键
     */
    virtual bool isKeyPress(char key);
    /*
     * 重绘方法
     * g 绘图对象
     */
    void onPaint(const FCRect& rect);
    /*
     * 秒表方法
     */
    void onTimer();
    /*
     * 粘帖
     */
    virtual std::string paste();
    /*
     * 设置是否可以操作
     */
    virtual void setAllowOperate(bool allowOperate);
    /*
     * 设置是否支持局部绘图
     */
    virtual void setAllowPartialPaint(bool allowPartialPaint);
    /*
     * 设置光标
     */
    virtual void setCursor(FCCursors cursor);
    /*
    * 设置点击坐标
    * mp 坐标
    */
    virtual void setTouchPoint(const FCPoint& mp);
    /*
     * 启动秒表
     * timerID 秒表ID
     * interval 间隔
     */
    virtual void startTimer(int timerID, int interval);
    /*
     * 结束秒表
     * timerID 秒表ID
     */
    virtual void stopTimer(int timerID);
    /*
     * 获取当前TICK
     */
    static unsigned long getTickCount()
    {
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
    }
};

#endif
