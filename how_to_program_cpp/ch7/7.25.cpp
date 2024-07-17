// Fig. 7.25: fig07_25.cpp
// Demostrating C++ Standard Library class template vector.
// #include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

void outputVector(const vector<int> &);
void inputVector(vector<int> *); // 書係用reference &，但我想試下pointer *
                                 // 證實係語法唔同，但做嘅嘢一樣。語法糖。
int main() {
    vector<int> integers1(7);
    vector<int> integers2(10);

    cout << "Size of vector integers1 is " << integers1.size()
         << "\nvector after initialization: " << endl;
    outputVector(integers1);

    cout << "Size of vector integers2 is " << integers2.size()
         << "\nvector after initialization: " << endl;
    outputVector(integers2); // passing the reference of vector object

    cout << "\nEnter 17 integers:" << endl;
    inputVector(&integers1); // passing the address of vector object
    inputVector(&integers2);

    cout << "\nAfter input, the vectors contain:\nintegers1:" << endl;
    outputVector(integers1);
    cout << "integers2:" << endl;
    outputVector(integers2);

    // use inequality (!=) operator with vector objects
    cout << "\nEvaluating: integers1 != integers2" << endl;

    if (integers1 != integers2)
        cout << "integers1 and integers2 are not equal" << endl;

    vector<int> integers3(integers1);

    cout << "\nSize of vector integers3 is " << integers3.size()
         << "\nvector after initialization:" << endl;
    outputVector(integers3);

    cout << "\nAssigning integers2 to integers1:" << endl;
    integers1 = integers2;

    cout << "integers1:" << endl;
    outputVector(integers1);
    cout << "integers2:" << endl;
    outputVector(integers2);

    cout << "\nEvaluating: integers1 == integers2" << endl;

    if (integers1 == integers2)
        cout << "integers1 and integers2 are equal" << endl;

    cout << "\nintegers1[5] is " << integers1[5];

    cout << "\n\nAssigning 1000 to integers1[5]" << endl;
    integers1[5] = 1000;
    cout << "integers1:" << endl;
    outputVector(integers1);

    try {
        cout << "\nAttempt to display integers1.at(15)" << endl;
        cout << integers1.at(15) << endl;
    } catch (out_of_range &ex) {
        cerr << "An exception occured: " << ex.what() << endl;
    }

    cout << "\nCurrent integers3 size is: " << integers3.size() << endl;
    integers3.push_back(1000);
    cout << "New integers3 size is: " << integers3.size() << endl;
    cout << "integers3 now contains: ";
    outputVector(integers3);
}

void outputVector(const vector<int> &array) {
    for (int item : array)
        cout << item << " ";
    cout.put('\n');
}

void inputVector(vector<int> *array) {
    for (int &item : *array)
        cin >> item;
}
/* execution result
 * Size of vector integers1 is 7
 * vector after initialization:
 * 0 0 0 0 0 0 0
 * Size of vector integers2 is 10
 * vector after initialization:
 * 0 0 0 0 0 0 0 0 0 0
 *
 * Enter 17 integers:
 * 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17<Enter>
 *
 * After input, the vectors contain:
 * integers1:
 * 1 2 3 4 5 6 7
 * integers2:
 * 8 9 10 11 12 13 14 15 16 17
 *
 * Evaluating: integers1 != integers2
 * integers1 and integers2 are not equal
 *
 * Size of vector integers3 is 7
 * vector after initialization:
 * 1 2 3 4 5 6 7
 *
 * Assigning integers2 to integers1:
 * integers1:
 * 8 9 10 11 12 13 14 15 16 17
 * integers2:
 * 8 9 10 11 12 13 14 15 16 17
 *
 * Evaluating: integers1 == integers2
 * integers1 and integers2 are equal
 *
 * integers1[5] is 13
 *
 * Assigning 1000 to integers1[5]
 * integers1:
 * 8 9 10 11 12 1000 14 15 16 17
 *
 * Attempt to display integers1.at(15)
 * An exception occured: vector
 *
 * Current integers3 size is: 7
 * New integers3 size is: 8
 * integers3 now contains: 1 2 3 4 5 6 7 1000
 */
