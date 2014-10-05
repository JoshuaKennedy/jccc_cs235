#include "shape.h"
#include "point.h"
#include "circle.h"
#include "cylinder.h"
#include "rectangle.h"
#include <iostream>
using namespace::std;
char directions(void);

void main()
{
	Shape * * info;     // array of pointers to shape objects
	int numberOfObjects;
	cout << "Enter the number of shape objects you want to create: ";
	cin >> numberOfObjects;
	info = new Shape * [numberOfObjects];    // create an array of shape pointers
	for ( int i = 0; i < numberOfObjects; i++)
	{
		char choice = directions();
		switch (choice)
		{
		  case 'p':   info[i] = new Point;
			          break;
		  case 'c':   break;
		  case 'y':   break;
		  case 'r':   break;
		  default:    cout << "Invalid Choice:" << endl;
		}
		info[i]->input(cin);
	}

	for ( int i = 0; i < numberOfObjects; i++)
	{
		cout << "An object of type " << info[i]->objectType() << endl;
		info[i]->print(cout);
		cout << "With area of " << info[i]->area() << endl;
		cout << endl;
	}

	for ( int i = 0; i < numberOfObjects; i++)
	{
		delete info[i];    // return individual shape memory, cell by cell
	}

	delete [] info;       // return array memory

	char temp;
	cin >> temp;


	return;
}

char directions(void)
{
	char ch;
	cout << "Enter p for point, c for circle, y for cylinder, r for rectangle ";
	cin >> ch;
	while ( ! ( ch == 'p' || ch == 'c' || ch == 'y' || ch == 'r' ) )
	{
		cout << "Invalid choice, try again" << endl;
		cin >> ch;
	}
	return ch;
}