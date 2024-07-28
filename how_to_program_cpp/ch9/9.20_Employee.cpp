// Fig 9.20: 9.20_Employee.cpp
// Employee class member-function definitions
#include "9.17_Date.h"
#include "9.19_Employee.h"
#include <iostream>
using namespace std;

Employee::Employee(const string &first, const string &last,
                   const Date &dateOfBirth, const Date &dateOfHire)
    : firstName(first), lastName(last), birthDate(dateOfBirth),
      hireDate(dateOfHire) {
    cout << "Employee object constructor: " << firstName << ' ' << lastName
         << endl;
}

void Employee::print() const {
    cout << lastName << ", " << firstName << " Hired: ";
    hireDate.print();
    cout << " Birthday: ";
    birthDate.print();
    cout << endl;
}

Employee::~Employee() {
    cout << "Employee object destructor: " << lastName << ", " << firstName
         << endl;
}
