// Fig. 13.11: fig13_11.cpp
// Creating and testing user-defined, nonparameterized stream manipulators
#include <iostream>
using namespace std;

ostream &bell(ostream &output) { return output << '\a'; }

ostream &carriageReturn(ostream &output) { return output << '\r'; }

ostream &tab(ostream &output) { return output << '\t'; }

ostream &endLine(ostream &output) { return output << '\n'; }

int main() {
    cout << "Testing the tab manipulator:" << endLine;
    cout << 'a' << tab << 'b' << tab << 'c' << endLine;

    cout << "Testing the carriageReturn and bell manipulators:" << endLine;
    cout << "............";
    cout << bell;
    cout << carriageReturn << "------" << endLine;
    return 0;
}
/* execution result
 * Testing the tab manipulator:
 * a       b       c
 * Testing the carriageReturn and bell manipulators:
 * ------......
 */
