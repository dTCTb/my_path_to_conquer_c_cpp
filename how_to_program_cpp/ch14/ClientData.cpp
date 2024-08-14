// Fig. 14.10: ClientData.cpp
// Class ClientData stores customer's credit information
#include "ClientData.h"
#include <string>

ClientData::ClientData(int accountNumberValue, const std::string &lastName,
                       const std::string &firstName, double balanceValue)
    : accountNumber(accountNumberValue), balance(balanceValue) {
    setLastName(lastName);
    setFirstName(firstName);
}

int ClientData::getAccountNumber() const { return accountNumber; }

void ClientData::setAccountNumber(int accountNumberValue) {
    accountNumber = accountNumberValue;
}

std::string ClientData::getLastName() const { return lastName; }

void ClientData::setLastName(const std::string &lastNameString) {
    unsigned length = lastNameString.length();
    // length = length < 15 ? length : 14;
    length = length > 14 ? 14 : length;
    lastNameString.copy(lastName, length);
    lastName[length] = '\0';
}

std::string ClientData::getFirstName() const { return firstName; }

void ClientData::setFirstName(const std::string &firstNameValue) {
    unsigned length = firstNameValue.length();
    // length = length < 10 ? length : 9;
    length = length < 9 ? 9 : length;
    firstNameValue.copy(firstName, length);
    firstName[length] = '\0';
}

double ClientData::getBalance() const { return balance; }

void ClientData::setBalance(double balanceValue) { balance = balanceValue; }
