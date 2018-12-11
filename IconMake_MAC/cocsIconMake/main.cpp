//
//  main.cpp
//  cocsIconMake
//
//  Created by 7cgames on 2018/4/19.
//  Copyright © 2018年 7cgames. All rights reserved.
//

#include <iostream>


#include "IconTools.hpp"
#include "iosIconTools.hpp"
#include "FileTools.hpp"


void mainRun()
{

        IconTools icon_tool;
        icon_tool.mainRun();
    
}


int main(int argc, const char * argv[]) {
    mainRun() ;
    
    
    std::cout << "Hello, World!\n";
    return 0;
}
