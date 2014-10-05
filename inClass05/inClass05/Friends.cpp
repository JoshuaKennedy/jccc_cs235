#include "Friends.h"

Friends::Friends()
{
    placer = 0;
}

Friends::Friends(const Friends &)
{
}
	
Friends::~Friends()
{
}

bool Friends::isFull(void) const
{
	return (placer >= NUMBER_FRIENDS);
}

bool Friends::isEmpty(void) const
{
	return (placer == 0);
}

bool Friends::addFront(const FullName& item)
{
	return true;
}

bool Friends::addRear(const FullName& item)
{
    if (this->isFull())
        return false;
    else
    {
        info[placer++] = item;
        return true;
    }
}
	
bool Friends::removeFront()
{
    // return true if not empty and data removed
	return true;
}
bool Friends::removeRear()
{
    // return true if not empty and data removed
    if (this->isEmpty())
        return false;
    else
    {
        placer--;
        return true;
    }
}

const Friends & Friends::operator=(const Friends & myFriend)
{
	return *this;
}

bool Friends::isSorted(void) const
{
    // return true is the names are sorted, use the < operator for FullName
	return false;
}

void Friends::printAll(ostream& output)
{
    for (int i = 0; i < placer; i++)
    {
        output << info[placer] << endl;
    }
}

int Friends::findFriend(const char* firstName) const
{
    // return first location where a FullName is found with the same firstName
    // return -1 is not found
    
    
	return -1;
}

FullName Friends::retrieveFriend(int location) const
{
	// starting at 1 return the FullName in the requested location
    FullName answer;
	return answer;
}

bool Friends::removeFriend(int location) const
{
	// starting at 1 delete the FullName in the requested location
    return true;
}