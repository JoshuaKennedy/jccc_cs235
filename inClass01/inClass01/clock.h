#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <string>

using namespace std;
class Clock   // use military time  see the website:
//  http://en.wikipedia.org/wiki/24-hour_clock
//  we will NOT use a time of 24 hours and 0 minutes
//  a time of 0 hours and 45 minutes is 12:45 am
//  a time of 1 hour and 0 minutes is 1:00am
//      and the clock would chime 1 time
//  a time of 14 hours and 0 minutes is 2:00pm
//      and the clock would chime 2 times

{
public:     // 11 member functions, i.e. methods  -  NEED TO BE WRITTEN
    int  getMinutes(void) const;
	int  getHours(void)   const;
	bool getChimeOnHalfHour(void)   const;
	bool getChimeOnHour(void)       const;
    
	void setMinutes(int m );
	void setHours(int h);
    void setChimeOnHalfHour(bool v );
	void setChimeOnHour(bool v);
    
	string chimeOnHalfHour(void) const;
	string chimeOnHour(void) const;
    
	void tick(void);           // time goes up 1 minute
    //  need to consider the cases:   59 minutes and any hour but 23
    //                                59 minues and 23 hours
private:
	int minutes;
	int hours;
	bool shouldChimeOnHalfHour;
	bool shouldChimeOnHour;
};
#endif