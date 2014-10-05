//
//  appointment.cpp
//  Lab 3
//
//  Created by Josh Kennedy on 4/8/14.
//  Copyright (c) 2014 Joshua Kennedy. All rights reserved.
//

#include "appointment.h"

#include <string.h>
#include <iostream>

using namespace std;

appointment::appointment()
{
    this->source = 0;
	this->desc = new char[256];
    this->day = 1;
    this->month = 1;
    this->year = 2000;
}

appointment::appointment(long s, const char* desc,int d, int m, int y)
{
    this->source = s;
    this->desc = (char*)desc;
    this->day = d;
    this->month = m;
    this->year = y;
}

appointment::appointment(const appointment& other)
{
    this->source = other.getSource();
    this->desc = (char*)other.getDescription();
    this->day = other.getDay();
    this->month = other.getMonth();
    this->year = other.getYear();
}

appointment::~appointment()
{
    cout << "destructing appointment instance at 0x" << this << endl;
}

void appointment::keyBoardInput()
{
    cout << "enter source: ";
    cin >> this->source;
    
    cout << "\ninput description (no spaces): ";
	cin >> this->desc;
    
    cout << "\ninput day, month, year: ";
    cin >> this->day >> this->month >> this->year;
}

long appointment::getSource() const
{
    return this->source;
}

void appointment::setSource(long s)
{
    this->source = s;
}

const char* appointment::getDescription() const
{
    return this->desc;
}

void appointment::changeDescription(const char* d)
{
    this->desc = (char*)d;
}

int appointment::getDay() const
{
    return this->day;
}

void appointment::setDay(int d)
{
    this->day = d;
}

int appointment::getMonth() const
{
    return this->month;
}

void appointment::setMonth(int m)
{
    this->month = m;
}

int appointment::getYear() const
{
    return this->year;
}

void appointment::setYear(int y)
{
    this->year = y;
}

void appointment::print(ostream& output, int dateFormat) const
{
    switch (dateFormat)
    {
        case 1:
        default:
            output << this->desc << " on " << this->month << '/' << this->day << '/' << this->year << endl;
            break;
        case 2:
            output << this->desc << " on " << this->day << '/' << this->month << '/' << this->year << endl;
            break;
    }

	output << "Created by source id: " << this->source << endl;
}
