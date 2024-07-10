// Fig. 5.14: fig05_14.cpp
// continue statement terminating an iteration of a for statement.
#include <iostream>
using namespace std;

int main() {
    for (unsigned count = 1; count <= 10; ++count) {
        if (count == 5)
            continue; // skip remaining code in loop
        cout << count << " ";
    }
    cout << "\nUsed continue to skip printing 5" << endl;
    return 0;
}
/* execution result
 * 1 2 3 4 6 7 8 9 10
 * Used continue to skip printing 5
 */
