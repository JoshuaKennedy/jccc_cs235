#include "person.h"

person::person(void)// new needed, strcpy needed
{
   age = 0;
   pName = new char[strlen("default") + 1];
   strcpy (pName, "default");
}
person::person(const char * n, int a)     // new needed, strcpy needed
{
   age = a;
   pName = new char [strlen (n) + 1];
   strcpy (pName, n);
}
person::person(const person & other)    // new needed, strcpy needed
{
   age = other.age;
   pName = new char [strlen (other.pName) + 1];
   strcpy (pName, other.pName);
}

person::~person(void)    // delete needed
{
   delete [] pName;
}

int person::getAgeV(void) const
{
   return age;
}

const int * person::getAgeP(void) const
{
   return & age;
}

const int & person::getAgeA(void) const
{
   return age;
}

// = operator
const person & person::operator=(const person & right) {

	if(this == & right) return * this;

	age = right.age;
	
	// check to see if heap memory has been allocated for country
	// if memory has been allocated, return the memory
	// to avoid a memory leak
	if (pName != NULL) delete [] pName; // return memory to heap (aka freestore) for dynamic array
	pName = new char [strlen(right.pName) + 1];
	strcpy(pName, right.pName);
	return * this;
}

const char * person::getName(void) const
{
   return pName;
}

void person::changeAge( int newAge)
{
   age = newAge;
}

//  delete, new and strcpy needed
void person::changeName( const char * newName) {

	// check to see if heap memory has been allocated for country
	// if memory has been allocated, return the memory
	// to avoid a memory leak
	if (pName != NULL) delete [] pName; // return memory to heap (aka freestore) for dynamic array
	
	pName = new char [strlen(newName) + 1];
	strcpy (pName, newName);  
}

void person::print(ostream & out) const
{
   out << getName() << " " << getAgeA() << endl;
}
