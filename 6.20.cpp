// Fig. 6.20: fig06_20.cpp
// Passing arguments by value and by reference.
#include <iostream>
using namespace std;

// function prototype
int squareByValue(int);        // value pass
void squareByReference(int &); // reference pass

int main() {
    int x = 2; // value to square using squareByValue
    int z = 4; // value to square using squareByReference

    // demonstrate squareByValue
    cout << "x = " << x << " before squareByValue\n";
    cout << "Value returned by squareByValue: " << squareByValue(x) << endl;
    cout << "x = " << x << " after squareByValue\n" << endl;

    // demonstrate squareByReference
    cout << "z = " << z << " before squareByReference\n";
    squareByReference(z);
    cout << "z = " << z << " after squareByReference\n" << endl;

    return 0;
}

/* squareByValue multiplies number by itself, stores the result in number and
 * returns the new value of number */
int squareByValue(int number) {
    return number *= number; // caller's argument not modified
}

/* squareByReference multiplies numberRef by itself and stores the result in the
 * variable to which numberRef refers in function main */
void squareByReference(int &numberRef) {
    numberRef *= numberRef; // caller's argument modified
}

/* execution result
 * x = 2 before squareByValue
 * Value returned by squareByValue: 4
 * x = 2 after squareByValue
 *
 * z = 4 before squareByReference
 * z = 16 after squareByReference
 */
