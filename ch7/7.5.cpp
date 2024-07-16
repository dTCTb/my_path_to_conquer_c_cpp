// Fig. 7.5: fig07_5.cpp
// Set array s to the even integers from 2 to 10.
#include <array>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    // constant variable can be used to specify array size
    const size_t arraySize = 5; // must initialize in declaration
    array<int, arraySize> s;    // array s has 5 elements

    for (size_t i = 0; i < s.size(); ++i)
        s[i] = i * 2 + 2;

    cout << "Element" << setw(13) << "Value" << endl;

    // output contents of array s in tabular format
    for (size_t j = 0; j < s.size(); ++j)
        cout << setw(7) << j << setw(13) << s[j] << endl;
    return 0;
}
/* execution result
 * Element        Value
 *       0            2
 *       1            4
 *       2            6
 *       3            8
 *       4           10
 */
