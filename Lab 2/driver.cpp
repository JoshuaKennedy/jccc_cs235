//   Lab 2 driver  CIS 235 

//  Student - You will not need to change this code
//               Input 5 different phone numbers, some with -'s, some without
//          - Write the code to test the member function that you designed
#include <iostream>
using namespace::std;
#include "phone.h"


// *********************************************************************************
//  user written functions for main

void sort( phone info[], int count);
void print(ostream &, const phone info[], int, const char * message);

//      Main program  **************************************************************

const int ENTRIES = 5;

int main(int argc, char* argv[])
{
    //   test a few functions
	phone jccc("913-469-8500");
	int w1; 
	char w2[20];                  // larger than needed
	w1 = jccc.getNumber();
	jccc.getPhone(w2);
	cout << w1 << ' ' << w2 << endl;

	phone work("9138349312");
	w1 = work.getNumber();
	work.getPhone(w2);
	cout << w1 << ' ' << w2 << endl;

	if ( jccc.sameAreaCode(work))
		cout << "Same area code\n";
	else
		cout << "Different area code\n";

	phone duplicate(jccc);
	cout << "Test of copy constructor\n";
	duplicate.print(cout);

	phone home(913,333,4444);
	cout << "Test of 3 argument constructor\n";
	home.print(cout);

	//   test your member function here  *****************************
    cout << "Testing out phone::phoneTakeApart(char*);" << endl;
    cout << "enter phone string (with/without hyphens): ";
    std::string testString;
    cin >> testString;
    phone testPhone = phone(testString.c_str());
    testPhone.print(cout);

    //  bring in the data and sort the data
	phone friends[ENTRIES];
    
	cout << "Enter " << ENTRIES << " Phone numbers "
		             << "of the form 913-469-8500 or 9134698500\n";
   int i;
	for ( i = 0; i < ENTRIES ; i++)
		friends[i].input();

	print(cout,friends,ENTRIES,"First array before sorting");

	sort(friends,ENTRIES);

	print(cout,friends,ENTRIES,"Numbers after sorting");
    
    return 0;
}

//  **********************  User written functions  ***************

//   THE FOLLOWING CODE WILL NOT BE CHANGED

void swapValues(phone &, phone &);      //  used in sort

int  indexSmallest(const phone data[] , int start, int count);  // used in sort

void sort(phone info[], int count)
{
	 //  Selection sort
	int smallIndex;
	for ( int i =0 ; i < count -1; i++)
	{
		smallIndex = indexSmallest(info,i,count);
		if ( i != smallIndex)
			swapValues(info[i],info[smallIndex]);
	}
}

void swapValues(phone & left, phone & right)
{
  phone work;
  left.copyTo(work);
  right.copyTo(left);
  work.copyTo(right);
}

int indexSmallest(const phone data[], int start, int numberUsed)
{
  int indexMin = start;
  phone min(data[start]);
  for ( int i = start + 1; i < numberUsed; i++)
  {
		if ( data[i].isSmaller(min) )
	  {
		  indexMin = i;
		  data[i].copyTo(min);
	  }
  }
  return indexMin;
}

void print(ostream & w, const phone info[], int count, const char * message)
{
	w << message << endl;
	for(int i = 0; i < count; i++)
	{
		 info[i].print(w);
		 w << endl;
	}
}

/* output:
 
 4699850 9134699850
 8349312 9138349312
 Same area code
 Test of copy constructor
 (913) 469-9850
 Test of 3 argument constructor
 (913) 333-4444
 Testing out phone::phoneTakeApart(char*);
 enter phone string (with/without hyphens): 1234567890
 (123) 456-7890
 Enter 5 Phone numbers of the form 913-469-8500 or 9134698500
 9134888146
 816-201-3831
 5555555555
 1234567890
 800-255-3700
 First array before sorting
 (913) 488-8146
 
 (816) 201-1383
 
 (555) 555-5555
 
 (123) 456-7890
 
 (800) 255-5370
 
 Numbers after sorting
 (123) 456-7890
 
 (555) 555-5555
 
 (800) 255-5370
 
 (816) 201-1383
 
 (913) 488-8146
 
 Program ended with exit code: 0
 
 */
