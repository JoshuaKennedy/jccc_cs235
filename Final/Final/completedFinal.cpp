CIS 235 - Test # 2     Spring, 2013                          NAME: Josh Kennedy

You can use the computer on Questions 2, 4 and 5.

1. Given the following program:         

PLEASE DO NOT USE VISUAL STUDIO FOR THIS PROBLEM #1
JUST TYPE IN THE ANSWERS DO NOT USE THE COMPUTER TO CHECK YOUR WORK

#include <fstream.h>

class demo {
friend ostream & operator << (ostream &, const demo &);
 public:
	 demo(int);
               demo( const demo &);
	 bool f1(void) const;
	 demo operator + (    int ) const;
 private:
	 int w;
 };

int f2( const demo *);

 void main()
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
	
	//
	// Josh Kennedy Added
	//
	p1 = new demo(4);
	p2 = new demo(5);
	p3 = new demo(*p2);
	cout << *p1 << *p2 << endl;
	if (p1->f1() && p2->f1()) {
		cout << f2(p3);
	*p1 = *p2 + 25;
	cout << *p1 << endl;
	delete [] p1;
	delete [] p2;
	delete [] p3;
	
                                                                  PAGE 2               

2.  Consider the following 3 classes:    

YOU CAN USE VISUAL STUDIO FOR THIS PROBLEM

class aaa {
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

                                                                                   PAGE 3             

//                     WRITE ALL OF THE FUNCTIONS FOR THE CLASS qqq


qqq::~qqq() {
	delete [] name;
}


qqq::qqq(void) : aaa(0), pear(0.0), a('$') {
	name = new char[strlen("NotSet")+1];
	strcpy(name,"NotSet");
}

qqq::qqq(int m, char n, double o , const char * na) : aaa(m) ,pear(o), a(n) {
	name = new char[strlen(na)+1];
	strcpy(name,na);
}

// Copy constructor
qqq::qqq(const qqq & r) : aaa(r), pear(r.pear), a(r.a) {
	name = new char[strlen(r.name)+1];
	strcpy(name,r.name);
}

//REWRITE of inherited function
// to return triple the value of the
// inherited function
int qqq::report(void) const {
	return 3 * this->lookAt();
}

ostream & operator << ( ostream & w, const qqq & r) {
	const aaa & aaaAlias = r;	// create alias
	w << aaaAlias <<			// insert a base object
		 r.a << ' '			// insert a composition object
		<< r.pear << ' '	// insert a double
		<< r.name << endl;
	return w;

}

const qqq & qqq::operator =( const qqq & r) {
	if ( this == &r) return *this;

	this->aaa::operator=(r);		// base assignment
	a = r.a;						// composition assignment
	pear = r.pear;

	name = new char[strlen(r.name)+1];
	strcpy(name,r.name);

	return *this;
}

//  Same return value as ccc's function
int qqq::lookAt(void) const {
	return a.lookAt();
}

// return true if all
//  "4" fields are equal
bool qqq::operator ==( const qqq & r) const {
	if ( this == &r) return true;

	return ( (this->a == r.a) && (this->pear == r.pear) && ( this->aaa::operator==(r) ) && !(strcmp(name,r.name)) ); 
}




                                                    PAGE 5           
3. Answer the following questions relating to Homework 6 on inheritance:
a)    cBox a(1,2,3);
       cBox * ptr = new cBox(1,2,3);
   
      Use the << operator to output the “rectangle” portion of the box  by
      using casting: 

         i)  cast the object and output the cast object
         
         		cout << static_cast<cRectangle2>(a) << endl;

         ii) cast the pointer and dereference the cast pointer to output the object
         
         		cout << static_cast<cRectangle2*>(ptr) << endl;


b) Which method is preferred, using execution efficiency as the criteria, and WHY it is preferred ?

		Cast the pointer and dereference the cast pointer to output the object is more efficient.
		The pointer uses less memory and CPU.

4.   Given the following class definitions:

YOU CAN USE VISUAL STUDIO FOR THIS PROBLEM

class Person {

	friend ostream & operator << ( ostream & w, const Person &);
	// will send name and age to w with NO descriptions

public:
	Person(const char *, int);
	Person(void);      //   The name NOT GIVEN will be used
	Person(const Person &);
	const Person & operator = (const Person &);
	void Print(void) const;     // will Print to cout the name and age with descriptions
	~Person();

private:
	char * name;
	int age;
};

class Worker : public Person {
	
	friend   ostream & operator << ( ostream & w, const Worker &);
	// will send name , age and salary to w with NO descriptions

public:
	Worker(const char *, int, double);
	Worker(const Worker &);
	void Print() const;
	// will Print the name, age and salary with descriptions

private:
	double salary;
};

// On the following pages write the:
// seven functions for the Person class
// four functions for the Worker class

// constructor (full)
Person::Person(const char * p , int a) : age(a) {
	name = new char[strlen(p)+1];
	strcpy(name,p);
}

Person::Person(void) : age(0)  {
	name = new char[strlen("NOT GIVEN")+1];
	strcpy(name,"NOT GIVEN");
}
// constructor (default)
//   The name NOT GIVEN will be used

Person::Person(const Person & other) {
	this->age = other.age;
	name = new char[strlen(other.name)+1];
	strcpy(name,other.name);
}
// constructor (copy)

