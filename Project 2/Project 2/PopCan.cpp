//
//  PopCan.cpp
//  Project 2
//
//  Created by Josh Kennedy on 5/3/14.
//  Copyright (c) 2014 Joshua Kennedy. All rights reserved.
//

#include "PopCan.h"

#include <iostream>

using namespace std;

PopCan::PopCan(string flavor)
{
    this->idNumber = 31337;
    this->name = "Can of Soda Pop";
    
    this->flavor = flavor;
}

PopCan::~PopCan()
{
    cout << "destructing can of pop at " << this << ", hopefully it's empty and it gets recycled." << endl;
}

double PopCan::getPrice() const
{
    return 0.50;
}

void PopCan::doSomething()
{
    cout << "wow such pop much fizz wow" << endl;
}

string PopCan::getFlavor() const
{
    return this->flavor;
}
