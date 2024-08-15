// Fig. 14.14: 14.14_main.cpp
// This program reads a random-access file sequentially, updates
// data previously written to the file, creates data to be placed
// in the file, and deletes data previously stored in the file.
#include "ClientData.h"
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

char enterChoice();
void createTextFile(fstream &);
void updateRecord(fstream &);
void newRecord(fstream &);
void deleteRecord(fstream &);
void outputLine(ostream &, const ClientData &);
int getAccount(const char *const);

// 我自己加嘅
void listRecord(fstream &);
void printHeader(std::ostream &f);
void reset(std::fstream &);
bool long_prompt = true;
const char *credit_file = "./ch14/credit.dat";
const char *file = "./ch14/print.txt";

enum Choices { // 書用digit, 我用character
    PROMPT,
    PRINT = 's',
    UPDATE = 'u',
    NEW = 'a',
    DELETE = 'd',
    LIST = 'l',
    RESET = 'r',
    END = 'q'
};

int main() {
    std::fstream inOutClient(credit_file,
                             std::ios::in | std::ios::out | std::ios::binary);

    if (!inOutClient) {
        std::cerr << "File could not be opened." << std::endl;
        exit(EXIT_FAILURE);
    }

    char choice;

    while ((choice = enterChoice()) != END) {
        switch (choice) {
        case PROMPT:
            long_prompt = false;
            break;
        case PRINT:
            createTextFile(inOutClient);
            break;
        case UPDATE:
            updateRecord(inOutClient);
            break;
        case NEW:
            newRecord(inOutClient);
            break;
        case DELETE:
            deleteRecord(inOutClient);
            break;
        case LIST:
            listRecord(inOutClient);
            break;
        case RESET:
            reset(inOutClient);
            break;
        default:
            std::cerr << "Incorrect choice" << std::endl;
            break;
        }

        inOutClient.clear(std::ios::goodbit);
    }
    return 0;
}

char enterChoice() {
    if (long_prompt) {
        std::cout << "\nEnter your choice" << std::endl;
        std::cout << "s - store a formatted text file of accounts\n"
                     "    called \"print.txt\" for printing"
                  << endl;
        std::cout << "u - update an account" << std::endl;
        std::cout << "a - add a new account" << std::endl;
        std::cout << "d - delete an account" << std::endl;
        std::cout << "l - list all accounts" << std::endl;
        std::cout << "r - reset to preset" << std::endl;
        std::cout << "q - end program\n? ";
    } else
        std::cout << "\n[s]ave [u]pdate [a]dd [d]elete [l]ist [r]eset "
                     "[q]uit\n? ";

    char menuChoice;
    cin >> menuChoice;
    return menuChoice;
}

void createTextFile(std::fstream &readFromFile) {
    ofstream outPrintFile(file, std::ios::out);

    if (!outPrintFile) {
        std::cerr << "File could not be created." << std::endl;
        exit(EXIT_FAILURE);
    }

    printHeader(outPrintFile);
    readFromFile.seekg(0);

    ClientData client;
    readFromFile.read(reinterpret_cast<char *>(&client), sizeof(ClientData));

    while (!readFromFile.eof()) {
        if (client.getAccountNumber() != 0)
            outputLine(outPrintFile, client);

        readFromFile.read(reinterpret_cast<char *>(&client),
                          sizeof(ClientData));
    }
}

void updateRecord(std::fstream &updateFile) {
    int accountNumber = getAccount("Enter account to update");
    unsigned long pos =
        updateFile.seekg((accountNumber - 1) * sizeof(ClientData)).tellg();

    ClientData client;
    updateFile.read(reinterpret_cast<char *>(&client), sizeof(ClientData));

    if (client.getAccountNumber() != 0) {
        outputLine(std::cout, client);

        cout << "\nEnter to specify (+) or payment (-): ";
        double transaction;
        cin >> transaction;

        double oldBalance = client.getBalance();
        client.setBalance(oldBalance + transaction);
        outputLine(std::cout, client);

        // updateFile.seekp((accountNumber - 1) * sizeof(ClientData));
        updateFile.seekp(pos);

        updateFile.write(reinterpret_cast<char *>(&client), sizeof(ClientData));
    } else
        std::cerr << "Account #" << accountNumber << " has no information."
                  << std::endl;
}

void newRecord(fstream &insertInFile) {
    int accountNumber = getAccount("Enter new account number");
    unsigned long pos =
        insertInFile.seekg((accountNumber - 1) * sizeof(ClientData)).tellg();

    ClientData client;
    insertInFile.read(reinterpret_cast<char *>(&client), sizeof(ClientData));

    if (client.getAccountNumber() == 0) {
        std::string lastName;
        std::string firstName;
        double balance;

        cout << "Enter lastname, firstname, balance\n? ";
        cin >> lastName >> firstName >> balance;

        client.setAccountNumber(accountNumber);
        client.setLastName(lastName);
        client.setFirstName(firstName);
        client.setBalance(balance);

        insertInFile.seekp(pos);
        insertInFile.write(reinterpret_cast<char *>(&client),
                           sizeof(ClientData));
    } else
        std::cerr << "Account #" << accountNumber
                  << " already contains information." << std::endl;
}

void deleteRecord(fstream &deleteFromFile) {
    int accountNumber = getAccount("Enter account to delete");
    unsigned long pos =
        deleteFromFile.seekg((accountNumber - 1) * sizeof(ClientData)).tellg();

    ClientData client;
    deleteFromFile.read(reinterpret_cast<char *>(&client), sizeof(ClientData));

    if (client.getAccountNumber() != 0) {
        ClientData blankClient;
        deleteFromFile.seekp(pos);
        deleteFromFile.write(reinterpret_cast<char *>(&blankClient),
                             sizeof(ClientData));
        std::cout << "Account #" << accountNumber << " deleted.\n";
    } else
        std::cerr << "Account #" << accountNumber << " is empty.\n";
}

void outputLine(std::ostream &output, const ClientData &record) {
    output << left << setw(10) << record.getAccountNumber() << setw(16)
           << record.getLastName() << setw(11) << record.getFirstName() << right
           << setw(10) << setprecision(2) << fixed << record.getBalance()
           << std::endl;
}

int getAccount(const char *const prompt) {
    int accountNumber;
    do {
        if (std::cin.peek() == '\n')
            cout << prompt << " (1 - 100): ";
        cin >> accountNumber;
    } while (accountNumber < 1 || accountNumber > 100);
    return accountNumber;
}

void printHeader(std::ostream &f) {
    f << left << setw(10) << "Account" << setw(16) << "Last Name" << setw(11)
      << "First Name" << right << setw(10) << "Balance" << endl;
}

void listRecord(fstream &f) {
    f.seekg(0);
    ClientData client;
    while (!f.eof()) {
        f.read(reinterpret_cast<char *>(&client), sizeof(ClientData));
        if (client.getAccountNumber() != 0) {
            outputLine(std::cout, client);
        }
    }
}

void reset(std::fstream &f) {
    ClientData c29(29, "Brown", "Nancy", -24.54);
    ClientData c33(33, "Dunn", "Stacey", 314.33);
    ClientData c37(37, "Barker", "Doug", 0.00);
    ClientData c88(88, "smith", "Dave", 258.34);
    ClientData c96(96, "Stone", "Sam", 34.98);
    ClientData *arr[5]{&c29, &c33, &c37, &c88, &c96};
    for (ClientData *c : arr) {
        f.seekp((c->getAccountNumber() - 1) * sizeof(ClientData));
        f.write(reinterpret_cast<char *>(c), sizeof(ClientData));
    }
}
