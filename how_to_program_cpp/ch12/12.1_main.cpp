// Fig. 12.1: 12.1_main.cpp
// Aiming base-class and derived-class pointers at base-class
// and derived-class objects, respectively.
#include "BCE.h"
#include "CE.h"
#include <iomanip>
#include <iostream>
using namespace std;
using CE = CommissionEmployee;
using BCE = BasePlusCommissionEmployee;

int main() {
    CommissionEmployee ce("Sue", "Jones", "222-22-222", 10000, .06);
    CommissionEmployee *cePtr = nullptr;
    BasePlusCommissionEmployee bce("Bob", "Lewis", "333-33-3333", 5000, .04,
                                   300);
    BasePlusCommissionEmployee *bcePtr = nullptr;

    cout << fixed << setprecision(2);

    cout << "Print base-class and derived-class objects:\n\n";
    ce.print();
    cout << "\n\n";
    bce.print();

    cePtr = &ce;
    cout << "\n\n\nCalling print with base-class pointer to "
         << "\nbase-class object invokes base-class print function:\n\n";
    cePtr->print();

    bcePtr = &bce;
    cout << "\n\n\nCalling print with derived-class pointer to "
         << "\nderived-class object invokes derived-class "
         << "print function:\n\n";
    bcePtr->print();

    cePtr = &bce;
    cout << "\n\n\nCalling print with base-class pointer to "
         << "derived-class object\ninvokes base-class print "
         << "function on that derived-class object:\n\n";
    cePtr->print();
    cout << endl;
    return 0;
}
/* execution result
 * Print base-class and derived-class objects:
 *
 * commission employee: Sue Jones
 * social security number: 222-22-222
 * gross sales: 10000.00
 * commission rate: 0.06
 *
 * base-salaried commission employee: Bob Lewis
 * social security number: 333-33-3333
 * gross sales: 5000.00
 * commission rate: 0.04
 * base salary: 300.00
 *
 *
 * Calling print with base-class pointer to
 * base-class object invokes base-class print function:
 *
 * commission employee: Sue Jones
 * social security number: 222-22-222
 * gross sales: 10000.00
 * commission rate: 0.06
 *
 *
 * Calling print with derived-class pointer to
 * derived-class object invokes derived-class print function:
 *
 * base-salaried commission employee: Bob Lewis
 * social security number: 333-33-3333
 * gross sales: 5000.00
 * commission rate: 0.04
 * base salary: 300.00
 *
 *
 * Calling print with base-class pointer to derived-class object
 * invokes base-class print function on that derived-class object:
 *
 * commission employee: Bob Lewis
 * social security number: 333-33-3333
 * gross sales: 5000.00
 * commission rate: 0.04
 * */
