/*================================================================
 *     Copyright © 2016年 lanhu. All rights reserved.
 *
 *   文件名称：scan.cpp
 *   创 建 者：Zhang Yuanhao
 *   邮    箱：bluefoxah@gmail.com
 *   创建日期：16/3/1
 *   描    述：
 *
 ================================================================*/
//标准库 & 系统头文件
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <sys/stat.h>
//第三方库头文件

//自己的头文件
#include "filelist.h"

#define THRIFTS_DIR             "thrifts"
#define THRIFTS_DIR_LEN         7
#define THRIFT_FILE_SUFFIX      ".thrift"
#define THRIFT_FILE_SUFFIX_LEN  7


CFileList::CFileList()
{
    
}

CFileList::~CFileList()
{
    
}

void CFileList::Parse(const char* pPath)
{
    size_t nPathLen = strlen(pPath);
    if (strncmp(pPath + (nPathLen - THRIFTS_DIR_LEN), THRIFTS_DIR, THRIFTS_DIR_LEN) != 0) {
        printf("\033[1;31;40m[WARNING]\033[0m parent path name must be \"thrifts\".\n");
        exit(-1);
    }
    listDir(pPath);
}

void CFileList::listDir(const char *pPath)
{
    char szChilePath[MAX_PATH_LEN];
    bzero(szChilePath, MAX_PATH_LEN);
    
    struct dirent *pDirent = NULL;
    DIR* pDir = NULL;
    
    if ((pDir = opendir(pPath)) == NULL) {
        printf("\033[1;31;40m[WARNING]\033[0m open current path failed. [path=%s]\n", pPath);
        return;
    }
    
    size_t nFileNameLen = 0;
    
    while ((pDirent = readdir(pDir)) != NULL) {
        snprintf(szChilePath, MAX_PATH_LEN, "%s/%s", pPath, pDirent->d_name);
        
        struct stat sb;
        if (stat(szChilePath, &sb) == -1){
            continue;
        }
        if (pDirent->d_type == DT_DIR || pDirent->d_type == DT_UNKNOWN) {
            //又一个目录
            if(strcmp(pDirent->d_name,".")==0 || strcmp(pDirent->d_name,"..")==0) {
                continue;
            }
            listDir(szChilePath);
        } else if (pDirent->d_type == DT_REG) {
            //普通文件
            nFileNameLen = strlen(szChilePath);
            //后缀名必须是.thrift
            if (strncmp(szChilePath + (nFileNameLen - THRIFT_FILE_SUFFIX_LEN), THRIFT_FILE_SUFFIX, THRIFT_FILE_SUFFIX_LEN) == 0) {
                m_lsFiles.push_back(szChilePath);
            }
        } else {
            printf("\033[1;31;40m[WARNING]\033[0m find unsupport file type.[file=%s]\n", szChilePath);
        }
    }
}

bool CFileList::isDir(std::string &strFile)
{
    struct stat sb;
    if (stat(strFile.c_str(), &sb) == -1) return false;
    return S_ISDIR(sb.st_mode);
}
