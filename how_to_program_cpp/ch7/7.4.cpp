// Fig. 7.4: fig07_04.cpp
// Initializing an array in a declaration.
#include <array>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    // use list initializer to initialize array n
    array<int, 5> n = {32, 27, 64, 18, 95};

    cout << "Element" << setw(13) << "Value" << endl;

    // output each array element's value
    for (size_t i = 0; i < 5; ++i)
        cout << setw(7) << i << setw(13) << n[i] << endl;
    return 0;
}
/* execution result
 * Element        Value
 *       0           32
 *       1           27
 *       2           64
 *       3           18
 *       4           95
 */
