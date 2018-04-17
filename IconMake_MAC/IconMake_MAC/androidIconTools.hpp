//
//  androidIconTools.hpp
//  IOSiconMake_MAC
//
//  Created by 7cgames on 2018/4/17.
//  Copyright © 2018年 7cgames. All rights reserved.
//

#ifndef androidIconTools_hpp
#define androidIconTools_hpp

#include <stdio.h>
#include "IconToolsBase.hpp"


class androidIconTools : public IconToolsBase
{
public:
    
    void mainRun(std::string path);
    
    const std::string kDefaultProfileName = "android_icon_list.profile";
    const std::string kDefaultImageName = "icon.jpg";
    const std::string kDefaultPrefixName = "Icon";
    const std::string kDefaultSuffixName = "png";
private:
    virtual void getIniInfoByDefault();
    virtual std::string getDefaultProfileName();
    
    

};



#endif /* androidIconTools_hpp */
