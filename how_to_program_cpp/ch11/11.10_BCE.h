// Fig. 11.10: 11.10_BCE.h
// BasePlusCommissionEmployee class derived from class CommissionEmployee
#ifndef BASEPLUS_H
#define BASEPLUS_H
#if defined EX11_3_3 // private data member
#include "11.4_CommissionEmployee.h"
#elif defined EX11_3_4 // protected data member
#include "11.12_CE.h"
#endif
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
