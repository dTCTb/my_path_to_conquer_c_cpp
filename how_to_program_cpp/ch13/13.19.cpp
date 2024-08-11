// Fig. 13.19: fig13_19.cpp
// Stream manipulator uppercase
#include <iostream>
using namespace std;

int main() {
    cout << "Printing uppercase letters in scientific" << endl
         << "notation exponents and hexadecimal values:" << endl;

    cout << uppercase << 4.345e10 << endl;
    cout << hex << showbase << 123456789 << endl;
}
/* execution result
 * Printing uppercase letters in scientific
 * notation exponents and hexadecimal values:
 * 4.345E+10
 * 0X75BCD15
 */
