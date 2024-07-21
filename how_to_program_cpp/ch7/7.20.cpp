// Fig. 7.20: fig07_20.cpp
// Initializing multidimensional arrays.
#include <array>
#include <iostream>
using namespace std;

const size_t rows = 2;
const size_t columns = 3;

using c3 = array<int, columns>;
using r2c3 = array<array<int, columns>, rows>;

typedef int oldC[rows][columns];

#define prompt(x) ("Values in array" #x " by row are:")
void printArray(const r2c3 &);
void printArray(const oldC *);
void stupid_printArray(const array<array<int, columns>, rows> &a); // from book
void still_stupid(const r2c3 &);

int main() {
    r2c3 array1 = {1, 2, 3, 4, 5, 6};
    r2c3 array2 = {1, 2, 3, 4, 5};
    oldC array3 = {{1, 2, 3}, {4, 5, 6}};

    cout << prompt(1) << endl;
    printArray(array1);
    still_stupid(array1);

    cout << prompt(2) << endl;
    printArray(array2);

    cout << prompt(3) << endl;
    printArray(&array3);

    return 0;
}

void printArray(const r2c3 &a) {
    for (const c3 &row : a) {
        for (const int &element : row)
            cout << element << ' ';
        cout.put('\n');
    }
}

void printArray(const oldC *a) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            cout << (*a)[i][j] << ' ';
        cout.put('\n');
    }
}

void stupid_printArray(const array<array<int, columns>, rows> &a) {
    for (auto const &row : a) {         // loop through array's rows
        for (auto const &element : row) // loop through columns of current row
            cout << element << ' ';
        cout << endl;
    }
}

void still_stupid(const r2c3 &a) {
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a[i].size(); j++)
            cout << "a[" << i << "][" << j << "] = " << a[i][j] << endl;
}
