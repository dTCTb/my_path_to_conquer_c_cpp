// clang-format off
// Fig. 12.17: 12.17_main.cpp
// Processing Employee derived-class objects individually
// and polymorphically using dynamic binding.
#include "base_employee.h"
#include "derived_base_plus_commission_employee.h"
#include "derived_commission_employee.h"
#include "derived_salaried_employee.h"
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
using E   = Employee;
using SE  = SalariedEmployee;
using CE  = CommissionEmployee;
using BCE = BasePlusCommissionEmployee;

void virtualViaPointer(const E *const);
void virtualViaReference(const E &);
void p_earnings(const E *const);
void p_earnings(const E &);

int main() {
    cout << fixed << setprecision(2);

    SE salariedEmployee(           "John", "Smith", "111-11-1111",   800);
    CE commissionEmployee(         "Sue",  "Jones", "333-33-3333", 10000, .06);
    BCE basePlusCommissionEmployee("Bob",  "Lewis", "444-44-4444",  5000,  .04, 300);

    cout << "Employees processed individually using static binding:\n\n";
    salariedEmployee.print();           p_earnings(salariedEmployee);
    commissionEmployee.print();         p_earnings(commissionEmployee);
    basePlusCommissionEmployee.print(); p_earnings(basePlusCommissionEmployee);

    vector<E *> employees = {&salariedEmployee, &commissionEmployee,
                             &basePlusCommissionEmployee};
    /* rubbish book version
    vector<E *> employees(3);
    employees[0] = &salariedEmployee;
    employees[1] = &commissionEmployee;
    employees[2] = &basePlusCommissionEmployee; */

    cout << "Employees processed polymorphically via dynamic binding:\n\n";

    cout << "Virtual function calls made off base-class pointers:\n\n";
    for (const E *ePtr : employees) virtualViaPointer(ePtr);

    cout << "Virtual function calls made off base-class references:\n\n";

    /* rubbish book version
    for (const E *ePtr : employees) virtualViaReference(*ePtr); */

    // my version eRef is reference of pointer to Employee
    for (E *&eRef : employees) virtualViaReference(*eRef);

    return 0;
}

void virtualViaPointer(const E *const ePtr) { ePtr->print(); p_earnings(ePtr); }
void virtualViaReference(const E &eRef)     { eRef.print();  p_earnings(eRef); }

void p_earnings(const E *const ePtr) { cout << "\nearned $" << ePtr->earnings() << "\n\n"; }
void p_earnings(const E &eRef)       { cout << "\nearned $" << eRef.earnings()  << "\n\n"; }
