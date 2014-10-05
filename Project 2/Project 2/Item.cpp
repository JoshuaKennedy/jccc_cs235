//
//  Item.cpp
//  Project 2
//
//  Created by Josh Kennedy on 5/3/14.
//  Copyright (c) 2014 Joshua Kennedy. All rights reserved.
//

#include "Item.h"

#include <iostream>

using namespace std;

Item::Item()
{
    this->idNumber = 0;
    this->name = "Empty Inventory Item";
}

Item::~Item()
{
    cout << "wow such destruction very symphony much guitar wow" << endl;
}

unsigned long Item::getIdNumber() const
{
    return this->idNumber;
}

double Item::getPrice() const
{
    return 0.00;
}

string Item::getName() const
{
    return this->name;
}

void Item::doSomething()
{
    std::cout << "this item does nothing" << endl;
}