const Person & Person::operator = (const Person & other) {
	if ( this == &other) return *this;

	this->age = other.age;
	name = new char[strlen(other.name)+1];
	strcpy(name,other.name);

	return *this;
}
// overloaded operator =

void Person::Print(void) const {
	cout << "Name " << name << endl;
	cout << "Age " << age << endl;
}
// will print to cout the name and age with descriptions

Person::~Person() {
	delete [] name;
}

Worker::Worker(const char * p, int a, double s) : Person(p,a), salary(s) {
	// intentionally left blank
}
// constructor (full)

Worker::Worker(const Worker & other) : Person(other), salary(other.salary) {
	// intentionally left blank
}
// constructor (copy)

void Worker::Print() const {
	Person::Print();	// code reuse
	cout << "Salary " << salary << endl;
}
// Will Print to cout the name, age and salary with descriptions

ostream & operator << ( ostream & out, const Person & p) {
	out << p.name << ' ' << p.age << endl;
	return out;
}
// Just the data, NO descriptions

ostream & operator << ( ostream & out, const Worker & w) {
	const Person & yo = w;
	out << yo << ' ' << w.salary << endl;
	return out;
}
//  Just the data, NO descriptions


5.  Consider the class defined below:

YOU CAN USE VISUAL STUDIO FOR THIS PROBLEM


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

Write the code for the 5 functions listed above.

bool operator== (const cSales & left, const cSales & right) {
	if (left.cellsUsed != right.cellsUsed) return false;	// return false if cellUsed are not equal

	for (int i = 0; i < left.cellsUsed; i++ ) {
		if ( left.info[i] != right.info[i] ) return false;
	}

	// If function reaches this statement all the entries for both objects have the same value
	// they have the same value in each memory location
	return true;
}

// constructor (default)
cSales::cSales(void) : cellsUsed(10) {
	info = new int[cellsUsed];
	for (int i = 0; i < cellsUsed; i++) {
		info[i] = 0;
	}
}

// constructor (copy)
cSales::cSales(const cSales & other) : cellsUsed(other.cellsUsed) {
	info = new int[other.cellsUsed];
	for (int i = 0; i < other.cellsUsed; i++) {
		info[i] = other.info[i];
	}
}

cSales cSales::operator+(const cSales & other) const {

	cSales workObject;
	workObject.info = new int[other.cellsUsed];		// allocate a new array

	// use the lower value of cellsUsed
	workObject.cellsUsed = (this->cellsUsed <= other.cellsUsed) ? this->cellsUsed : other.cellsUsed;
		
	for ( int i = 0; i < workObject.cellsUsed; i++) {
		workObject.info[i] = info[i] + other.info[i];
	}

	return workObject;
}
// Answer’s cells are the sum of corresponding cells
// use the smaller value of cellsUsed for the return value

// destructor
cSales::~cSales(void) {

	cout << "destructor says hello!" << endl;	
	delete [] info;
}



                                                          PAGE 9       

6.  Give the output for each function call in the following program.  Show the output to the right
of the statement that caused the output.

PLEASE DO NOT USE VISUAL STUDIO FOR THIS PROBLEM #6
JUST TYPE IN THE ANSWERS DO NOT USE THE COMPUTER TO CHECK YOUR WORK


#include <fstream.h>
class one {
public:
	void f1(void)const { cout <<"Tom\n";}
	void f2(void)const { cout <<"Mary\n";}
	virtual void f3(void)const { cout <<"Bill\n";}
private:
};

class two :public one {
public:
	void f2(void)const { cout <<"Ann\n";}
	virtual void f3(void)const { cout <<"Josh\n";}
	void f4(void) const { cout << "Kathy\n"; }
private:
};

void print(const one & o)
{
	o.f3();
}

void main()
{ 	one a;
	two b;
	one & c = b; My note: c is an alias of class one datatype
	one * p1; My note: p1 is base class one datatype pointer 
	two * p2; My note: p2 is derived class two datatype pointer 
	cout << "Test base class\n";
	a.f1(); Output: Tom  
	a.f2(); Output: Mary
	a.f3(); Output: Bill
	
	cout << "Test alias\n";
	c.f1(); Output: Tom
	c.f2(); Output: Mary
	c.f3(); Output: Josh
	
	cout << "Test of base class pointers pointers\n";
	p1 = & b; My note: p1 now points to  a derived class two datatype
	p1->f1(); Output: Tom  
	p1->f2(); Output: Mary 
	p1->f3(); Output: Josh

	cout << "Test of derived class pointers\n";
	p2 = & b; My note: p2 now points to to a derived class two datatype
	p2->f1(); Output: Tom  
	p2->f2(); Output: Ann 
	p2->f3(); Output: Josh 
	p2->f4(); Output: Kathy

	cout << "Test of casting derived class pointer\n";
	static_cast<one *>( p2 ) ->f1(); Output: Tom
	static_cast<one *>( p2 ) ->f2(); Output: Mary
	static_cast<one *>( p2 ) ->f3(); Output: Josh
	
	cout << "Test of casting derived class\n";

	static_cast<one>( b ).f1(); Output: Tom
	static_cast<one>( b ).f2(); Output: Mary
	static_cast<one>( b ).f3(); Output: Bill

	cout << "Test of base class alias function call\n";

	print(a); Output: Bill 
	print(b); Output: Josh
	print(c); Output: Josh
}