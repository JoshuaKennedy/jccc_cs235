// CIS 235 In Class Exercise 06
// Composition  a Person has a FullName
// Need to use Member Initialization List (MIL) for all Person constructors

#ifndef PERSON_H
#define PERSON_H
#include "FullName.h"

class Person
{
friend ostream & operator<<( ostream &, const Person &);

public:
   Person( void);                   // Default Constructor
   Person( const Person &);         // Copy Constructor
   Person( const char * first,       char middle,       const char * last,       int year,
	       const char * firstMother, char middleMother, const char * lastMother, int yearMother);
   Person( const FullName &, int year);

   ~Person();

   const char *   getFirstName()       const;
   char           getMiddleInitial()   const;
   const char *   getLastName()        const;
   int            getYearBorn()        const;
   const Person * getMother()          const;

   Person & setFirstName(const char *);
   Person & setMiddleInitial(char);
   Person & setLastName(const char *);

   bool hasMotherInformation()       const;
   const char * getMotherFirstName() const;
   const Person & print(ostream & )  const;  // of the form:    1964 Doe, John A.

   bool operator<(const Person & ) const;    // STUDENT determines the meaning of <, must consider BOTH instance fields

   bool areSiblings(const Person & ) const;   // does the invoking instance have the same mother as the parameter

   const Person & operator=(const Person &);


private:
	FullName   name;
	const int  yearBorn;
	Person *   mother;         // pointer to the Person Object with information about the mother
	                           //    NOTE:  in the person class we have a pointer to a person object
};

#endif