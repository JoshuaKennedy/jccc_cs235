#include "person.h"

#include <iostream>
using namespace std;

Person::Person() : catchphrase("wow such string")
{
}

Person::Person(string phrase) : catchphrase(phrase)
{
}

Person::Person(const Person& copy)
{
	this->catchphrase = copy.getCatchphrase();
}

Person::~Person()
{
}

string Person::getCatchphrase() const
{
	return this->catchphrase;
}

void Person::setCatchphrase(string phrase)
{
	this->catchphrase = phrase;
}

void Person::doAction()
{
	cout << "*pffft*" << endl;
}
