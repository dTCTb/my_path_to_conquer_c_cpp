// Fig. 7.24: 7.24_main.cpp
// Creates GradeBook object using a two-dimensional array of grades
#include "7.22_GradeBook.h"
#include <array>
using namespace std;

int main() {
    GradeBook::gradeTable grades = {
        {{87, 96, 70},
         {68, 87, 90},
         {94, 100, 90},
         {100, 81, 82},
         {83, 65, 85},
         {78, 87, 65},
         {85, 75, 83},
         {91, 94, 100},
         {76, 72, 84},
         {87, 93, 73}}}; // 注意！最外圍嗰個{} 係initializer list，入面先係2-d
    GradeBook myGradeBook("CS101 Introduction to C++ Programming", grades);
    myGradeBook.displayMessage();
    myGradeBook.processGrades();
}
/* execution result
 * Welcome to the grade book for
 * CS101 Introduction to C++ Programming!
 *
 * The Grades are:
 *
 *             Test 1  Test 2  Test 3  Average
 * Student  1      87      96      70    84.33
 * Student  2      68      87      90    81.67
 * Student  3      94     100      90    94.67
 * Student  4     100      81      82    87.67
 * Student  5      83      65      85    77.67
 * Student  6      78      87      65    76.67
 * Student  7      85      75      83    81.00
 * Student  8      91      94     100    95.00
 * Student  9      76      72      84    77.33
 * Student 10      87      93      73    84.33
 *
 * Lowest grade in the grade book is 65
 * Highest grade in the grade book is 100
 *
 * Overall Grade Distribution:
 *   0-9:
 * 10-19:
 * 20-29:
 * 30-39:
 * 40-49:
 * 50-59:
 * 60-69: ***
 * 70-79: ******
 * 80-89: ***********
 * 90-99: *******
 *   100: ***
 */
