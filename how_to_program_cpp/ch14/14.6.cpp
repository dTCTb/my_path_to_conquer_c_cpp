// Fig. 14.6: fig14_06.cpp
// Reading and printing a sequential file
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

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

    cout << left << setw(10) << "Account" << setw(13) << "Name" << setw(7)
         << "Balance" << endl;

    while (inClientFile >> account >> name >> balance)
        outputLine(account, name, balance);

    return 0;
}

void outputLine(int account, const string &name, double balance) {
    cout << left << setw(10) << account << setw(13) << name << setw(7) << fixed
         << setprecision(2) << right << balance << endl;
}

/* execution result
 * Account   Name         Balance
 * 100       Jones          24.98
 * 200       Doe           345.67
 * 300       White           0.00
 * 400       Stone         -42.16
 * 500       Rich          224.62
 */
