// Fig. 5.11: fig05_11.cpp
// Creating a GradeBook object and calling its member function.
#include "5.9_GradeBook.h" // include definition of class GradeBook

int main() {
    GradeBook myGradeBook("CS101 C++ Programming");

    myGradeBook.displayMessage();
    myGradeBook.inputGrades();
    myGradeBook.displayGradeReport();
    return 0;
}
/* execution result
 * Welcome to the grade book for
 * CS101 C++ Programming!
 *
 * Enter the letter grades.
 * Enter the EOF character to end input.
 * a
 * B
 * c
 * C
 * A
 * d
 * f
 * C
 * E
 * Z
 * Incorrect letter grade entered. Enter a new grade.
 * D
 * A
 * b
 * ^D
 *
 * Number of students who received each letter grade:
 * A: 3
 * B: 2
 * C: 3
 * D: 2
 * E: 1
 * F: 1
 */
