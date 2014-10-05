//
//  PopCan.h
//  Project 2
//
//  Created by Josh Kennedy on 5/3/14.
//  Copyright (c) 2014 Joshua Kennedy. All rights reserved.
//

#ifndef __Project_2__PopCan__
#define __Project_2__PopCan__

#include "Item.h"

#include <string>

class PopCan : public Item
{
public:
    PopCan(std::string flavor);
    ~PopCan();
    
    double getPrice() const;
    
    void doSomething();
    
    std::string getFlavor() const;
    
private:
    std::string flavor;
};

#endif /* defined(__Project_2__PopCan__) */
