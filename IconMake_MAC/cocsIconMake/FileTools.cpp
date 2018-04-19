//
//  FileTools.cpp
//  IOSiconMake_MAC
//
//  Created by 7cgames on 2018/4/17.
//  Copyright © 2018年 7cgames. All rights reserved.
//

#include "FileTools.hpp"


namespace FileTools
{
    int makeDir(std::string dir_path)
    {
        std::string recursiver_dir_path=dir_path+"/";
        std::vector<std::string> temp_dir_list;
        
        //temp_dir_list.push_back(recursiver_dir_path);
        
        int break_flag=0;
        do {
            std::string sub_dir_path=getDirForPath(recursiver_dir_path);
            sub_dir_path= sub_dir_path.substr(0,sub_dir_path.size()-1);
            /*
             R_OK 只判断是否有读权限
             W_OK 只判断是否有写权限
             X_OK 判断是否有执行权限
             F_OK 只判断是否存在
             */
            break_flag=access(sub_dir_path.c_str(), F_OK);
            if( break_flag!=0)
            {
                temp_dir_list.push_back(sub_dir_path);
                recursiver_dir_path=sub_dir_path.substr(0,sub_dir_path.size()-1);
            }else
            {
                break;
            }
        } while (break_flag!=0);
        
        for (int i= static_cast<int>(temp_dir_list.size()-1); i>=0;--i)
        {
            if(mkdir(temp_dir_list[i].c_str(),0755)!=0)
            {
                std::cout<<"error  mkdir  "<<temp_dir_list[i] <<"\r\n";
            }
        }
        return 0;
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
    std::string getFnameForPath(const std::string &path)
    {
        std::string fname_path="";
        size_t start_pos,end_pos;
        start_pos=path.rfind("/");
        end_pos=path.rfind(".");
        if( (start_pos!=std::string::npos)&&(end_pos!=std::string::npos))
        {
            fname_path=path.substr(start_pos+1,end_pos-start_pos-1);
        }
        return fname_path;
    }
}
