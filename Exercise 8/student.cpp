#include "student.h"

#include <iostream>
using namespace std;

Student::Student() : Person("I hate school."), gpa(3.25)
{
}

Student::Student(double avg, string phrase) : Person(phrase), gpa(avg)
{
}

Student::Student(const Student& copy)
{
	this->setCatchphrase(copy.getCatchphrase());
	this->gpa = copy.getGPA();
}

Student::~Student()
{
}

double Student::getGPA() const
{
	return this->gpa;
}

void Student::setGPA(double avg)
{
	this->gpa = avg;
}

void Student::doAction()
{
	cout << "I need more sleep and less homework!" << endl;
}
