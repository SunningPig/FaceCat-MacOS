/*
* FaceCat图形通讯框架
* 上海卷卷猫信息技术有限公司
*/

#ifndef FCUIView_h
#define FCUIView_h
#include "stdafx.h"
#import <Cocoa/Cocoa.h>
#include "FCUIXml.h"
#import <WebKit/WebKit.h>

/*
 * 原生视图
 */
@interface FCUIView : NSView<NSTextInputClient>

/*
 * 获取方法库
 */
-(FCNative*)getNative;
/*
 * 获取绘图对象
 */
-(FCPaint*)getPaint;
/*
 * 加载方法
 */
-(void)onLoad;
/*
 * 绘图方法
 * @param rect 矩形
 */
-(void)onPaint:(CGRect)rect;
/*
 * 设置XML
 * @param xml XML对象
 */
-(void)setXml:(FCUIXml*)xml;
/*
 * 获取XML对象
 */
-(FCUIXml*)getXml;
/*
 * 清除所有
 */
-(void)clearAll;
/*
 * 获取缩放比例
 */
-(double)getScaleFactor;
/*
 * 设置缩放比例
 * @param value 缩放比例
 */
-(void)setScaleFactor:(double)value;
/*
 * 重置缩放比例
 */
-(void)resetScaleSize;
/*
 * 设置是否允许缩放
 * @param allowZoom 允许缩放
 */
-(void)setAllowZoom:(BOOL)allowZoom;
/*
 * 设置窗体
 * @param window 窗体
 */
-(void)setWindow:(NSWindow*)window;
/*
 * 获取窗体
 */
-(NSWindow*)getWindow;
/*
 * 获取标记文本
 */
-(String)getMarkedText;
@end

#endif
