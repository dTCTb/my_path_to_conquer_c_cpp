// Fig. 13.9: fig13_09.cpp
// Controlling precision of floating-point values
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    double root2 = sqrt(2.0);
    int places; // precision, vary from 0-9

    cout << "Square root of 2 with precisions 0-9." << endl;
    cout << "Precision set by ios_base member function "
         << "precision:" << endl;

    cout << fixed;

    for (places = 0; places <= 9; ++places) {
        cout.precision(places);
        cout << root2 << endl;
    }

    cout << "\nPrecision set be stream manipulator " << "setprecision:" << endl;

    for (places = 0; places <= 9; ++places)
        cout << setprecision(places) << root2 << endl;

    return 0;
}
/* execution result
 * Square root of 2 with precisions 0-9.
 * Precision set by ios_base member function precision:
 * 1
 * 1.4
 * 1.41
 * 1.414
 * 1.4142
 * 1.41421
 * 1.414214
 * 1.4142136
 * 1.41421356
 * 1.414213562
 *
 * Precision set be stream manipulator setprecision:
 * 1
 * 1.4
 * 1.41
 * 1.414
 * 1.4142
 * 1.41421
 * 1.414214
 * 1.4142136
 * 1.41421356
 * 1.414213562
 */
