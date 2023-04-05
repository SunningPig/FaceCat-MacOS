/*
* FaceCat图形通讯框架
* 上海卷卷猫信息技术有限公司
*/

#import <Foundation/Foundation.h>

#import "FCUIView.h"
#include "IOSHost.h"
#include "stdafx.h"
#include "UIXmlEx.h"
#import "SafeCompile.h"
#include "FCDraw.h"
#include "MainFrame.h"
#import "MacUtil.h"
#import <InputMethodKit/InputMethodKit.h>
#include "DataCenter.h"
#include "FCFile.h"

@interface FCUIView(){
    /*
     * 绘图对象
     */
    ContextPaint *m_contextPaint;
    /*
     * 设备对象
     */
    IOSHost *m_host;
    /*
     * 鼠标左键是否按下
     */
    bool m_leftIsDown;
    /*
     * 方法库
     */
    FCNative *m_native;
    /*
     * 绘图对象
     */
    FCPaint *m_paint;
    /*
     * 鼠标右键是否按下
     */
    bool m_rightIsDown;
    /*
     * XML对象
     */
    FCUIXml *m_xml;
    /*
     * 上次的大小
     */
    FCSize m_lastSize;
    /*
     * 缩放比例
     */
    double m_scaleFactor;
    /*
     * 是否允许缩放
     */
    BOOL m_allowZoom;
    /*
     * 是否可以移动
     */
    BOOL m_canMove;
    /*
     * 窗体
     */
    NSWindow *m_window;
    /*
     * 标记文字的长度
     */
    int m_markedLength;
    /*
     * 标记文字
     */
    String m_markText;
}
@end

@implementation FCUIView

/*
 * 秒表方法
 */
- (void)printString:(NSString*)paramString{
    if(m_host){
        m_host->onTimer();
        [self performSelector : @selector (printString : ) withObject : @ "" afterDelay : 0.01 ];
    }
}

/*
 * 键盘按下
 */
-(void)doKeyDown:(char)key{
    m_native->onKeyDown(key);
}

/*
 * 获取标记文字
 */
-(String)getMarkedText{
    return m_markText;
}

/*
 * 设置是否允许缩放
 */
-(void)setAllowZoom:(BOOL)allowZoom{
    m_allowZoom = allowZoom;
}

/*
 * 清除所有
 */
-(void)clearAll{
    if(m_native){
        delete m_native;
    }
    m_contextPaint = 0;
    m_host = 0;
    m_native = 0;
    m_paint = 0;
    m_xml = 0;
}

/*
 * 绘制图形
 */
-(void)drawRect:(CGRect)rect{
    [self onPaint:rect];
}

/*
 * 获取方法库
 */
-(FCNative*)getNative{
    return m_native;
}

/*
 * 获取绘图对象
 */
-(FCPaint*)getPaint{
    return m_paint;
}

/*
 * 设置XML对象
 */
-(void)setXml:(FCUIXml*)xml{
    m_xml = xml;
}

/*
 * 获取XML对象
 */
-(FCUIXml*)getXml{
    return m_xml;
}

/*
 * 是否首先响应
 */
- (BOOL)acceptsFirstResponder{
    return YES;
}

/*
 * 鼠标响应
 */
-(BOOL)acceptsFirstMouse:(NSEvent *)event
{
    return YES;
}

/*
 * 加载方法
 */
-(void)onLoad{
    if(!m_native){
        m_canMove = true;
        m_scaleFactor = 1.0;
        m_native = new FCNative;
        m_host = new IOSHost;
        m_contextPaint = new ContextPaint;
        m_paint = m_contextPaint;
        m_native->setHost(m_host);
        m_native->setPaint(m_contextPaint);
        m_host->setNative(m_native);
        m_host->setView(self);
        FCSize size = IOSHost::getSize(self.frame.size);
        m_native->setSize(size);
        NSTrackingArea *area = [[NSTrackingArea alloc] initWithRect:self.bounds
                                                            options:NSTrackingMouseMoved |NSTrackingMouseEnteredAndExited|NSTrackingActiveInKeyWindow
                                                              owner:self
                                                           userInfo:nil];
        [self addTrackingArea:area];
        
        [self registerForDraggedTypes:[NSArray arrayWithObjects:NSFilenamesPboardType,nil]];
        [self performSelector : @selector (printString : ) withObject : @ "" afterDelay : 0.01 ];
    }
}

