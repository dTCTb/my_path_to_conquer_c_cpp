// Fig. 5.10: 5.10_GradeBook.cpp
// Member-function definitions for class GradeBook that
// uses a switch statement to count A, B, C, D, E, F grades.
#include "5.9_GradeBook.h" // include defintions of class GradeBook
#include <iostream>
using namespace std;

// constructor initializes courseName with string supplied as argument;
// initializes counter data members to 0
GradeBook::GradeBook(string name)
    : aCount(0), bCount(0), cCount(0), dCount(0), eCount(0), fCount(0) {
    setCourseName(name);
}

void GradeBook::setCourseName(string name) {
    if (name.size() <= 25)
        courseName = name;
    else {
        courseName = name.substr(0, 25);
        cerr << "Name \"" << name
             << "\" exceeds maximum length (25).\n"
                "Limiting courseName to first 25 characters.\n"
             << endl;
    }
}

string GradeBook::getCourseName() const { return courseName; }

void GradeBook::displayMessage() const {
    cout << "Welcome to the grade book for\n"
         << getCourseName() << "!\n"
         << endl;
}

// input arbitrary number of grades from user; update grade counter
void GradeBook::inputGrades() {
    int grade;

    cout << "Enter the letter grades." << endl
         << "Enter the EOF character to end input." << endl;

    while ((grade = cin.get()) != EOF) {
        switch (grade) {
        case 'A':
        case 'a':
            ++aCount;
            break;
        case 'B':
        case 'b':
            ++bCount;
            break;
        case 'C':
        case 'c':
            ++cCount;
            break;
        case 'D':
        case 'd':
            ++dCount;
            break;
        case 'E':
        case 'e':
            ++eCount;
            break;
        case 'F':
        case 'f':
            ++fCount;
            break;
        case '\n': // ignore newlines,
        case '\t': // tabs,
        case ' ':  // and spaces in input
            break; // exit switch
        default:   // catch all other characters
            cout << "Incorrect letter grade entered. Enter a new grade."
                 << endl;
            break; // optional; will exit switch anyway
        }
    }
}

// display a report based on the grades entered by user
void GradeBook::displayGradeReport() const {
    cout << "\n\nNumber of students who received each letter grade:"
         << "\nA: " << aCount << "\nB: " << bCount << "\nC: " << cCount
         << "\nD: " << dCount << "\nE: " << eCount << "\nF: " << fCount << endl;
}
