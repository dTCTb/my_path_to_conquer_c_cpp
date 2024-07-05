// Fig. 4.9: 4.9_GradeBook.cpp
// Member-function definitions for class GradeBook that solves the
// class average program with counter-controlled repetition.
#include "4.8_GradeBook.h" // include definition of class GradeBook
#include <iostream>

using namespace std;

GradeBook::GradeBook(string name) { setCourseName(name); }

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

// determine class average based on 10 grades entered by user
void GradeBook::determineClassAverage() const {
    // initialization phase
    int total = 0;                 // sum of grades entered by user
    unsigned int gradeCounter = 1; // number of grade to be enterd next

    // processing phase
    while (gradeCounter <= 10) {         // loop 10 times
        cout << "Enter grade: ";         // prompt for input
        int grade = 0;                   // grade value entered by user
        cin >> grade;                    // input next grade
        total = total + grade;           // add grade to total
        gradeCounter = gradeCounter + 1; // increment counter by 1
    }

    // termination phase
    int average = total / 10; // ok to mix declaration and calculation

    // display total and average of grades
    cout << "\nTotal of all 10 grades is " << total << endl;
    cout << "Class average is " << average << endl;
}
