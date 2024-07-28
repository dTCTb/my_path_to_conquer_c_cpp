// Fig. 9.19: 9.19_Employee.h
// Employee class definition showing composition
// Member-function defined in 9.20_Employee.cpp
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "9.17_Date.h"
#include <string>

class Employee {
  public:
    Employee(const std::string &, const std::string &, const Date &,
             const Date &);
    void print() const;
    ~Employee();

  private:
    std::string firstName;
    std::string lastName;
    const Date birthDate;
    const Date hireDate;
};

#endif