/*
 * 重绘方法
 */
-(void)onPaint:(CGRect)rect{
    if(m_native){
        FCSize size = IOSHost::getSize(self.frame.size);
        if(size.cx != m_lastSize.cx || size.cy != m_lastSize.cy){
            m_native->setSize(size);
            if(m_native->allowScaleSize()){
                [self resetScaleSize];
            }
            m_native->update();
            m_lastSize = size;
        }
        int width = rect.size.width, height = rect.size.height;
        if(m_host){
            FCRect pRect = {(int)rect.origin.x, (int)rect.origin.y, (int)(rect.origin.x + rect.size.width), (int)(rect.origin.y + rect.size.height)};
            pRect.top = size.cy - pRect.top - (pRect.bottom - pRect.top);
            pRect.bottom = pRect.top + height;
            double scaleFactorX = 1, scaleFactorY = 1;
            FCSize clientSize = m_host->getClientSize();
            if (m_native->allowScaleSize()){
                if (clientSize.cx > 0 && clientSize.cy > 0){
                    FCSize scaleSize = m_native->getScaleSize();
                    scaleFactorX = (double)(clientSize.cx) / scaleSize.cx;
                    scaleFactorY = (double)(clientSize.cy) / scaleSize.cy;
                }
            }
            FCRect newRect = {0};
            if(scaleFactorX > 0 && scaleFactorY > 0){
                newRect.left = floor(pRect.left / scaleFactorX);
                newRect.top = floor(pRect.top / scaleFactorY);
                newRect.right = ceil(pRect.right / scaleFactorX);
                newRect.bottom = ceil(pRect.bottom / scaleFactorY);
            }
            m_host->onPaint(newRect);
        }
    }
}

/*
 * 设置标记文字
 */
- (void)setMarkedText:(id)string selectedRange:(NSRange)selectedRange replacementRange:(NSRange)replacementRange{
    NSAttributedString *nSAttributedString = (NSAttributedString*)string;
    NSString *markText = nSAttributedString.string;
    m_markedLength = (int)markText.length;
    m_markText = FCTran::stringToString([markText UTF8String]);
    FCView *focusedView = m_native->getFocusedView();
    if(focusedView){
        FCTextBox *textBox = dynamic_cast<FCTextBox*>(focusedView);
        if(textBox){
            textBox->invalidate();
        }
    }
}

- (nullable NSAttributedString *)attributedSubstringForProposedRange:(NSRange)range actualRange:(nullable NSRangePointer)actualRange{
    return nil;
}

- (void)unmarkText{
}

- (NSUInteger)characterIndexForPoint:(NSPoint)point{
    return 0;
}

- (NSAttributedString *)attributedString{
    return nil;
}

- (CGFloat)fractionOfDistanceThroughGlyphForPoint:(NSPoint)point{
    return 0;
}

- (CGFloat)baselineDeltaForCharacterAtIndex:(NSUInteger)anIndex{
    return 0;
}

- (NSInteger)windowLevel{
    return 0;
}

- (BOOL)drawsVerticallyForCharacterAtIndex:(NSUInteger)charIndex API_AVAILABLE(macos(10.6)){
    return NO;
}

- (NSRange)selectedRange{
    NSRange range = NSMakeRange(0, 0);
    return range;
}

- (NSRange)markedRange{
    NSRange range = NSMakeRange(0, 0);
    return range;
}

/*
 * 控制输入法的位置
 */
