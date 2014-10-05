//
//  Item.h
//  Project 2
//
//  Created by Josh Kennedy on 5/3/14.
//  Copyright (c) 2014 Joshua Kennedy. All rights reserved.
//

#ifndef __Project_2__Item__
#define __Project_2__Item__

#include <string>

class Item
{
public:
    Item();
    
    virtual ~Item() = 0;
    
    unsigned long getIdNumber() const;
    
    virtual double getPrice() const;
    
    std::string getName() const;
    
    virtual void doSomething() = 0;
    
protected:
    unsigned long idNumber;
    std::string name;
};

#endif /* defined(__Project_2__Item__) */
