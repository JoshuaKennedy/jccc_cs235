#include <iostream>
using namespace::std;
#include "BigInteger.h"
#include "CollectionBigInteger.h"
int main()
{
   cout << "Number of digits in our numbers is " << BigInteger::getNumberOfDigits() << endl;
   cout << "Number of cells in CollectionBigInteger is " << CollectionBigInteger::getNumberOfCellsAllocated() << endl;
   {
	   // test module 1
	   BigInteger::debugOn = false;
	   cout << endl << "***** Test module 1 with debugOn false *****" << endl;
	   // test default constructor, destructor, placeInto and << operator
	   CollectionBigInteger info;
	   cout << "The data in the variable info is " << info << endl;
	   info.placeInto(BigInteger("4567887"));
	   info.placeInto(BigInteger(987654));
	   info.placeInto(BigInteger("45678870000000"));
	   cout << "The data in the variable info is "  << info << endl;
	   cout << "The largest value in info is " << info.findLargest() << endl;
   }  // end module 1
    
   {
	   BigInteger::debugOn = true;
	   cout << endl <<  "***** Test module 2 with debugOn true *****" << endl ;
	   // test default constructor, destructor, placeInto and << operator
	   CollectionBigInteger info;
	   cout << "The data in the variable info is " << info << endl;
	   info.placeInto(BigInteger("4567887"));
	   info.placeInto(BigInteger(987654));
	   info.placeInto(BigInteger("45678870000000"));
	   cout << "The data in the variable info is "  << info << endl;
	   cout << "The largest value in info is " << info.findLargest() << endl;
   }  // end module 2
    
   {
	   BigInteger::debugOn = false;
	   cout << endl <<  "***** Test module 3 with debugOn false *****" << endl ;
	   
	   CollectionBigInteger info1, info2, info3, info4;
	   info1.placeInto(BigInteger(50));
	   info1.placeInto(BigInteger(30));
	   info1.placeInto(BigInteger(40));
	   cout << "The data in the variable info1 is "  << info1 << endl;
	   cout << "The largest value in info is " << info1.findLargest() << endl;

	   info2.placeInto(BigInteger(5));
	   info2.placeInto(BigInteger(9));
	   info2.placeInto(BigInteger(3));
	   info2.placeInto(BigInteger(4));
	   info2.placeInto(BigInteger(300));
	   info4.placeInto(BigInteger(51));
	   info4.placeInto(BigInteger(30));
	   info4.placeInto(BigInteger(40));
	   cout << "The data in the variable info2 is "  << info2 << endl;
	   cout << "The largest value in info2 is " << info2.findLargest() << endl;

	   // test = operator
	   info3 = info1 ;
	   cout << "info3 after = is " << info3 << endl;
	   // test == operator
	   cout << "test of info1 == info3 " << (info1 == info3) << endl;
	   cout << "test of info1 == info4 " << (info1 == info4) << endl;
	   cout << "test of info1 == info2 " << (info1 == info2) << endl;
	   // test + operator
	   info3 = info1 + info2;
	   cout << info1 << " plus " << info2 << " gives " << info3 << endl;
	   info3 = info1 + info2;
	   cout << info2 << " plus " << info1 << " gives " << info3 << endl;
   }    // end module 3
}
