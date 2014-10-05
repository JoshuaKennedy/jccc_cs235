#include "Person.h"

//  *****************    THIS CODE WILL NOT COMPLILE UNTIL MIL CODE IS WRITTEN FOR THE INSTANCE FIELD yearBorn   *************

ostream & operator<<( ostream & out, const Person & r)
{
	out << r.yearBorn << ' ' << r.name;
	if ( r.mother == NULL )
		out << "Information on mother not available";
	else
	    out << "Mother: " << r.mother->yearBorn << ' ' << r.mother->name;
	return out;
}


Person::Person(void)
: yearBorn(1900), name("John", 'D', "Doe")
{
	mother = NULL;
}

Person::Person( const Person & r)
: yearBorn(r.yearBorn), name(r.getFirstName(), r.getMiddleInitial(), r.getLastName()), mother(r.mother)
{
	if ( r.mother == NULL )
		mother = NULL;
	else
		mother = new Person(r.mother->name,r.mother->yearBorn);
}

Person::Person( const char * first, char middle, const char * last, int year,
	       const char * firstMother, char middleMother, const char * lastMother, int yearMother)
: yearBorn(year), name(first, middle, last)
      
{
	   mother = new Person(FullName(firstMother,middleMother,lastMother),yearMother);
}

Person::Person( const FullName & r, int year)
: yearBorn(year), name(r.getFirstName(), r.getMiddleInitial(), r.getLastName())
{
	mother = NULL;
}

Person::~Person()
{
	if ( mother != NULL ) delete mother;

}

const char * Person::getFirstName()       const
{
     return name.getFirstName();
}

char Person::getMiddleInitial()   const
{
	 return 'x';         // STUDENTS:  write the code to return the middle initial
}

const char * Person::getLastName()        const
{
	return name.getLastName();
}

int Person::getYearBorn()        const
{
     return yearBorn;
}

Person & Person::setFirstName(const char * r)
{
	name.setFirstName(r);
    return *this;
}

Person & Person::setMiddleInitial(char r )
{
	name.setMiddleInitial(r);
	return *this;
}

Person & Person::setLastName(const char * r)
{
    name.setLastName(r);
	return *this;
}



const Person & Person::print(ostream & out) const
{
	out << yearBorn << ' ' << name;
	if ( mother == NULL )
		out << "Information on mother not available";
	else
	    out << "Mother: " << mother->yearBorn << ' ' << mother->name;
    return *this;
}

bool Person::operator<(const Person & r) const    
{
     if ( this->name < r.name ) return true;
	 if ( r.name < name )       return false;
	 return yearBorn < r.yearBorn;
}

bool Person::areSiblings(const Person & r) const
{
	//  STUDENTS:  write the code to return false if there in no information on the mother of
	//                    either the invoking instance or the parameter
	

	//   STUDENTS:  write the code to return true if the mother's name for both the invoking instance and the parameter are the same
	//                   and the year born for both the invoking instance and the parameter are the same
	//              otherwise return false
	//    NOTE:  the FullName class has a == operator

    return (this->mother->name == r.mother->name);
}


bool Person::hasMotherInformation()       const
{
	return mother != NULL;
}

const char * Person::getMotherFirstName() const
{
	// precondition hasMotherInformation() is true

	//  STUDENTS:   write the code to return the name of the mother of the invoking instance
    FullName motherName = this->mother->name;

	return motherName.getFirstName();   //  THIS CODE IS WRONG, ONLY HERE TO GET THE PROGRAM TO COMPILE

}

const Person & Person::operator=(const Person &)
{
	// this code has not been written
    return *this;
}