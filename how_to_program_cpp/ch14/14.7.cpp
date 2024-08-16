// Fig. 14.7: fig14_07.cpp
// Credit inquiry program
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

enum RequestType { ZERO_BALANCE = 1, CREDIT_BALANCE, DEBIT_BALANCE, END };
int getRequest();
bool shouldDisplay(int, double);
void outputLine(int, const string &, double);

int main() {
    ifstream inClientFile("./ch14/clients.txt", ios::in);

    if (!inClientFile) {
        cerr << "File could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    int account;
    string name;
    double balance;

    int request = getRequest();

    while (request != END) {
        switch (request) {
        case ZERO_BALANCE:
            cout << "\nAccount with zero balances:\n";
            break;
        case CREDIT_BALANCE:
            cout << "\nAccount with credit balances:\n";
            break;
        case DEBIT_BALANCE:
            cout << "\nAccount with debit balances:\n";
            break;
        default:
            break;
        }

        inClientFile >> account >> name >> balance;

        while (!inClientFile.eof()) {
            if (shouldDisplay(request, balance))
                outputLine(account, name, balance);

            inClientFile >> account >> name >> balance;
        }

        inClientFile.clear();
        inClientFile.seekg(0);
        request = getRequest();
    }

    cout << "End of run." << endl;
}

int getRequest() {
    int request;

    cout << "\nEnter request" << endl;
    cout << " 1 - List accounts with zero balances" << endl;
    cout << " 2 - List accounts with credit balances" << endl;
    cout << " 3 - List accounts with debit balances" << endl;
    cout << " 4 - End of run" << fixed << showpoint;

    do {
        cout << "\n? ";
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1024, '\n');
        }
        cin >> request;
    } while (request < ZERO_BALANCE || request > END);

    return request;
}

bool shouldDisplay(int type, double balance) {
    if (type == ZERO_BALANCE && balance == 0)
        return true;
    if (type == CREDIT_BALANCE && balance < 0)
        return true;
    if (type == DEBIT_BALANCE && balance > 0)
        return true;

    return false;
}

void outputLine(int account, const string &name, double balance) {
    cout << left << setw(10) << account;
    cout << setw(13) << name;
    cout << right << setw(7) << setprecision(2) << balance << endl;
}

/* execution result
 * Enter request
 *  1 - List accounts with zero balances
 *  2 - List accounts with credit balances
 *  3 - List accounts with debit balances
 *  4 - End of run
 * ? 1
 *
 * Account with zero balances:
 * 300       White           0.00
 *
 * Enter request
 *  1 - List accounts with zero balances
 *  2 - List accounts with credit balances
 *  3 - List accounts with debit balances
 *  4 - End of run
 * ? 2
 *
 * Account with credit balances:
 * 400       Stone         -42.16
 *
 * Enter request
 *  1 - List accounts with zero balances
 *  2 - List accounts with credit balances
 *  3 - List accounts with debit balances
 *  4 - End of run
 * ? 3
 *
 * Account with debit balances:
 * 100       Jones          24.98
 * 200       Doe           345.67
 * 500       Rich          224.62
 *
 * Enter request
 *  1 - List accounts with zero balances
 *  2 - List accounts with credit balances
 *  3 - List accounts with debit balances
 *  4 - End of run
 * ? 4
 * End of run.
 */
