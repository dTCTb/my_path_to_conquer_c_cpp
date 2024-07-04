// Fig. 3.17: fig03_17.cpp
// Create and manipulate a GradeBook object; illustrate validation.
#include "3.15_GradeBook.h" // include definition of class GradeBook
#include <iostream>
using namespace std;

int main() {
    // create two GradeBook objects;
    // initial course name of gradeBook1 is too long
    GradeBook gradeBook1("CS101 Introduction to Programming in C++");
    GradeBook gradeBook2("CS102 C++ Data Structures");

    cout << "gradeBook1's initial course name is: "
         << gradeBook1.getCourseName() << "\n"
         << "gradeBook2's initial course name is: "
         << gradeBook2.getCourseName() << endl;

    // modify gradeBook1's courseName (with a valid-length string)
    gradeBook1.setCourseName("CS101 C++ Programming");

    cout << "gradeBook1's course name is: " << gradeBook1.getCourseName()
         << "\n"
         << "gradeBook2's course name is: " << gradeBook2.getCourseName()
         << endl;

    return 0;
}
// clang++ -g -Wall -o 3.17 3.16_GradeBook.cpp 3.17_main.cpp
/* execution result
 * Name "CS101 Introduction to Programming in C++" exceeds maximum length (25).
 * Limiting courseName to first 25 characters.
 *
 * gradeBook1's initial course name is: CS101 Introduction to Pro
 * gradeBook2's initial course name is: CS102 C++ Data Structures
 * gradeBook1's course name is: CS101 C++ Programming
 * gradeBook2's course name is: CS102 C++ Data Structures
 */
