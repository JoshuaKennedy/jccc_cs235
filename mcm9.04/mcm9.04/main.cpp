#include <iostream>
using namespace::std;

void reverse(char *);

int main()
{
	//  RUN YOUR PROGRAM AT LEAST 3 TIMES TO TEST
	//     A C++ string with exactly 1 char
	//     A C++ string with an even number of characters
	//     A C++ string with an odd number of characters
	//  COPY AND PASTE THE OUTPUT OF EACH RUN AS A COMMENT
	//     AT THE END OF THIS FILE
    
	// declare a char array
    char* cString = new char[20];
    
	// prompt the user to enter a char array with no spaces
    cout << "enter string up to 20 characters with no spaces\n";
    cout.flush();
    
    cin >> cString;
    
	// echo the data the user typed in
    cout << "you have entered: " << endl;
    cout << cString << endl;
    
	// call the reverse function
    reverse(cString);
    
	// display the char array after the function reverse has been called
    cout << "the entered string reversed is: " << endl;
    cout << cString << endl;
    
	return 0;
}

// ======================
// reverse:
// Reverses the input string using pointers.
// ======================
void reverse(char *s)
{
    // write the code for the reverse function using pointers
    //      you cannot use array notation
    char* p = s;
    char* str = s + strlen(s) - 1;
    
    while (p < str)
    {
        char temp = *p;
        *p++ = *str;
        *str-- = temp;
    }
    
    s = str;
}

/* tests

test 1:

 enter string up to 20 characters with no spaces
 yes
 you have entered:
 yes
 the entered string reversed is:
 sey
 Program ended with exit code: 0

test 2:
 
 enter string up to 20 characters with no spaces
 tacocat
 you have entered:
 tacocat
 the entered string reversed is:
 tacocat
 Program ended with exit code: 0
 
test 3:
 
 enter string up to 20 characters with no spaces
 josh_is_cool
 you have entered:
 josh_is_cool
 the entered string reversed is:
 looc_si_hsoj
 Program ended with exit code: 0

*/

