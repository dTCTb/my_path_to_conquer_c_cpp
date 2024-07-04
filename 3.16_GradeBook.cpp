// clang-format off
// Fig. 3.16: 3.16_GradeBook.cpp
// Implementations of the GradeBook member-function definitions.
// The setCourseName functino performs validation.
#include "3.15_GradeBook.h" // include definition of class GradeBook
#include <iostream>
using namespace std;

GradeBook::GradeBook(string gradeBook, string name) : gradeBookName(gradeBook) {
    setCourseName(name);
    initCourseName(gradeBook);
}

void GradeBook::initCourseName(string gradeBook) const {
    cout << gradeBook << "'s initial course name is: " << getCourseName()
         << endl;
}

// function that sets the course name;
// ensure that the course name has at most 25 characters
void GradeBook::setCourseName(string name) {
    if (name.size() <= 25)  // if name has 25 or fewer characters
        courseName = name;  // store the course name in the object
    if (name.size() > 25) { // if name has more than 25 characters
        // set courseName to first 25 characters of parameter name
        courseName = name.substr(0, 25); // start at 0, length of 25
        cerr << "Name \"" << name << "\" exceeds maximum length (25).\n"
                "Limiting courseName to first 25 characters.\n" << endl;
    }
}

string GradeBook::getCourseName() const { return courseName; }

void GradeBook::displayMessage() const {
    cout << "Welcome to the grade book for\n" << getCourseName() << "!" << endl;
}
