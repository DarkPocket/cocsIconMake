//
//  IconTools.hpp
//  IOSiconMake_MAC
//
//  Created by 7cgames on 2018/4/17.
//  Copyright © 2018年 7cgames. All rights reserved.
//

#ifndef IconTools_hpp
#define IconTools_hpp


#include<iostream>
#include <vector>
#include <fstream>
#include<opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

#include "StringTools.hpp"

#include "androidIconTools.hpp"
#include "iosIconTools.hpp"

using namespace cv;


class IconTools
{
public:
    IconTools();
    ~IconTools();

    void mainRun( );
private:
    androidIconTools android_icon_tool_;
    iosIconTools ios_icon_toos_;
};


#endif /* IconTools_hpp */
