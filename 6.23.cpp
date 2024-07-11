// Fig. 6.23: fig06_23.cpp
// Overloaded square functions.
#include <iostream>
using namespace std;

// function square for int values
int square(int x) {
    cout << "square of integer " << x << " is ";
    return x * x;
}

// function square for double values
double square(double y) {
    cout << "square of double " << y << " is ";
    return y * y;
}

int main() {
    cout << square(7) << endl;
    cout << square(7.5) << endl;
    return 0;
}
/* execution result
 * square of integer 7 is 49
 * square of double 7.5 is 56.25
 */
