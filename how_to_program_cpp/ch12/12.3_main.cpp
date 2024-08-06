// Fig. 12.3: 12.3_main.cpp
// Attempting to invoke derived-class-only member functions
// via a base-class pointer.
#include "BCE.h"
#include "CE.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    CommissionEmployee *cePtr = nullptr;
    BasePlusCommissionEmployee bce("Bob", "Lewis", "333-33-3333", 5000, .04,
                                   300);

    cePtr = &bce;

    string firstName = cePtr->getFirstName();
    string lastName = cePtr->getLastName();
    string ssn = cePtr->getSocialSecurityNumber();
    double grossSales = cePtr->getGrossSales();
    double commissionRate = cePtr->getCommissionRate();

#if defined PRINT
    cout << "compiler error message when execution 'double baseSalary = "
            "cePtr->getBaseSalary();'\n"
         << "clang: No member named 'getBaseSalary' in 'CommissionEmployee' "
            "[no_member]"
         << endl;
    cout << "compiler error message when execution "
            "'cePtr->setBaseSalary(500);'\n"
         << "clang: No member named 'setBaseSalary' in "
            "'CommissionEmployee'[no_member]"
         << endl;
#else
    double baseSalary = cePtr->getBaseSalary();
    cePtr->setBaseSalary(500);
#endif
    // auto ptr = reinterpret_cast<BasePlusCommissionEmployee *>(cePtr);
    // double baseSalary = ptr->getBaseSalary();
    // ptr->setBaseSalary(500);

    return 0;
}
