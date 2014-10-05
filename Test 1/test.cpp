// Test 1 - Spring, 2014
// NAME: Brandon Anderson
//  CALL FUNCTIONS - IF POSSIBLE
//  AVOID WORK VARIABLES - IF POSSIBLE
//  CHAIN FUNCTIONS - IF POSSIBLE
//  You CANNOT write any helper functions of your own
//   you can only use the functions given in the class definition

#include <iostream>
using namespace::std;

class coin 
{
	 friend ostream & operator << ( ostream &, const coin &);
	 friend bool operator == ( int n, const coin & right);
				//  will return true if n is equal to the count field of right

public:
	coin(void);
	coin(int ct, const char * d);
	coin(const coin &);
	~coin(void);

	int getCount(void) const;

	const char * getDesc(void) const;

	coin & setCount(int n);
	coin & setDesc( const char *);

	const coin & getLarger( const coin & ) const;
	//  will  return as an alias the larger coin
	//  , i.e. larger of the invoking instance and the paramater
	//  use getCount() to determine the largest

	const coin & operator = ( const coin &);

	coin  operator + ( const coin & ) const;
	//  return coin with counts added
	//  same desc as the invoking instance

	bool operator == ( const coin &) const;
	//  return true if the counts are equal

	bool operator == ( int v) const;
	//  return true if v is equal to the count field
private:
	int count;
	char desc[25];
};

class bank 
{
	friend ostream & operator<<(ostream &, const bank &);
public:
	bank(void);
	bank(int, const char * coinDesc,  const char * ownerName);
	bank(const bank &);
	bank( const coin &, const char * ownerName);
	
	~bank();

	int getCount(void) const;

	bank &  changeOwner( const char *);

	const bank & operator = (const bank &);

	bool  operator == ( const bank & ) const;
	// will return true if the owners are equal as strings
	//  and coin fields data are equal as coins

	bool operator != ( const bank &) const;
private:
	coin  data;
	char* owner;
};

ostream & operator << ( ostream & w, const coin & c)
{
	w << c.getCount() << ' ' << c.getDesc() << endl;

	return w;
}

bool operator == ( int n, const coin & right)
				//  will return true if n is equal to the count field of right
{
	return (n == right.getCount());
}


coin::coin(void)
{
	this->setCount(1).setDesc("Pennies");
}

coin::coin(int ct, const char * d)
{
	this->setCount(ct).setDesc(d);
}

coin::coin(const coin & other)
{
	this->setCount(other.getCount()).setDesc(other.getDesc());
}

coin::~coin(void)
{
}

int coin::getCount(void) const
{
	return this->count;
}

const char* coin::getDesc(void) const
{
	return this->desc;
}

coin & coin::setCount(int count)
// MUST USE THE PARAMETER NAME OF COUNT
{
	this->count = count;
	return *this;
}

coin & coin::setDesc(const char * c)
{
	strcpy(this->desc, c);
	return *this;
}

const coin & coin::getLarger( const coin & right ) const
{
	return (this->count > right.getCount() ? *this : right);
}

//  In the above function, explain the 3 uses of const
// 1) the first const is for the return type, since the return type is a reference to a coin object.
//    the reference is constant so it can't be modified.
// 2) the second const is for the parameter, since it is a reference is a coin reference, we make it const so the function won't
//    modify that reference parameter.
// 3) the third const is for the function, so it won't modify any of the instance data of the object.

const coin & coin::operator = (const coin& right)
{
	this->count = right.getCount();
	this->setDesc(right.getDesc());
	
	return *this;
}

coin coin::operator + (const coin& right) const
{
	// return coin with counts added
	// same desc as the invoking instance

	return coin(this->count + right.getCount(), this->getDesc());
}

bool coin::operator == (const coin& right) const
// return true if the counts are equal
{
	return (this->count == right.getCount());
}

bool coin::operator == (int v) const
// return true if v is equal to the count field
{
	return (this->count == v);
}

// ******      bank functions        *******

ostream & operator<<(ostream & w, const bank& b)
{
	w << b.data << endl << b.owner << endl;

	return w;
}

bank::bank(void)
{
	this->data = coin();
	this->owner = "Josh Kennedy";
}

bank::bank(int a, const char* coinDesc,  const char* ownerName)
{
	this->data = coin(a, coinDesc);
	this->owner = (char*)ownerName;
}

bank::bank(const bank& other)
{
	this->owner = other.owner;
	this->data = other.data;
}

bank::bank(const coin & c, const char* ownerName)
{
	this->data = c;
	this->owner = (char*)ownerName;
}

bank::~bank()
{
}

int bank::getCount(void) const
{
	return this->data.getCount();
}

bank& bank::changeOwner(const char* c)
{
	this->owner = (char*)c;

	return *this;
}

const bank& bank::operator = (const bank& right)
{
	this->data = right.data;
	this->owner = right.owner;

	return *this;
}

bool bank::operator == (const bank& right) const
{
	// will return true if the owners are equal as strings
	//  and the coin fields are equal as coins

	return (this->data == right.data && strcmp(this->owner, right.owner) == 0);
}

bool bank::operator != (const bank & right) const
{
	return !(*this == right);
}

// *****************************************************************************
//   Client functions
// *****************************************************************************

coin returnLarger(const coin& left, const coin& right)
{
	//  will return the larger coin, based on the count value
	//  the desc of the coin returned will be "Larger Coin";
	coin largerCoin;

	if (left.getCount() > right.getCount())
		largerCoin.setCount(left.getCount());
	else if (right.getCount() > left.getCount()) 
		largerCoin.setCount(right.getCount());

	largerCoin.setDesc("Larger Coin");

	return largerCoin;
}

int main()
{
	coin a(4,"Dime");
	coin c(5,"Penny"), d(12,"Quarter"), e(15,"$20 Gold Coin"), f;
	bank b(24,"Dollar Bill", "John Doe");

	cout << a << b << c;

	//  Write the above using function notation:
	operator<<(operator<<(operator<<(cout, a), b), c);

	f = (c + d) + e;

	//   Write the above using function notation NOTE: There are 3 operators:
	f.operator=((c.operator+(d).operator+(e)));

	return 0;
}
