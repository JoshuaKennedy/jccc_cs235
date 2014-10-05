#include "address.h"

address::address()
{
	this->name = "John Doe";
	this->zip = "66203";
}

address::address(const address& other)
{
	this->name = other.name;
	this->zip = other.zip;
}

address::address(const string& theName, const string& theZip)
{
	this->name = theName;
	this->zip = theZip;
}

address::~address()
{
	// *whistles* 
	// nothin' to do 'ere.
}

address& address::setName(const string& theName)
{
	this->name = theName;
	return *this;
}

address& address::setZip(const string& theZip)
{
	this->zip = theZip;
	return *this;
}

string address::getName() const
{
	return this->name;
}

string address::getZip() const
{
	return this->zip;
}

const address& address::operator=(const address& right)
{
	this->name = right.name;
	this->zip = right.zip;

	return *this;
}

void address::print(ostream& output) const
{
	output << this->name << endl << this->zip << endl;
}

