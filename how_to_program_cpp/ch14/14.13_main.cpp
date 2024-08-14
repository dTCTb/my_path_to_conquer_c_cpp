// Fig. 14.13: 14.13_main.cpp
// Reading a random-access file sequentially
#include "ClientData.h"
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

void enquiry(std::ifstream &);
void outputLine(ostream &, const ClientData &);

int main() {
    std::ifstream inCredit("./ch14/credit.dat",
                           std::ios::in | std::ios::binary);
    if (!inCredit) {
        std::cerr << "File could not be opened.\n";
        exit(EXIT_FAILURE);
    }

    cout << left << setw(10) << "Account" << setw(16) << "Last Name" << setw(11)
         << "First Name" << left << setw(10) << right << "Balance" << std::endl;

    ClientData client;

    inCredit.read(reinterpret_cast<char *>(&client), sizeof(ClientData));

    while (inCredit && !inCredit.eof()) {
        if (client.getAccountNumber() != 0)
            outputLine(cout, client);
        inCredit.read(reinterpret_cast<char *>(&client), sizeof(ClientData));
    }

    enquiry(inCredit);

    return 0;
}

void outputLine(ostream &output, const ClientData &record) {
    std::ios::fmtflags ori = output.flags();
    output << left << setw(10) << record.getAccountNumber() << setw(16)
           << record.getLastName() << setw(11) << record.getFirstName()
           << setw(10) << setprecision(2) << right << fixed << showpoint
           << record.getBalance() << endl;
    std::cout.flags(ori);
}

void enquiry(std::ifstream &f) {
    if (f.eof())
        f.clear();
    int enquiry;
    ClientData client;

    // prompt for account number
    std::cout << "? ";
    std::cin >> enquiry;

    // only within 1 ~ 100
    while (enquiry > 0 && enquiry <= 100) {
        // set file pointer and read block of data to object client
        f.seekg((enquiry - 1) * sizeof(ClientData), std::ios::beg);
        f.read(reinterpret_cast<char *>(&client), sizeof(ClientData));

        // print out client data member
        outputLine(cout, client);
        // std::cout << std::setw(3) << std::setfill('0')
        //           << client.getAccountNumber();
        // std::cout << std::setfill(' ') << ' ' << client.getLastName() << ' '
        //           << client.getFirstName() << " $" << client.getBalance()
        //           << std::endl;

        // prompt for next account number if any
        if (std::cin.peek() == '\n') // if entered series of acc. no.
            std::cout << "? "; // e.g. 1 33 9 | this prompt won't print out
        std::cin >> enquiry;
    }
}
