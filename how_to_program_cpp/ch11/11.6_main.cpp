// Fig. 11.6: 11.6_main.cpp
// CommissionEmployee class test program
#include "11.4_CommissionEmployee.h"
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    CommissionEmployee employee("Sue", "Jones", "222-22-2222", 10000, .06);

    cout << fixed << setprecision(2);

    cout << "Employee information obtained by get functions: \n"
         << "\nFirst name is " << employee.getFirstName() << "\nLast name is "
         << employee.getLastName() << "\nSocial security number is "
         << employee.getSocialSecurityNumber() << "\nGross sales is "
         << employee.getGrossSales() << "\nCommission rate is "
         << employee.getCommissionRate() << endl;

    employee.setGrossSales(8000);
    employee.setCommissionRate(.1);

    cout << "\nUpdated employee information output by print function: \n"
         << endl;
    employee.print();

    cout << "\n\nEmployee's earnings: $" << employee.earnings() << endl;
    return 0;
}
/* execution result
 * Employee information obtained by get functions:
 *
 * First name is Sue
 * Last name is Jones
 * Social security number is 222-22-2222
 * Gross sales is 10000.00
 * Commission rate is 0.06
 *
 * Updated employee information output by print function:
 *
 * commission employee: Sue Jones
 * social security number: 222-22-2222
 * gross sales: 8000.00
 * commission rate: 0.10
 *
 * Employee's earnings: $800.00
 */