- (NSRect)firstRectForCharacterRange:(NSRange)range actualRange:(nullable NSRangePointer)actualRange{
    FCView *focusedView = m_native->getFocusedView();
    if(focusedView){
        FCTextBox *textBox = dynamic_cast<FCTextBox*>(focusedView);
        if(textBox){
            int clientX = m_native->clientX(textBox) + textBox->m_cursorPoint.x;
            int clientY = m_native->clientY(textBox) + textBox->m_cursorPoint.y + textBox->getLineHeight();
            double scaleFactorX = 1, scaleFactorY = 1;
            m_native->getPaint()->getScaleFactor(&scaleFactorX, &scaleFactorY);
            clientX = (int)(clientX * scaleFactorX);
            clientY = (int)(clientY * scaleFactorY);
            FCSize nativeSize = m_native->getSize();
            CGRect newRect = CGRectMake(clientX, nativeSize.cy * scaleFactorY - clientY, 0, 0);
            if(m_window){
                CGRect currentScreen = [m_window convertRectToScreen:newRect];
                return currentScreen;
            }else{
                CGRect currentScreen = [self.window convertRectToScreen:newRect];
                return currentScreen;
            }
        }
    }
    return CGRectMake(0, 0, 0, 0);
}

- (NSArray<NSAttributedStringKey>*) validAttributesForMarkedText{
    NSArray<NSAttributedStringKey> *arry = [[NSArray alloc] initWithObjects:NSFontAttributeName, NSParagraphStyleAttributeName, NSWritingDirectionLeftToRight];
    return arry;
}

/*
 * 插入文本
 */
- (void)insertText:(id)string replacementRange:(NSRange)replacementRange{
    FCView *focusedView = m_native->getFocusedView();
    m_markText = L"";
    m_markedLength = 0;
}

- (BOOL)hasMarkedText{
    return NO;
}

/*
 * 命令键监听
 */
- (void)doCommandBySelector:(SEL)selector{
    FCView *focusedView = m_native->getFocusedView();
    if(focusedView){
        FCTextBox *textBox = dynamic_cast<FCTextBox*>(focusedView);
        if(textBox){
            return;
        }
    }
    [super doCommandBySelector:selector];
}

/*
 * 键盘按下
 */
- (void)keyDown:(NSEvent *)event
{
    int code = event.keyCode;
    switch (code) {
        case 124://right
            if(m_markedLength > 0){
                [self interpretKeyEvents:[NSArray arrayWithObject:event]];
            }else{
                [self doKeyDown:39];
            }
            break;
        case 123://left
            if(m_markedLength > 0){
                [self interpretKeyEvents:[NSArray arrayWithObject:event]];
            }else{
                [self doKeyDown:37];
            }
            break;
        case 126://up
            if(m_markedLength > 0){
                [self interpretKeyEvents:[NSArray arrayWithObject:event]];
            }else{
                [self doKeyDown:38];
            }
            break;
        case 125://dow
            if(m_markedLength > 0){
                [self interpretKeyEvents:[NSArray arrayWithObject:event]];
            }else{
                [self doKeyDown:40];
            }
            break;
        case 51:{
                bool canKeyDown = false;
                if(m_markedLength > 0){
                    m_markedLength--;
                }else{
                    canKeyDown = true;
                }
                [self interpretKeyEvents:[NSArray arrayWithObject:event]];
                if(canKeyDown){
                    [self doKeyDown:8];
                }else{
                    if(m_markedLength == 0){
                        m_markText = L"";
                    }
                    FCView *focusedView = m_native->getFocusedView();
                    focusedView->invalidate();
                }
                break;
        }
        case 53:
            if(m_markedLength > 0){
                [self interpretKeyEvents:[NSArray arrayWithObject:event]];
            }else{
                [self doKeyDown:27];
            }
            if(m_markedLength > 0){
                FCView *focusedView = m_native->getFocusedView();
                focusedView->invalidate();
                m_markText = L"";
                m_markedLength = 0;
            }
            break;
        case 47:{
            char word = '.';
            if(m_host->isKeyPress(VK_SHIFT))
            {
                word = '>';
            }
            [self doKeyDown:word];
            m_native->onChar(word);
            [self interpretKeyEvents:[NSArray arrayWithObject:event]];
            break;
        }
        case 20:
        {
            char word = '3';
            if(m_host->isKeyPress(VK_SHIFT))
            {
                word = '#';
                m_native->onChar(word);
            }else{
                [self doKeyDown:word];
                m_native->onChar(word);
                [self interpretKeyEvents:[NSArray arrayWithObject:event]];
            }
            break;
        }
        default:
            NSString *chars = [event characters];
            unichar character = [chars characterAtIndex: 0];
            char keyCode = (char)character;
            if(keyCode == '\r' && m_markedLength > 0){
                [self interpretKeyEvents:[NSArray arrayWithObject:event]];
                return;
            }
            if(keyCode != '(' && keyCode != '$' && keyCode != '%' && keyCode != 39){
                [self doKeyDown:keyCode];
            }
            m_native->onChar(keyCode);
            [self interpretKeyEvents:[NSArray arrayWithObject:event]];
            break;
    }
    
    //[super keyDown:event];
}

