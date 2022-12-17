/*
* FaceCat图形通讯框架(非开源)
* 著作权编号:2015SR229355+2020SR0266727
* 上海卷卷猫信息技术有限公司
*/

#include "stdafx.h"
#include "FCDraw.h"
#include "FCFile.h"
#include "DataCenter.h"

static String m_systemFont;

MyColor::MyColor(){
    m_lastStyle = -1;
}

MyColor::~MyColor(){
}

void MyColor::setSystemFont(String value){
    m_systemFont = value;
}

String MyColor::getSystemFont(){
    if ((int)m_systemFont.length() == 0)
    {
        m_systemFont = L"Heiti SC";
    }
    return m_systemFont;
}

static int m_reverseColor = -1;

void MyColor::setReverseColor(int reverseColor){
    m_reverseColor = reverseColor;
}

int MyColor::getReverseColor(){
    if (m_reverseColor == -1)
    {
        m_reverseColor = 0;
    }
    return m_reverseColor;
}

static int m_style = 0;

int MyColor::getStyle(){
    return m_style;
}
void MyColor::setStyle(int value){
    m_style = value;
}

void MyColor::createColors(){
    m_userColors.clear();
    if (m_style == 1)
    {
        m_userColors.put(USERCOLOR, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR1, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR2, FCColor::rgba(0, 0, 0, 100)); //1
        m_userColors.put(USERCOLOR3, FCColor::rgb(0, 0, 0)); //1
        m_userColors.put(USERCOLOR4, FCColor::rgb(0, 0, 0)); //1
        m_userColors.put(USERCOLOR5, FCColor::rgb(42, 138, 195));
        m_userColors.put(USERCOLOR6, FCColor::rgba(0, 0, 0, 25)); //1
        m_userColors.put(USERCOLOR7, FCColor::rgb(255, 255, 255)); //1
        m_userColors.put(USERCOLOR8, FCColor::rgb(200, 200, 200)); //1
        m_userColors.put(USERCOLOR9, FCColor::rgb(255, 255, 255)); //1
        m_userColors.put(USERCOLOR10, FCColor::rgb(43, 138, 195));
        m_userColors.put(USERCOLOR11, FCColor::rgba(0, 0, 0, 200)); //1
        m_userColors.put(USERCOLOR12, FCColor::rgb(255, 255, 255)); //1
        m_userColors.put(USERCOLOR13, FCColor::rgba(200, 200, 200, 240)); //1
        m_userColors.put(USERCOLOR14, FCColor::rgba(200, 200, 200, 100)); //1
        m_userColors.put(USERCOLOR15, FCColor::rgb(200, 200, 200)); //1
        m_userColors.put(USERCOLOR16, FCColor::rgb(200, 200, 200)); //1
        m_userColors.put(USERCOLOR17, FCColor::rgb(150, 150, 150)); //1
        m_userColors.put(USERCOLOR18, FCColor::rgba(0, 0, 0, 5)); //1
        m_userColors.put(USERCOLOR19, FCColor::rgba(0, 0, 0, 50)); //1
        m_userColors.put(USERCOLOR20, FCColor::rgb(50, 50, 50)); //1
        m_userColors.put(USERCOLOR21, FCColor::rgb(175, 175, 175)); //1
        m_userColors.put(USERCOLOR22, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR23, FCColor::rgba(43, 138, 195, 100));
        m_userColors.put(USERCOLOR24, FCColor::rgb(150, 150, 150)); //1
        m_userColors.put(USERCOLOR25, FCColor::rgb(255, 82, 82));
        m_userColors.put(USERCOLOR26, FCColor::rgb(50, 105, 217));
        m_userColors.put(USERCOLOR27, FCColor::rgb(0, 0, 0)); //1
        m_userColors.put(USERCOLOR28, FCColor::rgb(50, 50, 50)); //1
        m_userColors.put(USERCOLOR29, FCColor::rgb(175, 175, 175));
        m_userColors.put(USERCOLOR30, FCColor::rgb(225, 225, 225));
        m_userColors.put(USERCOLOR31, FCColor::rgb(255, 0, 0)); //1
        m_userColors.put(USERCOLOR32, FCColor::rgb(139, 180, 248));
        m_userColors.put(USERCOLOR33, FCColor::rgb(0, 165, 137));
        m_userColors.put(USERCOLOR34, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR35, FCColor::rgba(150, 150, 150, 200)); //1
        m_userColors.put(USERCOLOR36, FCColor::rgba(43, 138, 195, 200));
        m_userColors.put(USERCOLOR37, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR38, FCColor::rgba(43, 138, 195, 25));
        m_userColors.put(USERCOLOR39, FCColor::rgba(51, 153, 255, 75));
        m_userColors.put(USERCOLOR40, FCColor::rgb(0, 200, 0));
        m_userColors.put(USERCOLOR41, FCColor::rgba(255, 255, 255, 10)); //1
        m_userColors.put(USERCOLOR42, FCColor::rgba(200, 200, 200, 50)); //1
        m_userColors.put(USERCOLOR43, FCColor::rgb(0, 105, 217));
        m_userColors.put(USERCOLOR44, FCColor::rgba(0, 0, 0, 150)); //1
        m_userColors.put(USERCOLOR45, FCColor::rgba(255, 0, 0, 200));
        m_userColors.put(USERCOLOR46, FCColor::rgba(170, 178, 189, 50));
        m_userColors.put(USERCOLOR47, FCColor::rgba(170, 178, 189, 200));
        m_userColors.put(USERCOLOR48, FCColor::rgb(219, 68, 83));
        m_userColors.put(USERCOLOR49, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR50, FCColor::rgb(246, 187, 67));
        m_userColors.put(USERCOLOR51, FCColor::rgb(59, 174, 218));
        m_userColors.put(USERCOLOR52, FCColor::rgb(216, 112, 173));
        m_userColors.put(USERCOLOR53, FCColor::rgb(140, 192, 81));
        m_userColors.put(USERCOLOR54, FCColor::rgb(80, 255, 80));
        m_userColors.put(USERCOLOR55, FCColor::rgba(255, 80, 80, 200));
        m_userColors.put(USERCOLOR56, FCColor::rgba(200, 200, 200, 150)); //1
        m_userColors.put(USERCOLOR57, FCColor::rgba(0, 105, 217, 240));
        m_userColors.put(USERCOLOR58, FCColor::rgba(255, 255, 255, 25)); //1
        m_userColors.put(USERCOLOR59, FCColor::rgb(255, 215, 0));
        m_userColors.put(USERCOLOR60, FCColor::rgb(100, 100, 100)); //1
        m_userColors.put(USERCOLOR61, FCColor::rgba(255, 255, 255, 200)); //1
        m_userColors.put(USERCOLOR62, FCColor::rgba(43, 138, 195, 50));
        m_userColors.put(USERCOLOR63, FCColor::rgb(10, 36, 106));
        m_userColors.put(USERCOLOR64, FCColor::rgb(255, 255, 255)); //1
        m_userColors.put(USERCOLOR65, FCColor::rgba(255, 255, 255, 100)); //1
        m_userColors.put(USERCOLOR66, FCColor::rgba(255, 255, 255, 50)); //1
        m_userColors.put(USERCOLOR67, FCColor::rgb(20, 20, 20)); //1
        m_userColors.put(USERCOLOR68, FCColor::rgb(220, 220, 220)); //1
        m_userColors.put(USERCOLOR69, FCColor::rgb(248, 73, 96));
        m_userColors.put(USERCOLOR70, FCColor::rgb(15, 193, 118));
        m_userColors.put(USERCOLOR71, FCColor::rgba(248, 73, 96, 150));
        m_userColors.put(USERCOLOR72, FCColor::rgba(15, 193, 118, 150));
        m_userColors.put(USERCOLOR73, FCColor::rgb(130, 140, 150));
        m_userColors.put(USERCOLOR74, FCColor::rgba(94, 102, 115, 200));
        m_userColors.put(USERCOLOR75, FCColor::rgb(83, 195, 42));
        m_userColors.put(USERCOLOR76, FCColor::rgb(231, 192, 42));
        m_userColors.put(USERCOLOR77, FCColor::rgb(254, 89, 82));
        m_userColors.put(USERCOLOR78, FCColor::rgba(42, 138, 195, 100));
        m_userColors.put(USERCOLOR79, FCColor::rgb(200, 200, 200)); //1
        m_userColors.put(USERCOLOR80, FCColor::rgba(200, 200, 200, 150)); //1
        m_userColors.put(USERCOLOR81, FCColor::rgb(16, 95, 205));
        m_userColors.put(USERCOLOR82, FCColor::rgba(16, 95, 205, 100));
        m_userColors.put(USERCOLOR83, FCColor::rgb(150, 150, 150)); //1
        m_userColors.put(USERCOLOR84, FCColor::rgb(20, 20, 20)); //1
        m_userColors.put(USERCOLOR85, FCColor::rgb(70, 76, 79));
        m_userColors.put(USERCOLOR86, FCColor::rgb(200, 200, 200));
        m_userColors.put(USERCOLOR87, FCColor::rgb(210, 210, 210)); //1
        m_userColors.put(USERCOLOR88, FCColor::rgb(184, 185, 186));
        m_userColors.put(USERCOLOR89, FCColor::rgb(100, 100, 100)); //1
        m_userColors.put(USERCOLOR90, FCColor::rgb(255, 255, 80));
        m_userColors.put(USERCOLOR91, FCColor::rgba(42, 138, 195, 200));  //1
        m_userColors.put(USERCOLOR92, FCColor::rgba(220, 220, 220, 50));
        m_userColors.put(USERCOLOR93, FCColor::rgba(200, 200, 200, 25));
        m_userColors.put(USERCOLOR94, FCColor::rgb(220, 220, 220)); //1
        m_userColors.put(USERCOLOR95, FCColor::rgb(128, 128, 128));
        m_userColors.put(USERCOLOR96, FCColor::rgb(150, 0, 0));
        m_userColors.put(USERCOLOR97, FCColor::rgb(80, 255, 255));
        m_userColors.put(USERCOLOR98, FCColor::rgb(217, 217, 68));
        m_userColors.put(USERCOLOR99, FCColor::rgb(112, 112, 112));
        m_userColors.put(USERCOLOR100, FCColor::rgb(192, 192, 192));
        m_userColors.put(USERCOLOR101, FCColor::rgb(255, 255, 0));
        m_userColors.put(USERCOLOR102, FCColor::rgba(255, 255, 255, 200));
        m_userColors.put(USERCOLOR103, FCColor::rgba(43, 138, 195, 240));
        m_userColors.put(USERCOLOR104, FCColor::rgba(230, 230, 230, 240));
        m_userColors.put(USERCOLOR105, FCColor::rgba(0, 0, 0, 12)); //1
        m_userColors.put(USERCOLOR106, FCColor::rgb(222, 86, 122));
        m_userColors.put(USERCOLOR107, FCColor::rgb(115, 183, 72));
        m_userColors.put(USERCOLOR108, FCColor::rgba(219, 68, 83, 200));
        m_userColors.put(USERCOLOR109, FCColor::rgba(140, 192, 81, 200));
        m_userColors.put(USERCOLOR110, FCColor::rgb(15, 193, 118));
        m_userColors.put(USERCOLOR111, FCColor::rgba(220, 220, 220, 100));
        m_userColors.put(USERCOLOR112, FCColor::rgba(42, 138, 195, 230));
        m_userColors.put(USERCOLOR113, FCColor::rgba(15, 193, 118, 50));
        m_userColors.put(USERCOLOR114, FCColor::rgba(248, 73, 96, 50));
        m_userColors.put(USERCOLOR115, FCColor::rgba(170, 178, 189, 25));
        m_userColors.put(USERCOLOR116, FCColor::rgb(217, 218, 223));
        m_userColors.put(USERCOLOR117, FCColor::rgb(167, 171, 184));
        m_userColors.put(FCColor_Back, FCColor::rgb(255, 255, 255)); //1
        m_userColors.put(FCColor_Border, FCColor::rgb(200, 200, 200)); //1
        m_userColors.put(FCColor_Text, FCColor::rgb(0, 0, 0)); //1
        m_userColors.put(FCColor_DisabledBack, FCColor::rgba(0, 0, 0, 25)); //1
        m_userColors.put(FCColor_DisabledText, 3289650);
        m_userColors.put(FCColor_Hovered, FCColor::rgba(43, 138, 195, 150));
        m_userColors.put(FCColor_Pushed, FCColor::rgba(43, 138, 195, 100));
    }
    else if (m_style == 2)
    {
        m_userColors.put(USERCOLOR, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR1, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR2, FCColor::rgba(255, 255, 255, 100));
        m_userColors.put(USERCOLOR3, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR4, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR5, FCColor::rgb(219, 68, 83)); //1
        m_userColors.put(USERCOLOR6, FCColor::rgba(255, 255, 255, 25));
        m_userColors.put(USERCOLOR7, FCColor::rgb(19, 21, 26));
        m_userColors.put(USERCOLOR8, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR9, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR10, FCColor::rgb(219, 68, 83)); //1
        m_userColors.put(USERCOLOR11, FCColor::rgba(255, 255, 255, 200));
        m_userColors.put(USERCOLOR12, FCColor::rgb(19, 21, 26));
        m_userColors.put(USERCOLOR13, FCColor::rgba(50, 50, 50, 240));
        m_userColors.put(USERCOLOR14, FCColor::rgba(50, 50, 50, 100));
        m_userColors.put(USERCOLOR15, FCColor::rgb(46, 47, 49));
        m_userColors.put(USERCOLOR16, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR17, FCColor::rgb(100, 100, 100));
        m_userColors.put(USERCOLOR18, FCColor::rgba(255, 255, 255, 5));
        m_userColors.put(USERCOLOR19, FCColor::rgba(255, 255, 255, 50));
        m_userColors.put(USERCOLOR20, FCColor::rgb(255, 255, 255)); 
        m_userColors.put(USERCOLOR21, FCColor::rgba(219, 68, 83, 100)); //1
        m_userColors.put(USERCOLOR22, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR23, FCColor::rgba(219, 68, 83, 100)); //1
        m_userColors.put(USERCOLOR24, FCColor::rgb(100, 100, 100));
        m_userColors.put(USERCOLOR25, FCColor::rgb(255, 82, 82));
        m_userColors.put(USERCOLOR26, FCColor::rgb(50, 105, 217));
        m_userColors.put(USERCOLOR27, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR28, FCColor::rgb(200, 200, 200));
        m_userColors.put(USERCOLOR29, FCColor::rgb(80, 80, 80));
        m_userColors.put(USERCOLOR30, FCColor::rgb(25, 25, 25));
        m_userColors.put(USERCOLOR31, FCColor::rgb(255, 0, 0));
        m_userColors.put(USERCOLOR32, FCColor::rgb(139, 180, 248));
        m_userColors.put(USERCOLOR33, FCColor::rgb(0, 165, 137));
        m_userColors.put(USERCOLOR34, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR35, FCColor::rgba(100, 100, 100, 200));
        m_userColors.put(USERCOLOR36, FCColor::rgba(219, 68, 83, 200)); //1
        m_userColors.put(USERCOLOR37, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR38, FCColor::rgba(43, 138, 195, 25));
        m_userColors.put(USERCOLOR39, FCColor::rgba(51, 153, 255, 75));
        m_userColors.put(USERCOLOR40, FCColor::rgb(0, 200, 0));
        m_userColors.put(USERCOLOR41, FCColor::rgba(0, 0, 0, 10));
        m_userColors.put(USERCOLOR42, FCColor::rgba(50, 50, 50, 50));
        m_userColors.put(USERCOLOR43, FCColor::rgb(0, 105, 217));
        m_userColors.put(USERCOLOR44, FCColor::rgba(255, 255, 255, 150));
        m_userColors.put(USERCOLOR45, FCColor::rgba(255, 0, 0, 200));
        m_userColors.put(USERCOLOR46, FCColor::rgba(170, 178, 189, 50));
        m_userColors.put(USERCOLOR47, FCColor::rgba(170, 178, 189, 200));
        m_userColors.put(USERCOLOR48, FCColor::rgb(219, 68, 83));
        m_userColors.put(USERCOLOR49, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR50, FCColor::rgb(246, 187, 67));
        m_userColors.put(USERCOLOR51, FCColor::rgb(59, 174, 218));
        m_userColors.put(USERCOLOR52, FCColor::rgb(216, 112, 173));
        m_userColors.put(USERCOLOR53, FCColor::rgb(140, 192, 81));
        m_userColors.put(USERCOLOR54, FCColor::rgb(80, 255, 80));
        m_userColors.put(USERCOLOR55, FCColor::rgba(255, 80, 80, 200));
        m_userColors.put(USERCOLOR56, FCColor::rgba(50, 50, 50, 150));
        m_userColors.put(USERCOLOR57, FCColor::rgba(0, 105, 217, 240));
        m_userColors.put(USERCOLOR58, FCColor::rgba(0, 0, 0, 25));
        m_userColors.put(USERCOLOR59, FCColor::rgb(255, 215, 0));
        m_userColors.put(USERCOLOR60, FCColor::rgb(150, 150, 150));
        m_userColors.put(USERCOLOR61, FCColor::rgba(0, 0, 0, 200));
        m_userColors.put(USERCOLOR62, FCColor::rgba(219, 68, 83, 50)); //1
        m_userColors.put(USERCOLOR63, FCColor::rgb(10, 36, 106));
        m_userColors.put(USERCOLOR64, FCColor::rgb(21, 24, 28));
        m_userColors.put(USERCOLOR65, FCColor::rgba(0, 0, 0, 100));
        m_userColors.put(USERCOLOR66, FCColor::rgba(0, 0, 0, 50));
        m_userColors.put(USERCOLOR67, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR68, FCColor::rgba(219, 68, 83, 200)); //1
        m_userColors.put(USERCOLOR69, FCColor::rgb(248, 73, 96));
        m_userColors.put(USERCOLOR70, FCColor::rgb(15, 193, 118));
        m_userColors.put(USERCOLOR71, FCColor::rgba(248, 73, 96, 150));
        m_userColors.put(USERCOLOR72, FCColor::rgba(15, 193, 118, 150));
        m_userColors.put(USERCOLOR73, FCColor::rgb(130, 140, 150));
        m_userColors.put(USERCOLOR74, FCColor::rgba(219, 68, 83, 200)); //1
        m_userColors.put(USERCOLOR75, FCColor::rgb(83, 195, 42));
        m_userColors.put(USERCOLOR76, FCColor::rgb(231, 192, 42));
        m_userColors.put(USERCOLOR77, FCColor::rgb(254, 89, 82));
        m_userColors.put(USERCOLOR78, FCColor::rgba(42, 138, 195, 100));
        m_userColors.put(USERCOLOR79, FCColor::rgb(219, 68, 83));; //1
        m_userColors.put(USERCOLOR80, FCColor::rgba(52, 53, 58, 150));
        m_userColors.put(USERCOLOR81, FCColor::rgb(219, 68, 83)); //1
        m_userColors.put(USERCOLOR82, FCColor::rgba(16, 95, 205, 100));
        m_userColors.put(USERCOLOR83, FCColor::rgb(107, 107, 107));
        m_userColors.put(USERCOLOR84, FCColor::rgb(233, 233, 233));
        m_userColors.put(USERCOLOR85, FCColor::rgb(70, 76, 79));
        m_userColors.put(USERCOLOR86, FCColor::rgba(219, 68, 83, 100)); //1
        m_userColors.put(USERCOLOR87, FCColor::rgb(39, 41, 46));
         m_userColors.put(USERCOLOR88, FCColor::rgb(184, 185, 186));
        m_userColors.put(USERCOLOR89, FCColor::rgb(150, 150, 150));
        m_userColors.put(USERCOLOR90, FCColor::rgb(255, 255, 80));
        m_userColors.put(USERCOLOR91, FCColor::rgba(219, 68, 83, 200)); //1
        m_userColors.put(USERCOLOR92, FCColor::rgba(219, 68, 83, 50));//1
        m_userColors.put(USERCOLOR93, FCColor::rgba(50, 50, 50, 25));
        m_userColors.put(USERCOLOR94, FCColor::rgba(219, 68, 83, 200)); //1
        m_userColors.put(USERCOLOR95, FCColor::rgba(219, 68, 83, 100)); //1
        m_userColors.put(USERCOLOR96, FCColor::rgb(150, 0, 0));
        m_userColors.put(USERCOLOR97, FCColor::rgb(80, 255, 255));
        m_userColors.put(USERCOLOR98, FCColor::rgb(217, 217, 68));
        m_userColors.put(USERCOLOR99, FCColor::rgb(112, 112, 112));
        m_userColors.put(USERCOLOR100, FCColor::rgb(192, 192, 192));
        m_userColors.put(USERCOLOR101, FCColor::rgb(255, 255, 0));
        m_userColors.put(USERCOLOR102, FCColor::rgba(0, 0, 0, 200));
        m_userColors.put(USERCOLOR103, FCColor::rgba(43, 138, 195, 240));
        m_userColors.put(USERCOLOR104, FCColor::rgba(21, 24, 28, 240));
        m_userColors.put(USERCOLOR105, FCColor::rgba(255, 255, 255, 12));
        m_userColors.put(USERCOLOR106, FCColor::rgb(222, 86, 122));
        m_userColors.put(USERCOLOR107, FCColor::rgb(115, 183, 72));
        m_userColors.put(USERCOLOR108, FCColor::rgba(219, 68, 83, 200));
        m_userColors.put(USERCOLOR109, FCColor::rgba(140, 192, 81, 200));
        m_userColors.put(USERCOLOR110, FCColor::rgb(219, 68, 83));
        m_userColors.put(USERCOLOR111, FCColor::rgba(32, 36, 38, 100));
        m_userColors.put(USERCOLOR112, FCColor::rgba(42, 138, 195, 230));
        m_userColors.put(USERCOLOR113, FCColor::rgba(15, 193, 118, 50));
        m_userColors.put(USERCOLOR114, FCColor::rgba(248, 73, 96, 50));
        m_userColors.put(USERCOLOR115, FCColor::rgba(170, 178, 189, 25));
        m_userColors.put(USERCOLOR116, FCColor::rgb(217, 218, 223));
        m_userColors.put(USERCOLOR117, FCColor::rgb(167, 171, 184));
        m_userColors.put(FCColor_Back, FCColor::rgb(19, 21, 26));
        m_userColors.put(FCColor_Border, FCColor::rgb(50, 50, 50));
        m_userColors.put(FCColor_Text, FCColor::rgb(255, 255, 255));
        m_userColors.put(FCColor_DisabledBack, FCColor::rgba(255, 255, 255, 25));
        m_userColors.put(FCColor_DisabledText, 3289650);
        m_userColors.put(FCColor_Hovered, FCColor::rgba(219, 68, 83, 150)); //1
        m_userColors.put(FCColor_Pushed, FCColor::rgba(219, 68, 83, 100)); //1
    }
    else if (m_style == 3)
    {
        m_userColors.put(USERCOLOR, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR1, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR2, FCColor::rgba(255, 255, 255, 100));
        m_userColors.put(USERCOLOR3, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR4, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR5, FCColor::rgb(15, 193, 118)); //1
        m_userColors.put(USERCOLOR6, FCColor::rgba(255, 255, 255, 25));
        m_userColors.put(USERCOLOR7, FCColor::rgb(19, 21, 26));
        m_userColors.put(USERCOLOR8, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR9, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR10, FCColor::rgb(15, 193, 118)); //1
        m_userColors.put(USERCOLOR11, FCColor::rgba(255, 255, 255, 200));
        m_userColors.put(USERCOLOR12, FCColor::rgb(19, 21, 26));
        m_userColors.put(USERCOLOR13, FCColor::rgba(50, 50, 50, 240));
        m_userColors.put(USERCOLOR14, FCColor::rgba(50, 50, 50, 100));
        m_userColors.put(USERCOLOR15, FCColor::rgb(46, 47, 49));
        m_userColors.put(USERCOLOR16, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR17, FCColor::rgb(100, 100, 100));
        m_userColors.put(USERCOLOR18, FCColor::rgba(255, 255, 255, 5));
        m_userColors.put(USERCOLOR19, FCColor::rgba(255, 255, 255, 50));
        m_userColors.put(USERCOLOR20, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR21, FCColor::rgba(15, 193, 118, 100)); //1
        m_userColors.put(USERCOLOR22, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR23, FCColor::rgba(15, 193, 118, 100)); //1
        m_userColors.put(USERCOLOR24, FCColor::rgb(100, 100, 100));
        m_userColors.put(USERCOLOR25, FCColor::rgb(255, 82, 82));
        m_userColors.put(USERCOLOR26, FCColor::rgb(50, 105, 217));
        m_userColors.put(USERCOLOR27, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR28, FCColor::rgb(200, 200, 200));
        m_userColors.put(USERCOLOR29, FCColor::rgb(80, 80, 80));
        m_userColors.put(USERCOLOR30, FCColor::rgb(25, 25, 25));
        m_userColors.put(USERCOLOR31, FCColor::rgb(255, 0, 0));
        m_userColors.put(USERCOLOR32, FCColor::rgb(139, 180, 248));
        m_userColors.put(USERCOLOR33, FCColor::rgb(0, 165, 137));
        m_userColors.put(USERCOLOR34, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR35, FCColor::rgba(100, 100, 100, 200));
        m_userColors.put(USERCOLOR36, FCColor::rgba(15, 193, 118, 200)); //1
        m_userColors.put(USERCOLOR37, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR38, FCColor::rgba(43, 138, 195, 25));
        m_userColors.put(USERCOLOR39, FCColor::rgba(51, 153, 255, 75));
        m_userColors.put(USERCOLOR40, FCColor::rgb(0, 200, 0));
        m_userColors.put(USERCOLOR41, FCColor::rgba(0, 0, 0, 10));
        m_userColors.put(USERCOLOR42, FCColor::rgba(50, 50, 50, 50));
        m_userColors.put(USERCOLOR43, FCColor::rgb(0, 105, 217));
        m_userColors.put(USERCOLOR44, FCColor::rgba(255, 255, 255, 150));
        m_userColors.put(USERCOLOR45, FCColor::rgba(255, 0, 0, 200));
        m_userColors.put(USERCOLOR46, FCColor::rgba(170, 178, 189, 50));
        m_userColors.put(USERCOLOR47, FCColor::rgba(170, 178, 189, 200));
        m_userColors.put(USERCOLOR48, FCColor::rgb(219, 68, 83));
        m_userColors.put(USERCOLOR49, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR50, FCColor::rgb(246, 187, 67));
        m_userColors.put(USERCOLOR51, FCColor::rgb(59, 174, 218));
        m_userColors.put(USERCOLOR52, FCColor::rgb(216, 112, 173));
        m_userColors.put(USERCOLOR53, FCColor::rgb(140, 192, 81));
        m_userColors.put(USERCOLOR54, FCColor::rgb(80, 255, 80));
        m_userColors.put(USERCOLOR55, FCColor::rgba(255, 80, 80, 200));
        m_userColors.put(USERCOLOR56, FCColor::rgba(50, 50, 50, 150));
        m_userColors.put(USERCOLOR57, FCColor::rgba(0, 105, 217, 240));
        m_userColors.put(USERCOLOR58, FCColor::rgba(0, 0, 0, 25));
        m_userColors.put(USERCOLOR59, FCColor::rgb(255, 215, 0));
        m_userColors.put(USERCOLOR60, FCColor::rgb(150, 150, 150));
        m_userColors.put(USERCOLOR61, FCColor::rgba(0, 0, 0, 200));
        m_userColors.put(USERCOLOR62, FCColor::rgba(15, 193, 118, 50)); //1
        m_userColors.put(USERCOLOR63, FCColor::rgb(10, 36, 106));
        m_userColors.put(USERCOLOR64, FCColor::rgb(21, 24, 28));
        m_userColors.put(USERCOLOR65, FCColor::rgba(0, 0, 0, 100));
        m_userColors.put(USERCOLOR66, FCColor::rgba(0, 0, 0, 50));
        m_userColors.put(USERCOLOR67, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR68, FCColor::rgba(15, 193, 118, 200)); //1
        m_userColors.put(USERCOLOR69, FCColor::rgb(248, 73, 96));
        m_userColors.put(USERCOLOR70, FCColor::rgb(15, 193, 118));
        m_userColors.put(USERCOLOR71, FCColor::rgba(248, 73, 96, 150));
        m_userColors.put(USERCOLOR72, FCColor::rgba(15, 193, 118, 150));
        m_userColors.put(USERCOLOR73, FCColor::rgb(130, 140, 150));
        m_userColors.put(USERCOLOR74, FCColor::rgba(15, 193, 118, 200)); //1
        m_userColors.put(USERCOLOR75, FCColor::rgb(83, 195, 42));
        m_userColors.put(USERCOLOR76, FCColor::rgb(231, 192, 42));
        m_userColors.put(USERCOLOR77, FCColor::rgb(254, 89, 82));
        m_userColors.put(USERCOLOR78, FCColor::rgba(42, 138, 195, 100));
        m_userColors.put(USERCOLOR79, FCColor::rgb(15, 193, 118));; //1
        m_userColors.put(USERCOLOR80, FCColor::rgba(52, 53, 58, 150));
        m_userColors.put(USERCOLOR81, FCColor::rgb(15, 193, 118)); //1
        m_userColors.put(USERCOLOR82, FCColor::rgba(16, 95, 205, 100));
        m_userColors.put(USERCOLOR83, FCColor::rgb(107, 107, 107));
        m_userColors.put(USERCOLOR84, FCColor::rgb(233, 233, 233));
        m_userColors.put(USERCOLOR85, FCColor::rgb(70, 76, 79));
        m_userColors.put(USERCOLOR86, FCColor::rgba(15, 193, 118, 100)); //1
        m_userColors.put(USERCOLOR87, FCColor::rgb(39, 41, 46));
         m_userColors.put(USERCOLOR88, FCColor::rgb(184, 185, 186));
        m_userColors.put(USERCOLOR89, FCColor::rgb(150, 150, 150));
        m_userColors.put(USERCOLOR90, FCColor::rgb(255, 255, 80));
        m_userColors.put(USERCOLOR91, FCColor::rgba(15, 193, 118, 200)); //1
        m_userColors.put(USERCOLOR92, FCColor::rgba(15, 193, 118, 50));//1
        m_userColors.put(USERCOLOR93, FCColor::rgba(50, 50, 50, 25));
        m_userColors.put(USERCOLOR94, FCColor::rgba(15, 193, 118, 200)); //1
        m_userColors.put(USERCOLOR95, FCColor::rgba(15, 193, 118, 100)); //1
        m_userColors.put(USERCOLOR96, FCColor::rgb(150, 0, 0));
        m_userColors.put(USERCOLOR97, FCColor::rgb(80, 255, 255));
        m_userColors.put(USERCOLOR98, FCColor::rgb(217, 217, 68));
        m_userColors.put(USERCOLOR99, FCColor::rgb(112, 112, 112));
        m_userColors.put(USERCOLOR100, FCColor::rgb(192, 192, 192));
        m_userColors.put(USERCOLOR101, FCColor::rgb(255, 255, 0));
        m_userColors.put(USERCOLOR102, FCColor::rgba(0, 0, 0, 200));
        m_userColors.put(USERCOLOR103, FCColor::rgba(43, 138, 195, 240));
        m_userColors.put(USERCOLOR104, FCColor::rgba(21, 24, 28, 240));
        m_userColors.put(USERCOLOR105, FCColor::rgba(255, 255, 255, 12));
        m_userColors.put(USERCOLOR106, FCColor::rgb(222, 86, 122));
        m_userColors.put(USERCOLOR107, FCColor::rgb(115, 183, 72));
        m_userColors.put(USERCOLOR108, FCColor::rgba(219, 68, 83, 200));
        m_userColors.put(USERCOLOR109, FCColor::rgba(140, 192, 81, 200));
        m_userColors.put(USERCOLOR110, FCColor::rgb(15, 193, 118));
        m_userColors.put(USERCOLOR111, FCColor::rgba(32, 36, 38, 100));
        m_userColors.put(USERCOLOR112, FCColor::rgba(42, 138, 195, 230));
        m_userColors.put(USERCOLOR113, FCColor::rgba(15, 193, 118, 50));
        m_userColors.put(USERCOLOR114, FCColor::rgba(248, 73, 96, 50));
        m_userColors.put(USERCOLOR115, FCColor::rgba(170, 178, 189, 25));
        m_userColors.put(USERCOLOR116, FCColor::rgb(217, 218, 223));
        m_userColors.put(USERCOLOR117, FCColor::rgb(167, 171, 184));
        m_userColors.put(FCColor_Back, FCColor::rgb(19, 21, 26));
        m_userColors.put(FCColor_Border, FCColor::rgb(50, 50, 50));
        m_userColors.put(FCColor_Text, FCColor::rgb(255, 255, 255));
        m_userColors.put(FCColor_DisabledBack, FCColor::rgba(255, 255, 255, 25));
        m_userColors.put(FCColor_DisabledText, 3289650);
        m_userColors.put(FCColor_Hovered, FCColor::rgba(15, 193, 118, 150)); //1
        m_userColors.put(FCColor_Pushed, FCColor::rgba(15, 193, 118, 100)); //1
    }
    else if (m_style == 4)
    {
        m_userColors.put(USERCOLOR, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR1, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR2, FCColor::rgba(255, 255, 255, 100));
        m_userColors.put(USERCOLOR3, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR4, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR5, FCColor::rgb(185, 63, 150)); //1
        m_userColors.put(USERCOLOR6, FCColor::rgba(255, 255, 255, 25));
        m_userColors.put(USERCOLOR7, FCColor::rgb(19, 21, 26));
        m_userColors.put(USERCOLOR8, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR9, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR10, FCColor::rgb(185, 63, 150)); //1
        m_userColors.put(USERCOLOR11, FCColor::rgba(255, 255, 255, 200));
        m_userColors.put(USERCOLOR12, FCColor::rgb(19, 21, 26));
        m_userColors.put(USERCOLOR13, FCColor::rgba(50, 50, 50, 240));
        m_userColors.put(USERCOLOR14, FCColor::rgba(50, 50, 50, 100));
        m_userColors.put(USERCOLOR15, FCColor::rgb(46, 47, 49));
        m_userColors.put(USERCOLOR16, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR17, FCColor::rgb(100, 100, 100));
        m_userColors.put(USERCOLOR18, FCColor::rgba(255, 255, 255, 5));
        m_userColors.put(USERCOLOR19, FCColor::rgba(255, 255, 255, 50));
        m_userColors.put(USERCOLOR20, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR21, FCColor::rgba(185, 63, 150, 100)); //1
        m_userColors.put(USERCOLOR22, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR23, FCColor::rgba(185, 63, 150, 100)); //1
        m_userColors.put(USERCOLOR24, FCColor::rgb(100, 100, 100));
        m_userColors.put(USERCOLOR25, FCColor::rgb(255, 82, 82));
        m_userColors.put(USERCOLOR26, FCColor::rgb(50, 105, 217));
        m_userColors.put(USERCOLOR27, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR28, FCColor::rgb(200, 200, 200));
        m_userColors.put(USERCOLOR29, FCColor::rgb(80, 80, 80));
        m_userColors.put(USERCOLOR30, FCColor::rgb(25, 25, 25));
        m_userColors.put(USERCOLOR31, FCColor::rgb(255, 0, 0));
        m_userColors.put(USERCOLOR32, FCColor::rgb(139, 180, 248));
        m_userColors.put(USERCOLOR33, FCColor::rgb(0, 165, 137));
        m_userColors.put(USERCOLOR34, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR35, FCColor::rgba(100, 100, 100, 200));
        m_userColors.put(USERCOLOR36, FCColor::rgba(185, 63, 150, 200)); //1
        m_userColors.put(USERCOLOR37, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR38, FCColor::rgba(43, 138, 195, 25));
        m_userColors.put(USERCOLOR39, FCColor::rgba(51, 153, 255, 75));
        m_userColors.put(USERCOLOR40, FCColor::rgb(0, 200, 0));
        m_userColors.put(USERCOLOR41, FCColor::rgba(0, 0, 0, 10));
        m_userColors.put(USERCOLOR42, FCColor::rgba(50, 50, 50, 50));
        m_userColors.put(USERCOLOR43, FCColor::rgb(0, 105, 217));
        m_userColors.put(USERCOLOR44, FCColor::rgba(255, 255, 255, 150));
        m_userColors.put(USERCOLOR45, FCColor::rgba(255, 0, 0, 200));
        m_userColors.put(USERCOLOR46, FCColor::rgba(170, 178, 189, 50));
        m_userColors.put(USERCOLOR47, FCColor::rgba(170, 178, 189, 200));
        m_userColors.put(USERCOLOR48, FCColor::rgb(219, 68, 83));
        m_userColors.put(USERCOLOR49, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR50, FCColor::rgb(246, 187, 67));
        m_userColors.put(USERCOLOR51, FCColor::rgb(59, 174, 218));
        m_userColors.put(USERCOLOR52, FCColor::rgb(216, 112, 173));
        m_userColors.put(USERCOLOR53, FCColor::rgb(140, 192, 81));
        m_userColors.put(USERCOLOR54, FCColor::rgb(80, 255, 80));
        m_userColors.put(USERCOLOR55, FCColor::rgba(255, 80, 80, 200));
        m_userColors.put(USERCOLOR56, FCColor::rgba(50, 50, 50, 150));
        m_userColors.put(USERCOLOR57, FCColor::rgba(0, 105, 217, 240));
        m_userColors.put(USERCOLOR58, FCColor::rgba(0, 0, 0, 25));
        m_userColors.put(USERCOLOR59, FCColor::rgb(255, 215, 0));
        m_userColors.put(USERCOLOR60, FCColor::rgb(150, 150, 150));
        m_userColors.put(USERCOLOR61, FCColor::rgba(0, 0, 0, 200));
        m_userColors.put(USERCOLOR62, FCColor::rgba(185, 63, 150, 50)); //1
        m_userColors.put(USERCOLOR63, FCColor::rgb(10, 36, 106));
        m_userColors.put(USERCOLOR64, FCColor::rgb(21, 24, 28));
        m_userColors.put(USERCOLOR65, FCColor::rgba(0, 0, 0, 100));
        m_userColors.put(USERCOLOR66, FCColor::rgba(0, 0, 0, 50));
        m_userColors.put(USERCOLOR67, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR68, FCColor::rgba(185, 63, 150, 200)); //1
        m_userColors.put(USERCOLOR69, FCColor::rgb(248, 73, 96));
        m_userColors.put(USERCOLOR70, FCColor::rgb(15, 193, 118));
        m_userColors.put(USERCOLOR71, FCColor::rgba(248, 73, 96, 150));
        m_userColors.put(USERCOLOR72, FCColor::rgba(15, 193, 118, 150));
        m_userColors.put(USERCOLOR73, FCColor::rgb(130, 140, 150));
        m_userColors.put(USERCOLOR74, FCColor::rgba(185, 63, 150, 200)); //1
        m_userColors.put(USERCOLOR75, FCColor::rgb(83, 195, 42));
        m_userColors.put(USERCOLOR76, FCColor::rgb(231, 192, 42));
        m_userColors.put(USERCOLOR77, FCColor::rgb(254, 89, 82));
        m_userColors.put(USERCOLOR78, FCColor::rgba(42, 138, 195, 100));
        m_userColors.put(USERCOLOR79, FCColor::rgb(185, 63, 150));; //1
        m_userColors.put(USERCOLOR80, FCColor::rgba(52, 53, 58, 150));
        m_userColors.put(USERCOLOR81, FCColor::rgb(185, 63, 150)); //1
        m_userColors.put(USERCOLOR82, FCColor::rgba(16, 95, 205, 100));
        m_userColors.put(USERCOLOR83, FCColor::rgb(107, 107, 107));
        m_userColors.put(USERCOLOR84, FCColor::rgb(233, 233, 233));
        m_userColors.put(USERCOLOR85, FCColor::rgb(70, 76, 79));
        m_userColors.put(USERCOLOR86, FCColor::rgba(185, 63, 150, 100)); //1
        m_userColors.put(USERCOLOR87, FCColor::rgb(39, 41, 46));
         m_userColors.put(USERCOLOR88, FCColor::rgb(184, 185, 186));
        m_userColors.put(USERCOLOR89, FCColor::rgb(150, 150, 150));
        m_userColors.put(USERCOLOR90, FCColor::rgb(255, 255, 80));
        m_userColors.put(USERCOLOR91, FCColor::rgba(185, 63, 150, 200)); //1
        m_userColors.put(USERCOLOR92, FCColor::rgba(185, 63, 150, 50));//1
        m_userColors.put(USERCOLOR93, FCColor::rgba(50, 50, 50, 25));
        m_userColors.put(USERCOLOR94, FCColor::rgba(185, 63, 150, 200)); //1
        m_userColors.put(USERCOLOR95, FCColor::rgba(185, 63, 150, 100)); //1
        m_userColors.put(USERCOLOR96, FCColor::rgb(150, 0, 0));
        m_userColors.put(USERCOLOR97, FCColor::rgb(80, 255, 255));
        m_userColors.put(USERCOLOR98, FCColor::rgb(217, 217, 68));
        m_userColors.put(USERCOLOR99, FCColor::rgb(112, 112, 112));
        m_userColors.put(USERCOLOR100, FCColor::rgb(192, 192, 192));
        m_userColors.put(USERCOLOR101, FCColor::rgb(255, 255, 0));
        m_userColors.put(USERCOLOR102, FCColor::rgba(0, 0, 0, 200));
        m_userColors.put(USERCOLOR103, FCColor::rgba(43, 138, 195, 240));
        m_userColors.put(USERCOLOR104, FCColor::rgba(21, 24, 28, 240));
        m_userColors.put(USERCOLOR105, FCColor::rgba(255, 255, 255, 12));
        m_userColors.put(USERCOLOR106, FCColor::rgb(222, 86, 122));
        m_userColors.put(USERCOLOR107, FCColor::rgb(115, 183, 72));
        m_userColors.put(USERCOLOR108, FCColor::rgba(219, 68, 83, 200));
        m_userColors.put(USERCOLOR109, FCColor::rgba(140, 192, 81, 200));
        m_userColors.put(USERCOLOR110, FCColor::rgb(216, 112, 173));
        m_userColors.put(USERCOLOR111, FCColor::rgba(32, 36, 38, 100));
        m_userColors.put(USERCOLOR112, FCColor::rgba(42, 138, 195, 230));
        m_userColors.put(USERCOLOR113, FCColor::rgba(15, 193, 118, 50));
        m_userColors.put(USERCOLOR114, FCColor::rgba(248, 73, 96, 50));
        m_userColors.put(USERCOLOR115, FCColor::rgba(170, 178, 189, 25));
        m_userColors.put(USERCOLOR116, FCColor::rgb(217, 218, 223));
        m_userColors.put(USERCOLOR117, FCColor::rgb(167, 171, 184));
        m_userColors.put(FCColor_Back, FCColor::rgb(19, 21, 26));
        m_userColors.put(FCColor_Border, FCColor::rgb(50, 50, 50));
        m_userColors.put(FCColor_Text, FCColor::rgb(255, 255, 255));
        m_userColors.put(FCColor_DisabledBack, FCColor::rgba(255, 255, 255, 25));
        m_userColors.put(FCColor_DisabledText, 3289650);
        m_userColors.put(FCColor_Hovered, FCColor::rgba(185, 63, 150, 150)); //1
        m_userColors.put(FCColor_Pushed, FCColor::rgba(185, 63, 150, 100)); //1
    }
    else if (m_style == 5)
    {
        m_userColors.put(USERCOLOR, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR1, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR2, FCColor::rgba(255, 255, 255, 100));
        m_userColors.put(USERCOLOR3, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR4, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR5, FCColor::rgb(75, 137, 220)); //1
        m_userColors.put(USERCOLOR6, FCColor::rgba(255, 255, 255, 25));
        m_userColors.put(USERCOLOR7, FCColor::rgb(19, 21, 26));
        m_userColors.put(USERCOLOR8, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR9, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR10, FCColor::rgb(75, 137, 220)); //1
        m_userColors.put(USERCOLOR11, FCColor::rgba(255, 255, 255, 200));
        m_userColors.put(USERCOLOR12, FCColor::rgb(19, 21, 26));
        m_userColors.put(USERCOLOR13, FCColor::rgba(50, 50, 50, 240));
        m_userColors.put(USERCOLOR14, FCColor::rgba(50, 50, 50, 100));
        m_userColors.put(USERCOLOR15, FCColor::rgb(46, 47, 49));
        m_userColors.put(USERCOLOR16, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR17, FCColor::rgb(100, 100, 100));
        m_userColors.put(USERCOLOR18, FCColor::rgba(255, 255, 255, 5));
        m_userColors.put(USERCOLOR19, FCColor::rgba(255, 255, 255, 50));
        m_userColors.put(USERCOLOR20, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR21, FCColor::rgba(75, 137, 220, 100)); //1
        m_userColors.put(USERCOLOR22, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR23, FCColor::rgba(75, 137, 220, 100)); //1
        m_userColors.put(USERCOLOR24, FCColor::rgb(100, 100, 100));
        m_userColors.put(USERCOLOR25, FCColor::rgb(255, 82, 82));
        m_userColors.put(USERCOLOR26, FCColor::rgb(50, 105, 217));
        m_userColors.put(USERCOLOR27, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR28, FCColor::rgb(200, 200, 200));
        m_userColors.put(USERCOLOR29, FCColor::rgb(80, 80, 80));
        m_userColors.put(USERCOLOR30, FCColor::rgb(25, 25, 25));
        m_userColors.put(USERCOLOR31, FCColor::rgb(255, 0, 0));
        m_userColors.put(USERCOLOR32, FCColor::rgb(139, 180, 248));
        m_userColors.put(USERCOLOR33, FCColor::rgb(0, 165, 137));
        m_userColors.put(USERCOLOR34, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR35, FCColor::rgba(100, 100, 100, 200));
        m_userColors.put(USERCOLOR36, FCColor::rgba(75, 137, 220, 200)); //1
        m_userColors.put(USERCOLOR37, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR38, FCColor::rgba(43, 138, 195, 25));
        m_userColors.put(USERCOLOR39, FCColor::rgba(51, 153, 255, 75));
        m_userColors.put(USERCOLOR40, FCColor::rgb(0, 200, 0));
        m_userColors.put(USERCOLOR41, FCColor::rgba(0, 0, 0, 10));
        m_userColors.put(USERCOLOR42, FCColor::rgba(50, 50, 50, 50));
        m_userColors.put(USERCOLOR43, FCColor::rgb(0, 105, 217));
        m_userColors.put(USERCOLOR44, FCColor::rgba(255, 255, 255, 150));
        m_userColors.put(USERCOLOR45, FCColor::rgba(255, 0, 0, 200));
        m_userColors.put(USERCOLOR46, FCColor::rgba(170, 178, 189, 50));
        m_userColors.put(USERCOLOR47, FCColor::rgba(170, 178, 189, 200));
        m_userColors.put(USERCOLOR48, FCColor::rgb(219, 68, 83));
        m_userColors.put(USERCOLOR49, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR50, FCColor::rgb(246, 187, 67));
        m_userColors.put(USERCOLOR51, FCColor::rgb(59, 174, 218));
        m_userColors.put(USERCOLOR52, FCColor::rgb(216, 112, 173));
        m_userColors.put(USERCOLOR53, FCColor::rgb(140, 192, 81));
        m_userColors.put(USERCOLOR54, FCColor::rgb(80, 255, 80));
        m_userColors.put(USERCOLOR55, FCColor::rgba(255, 80, 80, 200));
        m_userColors.put(USERCOLOR56, FCColor::rgba(50, 50, 50, 150));
        m_userColors.put(USERCOLOR57, FCColor::rgba(0, 105, 217, 240));
        m_userColors.put(USERCOLOR58, FCColor::rgba(0, 0, 0, 25));
        m_userColors.put(USERCOLOR59, FCColor::rgb(255, 215, 0));
        m_userColors.put(USERCOLOR60, FCColor::rgb(150, 150, 150));
        m_userColors.put(USERCOLOR61, FCColor::rgba(0, 0, 0, 200));
        m_userColors.put(USERCOLOR62, FCColor::rgba(75, 137, 220, 50)); //1
        m_userColors.put(USERCOLOR63, FCColor::rgb(10, 36, 106));
        m_userColors.put(USERCOLOR64, FCColor::rgb(21, 24, 28));
        m_userColors.put(USERCOLOR65, FCColor::rgba(0, 0, 0, 100));
        m_userColors.put(USERCOLOR66, FCColor::rgba(0, 0, 0, 50));
        m_userColors.put(USERCOLOR67, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR68, FCColor::rgba(75, 137, 220, 200)); //1
        m_userColors.put(USERCOLOR69, FCColor::rgb(248, 73, 96));
        m_userColors.put(USERCOLOR70, FCColor::rgb(15, 193, 118));
        m_userColors.put(USERCOLOR71, FCColor::rgba(248, 73, 96, 150));
        m_userColors.put(USERCOLOR72, FCColor::rgba(15, 193, 118, 150));
        m_userColors.put(USERCOLOR73, FCColor::rgb(130, 140, 150));
        m_userColors.put(USERCOLOR74, FCColor::rgba(75, 137, 220, 200)); //1
        m_userColors.put(USERCOLOR75, FCColor::rgb(83, 195, 42));
        m_userColors.put(USERCOLOR76, FCColor::rgb(231, 192, 42));
        m_userColors.put(USERCOLOR77, FCColor::rgb(254, 89, 82));
        m_userColors.put(USERCOLOR78, FCColor::rgba(42, 138, 195, 100));
        m_userColors.put(USERCOLOR79, FCColor::rgb(75, 137, 220));; //1
        m_userColors.put(USERCOLOR80, FCColor::rgba(52, 53, 58, 150));
        m_userColors.put(USERCOLOR81, FCColor::rgb(75, 137, 220)); //1
        m_userColors.put(USERCOLOR82, FCColor::rgba(16, 95, 205, 100));
        m_userColors.put(USERCOLOR83, FCColor::rgb(107, 107, 107));
        m_userColors.put(USERCOLOR84, FCColor::rgb(233, 233, 233));
        m_userColors.put(USERCOLOR85, FCColor::rgb(70, 76, 79));
        m_userColors.put(USERCOLOR86, FCColor::rgba(75, 137, 220, 100)); //1
        m_userColors.put(USERCOLOR87, FCColor::rgb(39, 41, 46));
         m_userColors.put(USERCOLOR88, FCColor::rgb(184, 185, 186));
        m_userColors.put(USERCOLOR89, FCColor::rgb(150, 150, 150));
        m_userColors.put(USERCOLOR90, FCColor::rgb(255, 255, 80));
        m_userColors.put(USERCOLOR91, FCColor::rgba(75, 137, 220, 200)); //1
        m_userColors.put(USERCOLOR92, FCColor::rgba(75, 137, 220, 50));//1
        m_userColors.put(USERCOLOR93, FCColor::rgba(50, 50, 50, 25));
        m_userColors.put(USERCOLOR94, FCColor::rgba(75, 137, 220, 200)); //1
        m_userColors.put(USERCOLOR95, FCColor::rgba(75, 137, 220, 100)); //1
        m_userColors.put(USERCOLOR96, FCColor::rgb(150, 0, 0));
        m_userColors.put(USERCOLOR97, FCColor::rgb(80, 255, 255));
        m_userColors.put(USERCOLOR98, FCColor::rgb(217, 217, 68));
        m_userColors.put(USERCOLOR99, FCColor::rgb(112, 112, 112));
        m_userColors.put(USERCOLOR100, FCColor::rgb(192, 192, 192));
        m_userColors.put(USERCOLOR101, FCColor::rgb(255, 255, 0));
        m_userColors.put(USERCOLOR102, FCColor::rgba(0, 0, 0, 200));
        m_userColors.put(USERCOLOR103, FCColor::rgba(43, 138, 195, 240));
        m_userColors.put(USERCOLOR104, FCColor::rgba(21, 24, 28, 240));
        m_userColors.put(USERCOLOR105, FCColor::rgba(255, 255, 255, 12));
        m_userColors.put(USERCOLOR106, FCColor::rgb(222, 86, 122));
        m_userColors.put(USERCOLOR107, FCColor::rgb(115, 183, 72));
        m_userColors.put(USERCOLOR108, FCColor::rgba(219, 68, 83, 200));
        m_userColors.put(USERCOLOR109, FCColor::rgba(140, 192, 81, 200));
        m_userColors.put(USERCOLOR110, FCColor::rgb(75, 137, 220));
        m_userColors.put(USERCOLOR111, FCColor::rgba(32, 36, 38, 100));
        m_userColors.put(USERCOLOR112, FCColor::rgba(42, 138, 195, 230));
        m_userColors.put(USERCOLOR113, FCColor::rgba(15, 193, 118, 50));
        m_userColors.put(USERCOLOR114, FCColor::rgba(248, 73, 96, 50));
        m_userColors.put(USERCOLOR115, FCColor::rgba(170, 178, 189, 25));
        m_userColors.put(USERCOLOR116, FCColor::rgb(217, 218, 223));
        m_userColors.put(USERCOLOR117, FCColor::rgb(167, 171, 184));
        m_userColors.put(FCColor_Back, FCColor::rgb(19, 21, 26));
        m_userColors.put(FCColor_Border, FCColor::rgb(50, 50, 50));
        m_userColors.put(FCColor_Text, FCColor::rgb(255, 255, 255));
        m_userColors.put(FCColor_DisabledBack, FCColor::rgba(255, 255, 255, 25));
        m_userColors.put(FCColor_DisabledText, 3289650);
        m_userColors.put(FCColor_Hovered, FCColor::rgba(75, 137, 220, 150)); //1
        m_userColors.put(FCColor_Pushed, FCColor::rgba(75, 137, 220, 100)); //1
    }
    else if (m_style == 6)
    {
        m_userColors.put(USERCOLOR, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR1, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR2, FCColor::rgba(255, 255, 255, 100));
        m_userColors.put(USERCOLOR3, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR4, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR5, FCColor::rgb(255, 215, 0)); //1
        m_userColors.put(USERCOLOR6, FCColor::rgba(255, 255, 255, 25));
        m_userColors.put(USERCOLOR7, FCColor::rgb(19, 21, 26));
        m_userColors.put(USERCOLOR8, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR9, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR10, FCColor::rgba(255, 215, 0, 200)); //1
        m_userColors.put(USERCOLOR11, FCColor::rgba(255, 255, 255, 200));
        m_userColors.put(USERCOLOR12, FCColor::rgb(19, 21, 26));
        m_userColors.put(USERCOLOR13, FCColor::rgba(50, 50, 50, 240));
        m_userColors.put(USERCOLOR14, FCColor::rgba(50, 50, 50, 100));
        m_userColors.put(USERCOLOR15, FCColor::rgb(46, 47, 49));;
        m_userColors.put(USERCOLOR16, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR17, FCColor::rgb(100, 100, 100));
        m_userColors.put(USERCOLOR18, FCColor::rgba(255, 255, 255, 5));
        m_userColors.put(USERCOLOR19, FCColor::rgba(255, 255, 255, 50));
        m_userColors.put(USERCOLOR20, FCColor::rgb(200, 200, 200));
        m_userColors.put(USERCOLOR21, FCColor::rgb(75, 75, 75));
        m_userColors.put(USERCOLOR22, FCColor::rgb(170, 178, 189));
        m_userColors.put(USERCOLOR23, FCColor::rgba(255, 215, 0, 100)); //1
        m_userColors.put(USERCOLOR24, FCColor::rgb(100, 100, 100));
        m_userColors.put(USERCOLOR25, FCColor::rgb(255, 82, 82));
        m_userColors.put(USERCOLOR26, FCColor::rgb(50, 105, 217));
        m_userColors.put(USERCOLOR27, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR28, FCColor::rgb(200, 200, 200));
        m_userColors.put(USERCOLOR29, FCColor::rgb(80, 80, 80));
        m_userColors.put(USERCOLOR30, FCColor::rgb(25, 25, 25));
        m_userColors.put(USERCOLOR31, FCColor::rgb(255, 0, 0));
        m_userColors.put(USERCOLOR32, FCColor::rgb(139, 180, 248));
        m_userColors.put(USERCOLOR33, FCColor::rgb(0, 165, 137));
        m_userColors.put(USERCOLOR34, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR35, FCColor::rgba(100, 100, 100, 200));
        m_userColors.put(USERCOLOR36, FCColor::rgba(255, 215, 0, 150)); //1
        m_userColors.put(USERCOLOR37, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR38, FCColor::rgba(255, 215, 0, 25)); //1
        m_userColors.put(USERCOLOR39, FCColor::rgba(51, 153, 255, 75));
        m_userColors.put(USERCOLOR40, FCColor::rgb(0, 200, 0));
        m_userColors.put(USERCOLOR41, FCColor::rgba(0, 0, 0, 10));
        m_userColors.put(USERCOLOR42, FCColor::rgba(50, 50, 50, 50));
        m_userColors.put(USERCOLOR43, FCColor::rgb(0, 105, 217));
        m_userColors.put(USERCOLOR44, FCColor::rgba(255, 255, 255, 150));
        m_userColors.put(USERCOLOR45, FCColor::rgba(255, 0, 0, 200));
        m_userColors.put(USERCOLOR46, FCColor::rgba(170, 178, 189, 50));
        m_userColors.put(USERCOLOR47, FCColor::rgba(170, 178, 189, 200));
        m_userColors.put(USERCOLOR48, FCColor::rgb(219, 68, 83));
        m_userColors.put(USERCOLOR49, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR50, FCColor::rgb(246, 187, 67));
        m_userColors.put(USERCOLOR51, FCColor::rgb(59, 174, 218));
        m_userColors.put(USERCOLOR52, FCColor::rgb(216, 112, 173));
        m_userColors.put(USERCOLOR53, FCColor::rgb(140, 192, 81));
        m_userColors.put(USERCOLOR54, FCColor::rgb(80, 255, 80));
        m_userColors.put(USERCOLOR55, FCColor::rgba(255, 80, 80, 200));
        m_userColors.put(USERCOLOR56, FCColor::rgba(50, 50, 50, 150));
        m_userColors.put(USERCOLOR57, FCColor::rgba(0, 105, 217, 240));
        m_userColors.put(USERCOLOR58, FCColor::rgba(0, 0, 0, 25));
        m_userColors.put(USERCOLOR59, FCColor::rgb(255, 215, 0));
        m_userColors.put(USERCOLOR60, FCColor::rgb(150, 150, 150));
        m_userColors.put(USERCOLOR61, FCColor::rgba(0, 0, 0, 200));
        m_userColors.put(USERCOLOR62, FCColor::rgba(255, 215, 0, 50)); //1
        m_userColors.put(USERCOLOR63, FCColor::rgb(10, 36, 106));
        m_userColors.put(USERCOLOR64, FCColor::rgb(21, 24, 28));
        m_userColors.put(USERCOLOR65, FCColor::rgba(0, 0, 0, 100));
        m_userColors.put(USERCOLOR66, FCColor::rgba(0, 0, 0, 50));
        m_userColors.put(USERCOLOR67, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR68, FCColor::rgb(32, 36, 38));
        m_userColors.put(USERCOLOR69, FCColor::rgb(248, 73, 96));
        m_userColors.put(USERCOLOR70, FCColor::rgb(15, 193, 118));
        m_userColors.put(USERCOLOR71, FCColor::rgba(248, 73, 96, 150));
        m_userColors.put(USERCOLOR72, FCColor::rgba(15, 193, 118, 150));
        m_userColors.put(USERCOLOR73, FCColor::rgb(130, 140, 150));
        m_userColors.put(USERCOLOR74, FCColor::rgba(94, 102, 115, 200));
        m_userColors.put(USERCOLOR75, FCColor::rgb(83, 195, 42));
        m_userColors.put(USERCOLOR76, FCColor::rgb(231, 192, 42));
        m_userColors.put(USERCOLOR77, FCColor::rgb(254, 89, 82));
        m_userColors.put(USERCOLOR78, FCColor::rgba(42, 138, 195, 100));
        m_userColors.put(USERCOLOR79, FCColor::rgb(52, 53, 58));
        m_userColors.put(USERCOLOR80, FCColor::rgba(52, 53, 58, 150));
        m_userColors.put(USERCOLOR81, FCColor::rgb(16, 95, 205));
        m_userColors.put(USERCOLOR82, FCColor::rgba(16, 95, 205, 100));
        m_userColors.put(USERCOLOR83, FCColor::rgb(107, 107, 107));
        m_userColors.put(USERCOLOR84, FCColor::rgb(233, 233, 233));
        m_userColors.put(USERCOLOR85, FCColor::rgb(70, 76, 79));
        m_userColors.put(USERCOLOR86, FCColor::rgb(50, 82, 114));
        m_userColors.put(USERCOLOR87, FCColor::rgb(39, 41, 46));
        m_userColors.put(USERCOLOR88, FCColor::rgb(184, 185, 186));
        m_userColors.put(USERCOLOR89, FCColor::rgb(150, 150, 150));
        m_userColors.put(USERCOLOR90, FCColor::rgb(255, 255, 80));
        m_userColors.put(USERCOLOR91, FCColor::rgba(42, 138, 195, 200));
        m_userColors.put(USERCOLOR92, FCColor::rgba(32, 36, 38, 50));;
        m_userColors.put(USERCOLOR93, FCColor::rgba(50, 50, 50, 25));
        m_userColors.put(USERCOLOR94, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR95, FCColor::rgb(128, 128, 128));
        m_userColors.put(USERCOLOR96, FCColor::rgb(150, 0, 0));
        m_userColors.put(USERCOLOR97, FCColor::rgb(80, 255, 255));
        m_userColors.put(USERCOLOR98, FCColor::rgb(217, 217, 68));
        m_userColors.put(USERCOLOR99, FCColor::rgb(112, 112, 112));
        m_userColors.put(USERCOLOR100, FCColor::rgb(192, 192, 192));
        m_userColors.put(USERCOLOR101, FCColor::rgb(255, 255, 0));
        m_userColors.put(USERCOLOR102, FCColor::rgba(0, 0, 0, 200));
        m_userColors.put(USERCOLOR103, FCColor::rgba(43, 138, 195, 240));
        m_userColors.put(USERCOLOR104, FCColor::rgba(21, 24, 28, 240));
        m_userColors.put(USERCOLOR105, FCColor::rgba(255, 255, 255, 12));
        m_userColors.put(USERCOLOR106, FCColor::rgb(222, 86, 122));
        m_userColors.put(USERCOLOR107, FCColor::rgb(115, 183, 72));
        m_userColors.put(USERCOLOR108, FCColor::rgba(219, 68, 83, 200));
        m_userColors.put(USERCOLOR109, FCColor::rgba(140, 192, 81, 200));
        m_userColors.put(USERCOLOR110, FCColor::rgb(15, 193, 118));
        m_userColors.put(USERCOLOR111, FCColor::rgba(32, 36, 38, 100));
        m_userColors.put(USERCOLOR112, FCColor::rgba(42, 138, 195, 230));
        m_userColors.put(USERCOLOR113, FCColor::rgba(15, 193, 118, 50));
        m_userColors.put(USERCOLOR114, FCColor::rgba(248, 73, 96, 50));
        m_userColors.put(USERCOLOR115, FCColor::rgba(170, 178, 189, 25));
        m_userColors.put(USERCOLOR116, FCColor::rgb(217, 218, 223));
        m_userColors.put(USERCOLOR117, FCColor::rgb(167, 171, 184));
        m_userColors.put(FCColor_Back, FCColor::rgb(19, 21, 26));
        m_userColors.put(FCColor_Border, FCColor::rgb(50, 50, 50));
        m_userColors.put(FCColor_Text, FCColor::rgb(255, 255, 255));
        m_userColors.put(FCColor_DisabledBack, FCColor::rgba(255, 255, 255, 25));
        m_userColors.put(FCColor_DisabledText, 3289650);
        m_userColors.put(FCColor_Hovered, FCColor::rgba(43, 138, 195, 150));
        m_userColors.put(FCColor_Pushed, FCColor::rgba(43, 138, 195, 100));
    }else{
        m_userColors.put(USERCOLOR, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR1, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR2, FCColor::rgba(255, 255, 255, 100));
        m_userColors.put(USERCOLOR3, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR4, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR5, FCColor::rgb(42, 138, 195));
        m_userColors.put(USERCOLOR6, FCColor::rgba(255, 255, 255, 25));
        m_userColors.put(USERCOLOR7, FCColor::rgb(19, 21, 26));
        m_userColors.put(USERCOLOR8, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR9, FCColor::rgb(0, 0, 0));
        m_userColors.put(USERCOLOR10, FCColor::rgb(43, 138, 195));
        m_userColors.put(USERCOLOR11, FCColor::rgba(255, 255, 255, 200));
        m_userColors.put(USERCOLOR12, FCColor::rgb(19, 21, 26));
        m_userColors.put(USERCOLOR13, FCColor::rgba(50, 50, 50, 240));
        m_userColors.put(USERCOLOR14, FCColor::rgba(50, 50, 50, 100));
        m_userColors.put(USERCOLOR15, FCColor::rgb(46, 47, 49));;
        m_userColors.put(USERCOLOR16, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR17, FCColor::rgb(100, 100, 100));
        m_userColors.put(USERCOLOR18, FCColor::rgba(255, 255, 255, 5));
        m_userColors.put(USERCOLOR19, FCColor::rgba(255, 255, 255, 50));
        m_userColors.put(USERCOLOR20, FCColor::rgb(200, 200, 200));
        m_userColors.put(USERCOLOR21, FCColor::rgb(75, 75, 75));
        m_userColors.put(USERCOLOR22, FCColor::rgb(170, 178, 189));
        m_userColors.put(USERCOLOR23, FCColor::rgba(43, 138, 195, 100));
        m_userColors.put(USERCOLOR24, FCColor::rgb(100, 100, 100));
        m_userColors.put(USERCOLOR25, FCColor::rgb(255, 82, 82));
        m_userColors.put(USERCOLOR26, FCColor::rgb(50, 105, 217));
        m_userColors.put(USERCOLOR27, FCColor::rgb(255, 255, 255));
        m_userColors.put(USERCOLOR28, FCColor::rgb(200, 200, 200));
        m_userColors.put(USERCOLOR29, FCColor::rgb(80, 80, 80));
        m_userColors.put(USERCOLOR30, FCColor::rgb(25, 25, 25));
        m_userColors.put(USERCOLOR31, FCColor::rgb(255, 0, 0));
        m_userColors.put(USERCOLOR32, FCColor::rgb(139, 180, 248));
        m_userColors.put(USERCOLOR33, FCColor::rgb(0, 165, 137));
        m_userColors.put(USERCOLOR34, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR35, FCColor::rgba(100, 100, 100, 200));
        m_userColors.put(USERCOLOR36, FCColor::rgba(43, 138, 195, 200));
        m_userColors.put(USERCOLOR37, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR38, FCColor::rgba(43, 138, 195, 25));
        m_userColors.put(USERCOLOR39, FCColor::rgba(51, 153, 255, 75));
        m_userColors.put(USERCOLOR40, FCColor::rgb(0, 200, 0));
        m_userColors.put(USERCOLOR41, FCColor::rgba(0, 0, 0, 10));
        m_userColors.put(USERCOLOR42, FCColor::rgba(50, 50, 50, 50));
        m_userColors.put(USERCOLOR43, FCColor::rgb(0, 105, 217));
        m_userColors.put(USERCOLOR44, FCColor::rgba(255, 255, 255, 150));
        m_userColors.put(USERCOLOR45, FCColor::rgba(255, 0, 0, 200));
        m_userColors.put(USERCOLOR46, FCColor::rgba(170, 178, 189, 50));
        m_userColors.put(USERCOLOR47, FCColor::rgba(170, 178, 189, 200));
        m_userColors.put(USERCOLOR48, FCColor::rgb(219, 68, 83));
        m_userColors.put(USERCOLOR49, FCColor::rgb(255, 80, 80));
        m_userColors.put(USERCOLOR50, FCColor::rgb(246, 187, 67));
        m_userColors.put(USERCOLOR51, FCColor::rgb(59, 174, 218));
        m_userColors.put(USERCOLOR52, FCColor::rgb(216, 112, 173));
        m_userColors.put(USERCOLOR53, FCColor::rgb(140, 192, 81));
        m_userColors.put(USERCOLOR54, FCColor::rgb(80, 255, 80));
        m_userColors.put(USERCOLOR55, FCColor::rgba(255, 80, 80, 200));
        m_userColors.put(USERCOLOR56, FCColor::rgba(50, 50, 50, 150));
        m_userColors.put(USERCOLOR57, FCColor::rgba(0, 105, 217, 240));
        m_userColors.put(USERCOLOR58, FCColor::rgba(0, 0, 0, 25));
        m_userColors.put(USERCOLOR59, FCColor::rgb(255, 215, 0));
        m_userColors.put(USERCOLOR60, FCColor::rgb(150, 150, 150));
        m_userColors.put(USERCOLOR61, FCColor::rgba(0, 0, 0, 200));
        m_userColors.put(USERCOLOR62, FCColor::rgba(43, 138, 195, 50));
        m_userColors.put(USERCOLOR63, FCColor::rgb(10, 36, 106));
        m_userColors.put(USERCOLOR64, FCColor::rgb(21, 24, 28));
        m_userColors.put(USERCOLOR65, FCColor::rgba(0, 0, 0, 100));
        m_userColors.put(USERCOLOR66, FCColor::rgba(0, 0, 0, 50));
        m_userColors.put(USERCOLOR67, FCColor::rgb(230, 230, 230));
        m_userColors.put(USERCOLOR68, FCColor::rgb(32, 36, 38));
        m_userColors.put(USERCOLOR69, FCColor::rgb(248, 73, 96));
        m_userColors.put(USERCOLOR70, FCColor::rgb(15, 193, 118));
        m_userColors.put(USERCOLOR71, FCColor::rgba(248, 73, 96, 150));
        m_userColors.put(USERCOLOR72, FCColor::rgba(15, 193, 118, 150));
        m_userColors.put(USERCOLOR73, FCColor::rgb(130, 140, 150));
        m_userColors.put(USERCOLOR74, FCColor::rgba(94, 102, 115, 200));
        m_userColors.put(USERCOLOR75, FCColor::rgb(83, 195, 42));
        m_userColors.put(USERCOLOR76, FCColor::rgb(231, 192, 42));
        m_userColors.put(USERCOLOR77, FCColor::rgb(254, 89, 82));
        m_userColors.put(USERCOLOR78, FCColor::rgba(42, 138, 195, 100));
        m_userColors.put(USERCOLOR79, FCColor::rgb(52, 53, 58));
        m_userColors.put(USERCOLOR80, FCColor::rgba(52, 53, 58, 150));
        m_userColors.put(USERCOLOR81, FCColor::rgb(16, 95, 205));
        m_userColors.put(USERCOLOR82, FCColor::rgba(16, 95, 205, 100));
        m_userColors.put(USERCOLOR83, FCColor::rgb(107, 107, 107));
        m_userColors.put(USERCOLOR84, FCColor::rgb(233, 233, 233));
        m_userColors.put(USERCOLOR85, FCColor::rgb(70, 76, 79));
        m_userColors.put(USERCOLOR86, FCColor::rgb(50, 82, 114));
        m_userColors.put(USERCOLOR87, FCColor::rgb(39, 41, 46));
        m_userColors.put(USERCOLOR88, FCColor::rgb(184, 185, 186));
        m_userColors.put(USERCOLOR89, FCColor::rgb(150, 150, 150));
        m_userColors.put(USERCOLOR90, FCColor::rgb(255, 255, 80));
        m_userColors.put(USERCOLOR91, FCColor::rgba(42, 138, 195, 200));
        m_userColors.put(USERCOLOR92, FCColor::rgba(32, 36, 38, 50));;
        m_userColors.put(USERCOLOR93, FCColor::rgba(50, 50, 50, 25));
        m_userColors.put(USERCOLOR94, FCColor::rgb(50, 50, 50));
        m_userColors.put(USERCOLOR95, FCColor::rgb(128, 128, 128));
        m_userColors.put(USERCOLOR96, FCColor::rgb(150, 0, 0));
        m_userColors.put(USERCOLOR97, FCColor::rgb(80, 255, 255));
        m_userColors.put(USERCOLOR98, FCColor::rgb(217, 217, 68));
        m_userColors.put(USERCOLOR99, FCColor::rgb(112, 112, 112));
        m_userColors.put(USERCOLOR100, FCColor::rgb(192, 192, 192));
        m_userColors.put(USERCOLOR101, FCColor::rgb(255, 255, 0));
        m_userColors.put(USERCOLOR102, FCColor::rgba(0, 0, 0, 200));
        m_userColors.put(USERCOLOR103, FCColor::rgba(43, 138, 195, 240));
        m_userColors.put(USERCOLOR104, FCColor::rgba(21, 24, 28, 240));
        m_userColors.put(USERCOLOR105, FCColor::rgba(255, 255, 255, 12));
        m_userColors.put(USERCOLOR106, FCColor::rgb(222, 86, 122));
        m_userColors.put(USERCOLOR107, FCColor::rgb(115, 183, 72));
        m_userColors.put(USERCOLOR108, FCColor::rgba(219, 68, 83, 200));
        m_userColors.put(USERCOLOR109, FCColor::rgba(140, 192, 81, 200));
        m_userColors.put(USERCOLOR110, FCColor::rgb(15, 193, 118));
        m_userColors.put(USERCOLOR111, FCColor::rgba(32, 36, 38, 100));
        m_userColors.put(USERCOLOR112, FCColor::rgba(42, 138, 195, 230));
        m_userColors.put(USERCOLOR113, FCColor::rgba(15, 193, 118, 50));
        m_userColors.put(USERCOLOR114, FCColor::rgba(248, 73, 96, 50));
        m_userColors.put(USERCOLOR115, FCColor::rgba(170, 178, 189, 25));
        m_userColors.put(USERCOLOR116, FCColor::rgb(217, 218, 223));
        m_userColors.put(USERCOLOR117, FCColor::rgb(167, 171, 184));
        m_userColors.put(FCColor_Back, FCColor::rgb(19, 21, 26));
        m_userColors.put(FCColor_Border, FCColor::rgb(50, 50, 50));
        m_userColors.put(FCColor_Text, FCColor::rgb(255, 255, 255));
        m_userColors.put(FCColor_DisabledBack, FCColor::rgba(255, 255, 255, 25));
        m_userColors.put(FCColor_DisabledText, 3289650);
        m_userColors.put(FCColor_Hovered, FCColor::rgba(43, 138, 195, 150));
        m_userColors.put(FCColor_Pushed, FCColor::rgba(43, 138, 195, 100));
    }
}

