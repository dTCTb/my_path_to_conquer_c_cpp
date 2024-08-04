// Fig. 11.14: 11.14_CE.cpp
// Class CommissionEmployee member-function definitions
#include "11.4_CommissionEmployee.h"
#include <iostream>
#include <stdexcept>
using namespace std;
using CE = CommissionEmployee;

CE::CommissionEmployee(const string &first, const string &last,
                       const string &ssn, double sales, double rate)
    : firstName(first), lastName(last), socialSecurityNumber(ssn) { // <--
    setGrossSales(sales);
    setCommissionRate(rate);
}

double CE::earnings() const { return getCommissionRate() * getGrossSales(); }

void CE::print() const {
    cout << "commission employee: " << getFirstName() << ' ' << getLastName()
         << "\nsocial security number: " << getSocialSecurityNumber()
         << "\ngross sales: " << getGrossSales()
         << "\ncommission rate: " << getCommissionRate();
}

// belows are remain unchanged

void CE::setFirstName(const string &first) { firstName = first; }

string CE::getFirstName() const { return firstName; }

void CE::setLastName(const string &last) { lastName = last; }

string CE::getLastName() const { return lastName; }

void CE::setSocialSecurityNumber(const string &ssn) {
    socialSecurityNumber = ssn;
}

string CE::getSocialSecurityNumber() const { return socialSecurityNumber; }

void CE::setGrossSales(double sales) {
    if (sales >= 0.0)
        grossSales = sales;
    else
        throw invalid_argument("Gross sales must be >= 0.0");
}

double CE::getGrossSales() const { return grossSales; }

void CE::setCommissionRate(double rate) {
    if (rate > 0.0 && rate < 1.0)
        commissionRate = rate;
    else
        throw invalid_argument("Commission Rate must be > 0.0 and < 1.0");
}

double CE::getCommissionRate() const { return commissionRate; }
