#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace::std;

class Person
{
public:
	Person();
	Person(string phrase);
	Person(const Person& copy);
	~Person();

	string getCatchphrase() const;
	void setCatchphrase(string phrase);

	virtual void doAction();

private:
	string catchphrase;
};

#endif
