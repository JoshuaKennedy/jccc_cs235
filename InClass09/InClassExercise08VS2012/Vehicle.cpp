#include "Vehicle.h"
ostream & operator<<(ostream & out, const Vehicle & r)
{
	out << r.getYearMade() << ' ' << r.getWeight();    // use gets since from internal to external
	return out;
}

istream & operator>>(istream & in, Vehicle & r)
{
	int tw, ty;     // set up work variables
	in >> tw >> ty;
	r.setWeight(tw).setYearMade(ty);
	return in;
}

Vehicle::Vehicle(void)
{
	this->setWeight(0).setYearMade(0);
}

Vehicle::Vehicle(int yr, int w)
{
	this->setWeight(w).setYearMade(yr);
}

Vehicle::Vehicle(const Vehicle & r)
{
    this->weight   = r.weight;     // ok to use = since from internal format to internal format
	this->yearMade = r.yearMade;
}

Vehicle::~Vehicle()
{
    // no code needed
}

int Vehicle::getYearMade() const
{
	return this->yearMade;
}

int Vehicle::getWeight()   const
{
	return this->weight;
}

Vehicle & Vehicle::setYearMade(int y)
{
	this->yearMade = y;
	return *this;
}

Vehicle & Vehicle::setWeight(int w)
{
	this->weight = w;
	return *this;
}

const Vehicle & Vehicle::operator=(const Vehicle & r)
{
	if ( this == & r ) return *this;   // self assignment
	this->weight   = r.weight;     // ok to use = since from internal format to internal format
	this->yearMade = r.yearMade;
	return *this;
}

void Vehicle::print(ostream & out)   const
{  // use gets since from internal to external
    out << "Weight: " << getWeight() << " Year Made: " << getYearMade() ;
}

void Vehicle::input(istream & in)
{
	int tw, ty;     // set up work variables
	cout << "Enter year made and weight ";
	in >> ty >> tw;
	setWeight(tw).setYearMade(ty);
}

	
	