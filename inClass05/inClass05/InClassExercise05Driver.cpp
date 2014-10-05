#include <iostream>
using namespace::std;
#include "FullName.h"
#include "Friends.h"

int main()
{
    Friends myPals;
    
    myPals.addRear(FullName("Brandon", 'C', "Cady"));
    myPals.addRear(FullName("Chad", 'P', "Jensen"));
    myPals.addRear(FullName("Frank", 'D', "Overton"));
    
	return 0;
}