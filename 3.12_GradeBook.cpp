// Fig 3.12: 3.12_GradeBook.cpp
// GradeBook member-function definitions. This file contains
// implementations of the member functions prototyped in 3.11_GradeBook.h.
#include "3.11_GradeBook.h" // include definition of class GradeBook
#include <iostream>
using namespace std;

// constructor initializes courseName with string supplied as argument
GradeBook::GradeBook(string name)
    : courseName(name) // member initializer to initialize courseName
{
    // empty body
}

void GradeBook::setCourseName(string name) {
    courseName = name; // store the course name in the object
}

string GradeBook::getCourseName() const {
    return courseName; // return object's courseName
}

void GradeBook::displayMessage() const {
    // call getCourseName to get the courseName
    cout << "Welcome to the grade book for\n" << getCourseName() << "!" << endl;
}
