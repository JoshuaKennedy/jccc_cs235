#include "FullName.h"

FullName::FullName()
{
   first = NULL;
   setFirstName("John");
}

FullName::FullName(const FullName & other)
{
   first = NULL;
   setFirstName(other.getFirstName());
}

FullName::FullName(const char * fr, char initial, const char * ls)
{
   first = NULL;
   setFirstName(fr);
}

FullName::~FullName()
{
    if ( first != NULL ) 
	{
	    cout << "FIRST NAME: " << first << " deleted from address " 
			 << static_cast<void *>(first) << endl;
	   delete [] first;
	}
}

const char * FullName::getFirstName()       const
{
	return first;
}

char  FullName::getMiddleInitial()    const
{
		return 'X';     // only here to get a compile - MUST be removed
}

const char * FullName::getLastName()         const
{
		return NULL;    // only here to get a compile - MUST be removed
}

void FullName::setFirstName(const char *fr)
{
   if ( first != NULL ) 
	   {
	    cout << "FIRST NAME: " << first << " deleted from address " 
			 << static_cast<void *>(first) << endl;
	    delete [] first;    // return heap memory
	}	   
   first = new char[strlen(fr) + 1];
   strcpy(first, fr);
   cout << "FIRST NAME: " << first << " added at address " 
			 << static_cast<void *>(first) << endl;

}

void FullName::setMiddleInitial(char m)
{
    this->mI = m;
}

void FullName::setLastName(const char * ln)
{
    this->last = (char*)ln;
}

void FullName::input(void)
{
	char tempFirst[100];
	cin.getline(tempFirst, 100);
	setFirstName(tempFirst);
}
void FullName::print(ostream & ) const  // of the form:    Doe, John A.
{
}

bool FullName::isSmaller(const FullName & right) const   // is invoking instance smaller than parameter
{
	if ( strcmp(getFirstName(),right.getFirstName()) < 0 )
        return true;
    else if (right.getMiddleInitial() < this->mI)
        return true;
    else if ( strcmp(getFirstName(),right.getFirstName()) < 0 )
        return true;
	else
        return false;
}

void FullName::copyTo( const FullName & right)    // copy parameter to invoking instance
{
   setFirstName(right.getFirstName());
}

bool FullName::isEqual(const FullName& right) const
{
    if ( strcmp(getFirstName(),right.getFirstName()) == 0 )
        return true;
    else if (right.getMiddleInitial() == this->mI)
        return true;
    else if ( strcmp(getFirstName(),right.getFirstName()) == 0 )
        return true;
	else
        return false;
}
