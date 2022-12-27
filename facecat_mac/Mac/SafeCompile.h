/*
* FaceCat图形通讯框架
* 上海卷卷猫信息技术有限公司
*/

#ifndef SafeCompile_h
#define SafeCompile_h
#import <Cocoa/Cocoa.h>

@interface SafeCompile : NSObject

+(void)setTextFieldDelegate:(NSTextField*)textField withView:(NSView*)nsView;

@end

#endif 
