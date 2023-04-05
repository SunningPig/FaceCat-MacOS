/*
* FaceCat图形通讯框架
* 上海卷卷猫信息技术有限公司
*/

#ifndef __CDRAW_H__
#define __CDRAW_H__
#pragma once
#include "stdafx.h"

#define USERCOLOR (Long)-200000000100
#define USERCOLOR1  (Long)-200000000100
#define USERCOLOR2  (Long)-200000000101
#define USERCOLOR3  (Long)-200000000102
#define USERCOLOR4  (Long)-200000000103
#define USERCOLOR5  (Long)-200000000104
#define USERCOLOR6  (Long)-200000000105
#define USERCOLOR7  (Long)-200000000106
#define USERCOLOR8  (Long)-200000000107
#define USERCOLOR9  (Long)-200000000108
#define USERCOLOR10 (Long)-200000000109
#define USERCOLOR11 (Long)-200000000110
#define USERCOLOR12 (Long)-200000000111
#define USERCOLOR13 (Long)-200000000112
#define USERCOLOR14 (Long)-200000000113
#define USERCOLOR15 (Long)-200000000114
#define USERCOLOR16 (Long)-200000000115
#define USERCOLOR17 (Long)-200000000116
#define USERCOLOR18 (Long)-200000000117
#define USERCOLOR19 (Long)-200000000118
#define USERCOLOR20 (Long)-200000000119
#define USERCOLOR21 (Long)-200000000120
#define USERCOLOR22 (Long)-200000000121
#define USERCOLOR23 (Long)-200000000122
#define USERCOLOR24 (Long)-200000000123
#define USERCOLOR25 (Long)-200000000124
#define USERCOLOR26 (Long)-200000000125
#define USERCOLOR27 (Long)-200000000126
#define USERCOLOR28 (Long)-200000000127
#define USERCOLOR29 (Long)-200000000128
#define USERCOLOR30 (Long)-200000000129
#define USERCOLOR31 (Long)-200000000130
#define USERCOLOR32 (Long)-200000000131
#define USERCOLOR33 (Long)-200000000132
#define USERCOLOR34 (Long)-200000000133
#define USERCOLOR35 (Long)-200000000134
#define USERCOLOR36 (Long)-200000000135
#define USERCOLOR37 (Long)-200000000136
#define USERCOLOR38 (Long)-200000000137
#define USERCOLOR39 (Long)-200000000138
#define USERCOLOR40 (Long)-200000000139
#define USERCOLOR41 (Long)-200000000140
#define USERCOLOR42 (Long)-200000000141
#define USERCOLOR43 (Long)-200000000142
#define USERCOLOR44 (Long)-200000000143
#define USERCOLOR45 (Long)-200000000144
#define USERCOLOR46 (Long)-200000000145
#define USERCOLOR47 (Long)-200000000146
#define USERCOLOR48 (Long)-200000000147
#define USERCOLOR49 (Long)-200000000148
#define USERCOLOR50 (Long)-200000000149
#define USERCOLOR51 (Long)-200000000150
#define USERCOLOR52 (Long)-200000000151
#define USERCOLOR53 (Long)-200000000152
#define USERCOLOR54 (Long)-200000000153
#define USERCOLOR55 (Long)-200000000154
#define USERCOLOR56 (Long)-200000000155
#define USERCOLOR57 (Long)-200000000156
#define USERCOLOR58 (Long)-200000000157
#define USERCOLOR59 (Long)-200000000158
#define USERCOLOR60 (Long)-200000000159
#define USERCOLOR61 (Long)-200000000160
#define USERCOLOR62 (Long)-200000000161
#define USERCOLOR63 (Long)-200000000162
#define USERCOLOR64 (Long)-200000000163
#define USERCOLOR65 (Long)-200000000164
#define USERCOLOR66 (Long)-200000000165
#define USERCOLOR67 (Long)-200000000166
#define USERCOLOR68 (Long)-200000000167
#define USERCOLOR69 (Long)-200000000168
#define USERCOLOR70 (Long)-200000000169
#define USERCOLOR71 (Long)-200000000170
#define USERCOLOR72 (Long)-200000000171
#define USERCOLOR73 (Long)-200000000172
#define USERCOLOR74 (Long)-200000000173
#define USERCOLOR75 (Long)-200000000174
#define USERCOLOR76 (Long)-200000000175
#define USERCOLOR77 (Long)-200000000176
#define USERCOLOR78 (Long)-200000000177
#define USERCOLOR79 (Long)-200000000178
#define USERCOLOR80 (Long)-200000000179
#define USERCOLOR81 (Long)-200000000180
#define USERCOLOR82 (Long)-200000000181
#define USERCOLOR83 (Long)-200000000182
#define USERCOLOR84 (Long)-200000000183
#define USERCOLOR85 (Long)-200000000184
#define USERCOLOR86 (Long)-200000000185
#define USERCOLOR87 (Long)-200000000186
#define USERCOLOR88 (Long)-200000000187
#define USERCOLOR89 (Long)-200000000188
#define USERCOLOR90 (Long)-200000000189
#define USERCOLOR91 (Long)-200000000190
#define USERCOLOR92 (Long)-200000000191
#define USERCOLOR93 (Long)-200000000192
#define USERCOLOR94 (Long)-200000000193
#define USERCOLOR95 (Long)-200000000194
#define USERCOLOR96 (Long)-200000000195
#define USERCOLOR97 (Long)-200000000196
#define USERCOLOR98 (Long)-200000000197
#define USERCOLOR99 (Long)-200000000198
#define USERCOLOR100 (Long)-200000000199
#define USERCOLOR101 (Long)-200000000200
#define USERCOLOR102 (Long)-200000000201
#define USERCOLOR103 (Long)-200000000202
#define USERCOLOR104 (Long)-200000000203
#define USERCOLOR105 (Long)-200000000204
#define USERCOLOR106 (Long)-200000000205
#define USERCOLOR107 (Long)-200000000206
#define USERCOLOR108 (Long)-200000000207
#define USERCOLOR109 (Long)-200000000208
#define USERCOLOR110 (Long)-200000000209
#define USERCOLOR111 (Long)-200000000210
#define USERCOLOR112 (Long)-200000000211
#define USERCOLOR113 (Long)-200000000212
#define USERCOLOR114 (Long)-200000000213
#define USERCOLOR115 (Long)-200000000214
#define USERCOLOR116 (Long)-200000000215
#define USERCOLOR117 (Long)-200000000216

