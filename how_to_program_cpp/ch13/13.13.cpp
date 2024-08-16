// Fig. 13.13: fig13_13.cpp
// Controlling the printing of trailing zeros and
// decimal points in floating-point values
#include <iostream>
using namespace std;

int main() {
    cout << "Before using showpoint" << endl;
    cout << "9.9900 prints as: " << 9.9900 << endl;
    cout << "9.9000 prints as: " << 9.9000 << endl;
    cout << "9.0000 prints as: " << 9.0000 << endl;

    cout << "\nAfter using showpoint" << endl << showpoint;
    cout << "9.9900 prints as: " << 9.9900 << endl;
    cout << "9.9000 prints as: " << 9.9000 << endl;
    cout << "9.0000 prints as: " << 9.0000 << endl;
}
/* execution result
 * Before using showpoint
 * 9.9900 prints as: 9.99
 * 9.9000 prints as: 9.9
 * 9.0000 prints as: 9
 *
 * After using showpoint
 * 9.9900 prints as: 9.99000
 * 9.9000 prints as: 9.90000
 * 9.0000 prints as: 9.00000
 */
