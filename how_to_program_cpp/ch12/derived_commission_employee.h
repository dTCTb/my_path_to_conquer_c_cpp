// Fig. 12.13: derived_commission_employee.h
// CommissionEmployee class derived from Employee.
#ifndef COMMISSION_H
#define COMMISSION_H
#include "base_employee.h"
#include <string>
class CommissionEmployee : public Employee {
  public:
    CommissionEmployee(const std::string &, const std::string &,
                       const std::string &, double = 0.0, double = 0.0);
    virtual ~CommissionEmployee() {}

    void setCommissionRate(double);
    double getCommissionRate() const;

    void setGrossSales(double);
    double getGrossSales() const;

    virtual double earnings() const override;
    virtual void print() const override;

  private:
    double grossSales;
    double commissionRate;
};
#endif
