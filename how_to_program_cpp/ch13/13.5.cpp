// Fig. 13.5: fig13_05.cpp
// Contrasting input of a string via cin and cin.get
#include <iostream>
using namespace std;

int main() {
    const int SIZE = 80;
    char buffer1[SIZE];
    char buffer2[SIZE];

    cout << "Enter a sentence:" << endl;
    cin >> buffer1;

    cout << "\nThe string read with cin was:\n" << buffer1 << "\n\n";

    cin.get(buffer2, SIZE);

    cout << "The string read with cin.get was:" << endl << buffer2 << endl;
}
/* execution result
 * Enter a sentence:
 * Contrasting string input with cin and cin.get
 *
 * The string read with cin was:
 * Contrasting
 *
 * The string read with cin.get was:
 *  string input with cin and cin.get
 */
