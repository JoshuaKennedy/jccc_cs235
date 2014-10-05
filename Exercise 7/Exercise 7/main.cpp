//  CIS 235 exercise 7

#include <iostream>
#include <string>

using namespace std;

//   declare a class for recording a test score
//   the data will be pointer to an integer, rather than an integer
//
//   - this exercise is designed to show how to work with pointer memory
//   - of course, we would NOT normally use a pointer for just an integer
//   - to illustrate the concepts, but keep the implementation simple,
//             integer data was used.  The general case would be object data,
//             not integer data
class testScore
{
public:
    //  declare a default constructor - the pointer should be set to NULL
    testScore()
    {
        this->score = NULL;
    }
    
    //  declare a function that returns a bool, indicating if the test has been taken
    bool testTaken()
    {
        return (this->score != NULL);
    }
    
    //  declare a function to record the test score, the parameter will be an integer
    //  use the following rules
    //  -  if no test has been taken, allocate memory and record the score
    //  -  if a test has been taken and the parameter is less than or equal to
    //         the score, do nothing
    //  -  if the test has been taken and the parameter is  higher than the score,
    //         - release the old memory
    //         - allocate new memory
    //         - record the score
    void recordTestScore(int score)
    {
        if (!this->testTaken())
        {
            this->score = new int(score);
            
            return;
        }
        
        if (this->testTaken() && (*this->score) < score)
        {
            delete[] this->score;
            
            this->score = new int(score);
            
            return;
        }
    }
    
    //   declare a function to print the score to an ostream parameter
    //   if the test has not been taken, send an appropriate message to the ostream
    //         otherwise print the score
    void print(ostream& out)
    {
        out << (this->testTaken() ? "Score: " + to_string(*this->score) : "No Score Recorded") << endl;
    }
    
    //   declare the destructor
    //   be CAREFUL, you will need an if statement in your destructor
    ~testScore()
    {
        if (this->testTaken())
        {
            delete[] this->score;
            this->score = nullptr;
        }
    }
    
private:
    //  declare the data needed to implement the class
    int* score;
};

//  test the class member functions
//    - declare an object, but do NOT record a score for the object

//    - declare a second object and record the scores of 83, 78, 92
//       use appropriate member print functions to verify your code
int main()
{
    testScore object1;
    testScore object2;
    
    object1.print(cout);
    
    object2.recordTestScore(83);
    object2.print(cout);
    
    object2.recordTestScore(78);
    object2.print(cout);
    
    object2.recordTestScore(92);
    object2.print(cout);
    
    return 0;
}

