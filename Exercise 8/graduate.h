#ifndef GRADUATE_H
#define GRADUATE_H

#include "student.h"

#include <string>
using namespace::std;

class Graduate : public Student
{
public:
	Graduate();
	Graduate(int year, double avg, string phrase);
	Graduate(const Graduate& copy);
	~Graduate();

	int getGraduationYear() const;
	void setGraduationYear(int year);

	void doAction();

private:
	int graduationYear;
};

#endif
