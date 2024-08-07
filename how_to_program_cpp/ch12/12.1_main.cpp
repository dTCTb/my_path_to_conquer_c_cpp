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

#if !defined VIRTUAL
    cout << "Print base-class and derived-class objects:\n\n";
#elif defined VIRTUAL
    cout << "Invoking print function on base-class and derived-class"
         << "\nobjects with static binding\n\n";
#endif
    ce.print();
    cout << "\n\n";
    bce.print();

#if defined VIRTUAL
    cout << "\n\n\nInvoking print function on base-class and "
         << "derived-class \nobjects with dynamic binding";
#endif

    cePtr = &ce;
#if !defined VIRTUAL
    cout << "\n\n\nCalling print with base-class pointer to "
         << "\nbase-class object invokes base-class print function:\n\n";
#elif defined VIRTUAL
    cout << "\n\nCalling virtual function print with base-class pointer"
         << "\nto base-class object invokes base-class "
         << "print function:\n\n";
#endif
    cePtr->print();

    bcePtr = &bce;
#if !defined VIRTUAL
    cout << "\n\n\nCalling print with derived-class pointer to "
         << "\nderived-class object invokes derived-class "
         << "print function:\n\n";
#elif defined VIRTUAL
    cout << "\n\nCalling virtual function print with derived-class "
         << "pointer\nto derived-class object invokes derived-class "
         << "print function:\n\n";
#endif
    bcePtr->print();

    cePtr = &bce;
#if !defined VIRTUAL
    cout << "\n\n\nCalling print with base-class pointer to "
         << "derived-class object\ninvokes base-class print "
         << "function on that derived-class object:\n\n";
#elif defined VIRTUAL
    cout << "\n\nCalling virtual function print with base-class pointer"
         << "\nto derived-class object invokes derived-class "
         << "print function:\n\n";
#endif
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
