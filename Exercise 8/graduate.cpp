#include "graduate.h"

#include <iostream>
using namespace std;

Graduate::Graduate() : Student(3.75, "I'm glad that I'm done with school!"), graduationYear(1995)
{
}

Graduate::Graduate(int year, double avg, string phrase) : Student(avg, phrase), graduationYear(year)
{
}

Graduate::Graduate(const Graduate& copy)
{
	this->setCatchphrase(copy.getCatchphrase());
	this->setGPA(copy.getGPA());
	this->graduationYear = copy.getGraduationYear();
}

Graduate::~Graduate()
{
}

int Graduate::getGraduationYear() const
{
	return this->graduationYear;
}

void Graduate::setGraduationYear(int year)
{
	this->graduationYear = year;
}

void Graduate::doAction()
{
	cout << "See ya' losers!" << endl;
}