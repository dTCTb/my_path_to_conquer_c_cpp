// Fig. 13.7: fig13_07.cpp
// Unformatted I/O using read, gcount and write
#include <iostream>
using namespace std;

int main() {
    const int SIZE = 80;
    char buffer[SIZE];

    cout << "Enter a sentence:\n";
    cin.read(buffer, 20);

    cout << "\nThe sentence entered was:\n";
    cout.write(buffer, cin.gcount());
    cout.put('\n');
}
/* execution result
 * Enter a sentence:
 * Using the read, write, and gcount member functions
 *
 * The sentence entered was:
 * Using the read, writ
 */
