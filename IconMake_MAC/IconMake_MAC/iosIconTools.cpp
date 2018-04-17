//
//  iosIconTools.cpp
//  IOSiconMake_MAC
//
//  Created by 7cgames on 2018/4/17.
//  Copyright © 2018年 7cgames. All rights reserved.
//

#include "iosIconTools.hpp"


std::string iosIconTools::getDefaultProfileName()
{
    return kDefaultProfileName;
}

void iosIconTools::mainRun(std::string image_path)
{
    if (image_path.size() < 4)
    {
        image_path = kDefaultImageName;
    }
    
    if (!inputSrcimage(image_path))
    {
        //pause
        char temp[255];
        std::cin >> temp;
        return;
    }
    else
    {
        getIniInfoByProfile();
        
        if(ini_info_prefix_list_.size()<=0)
        {
            getIniInfoByDefault();
            writeIniInfoToProfile();
        }
        
        std::string out_dir_path=StringTools::getDirForPath(image_path)+"icon/";
        for (auto it : ini_info_prefix_list_)
        {
            std::string out_mid_fname_path="/"+it.fname_+"-"+std::to_string(it.fsize_) +it.format_;
            std::string out_full_path=out_dir_path+"ios/"+it.dir_+out_mid_fname_path;
            std::string out_full_dir_path=StringTools::getDirForPath(out_full_path);
            
            FileTools::makeDir(out_full_dir_path);
            outIconToFile(out_full_path, it.fsize_, it.fsize_);
            std::cout <<"  "<< out_mid_fname_path<<" 已经 转化完成   " << std::endl;
        }
        std::cout << "ios 转化完成  共 "<< ini_info_prefix_list_.size()<<" 张" << std::endl;
        std::cout << " 输出至 "<<out_dir_path<< std::endl;
        
    }
}

void iosIconTools::getIniInfoByDefault()
{
    std::vector<int> size_list_default;
    size_list_default.push_back(29);
    size_list_default.push_back(40);
    size_list_default.push_back(50);
    size_list_default.push_back(57);
    size_list_default.push_back(58);
    size_list_default.push_back(72);
    size_list_default.push_back(76);
    size_list_default.push_back(80);
    size_list_default.push_back(100);
    size_list_default.push_back(114);
    size_list_default.push_back(120);
    size_list_default.push_back(144);
    size_list_default.push_back(152);
    size_list_default.push_back(1024);
    
    ini_info_prefix_list_.clear();
    for (int i=0;i<size_list_default.size();++i)
    {
        IniInfoPrefix iniInfo;
        iniInfo.dir_="ios";
        iniInfo.fname_="Icon";
        iniInfo.format_=".png";
        iniInfo.fsize_=size_list_default[i];
        ini_info_prefix_list_.push_back(iniInfo);
    }
  
}

