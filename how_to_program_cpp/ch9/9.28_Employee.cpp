// Fig. 9.28: 9.28_Employee.cpp
// Employee class member-function definitions
#include "9.27_Employee.h"
#include <iostream>
using namespace std;

unsigned friendCount() { return Employee::count; } // added by me

// define and initialize static data member at global namespace scope
unsigned Employee::count = 0;
// define static member function that returns number of Employee objects
// instantiated (declared static in 9.27_Employee.h)
unsigned Employee::getCount() { return count; }

Employee::Employee(const string &first, const string &last)
    : firstName(first), lastName(last) {
    ++count;
    cout << "Employee constructor for " << firstName << ' ' << lastName
         << " called." << endl;
}

Employee::~Employee() {
    cout << "~Employee() called for " << firstName << ' ' << lastName << endl;
    --count;
}

string Employee::getFirstName() const { return firstName; }
string Employee::getLastName() const { return lastName; }
