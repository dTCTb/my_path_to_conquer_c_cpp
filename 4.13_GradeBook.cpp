// Fig. 4.13: GradeBook.cpp
// Member-function definitions for class GradeBook that solves the
// class average program with sentinel-controlled repetition.
#include "4.12_GradeBook.h"
#include <cstdio>
#include <iomanip> // parameterized stream manipulators
#include <iostream>
using namespace std;

GradeBook::GradeBook(string name, int max) : max(max) { setCourseName(name); }

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
    int ret = 0;                   // validate no. of data formated by scanf
    int total = 0;                 // sum of grades entered by user
    unsigned int gradeCounter = 0; // number of grades entered
    int *p = rec;                  // pointer to rec array

    // processing phase
    // prompt for input and read grade from user
    int grade = 0; // grade value
    cout << "Enter grade or -1 to quit: ";
    ret = scanf("%d", &grade); // input grade or sentinel value

    while (grade != -1) {
        if (grade >= 0 && grade <= 100 && ret) {
            total += grade; // add grade to total
            gradeCounter++; // increment counter
            *p++ = grade;
        } else if (grade == 111) { // 111 to list all entered grades
            for (int *p = rec; *p != 0; p++)
                printf("%3d\n", *p);
            cout << "Total: " << total << " (" << gradeCounter << '/' << max
                 << ")" << endl;
        } else {
            // otherwise flush stdin and print the reminder
            fflush(stdin);
            cout << "Please ensure the grade within 0 ~ 100" << endl;
        }

        if (p == rec + max) {
            cout << "reaching the maximum input counts (" << max << ')' << endl;
            break;
        }

        // prompt for input and read next grade from user
        cout << "Enter grade or -1 to quit: ";
        ret = scanf("%d", &grade); // input grade or sentinel value
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
