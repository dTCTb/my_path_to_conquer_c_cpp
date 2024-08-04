// Fig. 11.11: 11.11_BCE.cpp
// Class BasePlusCommissionEmployee member-function definitions
#include "11.10_BCE.h"
#include <iostream>
#include <stdexcept>
using namespace std;
using BCE = BasePlusCommissionEmployee;

BCE::BasePlusCommissionEmployee(const string &first, const string &last,
                                const string &ssn, double sales, double rate,
                                double salary)
    : CommissionEmployee(first, last, ssn, sales, rate) {
    setBaseSalary(salary);
}

void BCE::setBaseSalary(double salary) {
    if (salary >= 0.0)
        baseSalary = salary;
    else
        throw invalid_argument("Salary must be >= 0.0");
}

double BCE::getBaseSalary() const { return baseSalary; }

#if defined EX11_3_3
// derived class cannot access the base class's private data
double BCE::earnings() const {
    return baseSalary + (getCommissionRate() * getGrossSales());
}
#elif defined EX11_3_4
// after changed base class's private data to protected data
double BCE::earnings() const {
    return baseSalary + (commissionRate * grossSales);
}
#endif

#if defined EX11_3_3
// derived class cannot access the base class's private data
void BCE::print() const {
    cout << "base-salaried commission employee: " << getFirstName() << ' '
         << getLastName()
         << "\nsocial security number: " << getSocialSecurityNumber()
         << "\ngross sales: " << getGrossSales()
         << "\ncommission rate: " << getCommissionRate()
         << "\nbase salary: " << baseSalary;
}
#elif defined EX11_3_4
// after changed base class's private data to protected data
void BCE::print() const {
    cout << "base-salaried commission employee: " << firstName << ' '
         << lastName << "\nsocial security number: " << socialSecurityNumber
         << "\ngross sales: " << grossSales
         << "\ncommission rate: " << commissionRate
         << "\nbase salary: " << baseSalary;
}
#endif
