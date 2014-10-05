//    CIS 235 Exercise 5B - write and test the following functions
//        - function names ending in I - use loops
//        - function names ending in R - use recursion, NO LOOPS
#include <iostream>
using namespace::std;


//    NOTE:        const char * p    denotes a C++ string
//                     which is an array of characters ending in the NULL character '\0'


int productI(const int data[], int cellsUsed);

int productR(const int data[], int cellsUsed);

int countCharI(const char* p, char lookFor);

int countCharR(const char* p, char lookFor);

int raiseToPowerI(int base, int exponent);  // assume exponent > 0
//     raiseToPower(2,4) returns 2*2*2*2 ==> 16

int raiseToPowerR(int base, int exponent);  // assume exponent > 0

bool equalI(const char* left, const char* right);   // are the 2 C++ strings equal or not

bool equalR(const char* left, const char* right);   // are the 2 C++ strings equal or not

char largestI(const char* p);

char largestR(const char* p);


int main()
{
	int info[5] = { 4, 8, 2, 9, 6};
	cout << "Testing product" << endl
    << productI(info, 5)<< endl
    << productR(info, 5 ) << endl;
    
    cout << "Testing countChar" << endl
    << countCharI("mississippi", 'i') << endl
    << countCharR("mississippi", 'i') << endl;
    
    cout << "Testing raiseToPower" << endl
    << raiseToPowerI(5,4) << endl
    << raiseToPowerR(5,4) << endl;
    
    cout << "Testing equalI" << endl
    << equalI("abcde", "abcde") << endl
    << equalI("abxde", "abcde") << endl
    << equalI("abc"  , "abcde") << endl
    << equalI("abcde", "abc"  ) << endl
    << equalI("abcde", "abcdg") << endl;
    
	cout << "Testing equalR" << endl
    << equalR("abcde", "abcde") << endl
    << equalR("abxde", "abcde") << endl
    << equalR("abc"  , "abcde") << endl
    << equalR("abcde", "abc"  ) << endl
    << equalR("abcde", "abcdg") << endl;
    
    
	cout << "Testing largestI" << endl
    << largestI("xabcde") << endl
    << largestI("abxcde") << endl
    << largestI("abcdex") << endl;
    
    
	cout << "Testing largestR" << endl
    << largestR("xabcde") << endl
    << largestR("abxcde") << endl
    << largestR("abcdex") << endl;
    
	return 0;
}

// ******************************************************************


int productI(const int data[], int cellsUsed)
{
    int product = 1;
    
    for (int i = 0; i < cellsUsed; i++)
    {
        product *= data[i];
    }
    
	return product;
}

int productR(const int data[], int cellsUsed)
{
    if (cellsUsed == 0) return 1;
    
    return data[0] * productR(data + 1, cellsUsed - 1);
}

int countCharI(const char* p, char lookFor)
{
	int count = 0;
    
	while(*p != '\0')
	{
		if (*p == lookFor)
			count++;
        
		p++;
	}
    
	return count;
}

int countCharR(const char* p, char lookFor)
{
	static int count = 0;
    
	if (*p == '\0') return count;
	else
	{
		if (*p == lookFor) count++;
		p++;
		return countCharR(p, lookFor);
	}
}

int raiseToPowerI(int base, int exponent)  // assume exponent > 0
{
    int result = 1;
    
    for (int i = 1; i <= exponent; i++)
    {
        result *= base;
    }
        
	return result;
}

int raiseToPowerR(int base, int exponent)  // assume exponent > 0
{
    if (exponent == 0) return 1;
    
	return base * raiseToPowerR(base, exponent - 1);
}

bool equalI(const char* left, const char* right)
{
    if (left == right) return true;
    
    while (*left != '\0' || *right != '\0')
    {
        if (*left != *right) return false;
        
        left++;
        right++;
    }
    
	return true;
}

bool equalR(const char* left, const char* right)
{
    if (left == right) return true;
    
    if (*left != *right) return false;
    
	return equalR(left + 1, right + 1);;
}

char largestI(const char* p)
{
    char large = *p;
    p++;
    
	while (*p != '\0')
    {
        if (*p > large) large = *p;
        p++;
    }
    
    return large;
}

char largestR(const char* p)
{
    if (*p == '\0') return '\0';
    
    char toRight = largestR(p + 1);
    
    return (*p > toRight ? *p : largestR(p + 1));
}
