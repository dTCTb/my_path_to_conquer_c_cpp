// Fig. 12.19: fig12_19.cpp
// Demonstrating downcasting and runtime type information.
// Note: You may need to enable RTTI on your compiler
// before you can compile this application.
#include "base_employee.h"
#include "derived_base_plus_commission_employee.h"
#include "derived_commission_employee.h"
#include "derived_salaried_employee.h"
#include <iomanip>
#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;
using E = Employee;
using SE = SalariedEmployee;
using CE = CommissionEmployee;
using BCE = BasePlusCommissionEmployee;

int main() {
    cout << fixed << setprecision(2);

    vector<E *> employee(3);
    employee[0] = new SE("John", "Smith", "111-11-1111", 800);
    employee[1] = new CE("Sue", "Jones", "333-33-3333", 10000, .06);
    employee[2] = new BCE("Bob", "Lewis", "444-44-4444", 5000, .04, 300);

    for (E *e : employee) {
        e->print();
        cout << endl;

        BCE *derivedPtr = dynamic_cast<BCE *>(e);

        if (derivedPtr != nullptr) {
            double oldBaseSalary = derivedPtr->getBaseSalary();
            cout << "old base salary: $" << oldBaseSalary << endl;
            derivedPtr->setBaseSalary(1.10 * oldBaseSalary);
            cout << "new base salary with 10% increase is: $"
                 << derivedPtr->getBaseSalary() << endl;
        }
        cout << "earned $" << e->earnings() << "\n\n";
    }

    for (const E *e : employee) {
        cout << "deleting object of " << typeid(*e).name() << endl;
        delete e;
    }

    return 0;
}
