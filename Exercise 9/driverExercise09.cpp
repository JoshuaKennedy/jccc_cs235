// Driver for Exercise 9
#include "PersonPr.h"
#include <iostream>
using namespace std;


void main()
{
   PersonPr a;
   cout << "Name: " << a.getName() << " Mother: " << a.getMotherName()
	   << " Father: " << a.getFatherName() << endl;

   PersonPr b("Tom");
   cout << "Name: " << b.getName() << " Mother: " << b.getMotherName()
	   << " Father: " << b.getFatherName() << endl;

   PersonPr c("Ralph", "Sue", "Bill");
   cout << "Name: " << c.getName() << " Mother: " << c.getMotherName()
	   << " Father: " << c.getFatherName() << endl;

   PersonPr d("Paul",PersonPr("Ann","Beth","Carl"),PersonPr("David","Kathy","Mark"));
   cout << "Name: " << d.getName() << " Mother: " << d.getMotherName()
	   << " Father: " << d.getFatherName() << endl;
   cout << "Grandmother of " << d.getName() << " is " << d.getMaternalGrandMotherName() << endl;

   PersonPr copyOfD(d);
   cout << "Name: " << copyOfD.getName() << " Mother: " << copyOfD.getMotherName()
	   << " Father: " << copyOfD.getFatherName() << endl;
   cout << "Grandmother of " << copyOfD.getName() << " is " << copyOfD.getMaternalGrandMotherName() << endl;

   cout << "Grandmother of " << a.getName() << " is " << a.getMaternalGrandMotherName() << endl;
   cout << "Grandmother of " << b.getName() << " is " << b.getMaternalGrandMotherName() << endl;
   cout << "Grandmother of " << c.getName() << " is " << c.getMaternalGrandMotherName() << endl;


}