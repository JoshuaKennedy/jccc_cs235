#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
using namespace::std;

class Vehicle
{
friend ostream & operator<<(ostream &, const Vehicle &);
friend istream & operator>>(istream &, Vehicle &);

public:

	Vehicle(void);
	Vehicle(int yr, int w);
	Vehicle(const Vehicle &);

	~Vehicle();

	int getYearMade() const;
	int getWeight() const;
	Vehicle & setYearMade(int);
	Vehicle & setWeight(int);

	const Vehicle & operator=(const Vehicle &);

	void print(ostream &)   const;
	void input(istream &);

private:
	int yearMade;
	int weight;

};

#endif
