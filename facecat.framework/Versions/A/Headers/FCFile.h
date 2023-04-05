/*
 * FaceCat图形通讯框架(非开源)
 * 著作权编号:2015SR229355+2020SR0266727
 * 上海卷卷猫信息技术有限公司
 */

#ifndef __FCFILE_H__
#define __FCFILE_H__
#pragma once
#include "stdafx.h"
#include <fstream>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>

namespace FaceCat{
    /*
     * 文件处理
     */
    class FCFile
    {
    public:
        /**
         * 追加内容
         */
        static bool append(const char *file, const char *content);
        /**
         * 追加内容-宽字符
         */
        static bool append(const String &file, const String &content);
        /**
         * 创建目录
         */
        static void createDirectory(const char *dir);
        /**
         * 创建目录-宽字符
         */
        static void createDirectory(const String &dir);
        /**
         * 判断目录是否存在
         */
        static bool isDirectoryExist(const char *dir);
        /**
         * 判断目录是否存在-宽字符
         */
        static bool isDirectoryExist(const String &dir);
        /**
         * 文件是否存在
         */
        static bool isFileExist(const char *file);
        /**
         * 文件是否存在-宽字符
         */
        static bool isFileExist(const String &file);
        /**
         * 获取目录
         */
        static bool getDirectories(const char *dir, ArrayList<std::string> *dirs);
        /**
         * 获取目录-宽字符
         */
        static bool getDirectories(const String &file, ArrayList<String> *dirs);
        /**
         * 获取文件长度
         */
        static long getFileLength(const char *file);
        /**
         * 获取文件长度-宽字符
         */
        static long getFileLength(const String &file);
        /**
         * 获取文件
         */
        static bool getFiles(const char *dir, ArrayList<std::string> *files);
        /**
         * 获取文件-宽字符
         */
        static bool getFiles(const String &dir, ArrayList<String> *files);
        /**
         * 获取文件状态
         */
        static int getFileState(const char *file, struct stat *buf);
        /**
         * 获取文件状态-宽字符
         */
        static int getFileState(const String &file, struct stat *buf);
        /**
         * 读取文件
         */
        static bool read(const char *file, std::string *content);
        /**
         * 读取文件-宽字符
         */
        static bool read(const String &file, String *content);
        /**
         * 移除文件
         */
        static void removeFile(const char *file);
        /**
         * 移除文件-宽字符
         */
        static void removeFile(const String &file);
        /**
         * 写入文件
         */
        static bool write(const char *file, const char *content);
        /**
         * 写入文件-宽字符
         */
        static bool write(const String &file, const String &content);
    private:
        /*
         * 创建文件夹
         */
        static bool makeDir (const std::string& pathName);
        /*
         * 获取文件名称
         */
        static bool getFileName(std::string srcDirPath , ArrayList<std::string> *fileNameList);
        /*
         * 拷贝文件
         */
        static void doCopy(std::string srcDirPath , std::string desDirPath, ArrayList<std::string> *fileNameLis);
    };
}
#endif
