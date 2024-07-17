// Fig. 5.2: fig05_02.cpp
// Counter-controlled repetition with the for statement.
#include <iostream>
using namespace std;

int main() {
    for (unsigned counter = 1; counter <= 10; ++counter)
        cout << counter << " ";
    cout << endl;
    return 0;
}
/* execution result
 * 1 2 3 4 5 6 7 8 9 10
 */
