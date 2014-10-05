//
//  Flower.cpp
//  Project 2
//
//  Created by Josh Kennedy on 5/3/14.
//  Copyright (c) 2014 Joshua Kennedy. All rights reserved.
//

#include "Flower.h"

#include <iostream>

using namespace std;

Flower::Flower(string color)
{
    this->idNumber = 8008135;
    this->name = "Flower";
    this->color = color;
}

Flower::~Flower()
{
    cout << "destructing flower at " << this << " :(" << endl;
}

double Flower::getPrice() const
{
    return 0.15;
}

void Flower::doSomething()
{
    cout << "spring is here!" << endl;
}

string Flower::getColor()
{
    return this->color;
}
