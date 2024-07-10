// Fig. 5.13: fig05_13.cpp
// break statement exiting a for statement.
#include <iostream>
using namespace std;

int main() {
    unsigned count;

    for (count = 1; count <= 10; ++count) {
        if (count == 5)
            break; // break loop only if count is 5
        cout << count << " ";
    }
    cout << "\nBroke out of loop at count = " << count << endl;
    return 0;
}
/* execution result
 * 1 2 3 4
 * Broke out of loop at count = 5
 */
