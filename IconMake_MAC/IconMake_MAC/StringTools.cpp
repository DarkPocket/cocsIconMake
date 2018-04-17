//
//  StringTools.cpp
//  IOSiconMake_MAC
//
//  Created by 7cgames on 2018/4/17.
//  Copyright © 2018年 7cgames. All rights reserved.
//

#include "StringTools.hpp"



namespace StringTools
{
    
    //判断是否全是空格
    bool isAllSpace(std::string &str){
        int flag = 1;
        
        for (int i = 0; i < str.size(); ++i){
            if (str[i] != ' '){
                flag = 0;
                break;
            }
        }
        
        if (flag == 0){
            //cout << s << "非空格" << s.size() << endl;
            return false;
        }
        else{
            //cout << s << "空格" << s.size() << endl;
            return true;
        }
    }
    
    std::string& ReplaceString(std::string &s, const std::string &OldPattern, const std::string &NewPattern)
    {
        if (OldPattern == NewPattern)
            return s;
        std::string::size_type i;
        while (true)
        {
            i = s.find(OldPattern);
            if (i == std::string::npos)
                break;
            else
                s = s.replace(i, OldPattern.length(), NewPattern);
        }
        return s;
    }
    
    std::wstring& ReplaceStringW(std::wstring &s, const std::wstring &OldPattern, const std::wstring &NewPattern)
    {
        if (OldPattern == NewPattern)
            return s;
        std::wstring::size_type i;
        while (true)
        {
            i = s.find(OldPattern);
            if (i == std::wstring::npos)
                break;
            else
                s = s.replace(i, OldPattern.length(), NewPattern);
        }
        return s;
    }
    
    void SplitString(const std::string &AString, const std::string &ASplitStr, std::vector<std::string> &AStrings)
    {
        const char *sdata = AString.c_str();
        const char *ssplit = ASplitStr.c_str();
        int i = 0, j = 0, iSizeA = AString.length(), iSizeB = ASplitStr.length();
        AStrings.clear();
        while (i < iSizeA)
        {
            if (i + iSizeB > iSizeA)
            {
                AStrings.push_back(AString.substr(j));
                j = i;
                break;
            }
            if (memcmp(&(sdata[i]), ssplit, iSizeB) == 0)
            {
                //if (j < i)
                AStrings.push_back(AString.substr(j, i - j));
                j = i + iSizeB;
                i += iSizeB;
            }
            else
                ++i;
        }
        if (j < i)
            AStrings.push_back(AString.substr(j));
        return;
    }
    
    void SplitStringW(const std::wstring &str, const std::wstring &splitstr, std::vector<std::wstring> &dest)
    {
        std::wstring::size_type pos = std::wstring::npos;
        std::wstring::size_type offset = 0;
        dest.clear();
        while (1)
        {
            pos = str.find(splitstr.c_str(), offset);
            if (std::wstring::npos == pos)
                break;
            dest.push_back(str.substr(offset, pos - offset));
            offset = splitstr.length() + pos;
            
        }
        if (offset != str.length())
            dest.push_back(str.substr(offset));
    }
    
    std::string StringList2String(const std::vector<std::string> &AStringList, const std::string &AConnectStr)
    {
        std::string ret;
        for (std::vector<std::string>::const_iterator it = AStringList.begin(); it != AStringList.end(); ++it)
        {
            if (ret.empty())
                ret = *it;
            else
                ret = ret + AConnectStr + *it;
        }
        return ret;
    }
    
    std::wstring StringList2StringW(const std::vector<std::wstring> &AStringList, const std::wstring &AConnectStr)
    {
        std::wstring ret;
        for (std::vector<std::wstring>::const_iterator it = AStringList.begin(); it != AStringList.end(); ++it)
        {
            if (ret.empty())
                ret = *it;
            else
                ret = ret + AConnectStr + *it;
        }
        return ret;
    }
    
    time_t LocalTimeToUtc(struct tm t)
    {
        //struct tm t;
        time_t    t_of_day;
        t.tm_year = t.tm_year - 1900;
        t.tm_mon = t.tm_mon - 1;
        t_of_day = mktime(&t);
        
        return t_of_day;
    }
    struct tm UtcToLocalTime(std::string UTCtime)
    {
        struct tm *tm_ptr;
        time_t the_time;
        
        if (UTCtime.length() == 13)
        {
            the_time = std::atoll(UTCtime.c_str()) / 1000;
        }
        else if (UTCtime.length() == 10)
        {
            the_time = std::atoll(UTCtime.c_str());
        }
        else
        {
            the_time = 1508774400; //2017 10 24
            //UTCtime error
        }
        tm_ptr = localtime(&the_time);
        tm_ptr->tm_year += 1900;
        tm_ptr->tm_mon += 1;
        return *tm_ptr;
    }
    std::string  UtcToLocalTimeStr(std::string UTCtime)
    {
        struct tm tm_ptr;
        
        tm_ptr = UtcToLocalTime(UTCtime);
        std::string timeStr = std::to_string(tm_ptr.tm_year) + "-" + std::to_string(tm_ptr.tm_mon) + "-" + std::to_string(tm_ptr.tm_mday);
        return timeStr;
    }
    
    std::string getCurPath()
    {
        char buff[1000];
        getcwd(buff, 1000);
        std::string curPath=buff;
        
        return curPath;
    }
    std::string GetExeDir()
    {
        std::string path="";
        std::string dir_path="";
        const char *file_name = "IOSiconMake_MAC";
        char abs_path_buff[PATH_MAX];
        
        //获取文件路径, 填充到abs_path_buff
        //realpath函数返回: null表示获取失败; 否则返回指向abs_path_buff的指针
        if(realpath(file_name, abs_path_buff)){
            // printf("%s %s\n", file_name, abs_path_buff);
            path=abs_path_buff;
            
            if(path.rfind("/")!=std::string::npos)
            {
                dir_path=path.substr(0,path.rfind("/"))+"/";
            }else
            {
                dir_path=path;
            }
        } else{
            // printf("the file '%s' is not exist\n", file_name);
            std::cout<<" "<<file_name<<" is not exist\n";
        }
        return dir_path;
    }
    std::string getDirForPath(const std::string &path)
    {
        std::string dir_path="";
        if(path.rfind("/")!=std::string::npos)
        {
            dir_path=path.substr(0,path.rfind("/"))+"/";
        }else
        {
            dir_path=path;
        }
        return dir_path;
    }
    
}



