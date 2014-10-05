#ifndef FRIENDS_H
#define FRIENDS_H
#include <iostream>
#include <cstring>
using namespace::std;
#include "FullName.h"

const int NUMBER_FRIENDS = 5;
class Friends
{
public:
	Friends();
	Friends(const Friends &);
	
	~Friends();

	bool isFull(void) const;
	bool isEmpty(void) const;

	bool addFront(const FullName &);     // return true if room and data added
	bool addRear(const FullName &);      // return true if room and data added
	
	bool removeFront();     // return true if not empty and data removed
	bool removeRear();      // return true if not empty and data removed

	const Friends & operator=(const Friends & );

	bool isSorted(void) const;           // return true is the names are sorted, use the < operator for FullName

	void printAll(ostream &);

	int findFriend( const char * firstName) const;  // return first location where a FullName
	                                                // is found with the same firstName
	                                                // return -1 is not found

	FullName retrieveFriend(int location ) const;   // starting at 1 return the FullName in the
	                                                //   requested location
	                                                //   if the location is not valid return a "dummy" FullName object

	bool removeFriend(int location ) const;   // starting at 1 delete the FullName in the
	                                                //   requested location  return true if location
	                                                //   is valid and data is removed


private:
     int placer;     // subscript of first empty cell, work left to right
	                 // NOTE:  could also use last occupied cell

	 FullName info[NUMBER_FRIENDS];



};
#endif