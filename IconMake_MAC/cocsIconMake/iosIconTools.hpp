//
//  iosIconTools.hpp
//  IOSiconMake_MAC
//
//  Created by 7cgames on 2018/4/17.
//  Copyright © 2018年 7cgames. All rights reserved.
//

#ifndef iosIconTools_hpp
#define iosIconTools_hpp

#include<iostream>
#include <vector>
#include <fstream>
#include<opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

#include "IconToolsBase.hpp"
#include "StringTools.hpp"

using namespace cv;

class iosIconTools : public IconToolsBase
{
public:
    
    void mainRun(std::string path);
    
    const std::string kDefaultProfileName = "ios_icon_list.profile";
    const std::string kDefaultImageName = "icon.jpg";
    const std::string kDefaultPrefixName = "Icon";
    const std::string kDefaultSuffixName = ".png";
private:
    virtual void getIniInfoByDefault();
    virtual std::string getDefaultProfileName();
    std::string image_path_dir_;
    
    
};



#endif /* iosIconTools_hpp */
