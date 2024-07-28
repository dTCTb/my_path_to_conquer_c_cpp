#include <iostream>

class SavingAccount {
  public:
    static double annualInterestRate;
    static void modifyInterestRate(double);
    void calculateMonthlyInterest();

    SavingAccount(double);
    ~SavingAccount();
    void printBalance() const;

  private:
    static unsigned uniqueID;
    unsigned id;
    double savingsBalance;
};

using std::cout, std::endl;

double SavingAccount::annualInterestRate = 0.03; // default annual interest rate
unsigned SavingAccount::uniqueID = 1;

void SavingAccount::modifyInterestRate(double newIR) {
    annualInterestRate = newIR;
    std::clog << "{Annual Interest Rate updated to " << newIR << '}' << endl;
}

void SavingAccount::calculateMonthlyInterest() {
    savingsBalance += (savingsBalance * annualInterestRate) / 12;
}

SavingAccount::SavingAccount(double balance) : savingsBalance(balance) {
    id = uniqueID++;
    cout << "New Saving Account " << "(ID " << id << ") Created.\n";
}

SavingAccount::~SavingAccount() {
    cout << '[' << id << "] Account DELETED" << endl;
}

void SavingAccount::printBalance() const {
    cout << '[' << id << "] Account Balance: " << savingsBalance << endl;
}

int main() {
    SavingAccount saver1(2000.00);
    SavingAccount saver2(3000.00);
    // principle balance
    saver1.printBalance();
    saver2.printBalance();

    cout << "After calculate monthly interest ("
         << SavingAccount::annualInterestRate << ")\n";
    saver1.calculateMonthlyInterest();
    saver1.printBalance();
    saver2.calculateMonthlyInterest();
    saver2.printBalance();

    SavingAccount::modifyInterestRate(0.04);

    cout << "After calculate monthly interest ("
         << SavingAccount::annualInterestRate << ")\n";
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();
    saver1.printBalance();
    saver2.printBalance();

    return 0;
}
