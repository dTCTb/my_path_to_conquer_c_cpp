// Fig. 13.15: fig13_15.cpp
// Printing an integer with internal spacing and plus sign
#include <array>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    array<int, 5> arr{123, 99, 6314, 3, 11};
    int sum = 0;
    cout << showpos << internal;
    for (int &v : arr) {
        cout << setw(10) << v << endl;
        sum += v;
    }
    cout << setfill('-') << setw(10) << '-' << setfill(' ') << endl;
    cout << noshowpos << setw(10) << sum << endl;
}
/* execution result
 * +      123
 * +       99
 * +     6314
 * +        3
 * +       11
 * ----------
 *       6550
 */
