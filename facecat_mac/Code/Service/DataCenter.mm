/*
* FaceCat图形通讯框架(非开源)
* 著作权编号:2015SR229355+2020SR0266727
* 上海卷卷猫信息技术有限公司
*/

#include "stdafx.h"
#include "DataCenter.h"
#include "FCClientService.h"
#include "FCFile.h"
#include "MainFrame.h"

string DataCenter::getGuid()
{
    CFUUIDRef puuid = CFUUIDCreate(nil);
    CFStringRef uuidString = CFUUIDCreateString(nil, puuid);
    NSString*result = (NSString*)CFBridgingRelease(CFStringCreateCopy(NULL, uuidString));
    CFRelease(puuid);
    CFRelease(uuidString);
    std::string ret=  [result UTF8String];
    return ret;
}

static string m_userPath;

string DataCenter::getUserPath(){
    if((int)m_userPath.length() == 0){
        #ifdef DEBUG
        NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
        m_userPath = [[paths objectAtIndex:0] UTF8String];
        #else
        m_userPath = FCTran::getAppPath();
        #endif
    }
    return m_userPath;
}


void DataCenter::startService(){
}
