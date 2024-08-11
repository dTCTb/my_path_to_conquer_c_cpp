// Fig. 13.21: fig13_21.cpp
// flags member function
#include <iostream>
using namespace std;

int main() {
    int integerValue = 1000;
    double doubleValue = 0.0947628;

    cout << "The value of the flags variable is: " << cout.flags()
         << "\nPrint int and double in original format:\n"
         << integerValue << '\t' << doubleValue << "\n\n";

    ios_base::fmtflags originalFormat = cout.flags();
    cout << showbase << oct << scientific;

    cout << "The value of the flags variable is: " << cout.flags()
         << "\nPrint int and double in a new format:\n"
         << integerValue << '\t' << doubleValue << "\n\n";

    cout.flags(originalFormat);

    cout << "The restored value of the flags variable is: " << cout.flags()
         << "\nPrint values in original format again:\n"
         << integerValue << '\t' << doubleValue << endl;
}
/* execution result
 * The value of the flags variable is: 40981000    0.0947628
 *
 * The value of the flags variable is: 011500
 * Print int and double in a new format:
 * 01750   9.476280e-02
 *
 * The restored value of the flags variable is: 4098
 * Print values in original format again:
 * 1000    0.0947628
 */
