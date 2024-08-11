// Fig. 13.18: fig13_18.cpp
// Floating-point values displayed in system default,
// scientific and fixed formats
#include <iostream>
using namespace std;

int main() {
    double x = 0.001234567;
    double y = 1.946e9;

    cout << "Displayed in default format:" << endl << x << '\t' << y << endl;

    cout << "\nDisplayed in scientific format:" << endl
         << scientific << x << '\t' << y << endl;

    cout << "\nDisplayed in fixed format:" << endl
         << fixed << x << '\t' << y << endl;
}
/* execution result
 * Displayed in default format:
 * 0.00123457      1.946e+09
 *
 * Displayed in scientific format:
 * 1.234567e-03    1.946000e+09
 *
 * Displayed in fixed format:
 * 0.001235        1946000000.000000
 */
