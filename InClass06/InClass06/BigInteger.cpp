#include "BigInteger.h"
bool BigInteger::debugOn = false;

ostream & operator <<( ostream & out, const BigInteger & r )
{
   int digitsStart  = 0;
   for(  ; digitsStart < NUMDIGITS && r.digits[digitsStart] == 0 ; digitsStart++)
   { }
   if ( digitsStart == NUMDIGITS )
   {
	   out << '0';
	   return out;
   }
   for(int i = digitsStart; i < NUMDIGITS; i++)
	   out << r.digits[i];
   return out;
}

BigInteger::BigInteger()
{
	setToZero();
	if (debugOn ) cout << "     DEBUG: Default Constructor used to create BigInteger at " << this << endl;
}

BigInteger::BigInteger(const BigInteger & r)
{
	this->overflow = r.overflow;
	for ( int i = 0; i < NUMDIGITS; i++)
		this->digits[i] = r.digits[i];
	if (debugOn ) cout << "     DEBUG: Copy Constructor used to create BigInteger at " << this << endl;
}

BigInteger::BigInteger( int r)
{
	this->convertIntToBigInteger(r);
	if (debugOn ) cout << "     DEBUG: integer argument Constructor used to create BigInteger at " << this << endl;
}

BigInteger::BigInteger( const char * s)
{
	if (debugOn ) cout << "     DEBUG: char * argument Constructor used to create BigInteger at " << this << endl;
	int len = strlen(s);
	setToZero();
	if ( len > NUMDIGITS )
	{
		overflow = true;
		return;
	}
	overflow = false;
	for ( int i = NUMDIGITS - 1, j = len - 1;   j >= 0; j--,i--)
	{
		digits[i] = s[j] - '0';
	}
	return;
}

BigInteger::~BigInteger()
{
	if (debugOn ) cout << "     DEBUG: Destructor called to remove BigInteger object at " << this << endl;
	return;
}

void BigInteger::setToZero()
{
	overflow = false;
	for( int i = 0; i < NUMDIGITS;i++)
		digits[i] = 0;
}

bool BigInteger::operator==(const BigInteger &r) const
{
	for ( int i = 0; i < NUMDIGITS; i++)
		if ( digits[i] != r.digits[i] ) return false;
	return true;
}
bool BigInteger::operator<(const BigInteger & r) const
{
	for (int i = 0; i < NUMDIGITS; i++)
	{
        if ( digits[i] < r.digits[i] ) return true;
		else if ( digits[i] > r.digits[i] ) return false;
	}
	return false; // all digits match, both BigIntegers are equal
}

bool BigInteger::operator<=(const BigInteger & r) const
{
	// code needed
	return true;
}

bool BigInteger::operator>(const BigInteger & r) const
{
	// code needed
	return true;
}

bool BigInteger::operator>=(const BigInteger & r) const
{
	// code needed
      return true;
}
bool BigInteger::operator!=(const BigInteger & r) const
{
	return !( *this == r );
}

const BigInteger & BigInteger::operator=(const BigInteger & r) 
{

	if ( this == & r ) return *this;
	overflow = r.overflow;
	for ( int i = 0; i < NUMDIGITS; i++)
		digits[i] = r.digits[i];
	return *this;
}

BigInteger BigInteger::operator+(const BigInteger & r) const
{
	BigInteger answer;
	int carry = 0;
	for ( int i = NUMDIGITS - 1; i >= 0 ; i--)
	{
		answer.digits[i] = ( digits[i] + r.digits[i] + carry ) % 10;
		carry  = ( digits[i] + r.digits[i] + carry ) / 10;
	}
	answer.overflow = ( carry > 0 );
	return answer;
}

BigInteger BigInteger::operator*(const BigInteger & r) const
{
	BigInteger i(0), total(0), one(1);
	for( ; i < *this; i = i + one )    // runs faster if *this < r   
	{
		total = total + r;
		if ( total.hasOverFlowed() ) return total;      // stop when overflow
	}
	return total;
}

bool BigInteger::hasOverFlowed(void) const
{
	return this->overflow;
}

void BigInteger::convertIntToBigInteger(int r)    // place the int parameter into the BigInteger format for the invoking instance
{
    this->setToZero();
	if ( r <= 0 ) return;
	int placer = NUMDIGITS - 1;
	int value = r;
	while ( value > 0 && placer >= 0 )
	{
        digits[placer] = value % 10;
		value = value / 10;
		placer--;
	}
	return;
}