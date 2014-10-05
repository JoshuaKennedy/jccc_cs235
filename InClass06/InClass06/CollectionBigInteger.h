#ifndef COLLECTIONBIGINTEGER_H
#define COLLECTIONBIGINTEGER_H
#include <iostream>
using namespace::std;
#include "BigInteger.h"
const int NUMCELLS = 5;

class CollectionBigInteger
{
	friend ostream & operator <<( ostream &, const CollectionBigInteger &);
public:
	CollectionBigInteger();
	CollectionBigInteger(const CollectionBigInteger &);
	

	~CollectionBigInteger();

	void setToZero();           //   Fill all cells with the BigInteger 0
	void setToEmpty();          //   The collection will now have no members
	bool isFull() const;
	bool placeInto(const BigInteger & );   // if full, return false

	BigInteger    findLargest()   const;     // return a copy of the largest BigInteger in the collection
                                         //   if the collection is empty, return the 0 BigInteger
	bool operator==(const CollectionBigInteger &) const;    // same number of cells, same value in each corresponding cell
	
	bool operator!=(const CollectionBigInteger &) const;

	const CollectionBigInteger & operator=(const CollectionBigInteger &) ;

	CollectionBigInteger operator+(const CollectionBigInteger &) const;   // add corresponding cells together
	                                                       // if different number of cells used, use the larger number of cells used
	                                                       //   and just copy over the cells of the larger number of cells after
	                                                       //   the smaller number of cells has been reached


	
	static int getNumberOfCellsAllocated(void) 
	{
		return NUMCELLS;
	}

	int getNumberOfCellsUsed(void) const;
private:
	
	BigInteger * data[NUMCELLS];   // fill the array starting a cell 0
	int placer;           // holds the subscript of the next cell to be used
};



#endif