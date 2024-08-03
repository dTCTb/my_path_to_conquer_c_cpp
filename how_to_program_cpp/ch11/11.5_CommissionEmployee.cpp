// Fig. 11.5: 11.5_CommissionEmployee.cpp
// Class COmmissionEmployee member-function definitions
#if defined NONE
#include "11.4_CommissionEmployee.h"
#elif defined PROTECTED
#include "11.12_CE.h"
#endif
#include <iostream>
#include <stdexcept>
using namespace std;
using CE = CommissionEmployee;

CE::CommissionEmployee(const string &first, const string &last,
                       const string &ssn, double sales, double rate) {
    firstName = first;
    lastName = last;
    socialSecurityNumber = ssn;
    setGrossSales(sales);
    setCommissionRate(rate);
}

void CE::setFirstName(const string &first) { firstName = first; }

string CE::getFirstName() const { return firstName; }

void CE::setLastName(const string &last) { lastName = last; }

string CE::getLastName() const { return lastName; }

void CE::setSocialSecurityNumber(const std::string &ssn) {
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
        throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
}

double CE::getCommissionRate() const { return commissionRate; }

double CE::earnings() const { return commissionRate * grossSales; }

void CE::print() const {
    cout << "commission employee: " << firstName << ' ' << lastName
         << "\nsocial security number: " << socialSecurityNumber
         << "\ngross sales: " << grossSales
         << "\ncommission rate: " << commissionRate;
}
