#ifndef BICYCLE_H
#define BICYCLE_H
#include <iostream>
#include <string>
#include "Vehicle.h"
using namespace::std;

// class Bicycle should inherit from class Vehicle

class Bicycle : public Vehicle
{
	friend ostream & operator<<(ostream &, const Bicycle &);
	friend istream & operator>>(istream &, Bicycle &);

public:
	Bicycle();
	Bicycle(int year, int weight, bool isOffroad);
	Bicycle(const Bicycle&);

	void setOffroad(bool isOffroad);
	bool getOffroad() const;

private:
	bool offroad;
};

#endif
