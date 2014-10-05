//
//  appointment.h
//  Lab 3
//


#ifndef __Lab_3__appointment__
#define __Lab_3__appointment__

#include <iostream>

using namespace std;

class appointment {
public:
    appointment(void);                       // default constructor
    appointment(long, const char*,int d,
                int m, int y);               // 5 argument constructor
    appointment(const appointment &);              // copy constructor
    
    void keyBoardInput(void);          // Assume no blanks in the desc
    
    long getSource(void) const;        // return source
    
    void setSource(long);              // change source
    
    void setMonth(int);
    void setDay(int);
    void setYear(int);
    
    int  getMonth(void) const;
    int  getDay(void)   const;
    int  getYear(void)  const;
    
    const char * getDescription(void) const; // return the address of the description
    
    void  changeDescription(const char *) ;  //  change an existing description
    
    void copyTo( appointment & ) const;      // copy invoking instance to parameter
    
    void incrementDate(void);      // advance the date by ONE day
    // You can assume 30 days in each month
    
    void print(ostream &, int dateFormat) const;   // print all fields
    // dateFormat == 1   month/day/year
    // dateFormat == 2   day/month/year
    
    ~appointment();               // destructor - indicate the address
    //    of the variable that is leaving
private:
    
    void setDescription(const char *);   //  used to allocated memory
    
    // data
    long source;          //  id of the person scheduling the appointment
    
    char * desc;          //  description of the appointment - Dynamic Data
    
    int  day;             //  day, month, and year when the appointment
    int  month;           //      will happen
    int  year;
};

#endif /* defined(__Lab_3__appointment__) */
