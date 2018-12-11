//
//  FileTools.hpp
//  IOSiconMake_MAC
//
//  Created by 7cgames on 2018/4/17.
//  Copyright © 2018年 7cgames. All rights reserved.
//

#ifndef FileTools_hpp
#define FileTools_hpp

#include <stdio.h>

#include <stdlib.h>
#include <iostream>
#include <deque>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "StringTools.hpp"

namespace FileTools
{
    int makeDir(std::string dir_path);
    std::string getDirForPath(const std::string &path);
    
    std::string getFnameForPath(const std::string &path);
    
    std::string getExtForPath(const std::string &path);
    
    bool test();
}

#endif /* FileTools_hpp */
