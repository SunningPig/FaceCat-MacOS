#ifndef MacUtil_h
#define MacUtil_h
#include "stdafx.h"

#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>
#import <CoreImage/CoreImage.h>

/**
 * 工具类
 */
class MacUtil
{
public:
    /*
     * 构造函数
     */
    MacUtil(){}
    /*
     * 析构函数
     */
    virtual ~MacUtil(){}
public:
    /*
     * 打开文件对话框,新建一个文件,创建成功后retPath 的值为文件保存的路径,返回值为1,反之
     */
    static int createFile(std::string *retPath){
        NSSavePanel *savePanel = [NSSavePanel savePanel];
        //NSDate *now = [NSDate date];
        //NSDateFormatter *fm = [[NSDateFormatter alloc]init];
        //[fm setDateFormat:@"yyyyMMDDHHmmss"];
        //NSString *currentDateStr = [fm stringFromDate:now];
        int length = (int)retPath->length();
        if(length > 0){
            NSString *nPath = [NSString stringWithUTF8String:retPath->c_str()];
            [savePanel setNameFieldStringValue:nPath];
        }else{
            [savePanel setNameFieldStringValue:@"NewFaceCat.html"];
        }
        [savePanel setMessage:@"新建文件"];
        [savePanel setAllowsOtherFileTypes:YES];
        //[savePanel setAllowedFileTypes:@[@"xml"]];
        [savePanel setExtensionHidden:YES];
        [savePanel setCanCreateDirectories:YES];
        NSString *savePath;
        NSInteger result = [savePanel runModal];
        if(result == NSFileHandlingPanelOKButton)
        {
            savePath = [[savePanel URL]path];
            *retPath = [savePath UTF8String];
            return 1;
        }
        return 0;
    }
    
    /*
     * 文件选择器,int 返回值为文件选择状态
     */
    static int fileExplore(std::string &path, BOOL chooseFile){
        NSOpenPanel *panel = [NSOpenPanel openPanel];
        [panel setMessage:@"选择一个位置保存"];
        [panel setPrompt:@"确定"];
        if(chooseFile)
        {
            [panel setCanChooseFiles:chooseFile];
            [panel setCanChooseDirectories:NO];
        }else
        {
            [panel setCanChooseFiles:chooseFile];
            [panel setCanChooseDirectories:YES];
        }
        NSString *path_all;
        NSInteger result = [panel runModal];
        if (result == NSFileHandlingPanelOKButton)
        {
            path_all = [[panel URL] path];
            path = [path_all UTF8String];
            return 1;
        }
        else if (result == NSFileHandlingPanelCancelButton)
        {
            return 0;
        }
        return -1;
    }
    
