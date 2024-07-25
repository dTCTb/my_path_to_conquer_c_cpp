// Fig. 9.12: 9.12_main.cpp
// Demonstrating a public member function that returns a reference to a private
// data member
#include "9.10_Time.h"
#include <iostream>
using namespace std;

int main() {
    Time t;

    unsigned &hourRef = t.badSetHour(20);

    cout << "Valid hour before modification: " << hourRef;
    hourRef = 30; // use hourRef to set invalid value in Time object t
    cout << "\nInvalid hour after modification: " << t.getHour();

    // Dangerous: Function call that returns
    // a reference can be used as an lvalue!
    t.badSetHour(12) = 74; // assign another invalid value to hour

    cout << "\n\n***********************************************\n"
         << "POOR PROGRAMMING PRACTICE!!!!!!!\n"
         << "t.badSetHour(12) as an lvalue, invalid hour: " << t.getHour()
         << "\n***********************************************" << endl;
}
/* execution result
 * Valid hour before modification: 20
 * Invalid hour after modification: 30
 *
 * ***********************************************
 * POOR PROGRAMMING PRACTICE!!!!!!!
 * t.badSetHour(12) as an lvalue, invalid hour: 74
 * ***********************************************
 */
