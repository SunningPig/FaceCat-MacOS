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

class IOSTimer{
public:
    IOSTimer();
    virtual ~IOSTimer();
    int m_interval;
    int m_tick;
    int m_timerID;
};

class ScrollButtonM : public FCButton{
public:
    int m_arrowType;
public:
    ScrollButtonM();
    virtual ~ScrollButtonM();
    virtual void onPaint(FCPaint *paint, const FCRect& clipRect);
    virtual void onPaintBorder(FCPaint *paint, const FCRect& clipRect);
};

class IOSHost : public FCHost{
public:
    bool m_allowOperate;
    bool m_allowPartialPaint;
    bool m_isViewAppear;
    FCLock m_lock;
    FCPoint m_mousePoint;
    FCNative *m_native;
    map<int, IOSTimer*> m_timers;
    NSView *m_view;
    int m_id;
public:
    IOSHost();
    virtual ~IOSHost();
    virtual FCNative* getNative();
    virtual void setNative(FCNative *native);
    virtual NSView* getView();
    virtual void setView(NSView *view);
public:
    static CGPoint getCGPoint(const FCPoint& point);
    static CGRect getCGRect(const FCRect& rect);
    static CGSize getCGSize(const FCSize& size);
    static NSString* getNSString(const wchar_t *str);
    static FCPoint getPoint(CGPoint cgPoint);
    static FCRect getRect(CGRect cgRect);
    static FCSize getSize(CGSize cgSize);
public:
    virtual bool allowOperate();
    virtual bool allowPartialPaint();
    virtual void beginInvoke(FCView *view, void *args);
    virtual void copy(string text);
    virtual FCView* createInternalView(FCView *parent, const String& clsid);
    FCSize getClientSize();
    virtual FCCursors getCursor();
    virtual int getIntersectRect(FCRect *lpDestRect, const FCRect *lpSrc1Rect, const FCRect *lpSrc2Rect);
    virtual FCPoint getTouchPoint();
    virtual FCSize getSize();
    virtual int getUnionRect(FCRect *lpDestRect, const FCRect *lpSrc1Rect, const FCRect *lpSrc2Rect);
    virtual void invalidate();
    virtual void invalidate(const FCRect& rect);
    virtual void invoke(FCView *view, void *args);
    virtual bool isKeyPress(char key);
    void onPaint(const FCRect& rect);
    void onTimer();
    virtual string paste();
    virtual void setAllowOperate(bool allowOperate);
    virtual void setAllowPartialPaint(bool allowPartialPaint);
    virtual void setCursor(FCCursors cursor);
    virtual void setTouchPoint(const FCPoint& mp);
    virtual void startTimer(int timerID, int interval);
    virtual void stopTimer(int timerID);
    static unsigned long getTickCount()
    {
        struct timespec ts;
        clock_gettime(CLOCK_MONOTONIC, &ts);
        return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
    }
};

#endif
