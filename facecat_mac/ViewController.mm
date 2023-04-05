/*
* FaceCat图形通讯框架
* 上海卷卷猫信息技术有限公司
*/

#include "stdafx.h"
#import "ViewController.h"
#include "MainFrame.h"
#include "DataCenter.h"
#include "IOSHost.h"
#include "FaceCatScript.h"
#include "UIXmlEx.h"
#include "FCFile.h"
#import <InputMethodKit/InputMethodKit.h>

@interface ViewController(){
    FCUIView *m_myView;
}
@end

@implementation ViewController

- (void)viewDidLoad {
    m_myView = [[FCUIView alloc] initWithFrame:NSMakeRect(0, 0, NSScreen.mainScreen.frame.size.width, NSScreen.mainScreen.frame.size.height)];
    [m_myView setAllowZoom:YES];
    self.view = m_myView;
    NSWindow *mainWindow = [[[NSApplication sharedApplication] windows] objectAtIndex:0];
    mainWindow.delegate = self;
    mainWindow.movableByWindowBackground = NO;
    [m_myView setWindow:mainWindow];
    //[mainWindow makeKeyAndOrderFront:mainWindow];
    [m_myView onLoad];
    FCNative *native = [m_myView getNative];
    MainFrame *mainFrame = new MainFrame;
    [m_myView setXml:mainFrame];
    mainFrame->setNative(native);
    mainFrame->setScript(new FaceCatScript(mainFrame));
    mainFrame->getEvent()->setScript(mainFrame->getScript());
    std::string path = FCTran::getAppPath() + "/Resources/mainframe.xml";
    String wPath = FCTran::stringToString(path);
    FCSize size = IOSHost::getSize(m_myView.frame.size);
    native->setSize(size);
    mainFrame->loadFile(wPath, 0);
    native->update();
    native->invalidate();
    native->update();
}
@end
