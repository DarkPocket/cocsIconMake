//
//  IconToolsBase.cpp
//  IOSiconMake_MAC
//
//  Created by 7cgames on 2018/4/17.
//  Copyright © 2018年 7cgames. All rights reserved.
//

#include "IconToolsBase.hpp"



IconToolsBase::IconToolsBase()
{
    
}


IconToolsBase::~IconToolsBase()
{
}

bool IconToolsBase::inputSrcimage(std::string path)
{
    image_src_ = imread(path);
    if (!image_src_.data)
    {
        std::cout << "呵呵，读取srcImage错误~！ 检查path " << path << "\r\n";
        return false;
    }
    return true;
}

void IconToolsBase::outIconToFile(std::string out_name, int out_width, int out_hight)
{
    Mat dst_image;
    
    if (!image_src_.data)
    {
        return;
    }
    
    resize(image_src_, dst_image, Size(out_width, out_hight), 0, 0, CV_INTER_AREA);
    
    imwrite(out_name, dst_image);
    
}

void IconToolsBase::writeIniInfoToProfile()
{
    profile_name_=getDefaultProfileName();
    
    std::ofstream out(profile_name_, std::ios::out);
    
    if (!out.is_open())
    {
        std::cout << "Error opening Profile file:" << profile_name_<<"\r\n";
    }
    else
    {
        std::string temp_str;
        for (auto it : ini_info_prefix_list_)
        {
            temp_str=it.dir_+"---"+it.fname_+"---"+it.format_+"---"+ std::to_string(it.fsize_)+"\r\n";
            out << temp_str;
        }
    }
    out.close();
}

void IconToolsBase::getIniInfoByProfile()
{
    profile_name_=getDefaultProfileName();
    std::vector<int> size_list_profile;
    std::ifstream in(profile_name_, std::ios::in);
    
    if (!in.is_open())
    {
        std::cout << "Error opening file:" << profile_name_<<" \r\n";
    }
    else
    {
        while (!in.eof())
        {
            char buffer[1024];
            in.getline(buffer, 1024);
            std::string context_str=buffer;
            
            ini_info_prefix_list_.clear();
            if(context_str.size()<=0)
            {
                break;
            }
            std::vector<std::string> str_list;
            StringTools::SplitString(context_str, "---", str_list);
            
            IniInfoPrefix iniInfo;
            iniInfo.dir_=str_list[0];
            iniInfo.fname_=str_list[1];
            iniInfo.format_=str_list[2];
            iniInfo.fsize_=std::atoi(str_list[3].c_str()) ;
            ini_info_prefix_list_.push_back(iniInfo);
        }
    }
    in.close();
}


