// Fig. 4.10: fig04_10.cpp
// Create GradeBook object and invoke its determineClassAverage function.
#include "4.8_GradeBook.h" // include definition of class GradeBook

int main() {
    // create GradeBook object myGradeBook and
    // pass course name to constructor
    GradeBook myGradeBook("CS101 C++ Programming");

    myGradeBook.displayMessage();        // display welcome message
    myGradeBook.determineClassAverage(); // find average of 10 grades

    return 0;
}
/* execution result
 * Welcome to the grade book for
 * CS101 C++ Programming!
 *
 * Enter grade: 67
 * Enter grade: 78
 * Enter grade: 89
 * Enter grade: 67
 * Enter grade: 87
 * Enter grade: 98
 * Enter grade: 93
 * Enter grade: 85
 * Enter grade: 82
 * Enter grade: 100
 *
 * Total of all 10 grades is 846
 * Class average is 84
 */
