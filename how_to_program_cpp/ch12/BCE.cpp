// Fig. 11.15: 11.15_BCE.cpp
// Class BasePlusCommissionEmployee member-function definitions
#include "BCE.h"
#include <iostream>
#include <stdexcept>
using namespace std;
using CE = CommissionEmployee;
using BCE = BasePlusCommissionEmployee;

double BCE::earnings() const {
    return getBaseSalary() + CE::earnings(); // <==
}

void BCE::print() const {
    cout << "base-salaried ";
    CE::print(); // <==
    cout << "\nbase salary: " << getBaseSalary();
}

// belows are remain unchanged

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
