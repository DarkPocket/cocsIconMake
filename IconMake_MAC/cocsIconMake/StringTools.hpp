//
//  StringTools.hpp
//  IOSiconMake_MAC
//
//  Created by 7cgames on 2018/4/17.
//  Copyright © 2018年 7cgames. All rights reserved.
//

#ifndef StringTools_hpp
#define StringTools_hpp


#include <string>
#include <vector>

#include <iostream>
#include <algorithm>
#include <ctime>

//#if defined(__linux__)
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)
 
#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>
//#import <Foundation/Foundation.h>
//#include <mach-o/dyld.h>
//#include <string.h>

//#endif

namespace StringTools
{
    void SplitString(const std::string &AString, const std::string &ASplitStr, std::vector<std::string> &AStrings);
    
    void SplitStringW(const std::wstring &str, const std::wstring &splitstr, std::vector<std::wstring> &dest);
    std::string StringList2String(const std::vector<std::string> &AStringList, const std::string &AConnectStr);
    std::wstring StringList2StringW(const std::vector<std::wstring> &AStringList, const std::wstring &AConnectStr);
    
    //将string转换成wstring
    std::wstring string2wstring(std::string str);
    //将char转换成wstring
    std::wstring char2wstring(char str[]);
    
    //将wstring转换成string
    std::string wstring2string(std::wstring wstr);
    bool isAllSpace(std::string &str);
    
    std::string& ReplaceString(std::string &s, const std::string &OldPattern, const std::string &NewPattern);
    std::wstring& ReplaceStringW(std::wstring &s, const std::wstring &OldPattern, const std::wstring &NewPattern);
    
    
    time_t LocalTimeToUtc(struct tm t);
    struct tm UtcToLocalTime(std::string UTCtime);
    std::string  UtcToLocalTimeStr(std::string UTCtime);
    
    std::string getCurPath();
    std::string GetExeDir();
    
    std::string getDirForPath(const std::string &path);
}



#endif /* StringTools_hpp */
