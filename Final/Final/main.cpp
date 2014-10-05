/*
CIS 235 - Test # 2     Spring, 2014                          NAME:_____________________________________

You can use the computer on Questions 2, 4 and 5.

1. Given the following program:

PLEASE DO NOT USE VISUAL STUDIO FOR THIS PROBLEM #1
JUST TYPE IN THE ANSWERS – DO NOT USE THE COMPUTER TO CHECK YOUR WORK
 */
 
#include <fstream>
#include <iostream>

using namespace std;

class demo
{
    friend ostream & operator << (ostream &, const demo &);
public:
    demo(int);
    demo( const demo &);
    bool f1(void) const;
    demo operator + (    int ) const;
private:
    int w;
};

int f2(const demo *);

int main()
{
	demo a(4),b(5);
    demo c(b);
	cout << a << b << endl;
	if (a.f1()  && b.f1() )
        cout << f2( & c);
	a = b + 25;
	cout << a << endl;
    //
    //  Rewrite the above code in main using three pointers
    //  Besides cout, the only variable names you can use are p1, p2, p3
    //      You CAN NOT use a, b, or c
	demo * p1, * p2, * p3;
 
    return 0;
}

// CONSIDER THE FOLLOWING CLASSES
// YOU CAN USE VISUAL STUDIO OR XCODE, I DON'T GIVE A SHIT.

class aaa
{
    friend ostream & operator<<(ostream &, const aaa &);
public:
    aaa(void);
    aaa(int);
    aaa(const aaa &);
    virtual ~aaa();
    virtual int report(void) const;
    int f1(void ) const;
    const aaa & operator = ( const aaa &);
    bool operator == (const aaa & ) const;
private:
    int x;
};

class ccc {
    friend ostream & operator<<(ostream &, const ccc &);
public:
    ccc(void);
    ccc(char);
    ccc(const ccc &);
    ~ccc();
    int lookAt(void) const;
    const ccc & operator = ( const ccc &);
    bool operator == ( const ccc &) const;
private:
    char y;
};

class qqq : public aaa {
    friend ostream & operator << ( ostream &, const qqq &);
public:
    qqq(void);
    
    qqq(int, char, double, const char *);
    
    qqq( const qqq &);
    
    virtual ~qqq();
    
    int report(void) const;    //REWRITE of inherited function
    // to return triple the value of the
    //  inherited function
    
    int lookAt(void) const;  //  Same return value as ccc's function
    
    const qqq & operator = ( const qqq &);
    
    bool operator == ( const qqq & ) const;  //  return true if all
    // "4" fields are equal
    
private:
    double pear;
    ccc a;
    char * name;
};

/*
 
 PAGE 3
 
 */

//                     WRITE ALL OF THE FUNCTIONS FOR THE CLASS qqq


qqq::~qqq()
{
    
}


qqq::qqq(void)
{
    
}


qqq::qqq(int m, char n, double o , const char * na)
{
    
}


qqq::qqq(const qqq & r)
{
    
}

int qqq::report(void) const
{
    // YOU'LL NEED TO COMPLETE THIS DAWG.
    return -1;
}

/*
 
 PAGE 4
 
 */

ostream & operator << ( ostream & w, const qqq & r)
{
    // FINISH THIS MAN!!!
    return w;
}


const qqq & qqq::operator =( const qqq & r)
{
    // SUP, MAN. YOU'LL NEED TO COMPLETE THIS.
    return *this;
}


int qqq::lookAt(void) const
{
    // NEED TO COMPLETE, DAWG
    return -1;
}


bool qqq::operator ==( const qqq & r) const
{
    // YO HOMIE, YOU NEED TO FINISH THIS HERE METHOD.
    return false;
}


/*
 
 PAGE 5
 3. Answer the following questions relating to Homework 6 on inheritance:
 a)    cBox a(1,2,3);
 cBox * ptr = new cBox(1,2,3);
 
 Use the << operator to output the “rectangle” portion of the box  by
 using casting:
 
 i)  cast the object and output the cast object
 
 cout <<   ___________________________________________
 
 ii) cast the pointer and dereference the cast pointer to output the object
 
 cout <<  ____________________________________________
 
 
 b) Which method is preferred, using execution efficiency as the criteria, and WHY it is preferred ?
 
 */


/*
 
 4.   Given the following class definitions:
 
 YOU CAN USE VISUAL STUDIO FOR THIS PROBLEM
 
 */

class Person{
    friend   ostream & operator << ( ostream & w, const Person &);  //   will send name and age to w with NO descriptions
    
public:  Person(const char *, int);
    Person(void);      //   The name NOT GIVEN will be used
    Person(const Person &);
    const Person & operator = (const Person &);
    void Print(void) const;     // will print to cout the name and age with descriptions
    ~Person();
private:
    char * name;
    int age;
} ;

