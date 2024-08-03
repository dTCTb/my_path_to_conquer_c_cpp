// Fig. 11.9: 11.9_main.cpp
// BasePlusCommissionEmployee class test program
#include "11.7_BasePlusCommissionEmployee.h"
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    BasePlusCommissionEmployee employee("Bob", "Lewis", "333-33-3333", 5000,
                                        .04, 300);
    cout << fixed << setprecision(2);
    cout << "Employee information obtained by get functions: \n"
         << "\nFirst name is " << employee.getFirstName() << "\nLastName is "
         << employee.getLastName() << "\nSocial security number is "
         << employee.getSocialSecurityNumber() << "\nGross sales is "
         << employee.getGrossSales() << "\nCommission rate is "
         << employee.getCommissionRate() << "\nBase salary is "
         << employee.getBaseSalary() << endl;
    employee.setBaseSalary(1000);
    cout << "\nUpdated employee information output by print function: \n"
         << endl;
    employee.print();
    cout << "\n\nEmployee's earnings: $" << employee.earnings() << endl;
    return 0;
}
/* execution result
 * Employee information obtained by get functions:
 *
 * First name is Bob
 * LastName is Lewis
 * Social security number is 333-33-3333
 * Gross sales is 5000.00
 * Commission rate is 0.04
 * Base salary is 300.00
 *
 * Updated employee information output by print function:
 *
 * base-salaried commission employee: Bob Lewis
 * social security number: 333-33-3333
 * gross sales: 5000.00
 * commission rate: 0.04
 * base salary: 1000.00
 *
 * Employee's earnings: $1200.00
 */
