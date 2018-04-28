//
//  androidIconTools.cpp
//  IOSiconMake_MAC
//
//  Created by 7cgames on 2018/4/17.
//  Copyright © 2018年 7cgames. All rights reserved.
//

#include "androidIconTools.hpp"


std::string androidIconTools::getDefaultProfileName()
{
    return image_path_dir_+kDefaultProfileName;
}

void androidIconTools::mainRun(std::string image_path)
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
        image_path_dir_=StringTools::getDirForPath(image_path);
        getIniInfoByProfile();
        
        if(ini_info_prefix_list_.size()<=0)
        {
            getIniInfoByDefault();
            writeIniInfoToProfile();
        }
        
        std::string fname_path=FileTools::getFnameForPath(image_path);
        std::string out_dir_path=image_path_dir_ +fname_path+"icon/";
        for (auto it : ini_info_prefix_list_)
        {
            std::string out_mid_dir_path="android/"+it.dir_;
            std::string out_full_path=out_dir_path+out_mid_dir_path+"/"+it.fname_+it.format_;
            
            std::string out_full_dir_path=StringTools::getDirForPath(out_full_path);
            
            FileTools::makeDir(out_full_dir_path);
            outIconToFile(out_full_path, it.fsize_, it.fsize_);
            std::cout << out_mid_dir_path<<" 已经 转化完成   " << std::endl;
        }
        std::cout << "安卓 转化完成  共 "<< ini_info_prefix_list_.size()<<" 张" << std::endl;
        std::cout << " 输出至 "<<out_dir_path<< std::endl;
        
    }
}

void androidIconTools::getIniInfoByDefault()
{
    ini_info_prefix_list_.clear();
    {
        IniInfoPrefix iniInfo;
        iniInfo.dir_=kDefaultDirPrefixName+"-hdpi";
        iniInfo.fname_=kDefaultPrefixName;
        iniInfo.format_=kDefaultSuffixName;
        iniInfo.fsize_=72;
        ini_info_prefix_list_.push_back(iniInfo);
    }
    {
        IniInfoPrefix iniInfo;
        iniInfo.dir_=kDefaultDirPrefixName+"-ldpi";
        iniInfo.fname_=kDefaultPrefixName;
        iniInfo.format_=kDefaultSuffixName;
        iniInfo.fsize_=36;
        ini_info_prefix_list_.push_back(iniInfo);
    }
    {
        IniInfoPrefix iniInfo;
        iniInfo.dir_=kDefaultDirPrefixName+"-mdpi";
        iniInfo.fname_=kDefaultPrefixName;
        iniInfo.format_=kDefaultSuffixName;
        iniInfo.fsize_=48;
        ini_info_prefix_list_.push_back(iniInfo);
    }
    {
        IniInfoPrefix iniInfo;
        iniInfo.dir_=kDefaultDirPrefixName+"-xhdpi";
        iniInfo.fname_=kDefaultPrefixName;
        iniInfo.format_=kDefaultSuffixName;
        iniInfo.fsize_=96;
        ini_info_prefix_list_.push_back(iniInfo);
    }
    {
        IniInfoPrefix iniInfo;
        iniInfo.dir_=kDefaultDirPrefixName+"-xxhdpi";
        iniInfo.fname_=kDefaultPrefixName;
        iniInfo.format_=kDefaultSuffixName;
        iniInfo.fsize_=144;
        ini_info_prefix_list_.push_back(iniInfo);
    }
    {
        IniInfoPrefix iniInfo;
        iniInfo.dir_=kDefaultDirPrefixName;
        iniInfo.fname_=kDefaultPrefixName;
        iniInfo.format_=kDefaultSuffixName;
        iniInfo.fsize_=196;
        ini_info_prefix_list_.push_back(iniInfo);
    }
}
