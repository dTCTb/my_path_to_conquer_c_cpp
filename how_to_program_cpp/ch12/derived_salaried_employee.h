// Fig. 12.11: derived_salaried_employee.h
// SalariedEmployee class derived from Employee.
#ifndef SALARIED_H
#define SALARIED_H
#include "base_employee.h"
#include <string>
class SalariedEmployee : public Employee {
  public:
    SalariedEmployee(const std::string &, const std::string &,
                     const std::string &, double = 0.0);
    virtual ~SalariedEmployee() {}

    void setWeeklySalary(double);
    double getWeeklySalary() const;

    virtual double earnings() const override;
    virtual void print() const override;

  private:
    double weeklySalary;
};
#endif
