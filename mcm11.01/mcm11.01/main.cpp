// **************************************************************************
//
// TestMoney.cpp
//
// Defines and tests a Money class that overloads >, >=,
// >>, and << and includes a percent functions.
//
// **************************************************************************
#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

//Class for amounts of money in U.S. currency.
class Money
{
public:
    
    friend bool operator >(const Money& amount1, const Money& amount2);
    
    friend bool operator >=(const Money& amount1, const Money& amount2);
    
    Money(long dollars, int cents);
    
    Money(long dollars);
    
    Money( );
    
    Money percent(int percent_figure) const;
    
    friend istream& operator >>(istream& ins, Money& amount);
    //Overloads the >> operator so it can be used to input values of type Money.
    //Notation for inputting negative amounts is as in -$100.00.
    //Precondition: If ins is a file input stream, then ins has already been
    //connected to a file.
    
    friend ostream& operator <<(ostream& outs, const Money& amount);
    //Overloads the << operator so it can be used to output values of type Money.
    //Precedes each output value of type Money with a dollar sign.
    //Precondition: If outs is a file output stream,
    //then outs has already been connected to a file.
    
private:
    long all_cents;
};


int digit_to_int(char c);
//Used in the definition of the overloaded input operator >>.
//Precondition: c is one of the digits '0' through '9'.
//Returns the integer for the digit; for example, digit_to_int('3') returns 3.

int main( )
{
    Money amount1, amount2;
    int percent;
    
    //
    // Get two money inputs from user to use for testing.
    // Note that program will exit (from >>) if format is incorrect
    //
    
    cout << "Enter two amounts of money using dollar sign and decimal point ";
    cout << "(e.g., $12.57)" << endl << endl;
    
    cout << "First amount: ";
    cin >> amount1;
    cout << "Second amount: ";
    cin >> amount2;
    
    //
    // Test > and >=
    //
    
    if (amount1 > amount2)
        cout << amount1 << " > " << amount2 << endl;
    else if (amount1 >= amount2)
        cout << amount1 << " = " << amount2 << endl;
    else
        cout << amount1 << " < " << amount2 << endl;
    
    //
    // Test percent
    //
    
    cout << endl << "Enter a percent (0-100): ";
    cin >> percent;
    cout << percent << "% of " << amount1 << " is " << amount1.percent(percent);
    
    cout << endl << endl << "Bye!" << endl;
    
}

//Uses iostream, cctype, cstdlib:
istream& operator >>(istream& ins, Money& amount)
{
    char one_char, decimal_point,
    digit1, digit2; //digits for the amount of cents
    long dollars;
    int cents;
    bool negative;//set to true if input is negative.
    
    ins >> one_char;
    if (one_char == '-')
    {
        negative = true;
        ins >> one_char; //read '$'
    }
    else
        negative = false;
    //if input is legal, then one_char == '$'
    
    ins >> dollars >> decimal_point >> digit1 >> digit2;
    
    if ( one_char != '$' || decimal_point != '.'
        || !isdigit(digit1) || !isdigit(digit2) )
    {
        cout << "Error illegal form for money input\n";
        exit(1);
    }
    
    cents = digit_to_int(digit1)*10 + digit_to_int(digit2);
    
    amount.all_cents = dollars*100 + cents;
    if (negative)
        amount.all_cents = -amount.all_cents;
    
    return ins;
}


int digit_to_int(char c)
{
    return ( int(c) - int('0') );
}


//Uses cstdlib and iostream:
ostream& operator <<(ostream& outs, const Money& amount)
{
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents/100;
    cents = positive_cents%100;
    
    if (amount.all_cents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';
    
    if (cents < 10)
        outs << '0';
    outs << cents;
    
    return outs;
}


Money::Money(long dollars, int cents)
{
    if(dollars*cents < 0) //If one is negative and one is positive
    {
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    all_cents = dollars*100 + cents;
}


Money::Money(long dollars) : all_cents(dollars*100)
{
    //Body intentionally blank.
}


Money::Money( ) : all_cents(0)
{
    //Body intentionally blank.
}


// --------------------------------
// ----- ENTER YOUR CODE HERE -----
// --------------------------------

Money Money::percent(int percent_figure) const
{
    Money temp;
	double perc;
    
	// get percentage as a double.
	perc = (static_cast<double>(percent_figure) / 100) ;
    
	// copy money value to working object
	temp.all_cents = all_cents;
    
	// get percentage and integer division okay (losing insignificant digits)
	temp.all_cents *= perc;
	
	return temp;
}

bool operator >=(const Money& amount1, const Money& amount2)
{
    return (amount1.all_cents > amount2.all_cents || amount1.all_cents == amount2.all_cents);
}

bool operator >(const Money& amount1, const Money& amount2)
{
    return (amount1.all_cents > amount2.all_cents);
}

// --------------------------------
// --------- END USER CODE --------
// --------------------------------



