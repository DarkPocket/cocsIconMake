//
//  IconToolsBase.hpp
//  IOSiconMake_MAC
//
//  Created by 7cgames on 2018/4/17.
//  Copyright © 2018年 7cgames. All rights reserved.
//

#ifndef IconToolsBase_hpp
#define IconToolsBase_hpp


#include<iostream>
#include <vector>
#include <fstream>
#include<opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

#include "StringTools.hpp"
#include "FileTools.hpp"

#include "IniInfoPrefix.hpp"
using namespace cv;


class IconToolsBase
{
public:
    IconToolsBase();
    ~IconToolsBase();
    
    virtual void getIniInfoByDefault()=0;
    virtual std::string getDefaultProfileName()=0;
    
    bool inputSrcimage(std::string);
    void getIniInfoByProfile();
    void writeIniInfoToProfile();
    
    void outIconToFile(std::string out_name, int out_width, int out_hight);
    
    //每个文件的 配置信息
    std::vector<IniInfoPrefix> ini_info_prefix_list_;
    Mat image_src_;
    std::string profile_name_ ;

 
};


#endif /* IconToolsBase_hpp */
