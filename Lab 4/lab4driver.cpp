#include "address.h"
#include "letter.h"

#include <iostream>
#include <string>
using namespace::std;

int main()
{
	//  include code to test your member functions as you go along
	address sample("JCCC","66210");

	sample.print(cout);

	//  after you have tested your functions, execute the following
	ofstream creditChargeFile;
	creditChargeFile.open("./charges.txt");

	letter saleNotice("The Bookstore","66210","Mike Smith","64114", 3.1);
	saleNotice.print(cout,"5401 8211 4567 9912",creditChargeFile);

    creditChargeFile.close();

	return 0;
}
