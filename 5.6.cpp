// Fig. 5.6: fig05_06.cpp
// Compound interest calculations with for.
#include <cmath> // standard math library
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    double amount;             // amount on deposit at end of each year
    double principal = 1000.0; // initial amount before interest
    double rate = .05;         // annual interest rate

    // display headers
    cout << "Year" << setw(21) << "Amount on deposit" << endl;

    // set floating-point number for format
    cout << fixed << setprecision(2);

    // calculate amount on deposite for each ten years
    for (unsigned year = 1; year <= 10; year++) {
        // calculate new amount for specified year
        amount = principal * pow(1.0 + rate, year);

        // display the year and the amount
        cout << setw(4) << year << setw(21) << amount << endl;
    }

    return 0;
}
/* execution result
 * Year    Amount on deposit
 *    1              1050.00
 *    2              1102.50
 *    3              1157.63
 *    4              1215.51
 *    5              1276.28
 *    6              1340.10
 *    7              1407.10
 *    8              1477.46
 *    9              1551.33
 *   10              1628.89
 */
