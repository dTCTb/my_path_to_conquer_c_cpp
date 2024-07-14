// Fig. 6.14: fig06_14.cpp
// square function used to demonstrate the function
// call stack and activation records.
#include <iostream>
using namespace std;

int square(int); // prototype for function square

int main() {
    int a = 10; // value to square (local automatic variable in main)
    cout << a << " squared: " << square(a) << endl; // display a squared
    return 0;
}

// returns the square of an integer
int square(int x) { return x * x; }

/* execution result
 * 10 squared: 100
 */
