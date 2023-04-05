/*
 * FaceCat图形通讯框架
 * 上海卷卷猫信息技术有限公司
 */

#import <Foundation/Foundation.h>
#import "SafeCompile.h"

@implementation SafeCompile

+(void)setTextFieldDelegate:(NSTextField*)textField withView:(NSView*)nsView{
    textField.delegate = nsView;
}

@end
