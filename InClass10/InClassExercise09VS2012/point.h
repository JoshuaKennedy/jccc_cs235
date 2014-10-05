#ifndef POINT_H
#define POINT_H
#include "shape.h"
class Point  :  public Shape
{
public:
	Point(void);
	Point(double xV, double yV);
	double area() const;
	void input(istream & );
	void print(ostream & ) const;
    string objectType() const;

private:
	double x,
		   y;

};

#endif