// Fig. 6.18: fig06_18.cpp
// Functions that take no arguments.
#include <iostream>
using namespace std;

// two functions that takes no arguments
void function1();
void function2(void);

int main() {
    // call function1, function2 with no arguments
    function1();
    function2();
    return 0;
}

/* function1 uses an empty parameter list to specify that the function receives
 * no arguments */
void function1() { cout << "function1 takes no arguments" << endl; }

/* function2 uses a void parameter list to specify that the function receives no
 * arguments */
void function2(void) { cout << "function2 also takes no arguments" << endl; }

/* execution result
 * function1 takes no arguments
 * function2 also takes no arguments
 */
