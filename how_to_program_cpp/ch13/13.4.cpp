// Fig. 13.4: fig13_04.cpp
// get, put and eof member functions
#include <iostream>
using namespace std;

int main() {
    int character;

    cout << "Before input, cin.eof() is " << cin.eof() << endl;
    cout << "Enter a sentence followed by end-of-file:" << endl;

    while ((character = cin.get()) != EOF)
        cout.put(character);

    cout << "\nEOF in this system is: " << character << endl;
    cout << "After input of EOF, cin.eof() is " << cin.eof() << endl;
    return 0;
}
/* execution result
 * Before input, cin.eof() is 0
 * Enter a sentence followed by end-of-file:
 * Testing the get and put member functions
 * Testing the get and put member functions
 * ^D
 * EOF in this system is: -1
 * After input of EOF, cin.eof() is 1
 */
