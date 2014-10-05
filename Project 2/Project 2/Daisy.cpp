//
//  Daisy.cpp
//  Project 2
//
//  Created by Josh Kennedy on 5/3/14.
//  Copyright (c) 2014 Joshua Kennedy. All rights reserved.
//

#include "Daisy.h"

#include <iostream>

using namespace std;

Daisy::Daisy() : Flower("White")
{
    this->name = "Daisy";
    this->idNumber = 6147510932;
}

Daisy::~Daisy()
{
    cout << "I'm pushing up daisies at " << this << endl;
}

double Daisy::getPrice() const
{
    return 0.30;
}

void Daisy::doSomething()
{
    cout << "insert reference to girl that I have a crush on" << endl;
}
