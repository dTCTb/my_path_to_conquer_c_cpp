// Fig. 7.17: fig07_17.cpp
// Greates GradeBook object using an array of grades.
#include "7.15_GradeBook.h"
#include <array>
using namespace std;

int main() {
    const array<int, GradeBook::students> grades{87, 68, 94, 100, 83,
                                                 78, 85, 91, 76,  87};
    string courseName = "CS101 Introduction to C++ Programming";

    GradeBook myGradeBook{courseName, grades};
    myGradeBook.displayMessage();
    myGradeBook.processGrades();
    return 0;
}
/* execution result
 * Welcome to the grade book for
 * CS101 Introduction to C++ Programming!
 *
 * The Grades are:
 *
 * Student  1:  87
 * Student  2:  68
 * Student  3:  94
 * Student  4: 100
 * Student  5:  83
 * Student  6:  78
 * Student  7:  85
 * Student  8:  91
 * Student  9:  76
 * Student 10:  87
 *
 * Class average is 84.90
 * Lowest grade is 68
 * Highest grade is 100
 *
 * Grade Distribution:
 *   0-9:
 * 10-19:
 * 20-29:
 * 30-39:
 * 40-49:
 * 50-59:
 * 60-69: *
 * 70-79: **
 * 80-89: ****
 * 90-99: **
 *   100: *
 */
