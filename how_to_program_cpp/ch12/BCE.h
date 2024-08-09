// Fig. 11.10: 11.10_BCE.h
// BasePlusCommissionEmployee class derived from class CommissionEmployee
#ifndef BASEPLUS_H
#define BASEPLUS_H
#include "CE.h"
#include <string>
class BasePlusCommissionEmployee : public CommissionEmployee {
  public:
    BasePlusCommissionEmployee(const std::string &, const std::string &,
                               const std::string &, double = 0.0, double = 0.0,
                               double = 0.0);
    void setBaseSalary(double);
    double getBaseSalary() const;

#if !defined VIRTUAL
    double earnings() const;
    void print() const;
#elif defined VIRTUAL
    virtual double earnings() const override;
    virtual void print() const override;
#endif

  private:
    double baseSalary;
};
#endif