static Long m_hoverdColor = FCColor_None;

Long MyColor::getUserColor(Long color){
    if (m_lastStyle != m_style)
    {
        if(m_lastStyle == -1)
        {
            m_style = 0;
        }
        m_lastStyle = m_style;
       createColors();
    }
    if (m_userColors.containsKey(color))
    {
        color = m_userColors.get(color);
    }
    return color;
}

void FCDraw::drawText(FCPaint *paint, String strText, Long dwPenColor, FCFont *font, int x, int y){
    FCSize textSize = paint->textSize(strText, font, -1);
    FCRect rect = {x, y, x + textSize.cx, y + textSize.cy};
    paint->drawText(strText, dwPenColor, font, rect, -1);
}

int FCDraw::drawUnderLineNum(FCPaint *paint, double value, int digit, FCFont *font, int fontColor, bool zeroAsEmpty, int x, int y)
{
    if(zeroAsEmpty && value == 0){
        String text = L"-";
        FCSize size = paint->textSize(text, font, -1);
        FCRect tRect = {x, y, x + size.cx, y + size.cy};
        paint->drawText(text, fontColor, font, tRect, -1);
        return size.cx;
    }
    else{
        String strValue = FCTran::getValueByDigit(value, digit);
        ArrayList<String> nbs = FCTran::split(strValue, L".");
        if(nbs.size() == 1){
            FCSize size = paint->textSize(nbs.get(0), font, -1);
            FCRect tRect = {x, y, x + size.cx, y + size.cy};
            paint->drawText(nbs.get(0), fontColor, font, tRect, -1);
            return size.cx;
        }
        else{
            FCSize decimalSize = paint->textSize(nbs.get(0), font, -1);
            FCSize size = paint->textSize(nbs.get(1), font, -1);
            FCDraw::drawText(paint, nbs.get(0), fontColor, font, x, y);
            FCDraw::drawText(paint, nbs.get(1), fontColor, font, x
                            + decimalSize.cx + 1, y);
            paint->drawLine(fontColor, 1, 0, x
                            + decimalSize.cx + 1, y + decimalSize.cy,
                            x + decimalSize.cx + size.cx, y + decimalSize.cy);
            return decimalSize.cx + size.cx;
        }
    }
}
