#include "CollectionBigInteger.h"

ostream & operator <<( ostream & out, const CollectionBigInteger & r)
{
	if ( r.placer == 0 ) cout << "EMPTY";
	for ( int i = 0; i < r.placer; i++)
		out << "XXXXXXXXXXXXXX" << ' ';
    // STUDENTS - Remove "XXXXXXXXXXXXXX" and replace with the name of the variable to display
	return out;
}

CollectionBigInteger::CollectionBigInteger()
{
	placer = 0;
	for (int i = 0; i < NUMCELLS; i++)
    {
        data[i] = NULL;
    }

}

CollectionBigInteger::CollectionBigInteger(const CollectionBigInteger & r)
{                                           //   STUDENTS - STUDY THIS CODE
	placer = 0;
	for ( int i = 0; i < NUMCELLS; i++)
		data[i] = NULL;
	for ( int i = 0; i < r.placer; i++)
		this->placeInto(*(r.data[i]));     //  BEST TO USE placeInto rather than coding the instructions yourself
}
	

CollectionBigInteger::~CollectionBigInteger()
{
	   //  STUDENTS - return all allocated heap memory using delete
	   //                after the memory has been returned, best to set the cell to NULL
    for (int i = 0; i < NUMCELLS; i++)
    {
        delete data[i];
    }
}

void CollectionBigInteger::setToZero()         //   Fill all cells with the BigInteger 0
{
	setToEmpty();
	BigInteger zero(0);
	for( int i = 0; i < NUMCELLS; i++)
		this->placeInto(zero);                 //  STUDENTS - note the use of placeInto
}

void CollectionBigInteger::setToEmpty()          //   The collection will now have no members
{
	for( int i = 0; i < placer; i++)
	{
        delete data[i];
		data[i] = NULL;
	}
	placer = 0;
}
bool CollectionBigInteger::isFull() const
{
	return placer >= NUMCELLS;
}

bool CollectionBigInteger::placeInto(const BigInteger & b )   // if full, return false
{
	if ( isFull() ) return false;
	data[placer] = new BigInteger(b);   //  STUDENTS - note the use of new, we need to allocate memory for a copy of
	placer++;                           //                of the paparmeter b and store the address of the copy on the heap
	return true;                        //                into the array data at cell placer
}

BigInteger    CollectionBigInteger::findLargest()   const     // return a copy of the largest BigInteger in the collection
                                         //   if the collection is empty, return the 0 BigInteger
{
	if ( placer == 0 )return BigInteger(0);
	BigInteger answer = *data[0];             //   STUDENTS - note the use of *, the dereference operator, we want the data, not the address
	for ( int i = 1; i < placer; i++)
	{
	 //   STUDENTS - need to check if answer is less then the BigInteger that is pointed to by cell i
	 //                    if so, replace answer with that BigInteger
	}

	return answer;
}

bool CollectionBigInteger::operator==(const CollectionBigInteger & r) const    // same number of cells, same value in each corresponding cell
{
	//  STUDENTS - first check to see of the two CollectionBigInteger objects have a different numbers of cells used, i.e. placer
	//             -   if so, return false
	//  STUDENTS - use a for loop to look for failure, if so return false

	//  STUDENTS - if the logic exits from the for loop, there is no failure, so return true for success


	return true;     //  STUDENTS, remove this statement - added so the code will compile
}
	
bool CollectionBigInteger::operator!=(const CollectionBigInteger & r) const
{
	return !( *this == r );      //   STUDENTS - note that we use the negation of ==
}

const CollectionBigInteger & CollectionBigInteger::operator=(const CollectionBigInteger & r) 
{
	if ( this == & r) return *this;              //  STUDENTS - study this code, similiar code in used in the copy constructor
	this->setToEmpty();                          //  STUDENTS - since the invoking instance already exists, we need to return
	for ( int i = 0; i < r.placer; i++ )         //               all allocated heap memory before copying over the data from r
		this->placeInto(*(r.data[i]));           //  STUDENTS - note again the use of * and placeInto
	return *this;
}

CollectionBigInteger CollectionBigInteger::operator+(const CollectionBigInteger & r) const   // add corresponding cells together
	                                                       // if different number of cells used, use the larger number of cells used
	                                                       //   and just copy over the cells of the larger number of cells after
	                                                       //   the smaller number of cells has been reached
{
	CollectionBigInteger answer;
	int small = (placer <= r.placer ? placer : r.placer);
	for ( int i = 0; i < small; i++)
		answer.placeInto( *(data[i]) + *(r.data[i]) );
	if ( placer > small )                       // more cells used in the invoking instance
		for( int i = small; i < placer; i++)
			answer.placeInto(*data[i]);
	//else                                        // more cells used in the parameter r
	                                         //  STUDENTS - write a similar for loop, but this time using r to fill out answer
	return answer;
}

int CollectionBigInteger::getNumberOfCellsUsed(void) const
{
	return placer;
}