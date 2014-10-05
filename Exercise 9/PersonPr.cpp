// PersonPr Implementation
#include "PersonPr.h"

PersonPr::PersonPr(void)
{
	this->name = "UNKNOWN";
	this->mother = NULL;
	this->father = NULL;
}

PersonPr::PersonPr(const PersonPr & right)
{
	this->name = right.name;

	if (right.mother == NULL)
		this->mother = NULL;
	else 
		this->mother = new PersonPr(*(right.mother));

	if (right.father == NULL) 
		this->father = NULL;
	else 
		this->father = new PersonPr(*(right.father));
}

PersonPr::PersonPr(const string & theName)  // mother and father not known
{
	this->name = theName;
	this->father = nullptr;
	this->mother = nullptr;
}

PersonPr::PersonPr(const string & theName, const string & motherName, const string & fatherName)
{
	this->name = theName;
	this->father = new PersonPr(fatherName);
	this->mother = new PersonPr(motherName);
}

PersonPr::PersonPr(const string & theName, const PersonPr & motherPerson, const PersonPr & fatherPerson)
{
	this->name = theName;
	this->mother = new PersonPr(motherPerson);
	this->father = new PersonPr(fatherPerson);
}

PersonPr::~PersonPr(void)  // the destructor - return memory allocated with new
{
	cout << "Object " << name << " is leaving" << endl;

	//  ADD CODE BELOW TO RETURN HEAP MEMORY IF NECESSARY
	if (mother != NULL)
	{
		delete mother;
		mother = NULL;
	}

	if (father != NULL)
	{
		delete father;
		father = NULL;
	}
}

string PersonPr::getName(void) const
{
	return this->name;
}
string PersonPr::getMotherName(void) const // if not known, return "UNKNOWN"
{
	return (this->mother == NULL ? "UNKNOWN" : this->mother->getName());
}

string PersonPr::getFatherName(void) const // if not known, return "UNKNOWN"
{
    return (this->father == NULL ? "UNKNOWN" : this->father->getName());
}

string PersonPr::getMaternalGrandMotherName(void) const // if not known, return "UNKNOWN"
{
	if (this->mother == NULL) return "UNKNOWN";

	return (this->mother->mother == NULL ? "UNKNOWN" : this->mother->mother->getName());
}