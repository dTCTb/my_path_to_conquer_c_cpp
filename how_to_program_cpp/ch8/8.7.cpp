// Fig. 8.7: fig08_07.cpp
// Pass-by-reference with a pointer argument used to cube a variable's value
#include <iostream>
using namespace std;

void cubeByReference(int *); // prototype

int main() {
    int number = 5;
    cout << "The original value of number is " << number;
    cubeByReference(&number); // pass number address to cubeByReference
    cout << "\nThe new value of number is " << number << endl;
    return 0;
}

// calculate cube of *nPtr; modifies variable number in main
void cubeByReference(int *nPtr) {
    *nPtr = *nPtr * *nPtr * *nPtr; // cube *nPtr
}

/* execution result
 * The original value of number is 5
 * The new value of number is 125
 */
