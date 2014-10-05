#ifndef BOAT_H
#define BOAT_H
#include "Vehicle.h"

#include <iostream>
using namespace::std;

class Boat : public Vehicle          //  HERE we declare the class Boat inherits from class Vehicle
{    // class Boat inherits ALL Vehicle member functions and ALL Vehicle member data
friend ostream & operator<<(ostream &, const Boat &);
friend istream & operator>>(istream &, Boat &);
public:
    Boat(void);
	Boat(int yr, int w, int len);
	Boat(const Boat &);

	~Boat();

	int getLength() const;
	Boat & setLength(int);

	const Boat & operator=(const Boat &);

	void print(ostream &)   const;          // overwritten from inherited print method
	void input(istream &);                  // overwritten from inherited print method

private:
	int length;
};

// NO NEED TO LIST INHERITED MEMBER DATA SUCH AS yearMade 
// NOR TO LIST INHERITED MEMBER FUNCTIONS SUCH AS getYearMade()
// THEY ARE AUTOMATICALLY PLACED IN CLASS Boat WHEN INHERITANCE IS DECLARED

#endif
