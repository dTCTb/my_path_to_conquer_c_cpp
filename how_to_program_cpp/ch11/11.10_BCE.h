// Fig. 11.10: 11.10_BCE.h
// BasePlusCommissionEmployee class derived from class CommissionEmployee
#ifndef BASEPLUS_H
#define BASEPLUS_H
#include "11.4_CommissionEmployee.h"
#include <string>
class BasePlusCommissionEmployee : public CommissionEmployee {
  public:
    BasePlusCommissionEmployee(const std::string &, const std::string &,
                               const std::string &, double = 0.0, double = 0.0,
                               double = 0.0);
    void setBaseSalary(double);
    double getBaseSalary() const;

    double earnings() const;
    void print() const;

  private:
    double baseSalary;
};
#endif
