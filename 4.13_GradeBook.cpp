// Fig. 4.13: GradeBook.cpp
// Member-function definitions for class GradeBook that solves the
// class average program with sentinel-controlled repetition.
#include "4.12_GradeBook.h"
#include <iomanip> // parameterized stream manipulators
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

void GradeBook::determineClassAverage() const {
    // initialization phase
    int total = 0;                 // sum of grades entered by user
    unsigned int gradeCounter = 0; // number of grades entered

    // processing phase
    // prompt for input and read grade from user
    cout << "Enter grade or -1 to quit: ";
    int grade = 0; // grade value
    cin >> grade;  // nput grade or sentinel value

    while (grade != -1) {
        total += grade; // add grade to total
        gradeCounter++; // increment counter

        // prompt for input and read next grade from user
        cout << "Enter grade or -1 to quit: ";
        cin >> grade; // input grade or sentinel value
    }

    if (gradeCounter != 0) { // if user enterd at least one grade...
        // calculate average of all grades entered
        double average = static_cast<double>(total) / gradeCounter;

        // display total and average (with two digits of precision)
        cout << "\nTotal of all " << gradeCounter << " grades entered is "
             << total << endl;
        cout << setprecision(2) << fixed;
        cout << "Class average is " << average << endl;
    } else { // no grades were entered, so output appropriate message
        cout << "No grades were entered" << endl;
    }
}
