#include "letter.h"

letter::letter()
{
	this->weight = 0.0;
	this->to = address();
	this->from = address();
}

letter::letter(const letter& other)
{
	this->weight = other.weight;
	this->to = other.to;
	this->from = other.from;
}

letter::letter(const address& sentBy, const address& sentTo, double theWeight)
{
	this->weight = theWeight;
	this->to = sentTo;
	this->from = sentBy;
}

letter::letter(const string& senderName, const string& senderZip, const string& toName, const string& toZip, double theWeight)
{
	this->weight = theWeight;
	this->to = address(toName, toZip);
	this->from = address(senderName, senderZip);
}

letter::~letter()
{
	// nothing to do here, yet.
}

address letter::getSender() const
{
	return this->from;
}

address letter::getTo() const
{
	return this->to;
}

string letter::getSenderName() const
{
	return this->from.getName();
}

string letter::getToName() const
{
	return this->to.getName();
}

string letter::getSenderZip() const
{
	return this->from.getZip();
}

string letter::getToZip() const
{
	return this->to.getZip();
}

letter& letter::setSender(const address& sender)
{
	this->from = sender;
	return *this;
}

letter& letter::setTo(const address& to)
{
	this->to = to;
	return *this;
}

letter& letter::setWeight(double weight)
{
	this->weight = weight;
	return *this;
}

const letter& letter::operator= (const letter& right)
{
	this->from = right.from;
	this->to = right.to;
	this->weight = right.weight;

	return *this;
}

double letter::getPostageCost() const
{
	if (weight < 1.0)
		return 0.44;
	else if (weight < 2.0)
		return 0.61;
	else if (weight < 3.0)
		return 0.78;
	else
		return 0.95;
}

void letter::print(ostream& output) const
{
	output << "FROM:" << endl;

	this->from.print(output);

	output << endl << "TO:" << endl;

	this->to.print(output);

	output << endl;
}

void letter::print(ostream& output, const string& creditCardNumber, ofstream& chargeFile) const
{
	this->print(output);

	chargeFile << creditCardNumber << '\t' << "TOTAL CHARGE: " << (this->getPostageCost() * 0.90) << endl;
}

