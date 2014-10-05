// CIS 235   -  Lab 3
// Given the class definition for an appointment
//  -- Write the member functions for the class appointment
//  -- Write the 3 NONMEMBER functions: makeappointment, getSource, and advanceDate
//  -- Write a main program to test all member functions for the class
//          and the  3 nonmember functions: makeappointment, getSource and advanceDate
//  -- Use three files  appointment.h     appointment.cpp      drlab3.cpp

// You need not include any data error checking code

#include <fstream>
using std::ostream;

#include <cstring>     // Needed for string functions

#include "appointment.h"

//  **********************************************************************

// The implementer will write all of the member functions
//         and place these functions in a separate file "appointment.cpp"


//   *********************************************************************


// The Client, i.e. User, will create the file drhw3.cpp
//  and prototype, write, and use the following 3 functions

appointment makeAppointment(long, const char [], int d, int m, int y);

long getSource(const appointment &);   // will return the source in the parameter

//  The following function will return an appointment with the same source and desc
//     as the parameter appointment.  The day, month, and year will reflect numberOfDays
//     into the future.
appointment advanceDate( const appointment &, int numberOfDays);

//  **********************************************************************
//                      main driver program

int main()
{
    //  The client will test the 3 function above along with all
    //             of the member functions
    
    appointment a = appointment();
    a.print(cout, 1);
    
    appointment b = appointment(8008135, "wow", 20, 4, 2014);
    b.print(cout, 2);
    
    appointment c = appointment(b);
    c.print(cout, 666);
    
    appointment d = makeAppointment(1234567, "such code", 21, 12, 2012);
    d.print(cout, 1);
    d = advanceDate(d, 10);
    d.print(cout, 1);
    
    cout << "source of d is: " << getSource(d) << endl;
    
	return 0;
}

//  **********************************************************************

//  Client places the code for makeappointment, getSource and advanceDate here

appointment makeAppointment(long s, const char n[], int d, int m, int y)
{
    return appointment(s, n, d, m, y);
}

long getSource(const appointment & e)   // will return the source in the parameter
{
    return e.getSource();
}

appointment advanceDate( const appointment & e, int numberOfDays)
{
    appointment newAppointment = appointment(e);
    
    int days = e.getDay();
    int months = e.getMonth();
    int years = e.getYear();

    days += numberOfDays;
    
    if (days > 30)
    {
        days -= 30;
        months++;
        
        if (months > 12)
        {
            months = 1;
            years++;
        }
    }
    
    newAppointment.setDay(days);
    newAppointment.setMonth(months);
    newAppointment.setYear(years);
    
    return newAppointment;
}
