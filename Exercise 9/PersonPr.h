// PersonPr class

#ifndef PERSONPR_H
#define PERSON_H
#include <string>
#include <iostream>
using namespace::std;

class PersonPr
{
public:
	PersonPr(void);
	PersonPr( const PersonPr & right);
	PersonPr( const string & theName);  // mother and father not known
	PersonPr( const string & theName, const string & motherName, const string & fatherName);
	PersonPr( const string & theName, const PersonPr & motherPerson, 
		                              const PersonPr & fatherPerson);
	~PersonPr(void);  // the destructor - return memory allocated with new
	string   getName(void) const;
	string   getMotherName(void) const; // if not known, return "UNKNOWN"
	string   getFatherName(void) const; // if not known, return "UNKNOWN"
	string   getMaternalGrandMotherName(void) const; // if not known, return "UNKNOWN"

private:
    string name;
	PersonPr * mother;   // node data type of PersonPr is not possible
	PersonPr * father;   //    because that would be a recursive definition
	     //  use NULL if mother's or father's information is not available



};




#endif