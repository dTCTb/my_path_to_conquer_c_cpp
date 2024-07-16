// Fig. 7.9: fig07_09.cpp
// Bar chart printing program.
#include <array>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    const size_t arraySize = 11;
    array<unsigned, arraySize> n = {0, 0, 0, 0, 0, 0, 1, 2, 4, 2, 1};

    cout << "Grade Distribution: " << endl;

    // for each element of array n, output a bar of the chart
    for (size_t i = 0; i < n.size(); ++i) {
        // output bar labels ("  0-  9: ", ... , " 90- 99: ", "    100: ")
        if (0 == i)
            cout << setw(3) << "0" << '-' << setw(3) << "9"
                 << ": ";
        else if (10 == i)
            cout << setw(7) << "100"
                 << ": ";
        else
            cout << setw(3) << i * 10 << '-' << setw(3) << ((i + 1) * 10) - 1
                 << ": ";

        // print bar of asterisks
        for (unsigned stars = 0; stars < n[i]; stars++)
            cout.put('*');
        cout.put('\n'); // start a new line of output
    }                   // end outer for
    return 0;
}
/* execution result
 * Grade Distribution:
 *   0-  9:
 *  10- 19:
 *  20- 29:
 *  30- 39:
 *  40- 49:
 *  50- 59:
 *  60- 69: *
 *  70- 79: **
 *  80- 89: ****
 *  90- 99: **
 *     100: *
 */
