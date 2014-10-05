#include "point.h"

Point::Point(void) : Shape()
{
	x = y = 0.0;
}

Point::Point(double xV, double yV) : Shape()
{
	x = xV;
	y = yV;
}

double Point::area() const
{
	return 0.0;
}

void Point::input(istream & in )
{
	cout << "Enter x and y: ";
	in >> x >> y;
}

void Point::print(ostream & out ) const
{
   Shape::print(out);
   out << '(' << x << ',' << y << ')' << endl;
}

string Point::objectType() const
{
     return string("POINT");
}
