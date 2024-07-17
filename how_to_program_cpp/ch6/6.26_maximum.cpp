// Fig. 6.26: fig06_26.cpp
// Function template maximum test program.
#include "6.25_maximum.h"
#include <iostream>
using namespace std;

int main() {
    int int1, int2, int3;
    cout << "Input three integer value is: ";
    cin >> int1 >> int2 >> int3;
    cout << "The maximum integer value is: " << maximum(int1, int2, int3);

    double double1, double2, double3;
    cout << "\n\nInput three double value is: ";
    cin >> double1 >> double2 >> double3;
    cout << "The maximum double value is: "
         << maximum(double1, double2, double3);

    char char1, char2, char3;
    cout << "\n\nInput three characters: ";
    cin >> char1 >> char2 >> char3;
    cout << "The maximum character value is: " << maximum(char1, char2, char3)
         << endl;

    return 0;
}
/* execution result
 * Input three integer value is: 1 2 3
 * The maximum integer value is: 3
 *
 * Input three double value is: 3.3 2.2 1.1
 * The maximum double value is: 3.3
 *
 * Input three characters: A C B
 * The maximum character value is: C
 */
