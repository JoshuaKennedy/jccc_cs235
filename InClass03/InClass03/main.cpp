#include "FullName.h"
#include <iostream>
using namespace::std;

int main()
{
	{
        FullName singer("Patsy",'P',"Cline");
        FullName anotherSinger(singer);
        anotherSinger.input();
        
	}   // want singer to go out of scope so destructor will be called
	char t;
	cin.get(t);
	cin.get(t);
	return 0;
    
}
/*
 FIRST NAME: Patsy added at address 00154A98
 FIRST NAME: Patsy added at address 00154B30
 Connie
 FIRST NAME: Patsy deleted from address 00154B30
 FIRST NAME: Connie added at address 00154B30
 FIRST NAME: Connie deleted from address 00154B30
 FIRST NAME: Patsy deleted from address 00154A98
 */
