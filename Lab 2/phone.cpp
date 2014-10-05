//    Lab 2     
//    IMPLEMENTATION OF CLASS MEMBER FUNCTIONS
//    Student - write the code for each member function
//            - also write the code for the member function you designed

#include "phone.h"
#include <cmath>
#include <cstring>
using namespace::std;

const char phone::SEPARATOR = '-';      //  give out the class data

const int phone::TOLL_FREE_EXCHANGES[COUNT_TOLL_FREE] = { 800, 822, 833, 844, 855, 866, 877, 880, 881, 882, 888 };

bool phone::tollFree(void) const   // return true if a toll free number
{
	if (areaCode == TOLL_FREE_EXCHANGES[0] || areaCode == TOLL_FREE_EXCHANGES[1])
		return true;
	else
		return false;
}

phone::phone(void)
{
	setPhone(111,222,3333);
}

phone::phone(int area, int exchange, int num)
{
	setPhone(area, exchange, num);
}

phone::phone(const phone & other)
{
	areaCode = other.areaCode;
	theExchange = other.theExchange;
	theLast4 = other.theLast4;
}

phone::phone(const char s[])
{
	setPhone(s);
}

phone::~phone(void)
{ }

void phone::setPhone(int area, int exchange, int num)
{
	areaCode = area;
	theExchange = exchange;
	theLast4 = num;
}

void phone::setPhone(const char sn[])
{
    // Enough to store with the hypens or without, including null char.
	char wow[13];

    // Copy sn to wow.
	//strncmp(wow, sn, 13);
    
    // For some reason, strncmp didn't work but this did. Weird!
    for (int i = 0; i < 13; i++)
	{
		wow[i] = '\0';
	}
    
	for (int i = 0; i < 13; i++)
	{
		wow[i] = sn[i];
	}

    // Can't forget this.
	wow[12] = '\0';

	// Remove the separators.
	if (strlen(wow) == 12)
	{
		// Copy the indexes 4-6 to 3-5.
		strncpy(wow + 3, wow + 4, 3);

		// Copy the indexes 8-11 to 7-10
		strncpy(wow + 7, wow + 8, 4);

		// Set the null char after the phone number.
		wow[10] = '\0';
	}

	this->phoneTakeApart(wow);
}


void phone::getPhone(char * s) const
{
	// Dividing by 100 gives us the first digit of the set.
	// Mod 100 and dividing by 10 gives us the second.
	// Mod 10 gives us the third.
	s[0] = '0' + areaCode / 100;
	s[1] = '0' + (areaCode % 100) / 10;
	s[2] = '0' + (areaCode % 10);
	
	s[3] = '0' + theExchange / 100;
	s[4] = '0' + (theExchange % 100) / 10;
	s[5] = '0' + (theExchange % 10);

	s[6] = '0' + theLast4 / 1000;
	s[7] = '0' + (theLast4 % 1000) / 100;
	s[8] = '0' + (theLast4 % 100) / 10;
	s[9] = '0' + theLast4 % 10;
	s[10] = '\0';
}

void phone::print(ostream & w) const
{
    w << '(' << this->areaCode << ')' << ' ' << this->theExchange << '-' << this->theLast4 << endl;
}

void phone::input(void)
{
    std::string inputString;
    
    cin >> inputString;
    
    this->setPhone(inputString.c_str());
}


void phone::copyTo(phone& r) const
{
	char temp[11];
    this->getPhone(temp);
    r.setPhone(temp);
}

bool phone::isSmaller(const phone& r) const
{
	if (areaCode < r.areaCode) return true;
	else if (areaCode > r.areaCode) return false;
	else if (theExchange < r.areaCode) return true;
	else if (theExchange > r.areaCode) return false;
	else if (theLast4 < r.theLast4) return true;
	else return false;

}

int phone::getNumber(void) const
{
	return ((this->theExchange * 10000) + this->theLast4);
}

bool phone::sameAreaCode(const phone& other) const
{
	if (other.areaCode == this->areaCode) return true;
    else return false;
}

// write the code for the member function that you designed
void phone::phoneTakeApart(const char pd[])
{
    // Stores numbers (the last 4 digits plus null as max length).
	char temp[5];

	// Parts of the number, area code, exchange, and last 4.
	int npa = 0, nxx = 0, xxxx = 0;
    
    // Split the numbers and convert them to int via atoi.
	strncpy(temp, pd, 3);
	temp[3] = '\0';
	npa = atoi(temp);

	strncpy(temp, pd + 3,3);
	temp[3] = '\0';
	nxx = atoi(temp);

	strncpy(temp, pd + 6, 4);
	temp[4] = '\0';
	xxxx = atoi(temp);
	
	// Set the attributes to their values.
	this->setPhone(npa, nxx, xxxx);
}
