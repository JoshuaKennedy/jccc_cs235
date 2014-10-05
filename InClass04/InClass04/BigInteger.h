#ifndef BIGINTEGER_H
#define BIGINTEGER_H
#include <iostream>
using namespace::std;

const int NUMDIGITS = 50;
//   A non-negative integer with NUMDIGITS
//      Leading zeores are stored in the number
//      if + or * result in overflow, i.e. and answer with more that NUMDIGIST, the overflow flag is set
class BigInteger
{
	friend ostream & operator <<( ostream &, const BigInteger &);
public:
	BigInteger();
	BigInteger(const BigInteger &);
	BigInteger( int );
	BigInteger( const char *);

	~BigInteger();

	void setToZero();

	bool operator==(const BigInteger &) const;
	bool operator<(const BigInteger &) const;
	bool operator<=(const BigInteger &) const;
	bool operator>(const BigInteger &) const;
	bool operator>=(const BigInteger &) const;
	bool operator!=(const BigInteger &) const;

	const BigInteger & operator=(const BigInteger &) ;

	BigInteger operator+(const BigInteger &) const;
	BigInteger operator*(const BigInteger &) const;

	bool hasOverFlowed(void) const;
	static int getNumberOfDigits(void)
	{
		return NUMDIGITS;
	}


private:
	void convertIntToBigInteger(int);    // place the int parameter into the BigInteger format for the invoking instance
	int digits[NUMDIGITS];   // high order digit stored in cell 0, low order digit stored in cell NUMDIGITS-1
	bool overflow;
};



#endif