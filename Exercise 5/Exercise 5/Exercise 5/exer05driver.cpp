// Exercise 05 driver

#include "person.h"
#include <iostream>
using namespace::std;


int main()
{
	person boss("Tom", 42);
	// sending the return value to cout, test the 3 ways of getting the age

	cout << "boss.getAgeV = " << boss.getAgeV() << endl;
	cout << "*boss.getAgeP() = " << *boss.getAgeP() << endl;
	cout << "boss.getAgeA() = " << boss.getAgeA() << endl;

	person * pPointer;						// make a pointer to person object
	pPointer = new person("Susan", 31);	// set aside heap (aka freestore) memory
	// sending the return value to cout, test the 3 ways of getting the age

	cout << "pPointer->getAgeA() = " << pPointer->getAgeA() << endl;
	cout << "*pPointer->getAgeP() = " << *pPointer->getAgeP() << endl;
	cout << "pPointer->getAgeV() = " << pPointer->getAgeV() << endl;

	//  test your member functions

	cout << "Before assignment overloading:\n";
	cout << "boss = ";
	boss.print(cout);
	cout << "pPointer = ";
	(*pPointer).print(cout);

	*pPointer = boss;

	cout << "After assignment overloading (*pPointer = boss):\n";
	cout << "boss = ";
	boss.print(cout);
	cout << "pPointer = ";
	(*pPointer).print(cout);

	
	int a = 0;
	cout << "Enter new age and press enter: ";
	cin >> a;
	boss.changeAge(a);
	cout << "boss.getName() = " << boss.getName() << endl;
	cout << boss.getName() << " age is now set to " << *boss.getAgeP() << endl;
	
	char newName[10] = "Marcia";
	boss.changeName(newName);
	cout << "changeName(newName) changed boss.getName() = " << boss.getName() << endl;

	cout << "Thanks for using CIS235 Exercise 5 program.\n";
	

	delete pPointer; // return memory to heap (aka freestore) for dynamic memory

    return 0;
}

/* My output

boss.getAgeV = 42
*boss.getAgeP() = 42
boss.getAgeA() = 42
pPointer->getAgeA() = 31
*pPointer->getAgeP() = 31
pPointer->getAgeV() = 31
Before assignment overloading:
boss = Tom 42
pPointer = Susan 31
After assignment overloading (*pPointer = boss):
boss = Tom 42
pPointer = Tom 42
Enter new age and press enter: 19
boss.getName() = Tom
Tom age is now set to 19
changeName(newName) changed boss.getName() = Marcia
Thanks for using CIS235 Exercise 5 program.
Press any key to continue . . .

*/
