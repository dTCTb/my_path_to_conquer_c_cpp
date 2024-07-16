// Fig. 3.13: fig03_13.cpp
// GradeBook class demonstration after separating
// its interface from its implementation.
#include "3.11_GradeBook.h" // include definition of class GradeBook
#include <iostream>
using namespace std;

int main() {
    // create two GradeBook objects
    GradeBook gradeBook1{"CS101 Introduction to C++ Programming"};
    GradeBook gradeBook2{"CS102 Data Structures in C++"};

    // display initial value of courseName for each GradeBook
    cout << "gradeBook1 created for course: " << gradeBook1.getCourseName()
         << "\ngradeBook2 created for course: " << gradeBook2.getCourseName()
         << endl;

    return 0;
}
/* execution result
 * gradeBook1 created for course: CS101 Introduction to C++ Programming
 * gradeBook2 created for course: CS102 Data Structures in C++
 */
