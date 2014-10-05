//
//  Flower.h
//  Project 2
//
//  Created by Josh Kennedy on 5/3/14.
//  Copyright (c) 2014 Joshua Kennedy. All rights reserved.
//

#ifndef __Project_2__Flower__
#define __Project_2__Flower__

#include "Item.h"

#include <string>

class Flower : public Item
{
public:
    Flower(std::string color);
    ~Flower();
    
    double getPrice() const;
    
    void doSomething();
    
    std::string getColor();
    
private:
    std::string color;
};

#endif /* defined(__Project_2__Flower__) */
