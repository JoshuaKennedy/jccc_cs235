// *****************************************************************
//
//  Rationals.cpp
//
//  This program contains a class for rational numbers and a
//  driver to test the class. The rational class represents a
//  rational number using two integers - one for the numerator
//  and one for the denominator. The class has 3 constructors -
//  a default constructor that sets the number to 1; a constructor
//  with one integer parameter that sets the rational number to
//  that integer; a constructor with two integer parameters which
//  are the numerator and denominator of the rational number. The
//  class also contains overloaded operators << and >> for output
//  and input of rational numbers in the format m/n, where m and
//  n are integers. The driver tests the << and >> operators by
//  reading in a rational number then printing it out.
//
// *****************************************************************

#include <iostream>
#include <cstdlib>

using namespace std;

class Rational
{
public:
    Rational();
    // Initializes the rational number to 0
    
    Rational (int wholeNumber);
    // Initializes the rational number to wholeNumber/1
    
    Rational (int m, int n);
    // Initializes the rational number to m/n if n is not 0;
    // the sign of the rational is stored in the numerator
    // (the denominator is always positive);
    // exits if n = 0 (invalid rational number)
    
    friend ostream& operator <<(ostream& outs, const Rational& r);
    // Precondition: If outs is a file output stream, then outs has
    // already been connected to a file.
    // Postcondition: The rational number has been sent to the
    // output stream as numerator slash denominator (with the
    // denominator always positive).
    
    friend istream& operator >>(istream& ins, Rational& r);
    // Precondition: If ins is a file input stream, then ins has
    // already been connected to a file. The rational number in
    // the input stream is in the form of an integer followed by
    // the slash character followed by an integer.
    // Postcondition: r has been set to the input value (and
    // standardized so the denominator is positive).
    
private:
    int num;     // the numerator of the number
    int denom;   // the denominator of the number
    
    void standardize();
    // Precondition: num and denom have values
    // Postcondition: if denom is 0 the program is terminated;
    // otherwise the rational number is standardized so that
    // denom is positive.
};



// =====================
//     main function
// =====================
int main ()
{
    //
    // Variable declarations
    //
    char doAgain;    // for the loop control
    int m, n;        // numerator and denominator - m/n
    Rational r;
    
    do
    {
        //
        // Read in a rational number
        //
        cout << "Enter a rational number in the form m/n: ";
        cin >> r;
        cout << endl;
        
        //
        // Print the number out
        //
        cout << "Here's your number: " << r << endl;
        
        //
        // See if the user wants to enter another number
        //
        cout << endl << "Enter another number? (y or n): ";
        cin >> doAgain;
        cout << endl;
    }
    while (doAgain == 'y' || doAgain == 'Y');
    
    // implement
    
    
    return 0;
}

// ===========================
//    Function Definitions
// ===========================

Rational::Rational()
{
    num = 0;
    denom = 1;
}

Rational::Rational (int wholeNumber)
{
    num = wholeNumber;
    denom = 1;
}

Rational::Rational (int m, int n)
{
    
    num = m;
    denom = n;
    standardize();
    
}

void Rational::standardize()
{
    if (denom < 0)
    {
        denom = -1 * denom;
        num = -1 * num;
    }
    else if (denom == 0)
    {
        cout << "Zero cannot be in the denominator - program aborting!!"
        << endl;
        exit(1);
    }
}


// --------------------------------
// ----- ENTER YOUR CODE HERE -----
// --------------------------------

ostream& operator <<(ostream& outs, const Rational& r)
{
    if (r.denom < 0)
        outs << '-' << r.num << '/' << r.denom;
    else
        outs << r.num << '/' << r.denom;
    return outs;
}

istream& operator >>(istream& ins, Rational& r)
{
    char slash;
    ins >> r.num >> slash >> r.denom;
    return ins;
}

// --------------------------------
// --------- END USER CODE --------
// --------------------------------


