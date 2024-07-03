// Fig. 3.10: fig03_10.cpp
// Including class GradeBook from file 3.9_GradeBook.h for use in main.
#include "3.9_GradeBook.h"
using namespace std;

int main() {
    GradeBook gradeBook1("CS101 Introduction to C++ Programming");
    GradeBook gradeBook2("CS102 Data Structure in C++");
    cout << "gradeBook1 created for course: " << gradeBook1.getCourseName()
         << "\ngradeBook2 created for course: " << gradeBook2.getCourseName()
         << endl;
    return 0;
}
/* execution result
 * gradeBook1 created for course: CS101 Introduction to C++ Programming
 * gradeBook2 created for course: CS102 Data Structure in C++
 */
