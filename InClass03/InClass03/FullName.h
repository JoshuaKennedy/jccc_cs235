#ifndef FULL_NAME
#define FULL_NAME
#include <iostream>
#include <cstring>
using namespace::std;

class FullName
{
public:
	FullName();
	FullName(const FullName &);
	FullName(const char * fr, char initial, const char * ls);

	~FullName();

	const char * getFirstName()       const;
	char         getMiddleInitial()   const;
	const char * getLastName()        const;

	void setFirstName(const char *);
	void setMiddleInitial(char);
	void setLastName(const char *);

	void input(void);
	void print(ostream & ) const;  // of the form:    Doe, John A.

	bool isSmaller(const FullName & ) const;   // is invoking instance smaller than parameter

	void copyTo( const FullName &) ;    // copy parameter to invoking instance
    
    bool isEqual(const FullName&) const;

private:
	char * first;
	char   mI;
	char * last;
};
#endif