/*
 * 我的颜色
 */
class MyColor{
public:
    /*
     * 构造函数
     */
    MyColor();
    /*
     * 析构函数
     */
    virtual ~MyColor();
    /*
     * 上次的样式
     */
    int m_lastStyle;
    /*
     * 用户颜色
     */
    HashMap<double, Long> m_userColors;
    /*
     * 获取样式
     */
    static int getStyle();
    /*
     * 设置样式
     */
    static void setStyle(int value);
    /*
     * 创建颜色
     */
    virtual void createColors();
    /*
     * 获取用户颜色
     */
    virtual Long getUserColor(Long color);
    /*
     * 设置反色
     */
    static void setReverseColor(int reverseColor);
    /*
     * 获取反色
     */
    static int getReverseColor();
    /*
     * 设置系统字体
     */
    static void setSystemFont(String value);
    /*
     * 获取系统字体
     */
    static String getSystemFont();
};

/*
 * 自定义绘图方法
 */
class FCDraw{
public:
    /*
     * 绘制文字
     */
    static void drawText(FCPaint *paint, String strText, Long dwPenColor, FCFont *font, int x, int y);
    /*
     * 绘制带下划线的数字
     */
    static int drawUnderLineNum(FCPaint *paint, double value, int digit, FCFont *font, int fontColor, bool zeroAsEmpty, int x, int y);
};
#endif
