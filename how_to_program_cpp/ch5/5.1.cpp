// Fig. 5.1: fig05_01.cpp
// Counter-controlled repetition.
#include <iostream>
using namespace std;

int main() {
    unsigned counter = 1;

    while (counter <= 10) {
        cout << counter << " ";
        ++counter;
    }

    cout << endl;

    return 0;
}
/* execution result
 * 1 2 3 4 5 6 7 8 9 10
 */