/*
 * 键盘抬起
 */
-(void)keyUp:(NSEvent *)event
{
    NSString *chars = [event characters];
    unichar character = [chars characterAtIndex: 0];
    char keyCode = (char)character;
    m_native->onKeyUp(keyCode);
}

/*
 * 鼠标按下
 */
-(void)mouseDown:(NSEvent *)event{
    m_leftIsDown = true;
    if(m_native){
        NSPoint nmp = [self convertPoint:[event locationInWindow] fromView:nil];
        FCPoint mp = IOSHost::getPoint(nmp);
        mp.y = self.frame.size.height - mp.y;
        m_host->setTouchPoint(mp);
        int clicks = (int)event.clickCount;
        FCTouchInfo touchInfo;
        touchInfo.m_firstTouch = true;
        touchInfo.m_clicks = clicks;
        m_native->onMouseDown(touchInfo);
    }
}

/*
 * 鼠标右键按下
 */
-(void)rightMouseDown:(NSEvent *)event{
    m_rightIsDown = true;
    if(m_native){
        NSPoint nmp = [self convertPoint:[event locationInWindow] fromView:nil];
        FCPoint mp = IOSHost::getPoint(nmp);
        mp.y = self.frame.size.height - mp.y;
        m_host->setTouchPoint(mp);
        FCTouchInfo touchInfo;
        touchInfo.m_secondTouch = true;
        touchInfo.m_clicks = (int)event.clickCount;
        m_native->onMouseDown(touchInfo);
    }
}

/*
 * 鼠标移动
 */
-(void)mouseMoved:(NSEvent *)event{
    if(m_native){
        NSPoint nmp = [self convertPoint:[event locationInWindow] fromView:nil];
        FCPoint mp = IOSHost::getPoint(nmp);
        mp.y = self.frame.size.height - mp.y;
        m_host->setTouchPoint(mp);
        if(m_leftIsDown){
            FCTouchInfo touchInfo;
            touchInfo.m_firstTouch = true;
            touchInfo.m_clicks = (int)event.clickCount;
            m_native->onMouseMove(touchInfo);
        }
        else if(m_rightIsDown){
            FCTouchInfo touchInfo;
            touchInfo.m_secondTouch = true;
            touchInfo.m_clicks = (int)event.clickCount;
            m_native->onMouseMove(touchInfo);
        }
        else{
            FCTouchInfo touchInfo;
            m_native->onMouseMove(touchInfo);
        }
    }
}

/*
 * 设置窗体
 */
-(void)setWindow:(NSWindow*)window{
    m_window = window;
}

/*
 * 获取窗体
 */
-(NSWindow*)getWindow{
    return m_window;
}

/*
 * 鼠标抬起
 */
-(void)mouseUp:(NSEvent *)event{
    m_leftIsDown = false;
    if(m_native){
        NSPoint nmp = [self convertPoint:[event locationInWindow] fromView:nil];
        FCPoint mp = IOSHost::getPoint(nmp);
        mp.y = self.frame.size.height - mp.y;
        m_host->setTouchPoint(mp);
        FCTouchInfo touchInfo;
        touchInfo.m_firstTouch = true;
        touchInfo.m_clicks = (int)event.clickCount;
        if(m_native){
            m_native->onMouseUp(touchInfo);
        }
    }
}

/*
 * 鼠标拖动
 */
