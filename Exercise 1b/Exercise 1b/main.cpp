#include <iostream>
using namespace::std;

// In C++ there are 4 ways a function can return an answer to the caller
//    All of our functions will calculate the answer as 1 added to the first parameter

// 1.  return the answer on the stack
//        NOTE:  the caller can save the returned answer by using the = operator

int  f1(int parm);

// 2.  place the answer in the 2nd parameter

void f2(int parm, int & answer);  //  Why the & ?

// 3.  place the answer in the memory location pointed to by the 2nd parameter
//        NOTE:  the 2nd parameter is for the address of the answer,
//               not the answer itself
//        NOTE:  the caller acquires the memory for the answer

void f3(int parm, int * pointerToAnswer);

// 4. return the address of the answer on the stack
//         NOTE:  the function must acquire the memory for the answer

int* f4(int parm);

int main()
{
	// investigate f1
	cout << f1(15) << endl;   // printed value is 16
    // NOTE:  value parameters can have constants
	int ans;
	//  call f1 and save the answer in ans and print ans
	//  STUDENT WRITES THE CODE
    cout << "\ntesting f1 with parameter of 68..." << endl;
    ans = f1(68);
    cout << ans << endl;
    
	//  function chaining - a parameter will be a function call
	//    sqrt(sqrt(16.0)) returns an answer of 2.0
	//  using f1 multiple times and the constant 22 have the value of 25 printed
    //  STUDENT WRITES THE CODE
    cout << "\ntesting chained f1 calls..." << endl;
    ans = f1(f1(f1(22)));
    cout << ans << endl;
    
	// investigate f2
	// declare an integer, call f2 using a first parameter of 35 and print the answer
    //  STUDENT WRITES THE CODE
    cout << "\ntesting f2 with parameter of 35..." << endl;
    f2(35, ans);
    cout << ans << endl;
    
    
	//  investigate f3
	//  PART A - work with integers
	int theAns;
	//  call f3 using a first parameter of 42 and have the answer placed in theAns
	//      then print theAns
	//  STUDENT WRITES THE CODE
    cout << "\ntesting f3 with parameter of 42..." << endl;
    f3(42, &theAns);
    cout << theAns << endl;
    
	//  PART B - work with pointers
	int* pointer;
	// acquire at run time the memory for an integer
	pointer = new int;
	//  call f3 using a first parameter of 117 and have the answer placed in the
	//       memory pointed to by pointer
	//       the print the answer
    //  STUDENT WRITES THE CODE
    cout << "\ntesting f3 with pointer and parameter of 117..." << endl;
    f3(117, pointer);
    cout << *pointer << endl;
    
	//  return the memory
	delete pointer;
    
	//  investigate f4
	//  PART A
	//   without saving the return value call f4 with the first parameter 234
	//    the value of 235 should be printed
	//  STUDENT WRITES THE CODE
    cout << "\ntesting f4 with value of 234..." << endl;
    int pToA = *f4(234);
    cout << pToA << endl;
    
	//  PART B
	//  declare a pointer variable, call f4 with the first parameter 319
	//     and save the return value in the pointer variable
	//     then print the answer -- the value 320 should be printed
    //  STUDENT WRITES THE CODE
    cout << "\ntesting f4 with pointer and parameter of 319..." << endl;
    int* secondPointer = new int;
    secondPointer = f4(319);
    cout << *secondPointer << endl;
    
    
	//  release the memory that the function acquired
	//  STUDENT WRITES THE CODE
    delete secondPointer;
    
    return 0;
}

// write the functions
// STUDENT WRITE THE CODE

int  f1(int parm)
{
    return parm + 1;   // DUMMY CODE TO GET TO COMPILE
}

void f2(int parm, int & answer)
{
    answer = parm + 1;
}

void f3(int parm, int * pointerToAnswer)
{
    *pointerToAnswer = parm + 1;
}

int * f4(int parm)
{
    int* pa = new int;
    *pa = parm + 1;
    
    return pa;  //  DUMMY CODE - DO NOT USE!!!! only to get a compile
}
