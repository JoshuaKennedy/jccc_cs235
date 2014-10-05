//  CIS 235  Exercise 2

#include <iostream>
#include <string>

using namespace std;

//  EXERCISE 01 FUNCTIONS
//  function will display on cout the contents of an arrary - FUNCTION 1
void printArray( ostream & out, const string data[], int cellsUsed)
{
    for (int i = 0; i < cellsUsed; i++)
    {
        out << data[i] << endl;
    }
}

//  function will sort an array - FUNCTION 2
void sortArray(string data[], int cellsUsed)
{
    for (int i = 0; i < cellsUsed; i++)
    {
        for (int k = 0; k < cellsUsed; k++)
        {
            if (std::strcmp(data[i].c_str(), data[k].c_str()) < 0)
            {
                string tmp = data[i];
                data[i] = data[k];
                data[k] = tmp;
            }
        }
    }
}

//  EXERCISE 02 FUNCTION
//  function in input an array - FUNCTION 3
void inputArray(istream & in, string data[], int cellsUsed)
{
    for (int i = 0; i < cellsUsed; i++)
    {
        cin >> data[i];
    }
}


int main()
{
	int cellsUsed;
	cout << "Enter the number of cells in the array ";
	cin >> cellsUsed;
    
	string * names;
    
	//  allocate memory for the array from the heap with the new operator
    names = new string[cellsUsed];
    
    //   STUDENT CODE HERE *****************
    
	// call the inputArray function -  NOTE: on input the space character ends a name
    cout << "enter array elements: ";
    inputArray(cin, names, cellsUsed);
    
	//   STUDENT CODE HERE *****************
	
    
	cout << "Original array" << endl;
	printArray(cout, names, cellsUsed);
	cout << endl;
    
	sortArray(names,cellsUsed);
    
	cout << "Sorted array" << endl;
	printArray(cout, names, cellsUsed);
	cout << endl;
    
	//  return the memory to the heap
    delete[] names;
    
    //   STUDENT CODE HERE *****************
    
    return 0;
}   // end main


//  write FUNCTION 1



//  write FUNCTION 2


//  write FUNCTION 3