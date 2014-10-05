#include <iostream>
using namespace::std;
#include "FullName.h"
#include "Person.h"

int main()
{
	Person one(FullName("Sue",'H', "Jones"), 1976) , two(FullName("Bill",'G', "Adams"),1983);
	cout << "ONE IS " << one << endl;
	cout << "TWO IS " << two << endl;
	Person one1("Sue",'H', "Jones", 1976, "Betty",'K',"Jones",1950) , 
		   two1("Bill",'G', "Jones",1983, "Betty",'K',"Jones",1950),
		   two2("Tom",'W', "Wilson",1984, "Betty",'K',"Jones",1951),
		   two3("Ann",'B', "Smith",1983, "Mary",'K',"Jones",1950);
	cout << "ONE1 IS " << one1 << endl;
	cout << "TWO1 IS " << two1 << endl;
	cout << "TWO2 IS " << two2 << endl;
	cout << "TWO3 IS " << two3 << endl;
    cout << "one and two siblings "   << one.areSiblings(two) << endl;
	cout << "one1 and two1siblings "  << one1.areSiblings(two1) << endl;
	cout << "one1 and two2 siblings " << one1.areSiblings(two2) << endl;
	cout << "one1 and two3 siblings " << one1.areSiblings(two3) << endl;
	cout << "TWO3 is " << two3.getFirstName() << ' ' << two3.getMiddleInitial() << ' ' << two3.getLastName() << endl;
	if ( two3.hasMotherInformation() ) 
		cout << "First name of two3 mother is " << two3.getMotherFirstName() << endl;
	else
		cout << "No information on mother of two2" << endl;
	if ( two.hasMotherInformation() ) 
		cout << "First name of two mother is " << two.getMotherFirstName() << endl;
	else
		cout << "No information on mother of two" << endl;
		
	return 0;
}
/*
ONE IS 1976 Jones, Sue H. Information on mother not available
TWO IS 1983 Adams, Bill G. Information on mother not available
ONE1 IS 1976 Jones, Sue H. Mother: 1950 Jones, Betty K.
TWO1 IS 1983 Jones, Bill G. Mother: 1950 Jones, Betty K.
TWO2 IS 1984 Wilson, Tom W. Mother: 1951 Jones, Betty K.
TWO3 IS 1983 Smith, Ann B. Mother: 1950 Jones, Mary K.
one and two siblings 0
one1 and two1siblings 1
one1 and two2 siblings 0
one1 and two3 siblings 0
TWO3 is Ann B Smith
First name of two3 mother is Mary
No information on mother of two
Press any key to continue . . .
*/