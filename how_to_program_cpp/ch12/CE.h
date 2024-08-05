// Fig. 11.4: 11.4_CommissionEmployee.h
// ComissionEmployee class definition represents a commission employee
#ifndef COMMISSION_H
#define COMMISSION_H
#include <string>
class CommissionEmployee {
  public:
    CommissionEmployee(const std::string &, const std::string &,
                       const std::string &, double = 0.0, double = 0);
    void setFirstName(const std::string &);
    std::string getFirstName() const;

    void setLastName(const std::string &);
    std::string getLastName() const;

    void setSocialSecurityNumber(const std::string &);
    std::string getSocialSecurityNumber() const;

    void setGrossSales(double);   // set gross sales amount
    double getGrossSales() const; // return gross sales amount

    void setCommissionRate(double);   // set commission rate (percentage)
    double getCommissionRate() const; // return commission rate

    double earnings() const; // calculate earnings
    void print() const;      // print CommissionEmployee object

  private:
    std::string firstName;
    std::string lastName;
    std::string socialSecurityNumber;
    double grossSales;     // gross weekly sales
    double commissionRate; // commission percentage
};
#endif
