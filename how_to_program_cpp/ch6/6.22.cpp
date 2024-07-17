// Fig. 6.22: fig06_22.cpp
// Unary scope resolution operator.
#include <iostream>
using namespace std;

int number = 7; // global variable named number

int main() {
    double number = 10.5; // local variable named number

    // display values of local and global variables
    cout << "Local double value of number = " << number
         << "\nGlobal int value of number = " << ::number << endl;

    return 0;
}
/* execution result
 * Local double value of number = 10.5
 * Global int value of number = 7
 */
