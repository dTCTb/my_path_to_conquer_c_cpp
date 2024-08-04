// Fig. 11.8: 11.8_BasePlusCommissionEmployee.cpp
// Class BasePlusCommissionEmployee member-function definitions
#include "11.7_BasePlusCommissionEmployee.h"
#include <iostream>
#include <stdexcept>
using namespace std;
using BCE = BasePlusCommissionEmployee;

BCE::BasePlusCommissionEmployee(const string &first, const string &last,
                                const string &ssn, double sales, double rate,
                                double salary) {
    firstName = first;
    lastName = last;
    socialSecurityNumber = ssn;
    setGrossSales(sales);
    setCommissionRate(rate);
    setBaseSalary(salary);
}

void BCE::setFirstName(const string &first) { firstName = first; }
string BCE::getFirstName() const { return firstName; }

void BCE::setLastName(const string &last) { lastName = last; }
string BCE::getLastName() const { return lastName; }

void BCE::setSocialSecurityNumber(const string &ssn) {
    socialSecurityNumber = ssn;
}
string BCE::getSocialSecurityNumber() const { return socialSecurityNumber; }

void BCE::setGrossSales(double sales) {
    if (sales >= 0.0)
        grossSales = sales;
    else
        throw invalid_argument("Gross sales must be >= 0.0");
}
double BCE::getGrossSales() const { return grossSales; }

void BCE::setCommissionRate(double rate) {
    if (rate > 0.0 && rate < 1.0)
        commissionRate = rate;
    else
        throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
}
double BCE::getCommissionRate() const { return commissionRate; }

void BCE::setBaseSalary(double salary) {
    if (salary >= 0.0)
        baseSalary = salary;
    else
        throw invalid_argument("Salary must be >= 0.0");
}
double BCE::getBaseSalary() const { return baseSalary; }

double BCE::earnings() const {
    return baseSalary + commissionRate * grossSales;
}
void BCE::print() const {
    cout << "base-salaried commission employee: " << firstName << ' '
         << lastName << "\nsocial security number: " << socialSecurityNumber
         << "\ngross sales: " << grossSales
         << "\ncommission rate: " << commissionRate
         << "\nbase salary: " << baseSalary;
}
