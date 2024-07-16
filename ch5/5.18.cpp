// Fig. 5.18: fig05_18.cpp
// Logical operators.
#include <iostream>
using namespace std;

int main() {
    // create truth table for && (logical AND) operator
    cout << boolalpha << "Logical AND (&&)"
         << "\nfalse && false: " << (false && false)
         << "\nfalse && true: " << (false && true)
         << "\ntrue && false: " << (true && false)
         << "\ntrue && true: " << (true && true) << "\n\n";

    // create truth table for || (logical OR) operator
    cout << "Logical OR (&&)"
         << "\nfalse || false: " << (false || false)
         << "\nfalse || true: " << (false || true)
         << "\ntrue || false: " << (true || false)
         << "\ntrue || true: " << (true || true) << "\n\n";

    cout << "Logical NOT (!)"
         << "\n!false: " << (!false) << "\n!true: " << (!true) << endl;

    return 0;
}
/* execution result
 * Logical AND (&&)
 * false && false: false
 * false && true: false
 * true && false: false
 * true && true: true
 *
 * Logical OR (&&)
 * false || false: false
 * false || true: true
 * true || false: true
 * true || true: true
 *
 * Logical NOT (!)
 * !false: true
 * !true: false
 */
