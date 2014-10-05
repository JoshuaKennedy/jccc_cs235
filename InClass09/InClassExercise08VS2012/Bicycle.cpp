#include "Bicycle.h"
#include "Vehicle.h"

#include <cctype>

Bicycle::Bicycle()
{
	this->setYearMade(2014);
	this->setWeight(30);
	this->offroad = true;
}

Bicycle::Bicycle(int year, int weight, bool isOffroad) : Vehicle(year, weight)
{
	this->offroad = isOffroad;
}

Bicycle::Bicycle(const Bicycle& other)
{
	this->setWeight(other.getWeight());
	this->setYearMade(other.getYearMade());
	this->offroad = other.offroad;
}

void Bicycle::setOffroad(bool isOffroad)
{
	this->offroad = isOffroad;
}

bool Bicycle::getOffroad() const
{
	return this->offroad;
}

ostream & operator<<(ostream & out, const Bicycle & r)
{
	//   vehicle stuff first
	const Vehicle &  aR = r;                // setup Vehicle alias to call Vehicle << operator
	out << aR << ' ';
	//   boat stuff last
	out << ' ' << r.getOffroad() << endl;
	return out;
}

istream & operator>>(istream & in, Bicycle & r)
{
    Vehicle & aR = r;                       // setup Vehicle alias to call Vehicle >> operator
    in >> aR;
    string tempOffroad;
    cin >> tempOffroad;
	char* offroad = (char*)tempOffroad.c_str();
	char temp;
	while(*offroad)
	{
		temp = toupper(*offroad);
		*offroad = temp;
		offroad++;
	}
	bool offroadStatus = (strcmp(offroad, "TRUE") == 0);
	r.setOffroad(offroadStatus);
	return in;
}
