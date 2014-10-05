#include "BigInteger.h"

ostream & operator <<( ostream & out, const BigInteger & r )
{
    int digitsStart  = 0;
    // STUDENTS write a for or while loop to place the subscript of the first high order digit that is not 0 in digitsStart
    
    for (int i = 0; i < BigInteger::getNumberOfDigits(); i++)
    {
        if (r.digits[i] != 0)
        {
            digitsStart = i;
            break;
        }
    }
    
    if ( digitsStart == NUMDIGITS )   // the number is all 0's
    {
        out << '0';
        return out;
    }
    
    for(int i = digitsStart; i < NUMDIGITS; i++)
    {
        // this code prevents leading 0's from being printed
        out << r.digits[i];
    }
    return out;
}

BigInteger::BigInteger()
{
	setToZero();
}

BigInteger::BigInteger(const BigInteger & r)
{
	this->overflow = r.overflow;
	for ( int i = 0; i < NUMDIGITS; i++)
		this->digits[i] = r.digits[i];
}

BigInteger::BigInteger( int r)
{
	this->convertIntToBigInteger(r);
}

BigInteger::BigInteger( const char * s)
{
	int len = strlen(s);
	setToZero();
	if ( len > NUMDIGITS )
	{
		overflow = true;
		return;
	}
	overflow = false;

	//    STUDENTS
	//   write a for or while loop to place the correct number in the digits array from the C++ string
	//           work right to left and move the digits one by one   WILL NEED TO CONVERT A CHAR DIGIT TO A NUMBER DIGIT
	
    for (int i = len; i > 0; i--)
    {
        digits[i] = s[i] - '0';
    }

	return;
}

BigInteger::~BigInteger()
{
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
	//   STUDENTS
	//   Write a for or a while loop to compare digits left to right
	//     if a smaller digit is found in the invoking instance return true
	//     if a larger digit is found in the invoking instance return false
    for (int i = 0; i < BigInteger::getNumberOfDigits(); i++)
    {
        if (this->digits[i] > r.digits[i]) return false;
        else if (this->digits[i] < r.digits[i]) return true;
    }

	//  for loop has been completed here ==> all digits match, so return false
	return false; // all digits match, both BigIntegers are equal
}

bool BigInteger::operator<=(const BigInteger & r) const
{
	//  STUDENTS
	// code needed
	return true;
}

bool BigInteger::operator>(const BigInteger & r) const
{
	// STUDENTS
	// code needed
    
    for (int i = 0; i < BigInteger::getNumberOfDigits(); i++)
    {
        if (this->digits[i] > r.digits[i]) return true;
        else if (this->digits[i] < r.digits[i]) return false;
    }
    
	return false;
}

bool BigInteger::operator>=(const BigInteger & r) const
{
	// STUDENTS
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
	//  STUDENTS
	//   using a for or a while loop add the digits right to left using the carry
	//       review your notes from class



	//  loop exit, set the overflow flag
	answer.overflow = ( carry > 0 );
	return answer;
}

BigInteger BigInteger::operator*(const BigInteger & r) const
{
	BigInteger i(0), total(0), one(1);

	//   STUDENTS 
	//     modify the code so that the small BigInteger is always used to control the for loop

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
	if (r <= 0) return;
	int placer = NUMDIGITS - 1;    // rightmost digit,  work right to left
	int value = r;
	while (value > 0 && placer >= 0 )
	{
		// Students
		//   use % operator to select the right most digit and place in the array
		//   change the variable value by removing the right digit using / operator
        //   move to the left for placing digits in the array
		
        placer--;
	}
	return;
}