// Fig. 13.8: fig13_08.cpp
// Using stream manipulators hex, oct, dec and setbase
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int number;

    cout << "Enter a decimal number: ";
    cin >> number;

    cout << number << " in hexadecimal is: " << hex << number << endl;
    cout << dec << number << " in octal is: " << oct << number << endl;

    cout << setbase(10) << number << " in decimal is: " << number << endl;

    return 0;
}
/* execution result
 * Enter a decimal number: 20
 * 20 in hexadecimal is: 14
 * 20 in octal is: 24
 * 20 in decimal is: 20
 */
