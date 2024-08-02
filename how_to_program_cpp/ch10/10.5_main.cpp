// Fig. 10.5: 10.5_main.cpp
// Demonstrating class PhoneNumber's overloaded stream insertion and stream
// extraction operators
#include "10.3_PhoneNumber.h"
#include <iostream>
using namespace std;

int main() {
    PhoneNumber phone;
    cout << "Enter phone number in the form (123) 456-7890:" << endl;
    cin >> phone;
    cout << "The phone number entered was: ";
    cout << phone << endl;
    return 0;
}
/* execution result
 * Enter phone number in the form (123) 456-7890:
 * (800) 555-1212
 * The phone number entered was: (800) 555-1212
 */
