#include <iostream>
using namespace::std;
#include "Vehicle.h"
#include "Boat.h"
#include "Bicycle.h"


int main()
{
	Vehicle myVehicle(1993, 1200);
	Vehicle yourVehicle(1982,3000);
	Boat myBoat(2010,6000,100);
	Boat yourBoat(1965, 500, 6);
    cout << "myVehicle is " << myVehicle << endl;
    cout << "yourBoat is " << yourBoat << endl;
    cout << "myVehicle information" << endl;
    myVehicle.print(cout);
    cout << endl;
    cout << "yourBoat information" << endl;
    yourBoat.print(cout);
    cout << endl;

    // Students ==> write some code to test your class Bicycle
	Bicycle myBike = Bicycle(1995, 36, true);
	cout << myBike;

	cout << "Chad's Bike" << endl;
	Bicycle chadBike;
	cin >> chadBike;
	cout << chadBike;

	cout << "Brandon's Bike" << endl;
	Bicycle brandonBike;
	cout << brandonBike;

	return 0;
}
