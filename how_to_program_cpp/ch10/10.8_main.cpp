// Fig. 10.8: 10.8_main.cpp
// Date class test program
#include "10.6_Date.h"
#include <iostream>
using namespace std;

int main() {
    Date d1(12, 27, 2010);
    Date d2;

    cout << "d1 is " << d1 << "\nd2 is " << d2;
    cout << "\n\nd1 += 7 is " << (d1 += 7);

    d2.setDate(2, 28, 2008);
    cout << "\n\n  d2 is " << d2;
    cout << "\n++d2 is " << ++d2 << " (leap year allows 29th)";

    Date d3(7, 13, 2010);

    cout << "\n\nTesting the prefix increment operator:\n"
         << "  d3 is " << d3 << endl;
    cout << "++d3 is " << ++d3 << endl;
    cout << "  d3 is " << d3;

    cout << "\n\nTesting the postfile increment operator:\n"
         << "  d3 is " << d3 << endl;
    cout << "d3++ is " << d3++ << endl;
    cout << "  d3 is " << d3 << endl;
    return 0;
}
/* execution result
 * d1 is December 27, 2010
 * d2 is January 1, 1900
 *
 * d1 += 7 is January 3, 2011
 *
 *   d2 is February 28, 2008
 * ++d2 is February 29, 2008 (leap year allows 29th)
 *
 * Testing the prefix increment operator:
 *   d3 is July 13, 2010
 * ++d3 is July 14, 2010
 *   d3 is July 14, 2010
 *
 * Testing the postfile increment operator:
 *   d3 is July 14, 2010
 * d3++ is July 14, 2010
 *   d3 is July 15, 2010
 */
