#ifndef STUDENT_H
#define STUDENT_H

#include "person.h"

#include <string>
using namespace::std;

class Student : public Person
{
public:
	Student();
	Student(double avg, string phrase);
	Student(const Student& copy);
	~Student();

	double getGPA() const;
	void setGPA(double avg);

	void doAction();

private:
	double gpa;
};

#endif
