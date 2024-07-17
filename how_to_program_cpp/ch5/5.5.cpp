// Fig. 5.5: fig05_05.cpp
// Summing integers with the for statement.
#include <iostream>
using namespace std;

int main() {
    unsigned total = 0;
    for (unsigned number = 2; number <= 20; number += 2)
        total += number;
    cout << "Sum is " << total << endl;
    return 0;
}
/* execution result
 * Sum is 110
 */
