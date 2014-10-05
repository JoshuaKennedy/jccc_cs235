// **********************************************************
//
//  WordLetterCount.cpp
//
//  This program counts the number of words and the number
//  of occurrences of each letter in a line of input.
//
// **********************************************************

#include <iostream>
#include <cctype>

using namespace std;

void readAndCount (int &numWords, int letterCount[]);
// Reads a line of input. Counts the words and the number
// of occurrences of each letter.

void outputLetterCounts (int letterCount[]);
// Prints the number of occurrences of each letter that
// appears in the input line.


// =========================
//      main function
// =========================
int main()
{
    int numWords;
    int letterCount[26] = { 0 };  // stores the frequency of each letter
    
    cout << endl;
    cout << "Enter a line of text.." << endl << endl;
    
    readAndCount (numWords, letterCount);
    
    cout << endl;
    cout << numWords << " words" << endl;
    outputLetterCounts(letterCount);
    
    return 0;
}

// =========================
//   Function Definitions
// =========================

void readAndCount(int& numWords, int letterCount[])
{
    bool inWord;
    numWords = 0;
    char letter;
    
    cin.get(letter);
    
    while (letter != '\n')
    {
        if (isalpha(letter))
        {
            inWord = true;
            
            letterCount[tolower(letter) - 'a']++;
        }
        else
        {
            if (inWord)
                numWords++;
            
            inWord = false;
        }
        
        cin.get(letter);
    }
    
    if (inWord)
        numWords++;
}

void outputLetterCounts(int letterCount[])
{
    for (int i = 0; i < 26; i++)
    {
        if (letterCount[i] > 0)
        {
            cout << letterCount[i] << " " << char('a' + i) << endl;
        }
    }
}