class Worker : public Person {
    friend   ostream & operator << ( ostream & w, const Worker &);  //   will send name , age and salary to w
    // with NO descriptions
public:
    Worker(const char *, int, double);
    Worker(const Worker &);
    void Print() const;       // Will Print the name, age and salary with descriptions
private:
    double salary;
} ;

/*
 On the following pages write the seven functions for the Person class and write the four functions for the Worker class.
 
 PAGE 6
 
 Code for Problem 4
 */

Person::Person(const char * p , int a)
{
    
}


Person::Person(void)      //   The name NOT GIVEN will be used
{
    
}


Person::Person(const Person & other)
{
    
}


const Person & Person::operator = (const Person & other)
{
    // YOU WILL NEED TO COMPLETE THIS FUNCTION, MAN.
    return *this;
}


void Person::Print(void) const     // will print to cout the name and age with descriptions
{
    
}

/*
 
Person::~Person()

PAGE 7

Code for Problem 4 Continued
 
*/

Worker::Worker(const char * p, int a, double s)
{
    
}


Worker::Worker(const Worker & other)
{
    
}


void Worker::Print() const       // Will Print to cout the name, age and salary with descriptions
{
    
}

ostream & operator << ( ostream & out, const Person & p)   // Just the data, NO descriptions
{
    // FINISH THIS! (Mortal Kombat voice)
    return out;
}


ostream & operator << ( ostream & out, const Worker & w)  //  Just the data, NO descriptions
{
    // POR FAVOR COMPLETAR! (ES MUY IMPORTANTE)
    return out;
}


/*

PAGE 8


5.  Consider the class defined below:

YOU CAN USE VISUAL STUDIO FOR THIS PROBLEM
 
*/


class cSales {
    
    friend bool operator == (const cSales &, const cSales &);
    // equal if same number of cells and all corresponding cells are equal
    
public:
    cSales(void);                           // Default Constructor - all cells set to 0
    cSales(const cSales &);           // Copy Constructor
    cSales operator+(const cSales &) const;   // Answer’s cells are the sum of corresponding cells
    //  use the smaller value of cellsUsed for the return value
    ~cSales(void);
private:
    int * info;
    int  cellsUsed;
};

// ^^^ Write the code for the 5 functions listed above. ^^^




/*
 
 PAGE 9
 
 6.  Give the output for each function call in the following program.  Show the output to the right
 of the statement that caused the output.
 
 PLEASE DO NOT USE VISUAL STUDIO FOR THIS PROBLEM #6
 JUST TYPE IN THE ANSWERS – DO NOT USE THE COMPUTER TO CHECK YOUR WORK
 
 */

class one
{
public:
    void f1(void)const { cout <<"Tom\n";}
    void f2(void)const { cout <<"Mary\n";}
    virtual void f3(void)const { cout <<"Bill\n";}
    private:
};

class two : public one
{
public:
    void f2(void)const { cout <<"Ann\n";}
    virtual void f3(void)const { cout <<"Paul\n";}
    void f4(void) const { cout << "Kathy\n"; }
    private:
};

void print(const one & o)
{
    o.f3();
}

int problemSix()
{
    one a;
    two b;
    one & c = b;
    one * p1;
    two * p2;
    cout << "Test base class\n";
    
    a.f1(); // _______________________________
    
    a.f2(); // _______________________________
    
    a.f3(); // _______________________________
    
    cout << "Test alias\n";
    
    c.f1(); // _______________________________
    
    c.f2(); // _______________________________
    
    c.f3(); // _______________________________
    
    cout << "Test of base class pointers pointers\n";
    
    p1 = & b;
    
    p1->f1();
    
    p1->f2();
    
    p1->f3();
    
    
    // PAGE 10
    // 6. (Continued)
    
    
    cout << "Test of derived class pointers\n";
    p2 = & b;
    
    p2->f1(); // _______________________________
    
    p2->f2(); // _______________________________
    
    p2->f3(); // _______________________________
    
    p2->f4(); // _______________________________
    
    cout << "Test of casting derived class pointer\n";
    
    static_cast<one *>( p2 ) ->f1(); // _______________________________
    
    static_cast<one *>( p2 ) ->f2(); // _______________________________
    
    static_cast<one *>( p2 ) ->f3(); // _______________________________
    
    cout << "Test of casting derived class\n";
    
    static_cast<one>( b ).f1(); // _______________________________
    
    static_cast<one>( b ).f2(); // _______________________________
    
    static_cast<one>( b ).f3(); // _______________________________
    
    cout << "Test of base class alias function call\n";
    
    print(a); // _______________________________
    
    print(b); // _______________________________
    
    print(c); // _______________________________
    
    return 0;
}


