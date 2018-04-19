//
//  IconTools.cpp
//  IOSiconMake_MAC
//
//  Created by 7cgames on 2018/4/17.
//  Copyright © 2018年 7cgames. All rights reserved.
//

#include "IconTools.hpp"




//const std::string kDefaultProfileName = "icon_list.profile";
//const std::string kDefaultImageName = "icon.jpg";
//const std::string kDefaultPrefixName = "Icon";
//const std::string kDefaultSuffixName = "png";

IconTools::IconTools()
{
}


IconTools::~IconTools()
{
}

void IconTools::mainRun()
{
    auto out_path=StringTools::getCurPath()+"/";
    std::cout << " cur路径地址 "<<out_path<<"\r\n";
    
    std::cout << "输入目标图全路径地址 （建议1024x1024像素）默认路径"<< android_icon_tool_.kDefaultImageName<<"（y 确认） " << std::endl;
    char image_path_in[255]="";
    
    std::cin >> image_path_in;
    std::string image_path= image_path_in;
    
    android_icon_tool_.mainRun(image_path);
    ios_icon_toos_.mainRun(image_path);
    

}

