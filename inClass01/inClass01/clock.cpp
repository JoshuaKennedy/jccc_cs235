#include "clock.h"

// 11 member functions, i.e. methods  -  NEED TO BE WRITTEN
//   Below:  5 methods are written, a 6th method has only a shell
// get methods
int  Clock::getMinutes(void) const
{
    return minutes;
}

int Clock::getHours() const
{
    return this->hours;
}

bool Clock::getChimeOnHalfHour(void) const
{
	return Clock::shouldChimeOnHalfHour;
}

bool Clock::getChimeOnHour() const
{
    return this->shouldChimeOnHour;
}

// set methods


void Clock::setMinutes(int m )
{
	if ( m >= 0 && m <= 59 )
		minutes = m;
	else
		minutes = 0;
}

void Clock:: setHours(int h)
{
    if (h > 0 && h <= 23)
        this->hours = h;
    else
        this->hours = 0;
}

void Clock::setChimeOnHalfHour(bool v )
{
	shouldChimeOnHalfHour = v;
}

void Clock::setChimeOnHour(bool v)
{
    this->shouldChimeOnHour = v;
}

string Clock::chimeOnHalfHour(void) const
{
    if ( this->getChimeOnHalfHour() && this->getMinutes() == 30 )
		return "ding";
	else
		return "";
}

string Clock::chimeOnHour(void) const
{
    if (this->getChimeOnHour() && this->getMinutes() == 0)
    {
        int numChimes = this->getHours();
        string message;
    
        if (this->getHours() > 12)
        {
            numChimes = this->getHours() - 12; // 13 will be 1, 14 will be 2, etc.
        }
        else if (this->getHours() == 0)
        {
            numChimes = 12;
        }
    
        for (int i = 0; i < numChimes; i++)
        {
            message += "dong ";
        }
    
        return message;
    }
    else
        return "";
}

void Clock::tick()
{
    if (this->minutes == 59)
    {
        this->minutes = 0;
        
        if (this->hours == 23)
            this->hours = 0;
        else
            this->hours++;
        
        if (this->getChimeOnHour())
            cout << this->chimeOnHour() << endl;
    }
    else
    {
        this->minutes++;
        
        if (this->minutes == 30)
        {
            if (this->getChimeOnHalfHour())
                cout << this->chimeOnHalfHour() << endl;
        }
    }
}