-(void)mouseDragged:(NSEvent *)event{
    if(m_native){
        NSPoint nmp = [self convertPoint:[event locationInWindow] fromView:nil];
        FCPoint mp = IOSHost::getPoint(nmp);
        mp.y = self.frame.size.height - mp.y;
        m_host->setTouchPoint(mp);
        if(m_leftIsDown){
            FCTouchInfo touchInfo;
            touchInfo.m_firstTouch = true;
            touchInfo.m_clicks = (int)event.clickCount;
            m_native->onMouseMove(touchInfo);
        }
        else if(m_rightIsDown){
            FCTouchInfo touchInfo;
            touchInfo.m_secondTouch = true;
            touchInfo.m_clicks = (int)event.clickCount;
            m_native->onMouseMove(touchInfo);
        }
        else{
            FCTouchInfo touchInfo;
            m_native->onMouseMove(touchInfo);
        }
    }
}

/*
 * 鼠标右键拖动
 */
-(void)rightMouseDragged:(NSEvent *)event{
    if(m_native){
        NSPoint nmp = [self convertPoint:[event locationInWindow] fromView:nil];
        FCPoint mp = IOSHost::getPoint(nmp);
        mp.y = self.frame.size.height - mp.y;
        m_host->setTouchPoint(mp);
        if(m_leftIsDown){
            FCTouchInfo touchInfo;
            touchInfo.m_firstTouch = true;
            touchInfo.m_clicks = (int)event.clickCount;
            m_native->onMouseMove(touchInfo);
        }
        else if(m_rightIsDown){
            FCTouchInfo touchInfo;
            touchInfo.m_secondTouch = true;
            touchInfo.m_clicks = (int)event.clickCount;
            m_native->onMouseMove(touchInfo);
        }
        else{
            FCTouchInfo touchInfo;
            m_native->onMouseMove(touchInfo);
        }
    }
}

/*
 * 鼠标滚轮
 */
- (void)scrollWheel:(NSEvent *)event{
    if(m_native){
        NSPoint nmp = [self convertPoint:[event locationInWindow] fromView:nil];
        FCPoint mp = IOSHost::getPoint(nmp);
        mp.y = self.frame.size.height - mp.y;
        m_host->setTouchPoint(mp);
        CGFloat deltaX = [event scrollingDeltaX];
        CGFloat deltaY = [event scrollingDeltaY];
        if(m_allowZoom){
            if (m_host->isKeyPress(VK_CONTROL)) {
                double scaleFactor = m_scaleFactor;
                if (deltaY > 0)
                {
                    if (scaleFactor > 0.2)
                    {
                        scaleFactor -= 0.05;
                    }
                }
                else if (deltaY < 0)
                {
                    if (scaleFactor < 10)
                    {
                        scaleFactor += 0.05;
                    }
                }
                m_scaleFactor = scaleFactor;
                [self resetScaleSize];
                m_native->invalidate();
                return;
            }
        }
        if(deltaY > 0){
            FCTouchInfo touchInfo;
            touchInfo.m_firstTouch = true;
            touchInfo.m_delta = 1;
            m_native->onMouseWheel(touchInfo);
        }
        else if(deltaY < 0){
            FCTouchInfo touchInfo;
            touchInfo.m_firstTouch = true;
            touchInfo.m_delta = -1;
            m_native->onMouseWheel(touchInfo);
        }
    }
}

/*
 * 获取缩放比例
 */
-(double)getScaleFactor{
    return m_scaleFactor;
}

/*
 * 设置缩放比例
 */
-(void)setScaleFactor:(double)value{
    m_scaleFactor = value;
}
    
/*
 * 重置缩放
 */
-(void)resetScaleSize{
    CGRect frame = [self frame];
    FCSize clientSize = {(int)frame.size.width, (int)frame.size.height};
    //m_host->setAllowPartialPaint(false);
    m_native->setAllowScaleSize(true);
    m_native->setScaleSize({(int)(clientSize.cx * m_scaleFactor), (int)(clientSize.cy * m_scaleFactor)});
    m_native->update();
}
@end
