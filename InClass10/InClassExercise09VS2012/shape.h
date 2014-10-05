
#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <string>
using namespace::std;

class Shape
{
public:
	Shape(void);
	virtual double area() const = 0;        // Abstract Class, Polymorphic Member Function
	virtual string objectType() const = 0;        // Abstract Class, Polymorphic Member Function
	virtual void input(istream & ) = 0;     // Abstract Class, Polymorphic Member Function
	virtual void print(ostream &) const ;   // Polymorphic Member Function
private:
	int timeCreated;     // in seconds since 1/1/1970
};

#endif