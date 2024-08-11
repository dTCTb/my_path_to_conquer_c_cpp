// Fig. 13.20: fig13_20.cpp
// Stream manipulators boolalpha and noboolalpha
#include <iostream>
using namespace std;

int main() {
    bool booleanValue = true;

    cout << "booleanValue is " << booleanValue << endl;

    cout << "booleanValue (after using boolalpha) is " << boolalpha
         << booleanValue << endl
         << endl;

    cout << "switch booleanValue and use noboolalpha" << endl;
    booleanValue = false;
    cout << noboolalpha << endl;

    cout << "booleanValue is " << booleanValue << endl;

    cout << "booleanValue (after using boolalpha) is " << boolalpha
         << booleanValue << endl;
}
/* execution result
 * booleanValue is 1
 * booleanValue (after using boolalpha) is true
 *
 * switch booleanValue and use noboolalpha
 *
 * booleanValue is 0
 * booleanValue (after using boolalpha) is false
 */
