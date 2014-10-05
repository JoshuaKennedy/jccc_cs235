#include "FullName.h"

ostream & operator<<( ostream & out, const FullName & r)
{
    out << r.getFirstName() << " " << r.getLastName();
	return out;
}

FullName::FullName()
{
   first = NULL;
   setFirstName("John");
   setMiddleInitial('Q');
   last = NULL;
   setLastName("Public");
}

FullName::FullName(const FullName & other)
{
   first = NULL;
   setFirstName(other.getFirstName());
   setMiddleInitial(other.getMiddleInitial());
   last = NULL;
   setLastName(other.getLastName());
}

FullName::FullName(const char * fr, char initial, const char * ls)
{
   first = NULL;
   setFirstName(fr);
   setMiddleInitial(initial);
   last = NULL;
   setLastName(ls);
}

FullName::~FullName()
{
    if ( first != NULL ) delete [] first;
	if ( last  != NULL ) delete [] last;
}

const char * FullName::getFirstName()       const
{
	return first;
}

char  FullName::getMiddleInitial()    const
{
		return mI;
}

const char * FullName::getLastName()         const
{
		return last;
}

void FullName::setFirstName(const char *fr)
{
   if ( first != NULL ) delete [] first;
   first = new char[strlen(fr) + 1];
   strcpy(first, fr);

}
void FullName::setMiddleInitial(char m)
{
    mI = m;
}

void FullName::setLastName(const char * ls)
{
   if ( last != NULL ) delete [] last;
   last = new char[strlen(ls) + 1];
   strcpy(last, ls);
}

void FullName::input(void)
{
	char tempFirst[100];
	cin >> tempFirst;
	setFirstName(tempFirst);
	char tempMiddle;
	cin >> tempMiddle;
	setMiddleInitial(tempMiddle);
	char tempLast[100];
	cin >> tempLast;
	setLastName(tempLast);
}
void FullName::print(ostream & out ) const  // of the form:    Doe, John A.
{
	out << getLastName() << ',' << getFirstName() << ' ' << getMiddleInitial() << '.';
}

bool FullName::isSmaller(const FullName & right) const   // is invoking instance smaller than parameter
{
	int lastResult = strcmp(getLastName(),right.getLastName());
	if ( lastResult < 0 ) return true;
	if ( lastResult > 0 ) return false;
	int firstResult = strcmp(getFirstName(),right.getFirstName());
	if ( firstResult < 0 ) return true;
	if ( firstResult > 0 ) return false;
	return getMiddleInitial() < right.getMiddleInitial();
	return false;
}

bool FullName::operator<(const FullName & right) const
{
	int lastResult = strcmp(getLastName(),right.getLastName());
	if ( lastResult < 0 ) return true;
	if ( lastResult > 0 ) return false;
	int firstResult = strcmp(getFirstName(),right.getFirstName());
	if ( firstResult < 0 ) return true;
	if ( firstResult > 0 ) return false;
	return getMiddleInitial() < right.getMiddleInitial();
	return false;
}

void FullName::copyTo( const FullName & right)    // copy parameter to invoking instance
{
   if ( this == & right ) return;
   setFirstName(right.getFirstName());
   setMiddleInitial(right.getMiddleInitial());
   setLastName(right.getLastName());
   return;
}

const FullName & FullName::operator=(const FullName & right)
{
   if ( this == & right ) return *this;
   setFirstName(right.getFirstName());
   setMiddleInitial(right.getMiddleInitial());
   setLastName(right.getLastName());
   return *this;
}
