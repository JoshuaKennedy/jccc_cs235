//  CIS 235  Exercise 1

#include <iostream>
#include <string>

using namespace std;

//  function will display on cout the contents of an arrary -  FUNCTION 1
void printArray( ostream & out, const string data[], int cellsUsed);


//  function will sort an array                             -  FUNCTION 2
void sortArray( string data[], int cellsUsed);
//   NOTE:  in the string class the assignment operator and all of the relational operators
//                have been overloaded
//          Thus, in your sort algorithm you can use   data[i] < data[j]


int main()
{
	const int CELLS = 5;
	string  names[CELLS] = { "tom", "mary", "ann", "bill","carol"};
    
	cout << "Original array" << endl;
	printArray(cout,names,CELLS);
	cout << endl;
    
	sortArray(names,CELLS);
    
	cout << "Sorted array" << endl;
	printArray(cout,names,CELLS);
	cout << endl;
    
    
    return 0;
    
}   // end main


//  write FUNCTION 1
void printArray(ostream& out, const string data[], int cellsUsed)
{
    for (int i = 0; i < cellsUsed; i++)
    {
        out << data[i] << " ";
    }
    
    out << endl;
}

//  write FUNCTION 2
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