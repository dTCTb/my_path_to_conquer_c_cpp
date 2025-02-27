// Fig. 12.15: derived_base_plus_commission_employee.h
// BasePlusCommissionEmployee class derived from CommissionEmployee.
#ifndef BASEPLUS_H
#define BASEPLUS_H
#include "derived_commission_employee.h"
#include <string>
class BasePlusCommissionEmployee : public CommissionEmployee {
  public:
    BasePlusCommissionEmployee(const std::string &, const std::string &,
                               const std::string &, double = 0.0, double = 0.0,
                               double = 0.0);
    virtual ~BasePlusCommissionEmployee() {}

    void setBaseSalary(double);
    double getBaseSalary() const;

    virtual double earnings() const override;
    virtual void print() const override;

  private:
    double baseSalary;
};
#endif
