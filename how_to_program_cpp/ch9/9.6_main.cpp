// Fig. 9.6: 9.6_main.cpp
// Constructor with default arguments
#include "9.4_Time.h"
#include <iostream>
#include <stdexcept>
using namespace std;

void print(string s, Time &t);

int main() {
    Time t1;
    Time t2(2);
    Time t3(21, 34);
    Time t4(12, 25, 42);

    print("Constructed with:\n\nt1: all arguments defaulted", t1);
    print("\n\nt2: hour specified; minute and second defaulted", t2);
    print("\n\nt3: hour and minute specified; second defaulted", t3);
    print("\n\nt4: hour, minute and second specified", t4);

    try {
        Time t5(27, 74, 99);
    } catch (invalid_argument &e) {
        cerr << "\n\nException while initializing t5: " << e.what() << endl;
    }
    return 0;
}

void print(string s, Time &t) {
    cout << s << endl;
    t.printUniversal();
    cout << endl;
    t.printStandard();
}
/* execution result
 * Constructed with:
 *
 * t1: all arguments defaulted
 * 00:00:0
 * 12:00:00 AM
 *
 * t2: hour specified; minute and second defaulted
 * 02:00:0
 * 2:00:00 AM
 *
 * t3: hour and minute specified; second defaulted
 * 21:34:0
 * 9:34:00 PM
 *
 * t4: hour, minute and second specified
 * 12:25:42
 * 12:25:42 PM
 *
 * Exception while initializing t5: hour must be 0-23
 */
