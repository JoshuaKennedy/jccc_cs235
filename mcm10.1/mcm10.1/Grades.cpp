// ******************************************************************
//
//  Grades.cpp
//
//  This program computes student grades. For each student, two
//  quiz grades (graded on a 10 point basis), one midterm exam grade
//  and one final exam grade (each on a 100 point basis) are read
//  in. The final numeric grade is computed weighing the final
//  exam 50%, the midterm 25%, and the quizzes 25%. The numeric
//  grade and corresponding letter grade are output.
//
// ******************************************************************

#include <iostream>

using namespace std;

//
// Structure for a student record
//

struct StudentRecord
{
    double quiz1, quiz2, midtermExam, finalExam, courseAverage;
    char letterGrade;
};

void outputRecord (StudentRecord record)
{
    cout << endl;
    cout << "Quiz Scores: " << record.quiz1 << ", and " << record.quiz2 << endl;
    cout << "Midterm Exam Score: " << record.midtermExam << endl;
    cout << "Final Exam Score: " << record.finalExam << endl;
    cout << endl;
    cout << "Course Average: " << record.courseAverage << endl;
    cout << "Final Letter Grade: " << record.letterGrade << endl;
    cout << endl;
}

char getLetterGrade(double numericGrade)
{
    char letter;
    
    if (numericGrade < 60)
        letter = 'F';
    else if (numericGrade < 70)
        letter = 'D';
    else if (numericGrade < 80)
        letter = 'C';
    else if (numericGrade < 90)
        letter = 'B';
    else
        letter = 'A';
    
    return letter;
}

void computeAverage (StudentRecord& record)
{
    const double EXAM_WT = 0.5;
    const double MIDTERM_WT = 0.25;
    const double QUIZ_WT = 0.25;
    double quiz1Percent, quiz2Percent;
    
    //
    // Convert the 10 point quizzes to a percent, then find the average
    //
    quiz1Percent = 100 * record.quiz1 / 10.0;
    quiz2Percent = 100 * record.quiz2 / 10.0;
    double quizAvg = (quiz1Percent + quiz2Percent) / 2;
    
    //
    // Compute the weighted average to get the numeric course grade
    //
    record.courseAverage = quizAvg * QUIZ_WT +
    record.midtermExam * MIDTERM_WT + record.finalExam * EXAM_WT;
    
    //
    // Call the getLetterGrade function to find the corresponding letter grade
    //
    record.letterGrade = getLetterGrade(record.courseAverage);
}

int main()
{
    StudentRecord myRecord;
    
    cout << "Enter grade for Quiz 1 (out of 10pts): ";
    cin >> myRecord.quiz1;
    
    cout << "Enter grade for Quiz 2 (out of 10pts): ";
    cin >> myRecord.quiz2;
    
    cout << "Enter grade for Midterm Examination: ";
    cin >> myRecord.midtermExam;
    
    cout << "Enter grade for Final Examination: ";
    cin >> myRecord.finalExam;
    
    computeAverage(myRecord);
    
    outputRecord(myRecord);
}
