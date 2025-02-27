// Fig. 14.9: ClientData.h
// Class ClientData definition used in 14.11-14.14
#ifndef CLIENTDATA_H
#define CLIENTDATA_H
#include <string>

class ClientData {
  public:
    ClientData(int = 0, const std::string & = "", const std::string & = "",
               double = 0.0);

    void setAccountNumber(int);
    int getAccountNumber() const;

    void setLastName(const std::string &);
    std::string getLastName() const;

    void setFirstName(const std::string &);
    std::string getFirstName() const;

    void setBalance(double);
    double getBalance() const;

  private:
    int accountNumber;
    char lastName[15];
    char firstName[10];
    double balance;
};
#endif
