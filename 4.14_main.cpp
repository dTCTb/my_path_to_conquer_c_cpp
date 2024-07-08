// Fig. 4.14: fig04_14.cpp
// Create GradeBook object and invoke its determineClassAverage function.
#include "4.12_GradeBook.h"
#include <cstdlib>

int main(int argc, char **argv) {
    int max = argc == 2 ? atoi(argv[1]) : 10;
    GradeBook myGradeBook("CS101 C++ Programming", max);

    myGradeBook.displayMessage();
    myGradeBook.determineClassAverage();

    return 0;
}
/* execution result
 * Welcome to the grade book for
 * CS101 C++ Programming!
 *
 * Enter grade or -1 to quit: 97
 * Enter grade or -1 to quit: 88
 * Enter grade or -1 to quit: 72
 * Enter grade or -1 to quit: -1
 *
 * Total of all 3 grades entered is 257
 * Class average is 85.67
 */
