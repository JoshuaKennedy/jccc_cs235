#include "Boat.h"
ostream & operator<<(ostream & out, const Boat & r)
{
	//   vehicle stuff first
	const Vehicle &  aR = r;                // setup Vehicle alias to call Vehicle << operator
	out << aR << ' ';
	//   boat stuff last
	out << ' ' << r.getLength() << endl;
	return out;
}

istream & operator>>(istream & in, Boat & r)
{
    Vehicle & aR = r;                       // setup Vehicle alias to call Vehicle >> operator
    in >> aR;
    int tempLen;
    cin >> tempLen;
    r.setLength(tempLen);
	return in;
}

Boat::Boat(void) : Vehicle()                           // Member Initialization List, Vehicle default constructor
{
    setLength(10);
}

Boat::Boat(int yr, int w, int len) : Vehicle(yr,w)      // Member Initialization List, Vehicle argument constructor
{
    setLength(len);
}

Boat::Boat(const Boat & r) : Vehicle(r)                // Member Initialization List, Vehicle copy constructor
{
   setLength(r.getLength());
}

Boat::~Boat()
{
    // no work to do
}

int Boat::getLength() const
{
	return this->length;
}

Boat & Boat::setLength(int len)
{
    length = len;
	return *this;           // for function chaining
}

const Boat & Boat::operator=(const Boat & r)
{
	if ( this == &r ) return *this;
	// move over the Boat data
	length = r.length;
	// move over the inherited data piece by piece or all at once
	//  all at once using the = operator in the Vehicle class
	(*this).Vehicle::operator=(r);      // use scoping to call inherited Vehicle = operator
	return *this;
}

void Boat::print(ostream & out)   const
{
	Vehicle::print(out);              // use scoping to call inherited Vehicle print method
	out << " Length: " << Boat::getLength() << endl;

}

void Boat::input(istream & in)
{
   Vehicle::input(in);                 // use scoping to call inherited Vehicle input method
   int tempLen;
   cout << "Enter boat length ";
   in >> tempLen;
   setLength(tempLen);
}
