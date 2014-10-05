//  CIS 235 Exercise 4

#include <iostream>
#include <string>
#include <ctime>

using namespace::std;

//  in the <ctime> library is a function   time(0)
//     that returns the number of seconds since 1/1/1970 when the function is called
//  to compute an elapsed time
//      1st - call time(0) and remember the value
//      2nd - at a time in the future, call time(0) again
//               and subtract the remembered value
//               -  that will give you the elapsed time
//

class timeC //   this class will keep track of the time the object was created
{
public:
    //  declare a default constructor
    timeC()
    {
        this->seconds = time(0);
    }
    
    //  declare a function to return when the object was "born" in seconds
    long born()
    {
        return this->seconds;
    }
    
    //  declare a function to return the age of the time object in seconds
    //   NOTE:  - the age is an elapsed time from when the object was created
    //          - call the age function a little later, and the age is greater
    long timeAge()
    {
        return time(0) - this->seconds;
    }
    
private:
    //  declare the data needed to implement the class
    long seconds;
};

//  test the 3 member functions

int main()
{
    cout << "wow creating timeC object\n";
    timeC yes = timeC();
    cout << "age of object in seconds since 1970 is " << yes.born() << endl;
    
    for (int i = 0; i < 975896194; i++) { }
    
    cout << "it has been " << yes.timeAge() << " seconds since the object was created! wow" << endl;
    
    return 0;
}

