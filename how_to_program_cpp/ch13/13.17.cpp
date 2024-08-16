// Fig. 13.17: fig13_17.cpp
// Stream manipulator showbase
#include <iostream>
using namespace std;

int main() {
    int x = 100;
    cout << "Printing integers preceded by their base:" << endl << showbase;
    cout << x << endl;
    cout << oct << x << endl;
    cout << hex << x << endl;
}
/* execution result
 * Printing integers preceded by their base:
 * 100
 * 0144
 * 0x64
 */
