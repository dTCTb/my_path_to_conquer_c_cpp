// Fig. 9.3 : 9.3_main.cpp
// Program to test class Time
// NOTE: This file must be compiled with 9.2_Time.cpp
#include "9.1_Time.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    Time t;

    cout << "The initial universal time is ";
    t.printUniversal();
    cout << "\nThe initial standard time is ";
    t.printStandard();

    t.setTime(13, 27, 6);

    cout << "\n\nUniversal time after setTime is ";
    t.printUniversal();
    cout << "\nStandard time after setTime is ";
    t.printStandard();

    try {
        t.setTime(99, 99, 99);
    } catch (invalid_argument &e) {
        cout << "\n\nException: " << e.what() << endl;
    }

    cout << "\nAfter attempting invalid settings:"
         << "\nUniversal time: ";
    t.printUniversal();
    cout << "\nStandard time: ";
    t.printStandard();
    cout << endl;
    return 0;
}
/* execution result
 * The initial universal time is 00:00:00
 * The initial standard time is 12:00:00 AM
 *
 * Universal time after setTime is 13:27:06
 * Standard time after setTime is 1:27:06 PM
 *
 * Exception: hour, minute and/or second was out of range
 *
 * After attempting invalid settings:
 * Universal time: 13:27:06
 * Standard time: 1:27:06 PM
 */
