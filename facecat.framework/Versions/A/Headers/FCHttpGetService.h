/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifndef __FCHTTPGETSERVICE_H__
#define __FCHTTPGETSERVICE_H__
#pragma once
#include "stdafx.h"
namespace FaceCat{
    /**
     * HTTP的GET服务
     */
    class FCHttpGetService{
    public:
        /**
         * 获取网页数据
         * @param  url  地址
         */
        string get(string url);
        /**
         * 获取网页数据
         * @param  url  地址
         */
        String get(String url);
    };
}


#endif
