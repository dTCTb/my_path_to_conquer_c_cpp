// Fig. 14.3: fig14_03.cpp
// Create a sequential file
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ofstream outClientFile("./ch14/clients.txt", ios::out);

    if (!outClientFile) {
        cerr << "File could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Enter the account, name, and balance." << endl
         << "Enter end-of-file to end input.\n? ";

    int account;
    string name;
    double balance;

    while (cin >> account >> name >> balance) {
        outClientFile << account << ' ' << name << ' ' << balance << endl;
        cout << "? ";
    }
}
/* execution result
 * * Enter the account, name, and balance.
 * Enter end-of-file to end input.
 * ? 100 Jones 24.98
 * ? 200 Doe 345.67
 * ? 300 White 0.00
 * ? 400 Stone -42.16
 * ? 500 Rich 224.62
 * ? <c-d>
 */
