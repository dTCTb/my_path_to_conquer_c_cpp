// Fig. 13.6: fig13_06.cpp
// Inputting characters using cin member function getline
#include <iostream>
using namespace std;

int main() {
    const int SIZE = 80;
    char buffer[SIZE];

    cout << "Enter a sentence:\n";
    cin.getline(buffer, SIZE);

    cout << "\nThe sentence entered is:\n" << buffer << endl;
}
/* execution result
 * Enter a sentence:
 * Using the getline member function
 *
 * The sentence entered is:
 * Using the getline member function
 */
