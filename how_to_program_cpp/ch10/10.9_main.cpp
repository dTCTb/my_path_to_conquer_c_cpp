// Fig. 10.9: 10.9_main.cpp
// Array class test program
#define NATURAL
#include "../../termcolor.h"
#include "10.10_Array.h"
#include <iostream>
#include <stdexcept>
using namespace std;

void book();

int main() {
    book();
    return 0;
}

void book() {
    Array integers1(7);
    Array integers2;

    cout << "Size of Array " YEL("integers1") " is " << integers1.getSize()
         << "\nArray after initialization:\n"
         << integers1;

    cout << "Size of Array " PUR("integers2") " is " << integers2.getSize()
         << "\nArray after initialization:\n"
         << integers2;

    cout << "\nEnter 17 integers: " << endl << BLUC;
    cin >> integers1 >> integers2;
    cout << RESET;

    cout << "\nAfter input, the Arrays contain:\n"
         << YEL("integers1") ":\n"
         << integers1 << PUR("integers2") ":\n"
         << integers2;

    cout << "\nEvaluating: " YEL("integers1") " != " PUR("integers2") << endl;

    if (integers1 != integers2)
        cout << YEL("integers1") " and " PUR("integers2") " are not equal"
             << endl;

    Array integers3(integers1); // invokes copy constructor

    cout << "\nSize of Array " AQU("integers3") " is " << integers3.getSize()
         << "\nArray after initialization:\n"
         << integers3;

    cout << "\nAssigning " PUR("integers2") " to " YEL("integers1") ":" << endl;
    integers1 = integers2; // note that target Array is smaller

    cout << YEL("integers1") ":\n"
         << integers1 << PUR("integers2") ":\n"
         << integers2;

    cout << "\nEvaluating " YEL("integers1") " == " PUR("integers2") << endl;

    if (integers1 == integers2)
        cout << YEL("integers1") " and " PUR("integers2") " are equal" << endl;

    cout << YEL("\nintegers1") "[5] is " << integers1[5];

    cout << "\n\nAssigning 1000 to " YEL("integers1") "[5]" << endl;
    integers1[5] = 1000;
    cout << YEL("integers1") ":\n" << integers1;

    try {
        cout << "\nAttempt to assign 1000 to " YEL("integers1") "[15]" << endl;
        integers1[15] = 1000;
    } catch (out_of_range &ex) {
        cout << BREDC "An exception occurred: " << ex.what() << RESET << endl;
    }
}