    /*
     * 打开文件夹
     */
    static void openBrowser(const std::string &url){
        NSString *strUrl = [NSString stringWithUTF8String:url.c_str()];
        strUrl = [strUrl stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
        NSURL *nsurl = [NSURL URLWithString:strUrl];
        [[NSWorkspace sharedWorkspace]openURL:nsurl];
    }
    
    /*
     * 显示文件
     */
    static void showExplore(const std::string &path){
        NSString *nPath = [NSString stringWithUTF8String:path.c_str()];
        [[NSWorkspace sharedWorkspace]openFile:nPath];
    }
    
    /*
     * 显示文件
     */
    static void showExplore(const String &path){
        std::string cPath = FCTran::StringTostring(path);
        NSString *nPath = [NSString stringWithUTF8String:cPath.c_str()];
        [[NSWorkspace sharedWorkspace]openFile:nPath];
    }
    
    /*
     * 如果点击了确定按钮,将返回true,否则返回false
     */
    static bool showMessageBox(String title, String message){
        NSAlert *alert = [[NSAlert alloc] init];
        std::string wmsg1 = FCTran::StringTostring(title);
        alert.window.title = [NSString stringWithUTF8String:wmsg1.c_str()];
        alert.icon = [NSImage imageNamed:@"Tips"];
        [alert addButtonWithTitle:@"确定"];
        [alert addButtonWithTitle:@"取消"];
        [alert setAlertStyle:NSAlertStyleWarning];
        [alert setMessageText:@"提示信息:"];
        std::string wmsg = FCTran::StringTostring(message);
        //[alert.window setFrame:CGRectMake(1000.0f, 5.0f, 400.0f, 150.0f) display:false];
        [alert setInformativeText:[NSString stringWithUTF8String:wmsg.c_str()]];
        NSUInteger ret = [alert runModal];
        if(ret == NSAlertFirstButtonReturn)
        {
            return true;
        }
        return false;
    }
    
    /*
     * 显示提示框
     */
    static bool showMessageBox(String message){
        NSAlert *alert = [[NSAlert alloc] init];
        alert.icon = [NSImage imageNamed:@"Tips"];
        [alert addButtonWithTitle:@"确定"];
        [alert addButtonWithTitle:@"取消"];
        [alert setAlertStyle:NSAlertStyleWarning];
        [alert setMessageText:@"提示信息:"];
        std::string wmsg = FCTran::StringTostring(message);
        [alert setInformativeText:[NSString stringWithUTF8String:wmsg.c_str()]];
        
        NSUInteger ret = [alert runModal];
        if(ret == NSAlertFirstButtonReturn)
        {
            return true;
        }
        return false;
    }
    
    /*
     * 显示警告提示框
     */
    static void showWarningMessageBox(String title, String message){
        NSAlert *alert = [[NSAlert alloc] init];
        std::string wmsg1 = FCTran::StringTostring(title);
        alert.window.title = [NSString stringWithUTF8String:wmsg1.c_str()];
        alert.icon = [NSImage imageNamed:@"Tips"];
        [alert addButtonWithTitle:@"确定"];
        [alert setAlertStyle:NSAlertStyleWarning];
        [alert setMessageText:@"提示信息:"];
        std::string wmsg = FCTran::StringTostring(message);
        [alert setInformativeText:[NSString stringWithUTF8String:wmsg.c_str()]];
        [alert runModal];
    }
    
    /*
     * 显示确认提示框
     */
    static bool showConfirmMessageBox(String title, String message){
        NSAlert *alert = [[NSAlert alloc] init];
        std::string wmsg1 = FCTran::StringTostring(title);
        alert.window.title = [NSString stringWithUTF8String:wmsg1.c_str()];
        alert.icon = [NSImage imageNamed:@"Tips"];
        [alert addButtonWithTitle:@"确定"];
        //[alert addButtonWithTitle:@"取消"];
        [alert setAlertStyle:NSAlertStyleWarning];
        [alert setMessageText:@"提示信息:"];
        std::string wmsg = FCTran::StringTostring(message);
        [alert setInformativeText:[NSString stringWithUTF8String:wmsg.c_str()]];
        NSUInteger ret = [alert runModal];
        if(ret == NSAlertFirstButtonReturn)
        {
            return true;
        }
        return false;
    }
    
    /*
     * 输出二维码
     */
    static void outputQrCode(String url, String savePath){
        std::string sUrl = FCTran::StringTostring(url);
        std::string sSavePath = FCTran::StringTostring(savePath);
        NSString *nsUrl = [NSString stringWithUTF8String:sUrl.c_str()];
        NSString *nsSavePath = [NSString stringWithUTF8String:sSavePath.c_str()];
        NSImage *image =  qrCodeImageForString(nsUrl, 300);
        [image lockFocus];
        //先设置 下面一个实例
        NSBitmapImageRep *bits = [[NSBitmapImageRep alloc]initWithFocusedViewRect:NSMakeRect(0, 0, 300, 300)];        //138.32为图片的长和宽
        [image unlockFocus];
        //再设置后面要用到得 props属性
        NSDictionary *imageProps = [NSDictionary dictionaryWithObject:[NSNumber numberWithBool:0] forKey:NSImageCompressionFactor];

        //之后 转化为NSData 以便存到文件中
        NSData *imageData = [bits representationUsingType:NSPNGFileType properties:imageProps];
        //设定好文件路径后进行存储就ok了
        BOOL result = [imageData writeToFile:[[NSString stringWithString:nsSavePath] stringByExpandingTildeInPath]atomically:YES];
    }
    
    /*
     * 从文字输出二维码
     */
    static NSImage* qrCodeImageForString(NSString *string, CGFloat sizeLength){
        CIFilter *qrFilter = [CIFilter filterWithName:@"CIQRCodeGenerator"];
        [qrFilter setDefaults];
        [qrFilter setValue:[string dataUsingEncoding:NSUTF8StringEncoding] forKey:@"inputMessage"];
        CIImage *outputCiImage = qrFilter.outputImage;
        NSImage *qrImage = createNonInterpolatedUIImageFormCIImage(outputCiImage, sizeLength);
        return qrImage;
    }
    
    /*
     * 显示二维码图片
     */
    static NSImage* createNonInterpolatedUIImageFormCIImage(CIImage *image, CGFloat sizeLength){
        CGRect extent = CGRectIntegral(image.extent);
        CGFloat scale = MIN(sizeLength / CGRectGetWidth(extent), sizeLength / CGRectGetHeight(extent));
        size_t width = CGRectGetWidth(extent) * scale;
        size_t height = CGRectGetHeight(extent) * scale;
        CGColorSpaceRef cs = CGColorSpaceCreateDeviceGray();
        CGContextRef bitmapRef = CGBitmapContextCreate(NULL, width, height, 8, 0, cs, (CGBitmapInfo)kCGImageAlphaNone);
        CIContext *context = [CIContext contextWithOptions:nil];
        CGImageRef bitmapImage = [context createCGImage:image fromRect:extent];
        CGContextSetInterpolationQuality(bitmapRef, kCGInterpolationNone);
        CGContextScaleCTM(bitmapRef, scale, scale);
        CGContextDrawImage(bitmapRef, extent, bitmapImage);
        CGImageRef scaledImage = CGBitmapContextCreateImage(bitmapRef);
        CGContextRelease(bitmapRef);
        CGImageRelease(bitmapImage);
        NSRect imageRect = NSMakeRect(0.0, 0.0, 0.0, 0.0);
        NSImage* newImage = nil;
        imageRect.size.height = CGImageGetHeight(scaledImage);
        imageRect.size.width = CGImageGetWidth(scaledImage);
        newImage = [[NSImage alloc] initWithSize:imageRect.size];
        [newImage lockFocus];
        // Get the Quartz context and draw.
        CGContextRef imageContext = (CGContextRef)[[NSGraphicsContext currentContext] graphicsPort];
        CGContextDrawImage(imageContext, *(CGRect*)&imageRect, scaledImage);
        [newImage unlockFocus];
        return newImage;
    }
};

#endif
