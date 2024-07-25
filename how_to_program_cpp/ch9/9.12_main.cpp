// Fig. 9.12: 9.12_main.cpp
// Demonstrating a public member function that returns a reference to a private
// data member
#include "9.10_Time.h"
#include <iostream>
using namespace std;

void usingRef() {
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

void usingPtr() {
    Time t;

    unsigned *hourPtr = t.badbad(20);

    cout << "Valid hour before modification: " << *hourPtr;
    *hourPtr = 30;
    cout << "\nInvalid hour after modification: " << t.getHour();

    *(t.badbad(12)) = 74;

    cout << "\n\n***********************************************\n"
         << "POOR PROGRAMMING PRACTICE!!!!!!!\n"
         << "t.badbad(12) as an lvalue, invalid hour: " << t.getHour()
         << "\n***********************************************" << endl;
}

int main() {
    cout << "using Reference to demonstrating:" << endl;
    usingRef();
    cout << "- -- - -- - -- - -- - -- - -- - -- - -- - -- - -- " << endl;
    cout << "using Pointer to demonstrating:" << endl;
    usingPtr();
    return 0;
}
/* execution result
 * Valid hour before modification: 20
 * Invalid hour after modification: 30
 *
 * ***********************************************
 * POOR PROGRAMMING PRACTICE!!!!!!!
 * t.badSetHour(12) as an lvalue, invalid hour: 74
 * ***********************************************
 * - -- - -- - -- - -- - -- - -- - -- - -- - -- - --
 * Valid hour before modification: 20
 * Invalid hour after modification: 30
 *
 * ***********************************************
 * POOR PROGRAMMING PRACTICE!!!!!!!
 * t.badbad(12) as an lvalue, invalid hour: 74
 * ***********************************************
 */
