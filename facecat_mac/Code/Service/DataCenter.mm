/*
* FaceCat图形通讯框架
* 上海卷卷猫信息技术有限公司
*/

#include "stdafx.h"
#include "DataCenter.h"
#include "FCClientService.h"
#include "FCFile.h"
#include "MainFrame.h"

std::string DataCenter::getGuid()
{
    CFUUIDRef puuid = CFUUIDCreate(nil);
    CFStringRef uuidString = CFUUIDCreateString(nil, puuid);
    NSString*result = (NSString*)CFBridgingRelease(CFStringCreateCopy(NULL, uuidString));
    CFRelease(puuid);
    CFRelease(uuidString);
    std::string ret=  [result UTF8String];
    return ret;
}

static std::string m_userPath;

std::string DataCenter::getUserPath(){
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
