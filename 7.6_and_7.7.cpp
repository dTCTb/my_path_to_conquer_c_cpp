// This program cannot compile correctly
#include <iostream>
using namespace std;

// Fig. 7.6: fin07_06.cpp
// Using  a properly initialized constant variable.
void fig07_06() {
    const int x = 7;
    cout << "The value of constant variable x is: " << x << endl;
}

// Fig. 7.7: fig07_07.cpp
// A const variable must be initialized.
void fig07_07() {
    const int x; // Error: x must be initialized
    x = 7;       // Error: cannot modify a const variable
}

int main() {
    fig07_06();
    // fig07_07();
    return 0;
}
// clang-format off
/* compilation log
* 7.6_and_7.7.cpp:14:15: error: default initialization of an object of const type 'const int'
*    14 |     const int x; // Error: x must be initialized
*       |               ^
*       |                 = 0
* 7.6_and_7.7.cpp:15:7: error: cannot assign to variable 'x' with const-qualified type 'const int'
*    15 |     x = 7;       // Error: cannot modify a const variable
*       |     ~ ^
* 7.6_and_7.7.cpp:14:15: note: variable 'x' declared const here
*    14 |     const int x; // Error: x must be initialized
*       |     ~~~~~~~~~~^
* 2 errors generated.
*/
