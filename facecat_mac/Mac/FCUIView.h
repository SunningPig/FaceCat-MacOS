/*
* FaceCat图形通讯框架(非开源)
* 著作权编号:2015SR229355+2020SR0266727
* 上海卷卷猫信息技术有限公司
*/

#ifndef FCUIView_h
#define FCUIView_h
#include "stdafx.h"
#import <Cocoa/Cocoa.h>
#include "FCUIXml.h"
#import <WebKit/WebKit.h>

@interface FCUIView : NSView<NSTextInputClient>

-(FCNative*)getNative;
-(FCPaint*)getPaint;
-(void)onLoad;
-(void)onPaint:(CGRect)rect;
-(void)setXml:(FCUIXml*)xml;
-(FCUIXml*)getXml;
-(void)clearAll;
-(double)getScaleFactor;
-(void)setScaleFactor:(double)value;
-(void)resetScaleSize;
-(void)setAllowZoom:(BOOL)allowZoom;
-(void)setWindow:(NSWindow*)window;
-(NSWindow*)getWindow;
-(String)getMarkedText;
@end

#endif
