// Fig. 14.12: 14.12_main.cpp
// Writing to a random-access file
#include "ClientData.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

int main() {
    int accountNumber;
    std::string lastName;
    std::string firstName;
    double balance;

    std::fstream outCredit("./ch14/credit.dat",
                           std::ios::out | std::ios::in | std::ios::binary);
    if (!outCredit) {
        std::cerr << "File could not be opened.\n";
        exit(EXIT_FAILURE);
    }

    std::cout << "Enter account number (1 to 100, 0 to end input)\n? ";

    ClientData client;
    std::cin >> accountNumber;
    while (accountNumber > 0 && accountNumber <= 100) {
        std::cout << "Enter lastname, firstname, balance\n? ";
        std::cin >> lastName >> firstName >> balance;

        client.setAccountNumber(accountNumber);
        client.setLastName(lastName);
        client.setFirstName(firstName);
        client.setBalance(balance);

        outCredit.seekp((client.getAccountNumber() - 1) * sizeof(ClientData));
        outCredit.write(reinterpret_cast<char *>(&client), sizeof(ClientData));

        std::cout << "Enter account number\n? ";
        std::cin >> accountNumber;
    }
    return 0;
}
