//
//  Daisy.h
//  Project 2
//
//  Created by Josh Kennedy on 5/3/14.
//  Copyright (c) 2014 Joshua Kennedy. All rights reserved.
//

#ifndef __Project_2__Daisy__
#define __Project_2__Daisy__

#include "Flower.h"

#include <string>

class Daisy : public Flower
{
public:
    Daisy();
    ~Daisy();
    
    double getPrice() const;
    
    void doSomething();
};

#endif /* defined(__Project_2__Daisy__) */
