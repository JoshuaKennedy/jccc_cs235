#include "person.h"
#include "student.h"
#include "graduate.h"

#include <iostream>
#include <string>
using namespace::std;
/*
All of the files are blank.  You are to design your own classes and
          write your own driver program.

Graduate will inherit from Student and Student will inherit from Person.

Keep things simple => only one data item per class is ok.  Use the
String class for all non-numeric data.

Be sure and write argument and copy constructor functions and use
        Member Initialization List.

Write at least one overridden function.

*/

int main()
{
	Person josh = Person("wow such catchphrase very catchy wow");

	josh.doAction();

	cout << "Josh's catchphrase is: " << josh.getCatchphrase() << endl;

	Student chad = Student(3.86, "I don't know, lol.");

	cout << "Chad's GPA is: " << chad.getGPA() << endl;
	cout << "Chad's catchphrase is: " << chad.getCatchphrase() << endl;

	chad.doAction();

	Graduate brandon = Graduate(2014, 3.6, "lol");

	cout << "Brandon's Graduation Year is: " << brandon.getGraduationYear() << endl;
	cout << "Brandon's GPA is: " << brandon.getGPA() << endl;
	cout << "Brandon's catchphrase is: " << brandon.getCatchphrase() << endl;
	
	brandon.doAction();

#if defined(WIN32)
	system("PAUSE");
#elif defined(__APPLE__)
	// OS X doesn't have anything like pause, and getchar doesn't work that well. :(
#endif

	return 0;
}