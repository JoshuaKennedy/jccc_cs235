#include "clock.h"

int main()
{
    //  TEST YOUR 11 member functions below
    
    Clock myClock;
    
    myClock.setHours(23);
    myClock.setMinutes(59);
    myClock.setChimeOnHour(true);
    
    myClock.tick();
    
    cout << "myClock will " << (myClock.getChimeOnHalfHour() ? "" : "not ") << "ding on the half-hour." << endl;
    
    for (int i = 0; i <= 31; i++)
    {
        cout << myClock.getHours() << ":" << (myClock.getMinutes() < 10 ? "0" : "") << myClock.getMinutes() << endl;
        
        myClock.tick();
    }
    
    myClock.setHours(23);
    myClock.setMinutes(46);
    myClock.setChimeOnHour(false);
    myClock.setChimeOnHalfHour(true);
    
    cout << "myClock will " << (myClock.getChimeOnHour() ? "" : "not ") << "dong on the hour." << endl;
    
    for (int i = 0; i <= 46; i++)
    {
        cout << myClock.getHours() << ":" << (myClock.getMinutes() < 10 ? "0" : "") << myClock.getMinutes() << endl;
        
        myClock.tick();
    }
    
    return 0;
}