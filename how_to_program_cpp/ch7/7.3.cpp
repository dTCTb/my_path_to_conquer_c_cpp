// Fig. 7.3: fig07_03.cpp
// Initializing an array's elements to zeros and printing the array.
#include <array>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    array<int, 5> n; // n is an array of 5 int values

    // initialize elements of array n to 0
    for (size_t i = 0; i < 5; ++i)
        n[i] = 0; // set element at location i to 0

    cout << "Element" << setw(13) << "Value" << endl;

    // output each array element's value
    for (size_t j = 0; j < 5; ++j)
        cout << setw(7) << j << setw(13) << n[j] << endl;
    return 0;
}
/* execution result
 * Element        Value
 *       0            0
 *       1            0
 *       2            0
 *       3            0
 *       4            0
 */
