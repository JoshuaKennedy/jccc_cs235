#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <cstring>
using namespace::std;

class person
{
   public:
       person(void);                      // new needed, strcpy needed
       person(const char * n, int a);     // new needed, strcpy needed
       person(const person & other);      // new needed, strcpy needed

       ~person(void);                     // delete needed

       int getAgeV(void) const;
       const int * getAgeP(void) const;
       const int & getAgeA(void) const;

	   const person & operator=(const person & right);     // = operator

       const char * getName(void) const; 

       void changeAge( int newAge);
       void changeName( const char * newName);  //  delete, new and strcpy needed

       void print(ostream &) const;

   private:
       int age;
       char * pName;
 };



#endif