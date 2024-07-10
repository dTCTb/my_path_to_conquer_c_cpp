// Fig. 5.7: fig05_07.cpp
// do...while repetition statement.
#include <iostream>
using namespace std;

int main() {
    unsigned counter = 1;

    do {
        cout << counter << " ";
        ++counter;
    } while (counter <= 10);

    cout << endl;
    return 0;
}
/* execution result
 * 1 2 3 4 5 6 7 8 9 10
 */
