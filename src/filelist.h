/*================================================================
 *     Copyright © 2016年 lanhu. All rights reserved.
 *
 *   文件名称：scan.h
 *   创 建 者：Zhang Yuanhao
 *   邮    箱：bluefoxah@gmail.com
 *   创建日期：16/3/1
 *   描    述：
 *
 ================================================================*/

//标准库 & 系统头文件
#include <iostream>
#include <list>

//第三方库头文件

//自己的头文件

#ifndef __FILELIST_H__
#define __FILELIST_H__


#define MAX_PATH_LEN            1024

class CFileList {
public:
    CFileList();
    ~CFileList();
    
public:
    void Parse(const char* pPath);
    std::list<std::string>& getFileList() { return m_lsFiles; }
    
private:
    void listDir(const char* pPath);
    bool isDir(std::string& strFile);
    
private:
    std::list<std::string>  m_lsFiles;
};

#endif //__FILELIST_H__
