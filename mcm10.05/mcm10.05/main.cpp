// **************************************************************************
//
// Counter.cpp
//
// Defines and tests class CounterType, which is used to count things.
// CounterType contains both a default constructor and a constructor that
// sets the count to a specified value, plus methods to increment, decrement,
// return, and output the count.  The count is always nonnegative.
//
// **************************************************************************
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class CounterType
{
public:
    CounterType();
    //Initializes the count to 0.
    
    CounterType(int initCount);
    //Precondition: initCount holds the initial value for the count.
    //Postcondition:
    //  If initCount > 0,initializes the count to initCount.
    //  If initCount <= 0,initializes the count to 0.
    
    void increment();
    //Postcondition:
    //  The count is one more than it was.
    
    void decrement();
    //Postcondition:
    //  If the count was positive, it is now one less than it was.
    //  If the count was 0, it is still 0
    
    int getCount();
    void output(ostream& outStream);
    //Precondition: outStream is ready to write to
    //Postcondition: count has been written to outStream
    
private:
    int count;
    
};


// --------------------------------
// ----- ENTER YOUR CODE HERE -----
// --------------------------------
int main()
{
    CounterType test;
    
    test.increment();
    test.decrement();
    
    test.output(cout);
    
    cout << endl;
    
    test = CounterType(25);
    
    test.output(cout);
    
    cout << endl;
    
    if (test.getCount() == 25)
    {
        cout << "wow much code very well wow" << endl;
    }
    
    return 0;
}

// --------------------------------
// --------- END USER CODE --------
// --------------------------------


CounterType::CounterType()
{
    count = 0;
}

CounterType::CounterType(int initCount)
{
    if (initCount >= 0)
        count = initCount;
    else
        count = 0;
}

void CounterType::increment()
{
    count++;
}

void CounterType::decrement()
{
    if (count > 0)
        count--;
}

int CounterType::getCount()
{
    return count;
}

void CounterType::output(ostream& outStream)
{
    outStream << count;
}
