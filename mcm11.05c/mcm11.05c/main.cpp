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
//  are the numerator and denominator of the rational number.
//  The class also contains a function to print a rational number
//  in the format m/n and overloads the relational operators
//  ==, >, <, >=, <=, !=
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
    
    void output();
    // Precondition: The rational number is defined.
    // Postcondition: The rational number has been displayed on
    // the screen in the form m/n.
    
    friend bool operator ==(const Rational& r1, const Rational& r2);
    // Precondition: r1 and r2 are valid rational numbers
    // Returns true if r1 equals r2; false otherwise.
    
    friend bool operator <(const Rational& r1, const Rational& r2);
    // Precondition: r1 and r2 are valid rational numbers
    // Returns true if r1 is less than r2; false otherwise.
    
    friend bool operator >(const Rational& r1, const Rational& r2);
    // Precondition: r1 and r2 are valid rational numbers
    // Returns true if r1 is greater than r2; false otherwise.
    
    friend bool operator <=(const Rational& r1, const Rational& r2);
    // Precondition: r1 and r2 are valid rational numbers
    // Returns true if r1 is less than or equal to r2; false otherwise.
    
    friend bool operator >=(const Rational& r1, const Rational& r2);
    // Precondition: r1 and r2 are valid rational numbers
    // Returns true if r1 is greater than or equal to r2; false otherwise.
    
    friend bool operator !=(const Rational& r1, const Rational& r2);
    // Precondition: r1 and r2 are valid rational numbers
    // Returns true if r1 is not equal to r2; false otherwise.
    
private:
    int num;     // the numerator of the number
    int denom;   // the denominator of the number
    
    void standardize();
    // Precondition: num and denom have values
    // Postcondition: if denom is 0 the program is terminated;
    // otherwise the rational number is standardized so that
    // denom is positive.
    
};


// ========================
//     main function
// ========================
int main ()
{
    //
    // Variable declarations
    //
    char doAgain;    // for the loop control
    int m, n;        // numerator and denominator - m/n
    
    cout << endl << "Testing relational operators..." << endl << endl;
    
    do {
        //
        // Read and construct two rational numbers
        //
        cout << "Enter two rational numbers (numerator and denominator "
        << "separated by a blank)." << endl << endl;
        cout << "Numerator and denominator of the first rational number: ";
        cin >> m >> n;
        cout << endl;
        
        Rational r1(m, n);
        
        cout << "Numerator and denominator of the second rational number: ";
        cin >> m >> n;
        cout << endl;
        
        Rational r2(m, n);
        
        
        //
        // Test all comparisons
        //
        r1.output();
        if (r1 == r2)
            cout << " is equal to ";
        else
            cout << " is not equal to ";
        r2.output();
        cout << endl;
        
        r1.output();
        if (r1 < r2)
            cout << " is less than ";
        else
            cout << " is not less than ";
        r2.output();
        cout << endl;
        
        r1.output();
        if (r1 > r2)
            cout << " is greater than ";
        else
            cout << " is not greater than ";
        r2.output();
        cout << endl;
        
        r1.output();
        if (r1 <= r2)
            cout << " is less than or equal to ";
        else
            cout << " is not less than or equal to ";
        r2.output();
        cout << endl;
        
        r1.output();
        if (r1 >= r2)
            cout << " is greater than or equal to ";
        else
            cout << " is not greater than or equal to ";
        r2.output();
        cout << endl;
        
        r1.output();
        if (r1 != r2)
            cout << " is not equal to ";
        else
            cout << " is equal to ";
        r2.output();
        cout << endl;
        
        
        //
        // See if the user wants to enter another number
        //
        cout << endl << "Enter another number? (y or n): ";
        cin >> doAgain;
        cout << endl;
    }
    while (doAgain == 'y' || doAgain == 'Y');
    
    
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


void Rational::output()
{
    cout << num << "/" << denom;
}


// --------------------------------
// ----- ENTER YOUR CODE HERE -----

// --------------------------------
bool operator ==(const Rational& r1, const Rational& r2)
{
    return (r1.num * r2.denom) == (r1.denom * r2.num);
}

bool operator <(const Rational& r1, const Rational& r2)
{
    return (r1.num * r2.denom) < (r1.denom * r2.num);
}

bool operator >(const Rational& r1, const Rational& r2)
{
    return (r1.num * r2.denom) > (r1.denom * r2.num);
}

bool operator <=(const Rational& r1, const Rational& r2)
{
    return (r1.num * r2.denom) < (r1.denom * r2.num) || (r1.num * r2.denom) == (r1.denom * r2.num);
}

bool operator >=(const Rational& r1, const Rational& r2)
{
    return (r1.num * r2.denom) > (r1.denom * r2.num) || (r1.num * r2.denom) == (r1.denom * r2.num);
}

bool operator !=(const Rational& r1, const Rational& r2)
{
    return (r1.num * r2.denom) != (r1.denom * r2.num);
}

// --------------------------------
// --------- END USER CODE --------
// --------------------------------



