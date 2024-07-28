// Fig 9.26: 9.26_main.cpp
// Cascading member-function calls with the this pointer.
#include "9.24_Time.h"
#include <iostream>
using namespace std;

int main() {
    Time t;

    t.setHour(18).setMinute(30).setSecond(22);

    cout << "Universal time: ";
    t.printUniversal();

    cout << "\nStandard time: ";
    t.printStandard();

    cout << "\n\nNew standard time: ";

    t.setTime(20, 20, 20).printStandard();
    cout << endl;
    return 0;
}
/* execution result
 * Universal time: 18:30:22
 * Standard time: 6:30:22 PM
 *
 * New standard time: 8:20:20 PM
 */
