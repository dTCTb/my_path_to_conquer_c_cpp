// Fig 13.10: fig13_10.cpp
// width member function of class ios_base
#include <iostream>
using namespace std;

int main() {
    int widthValue = 4;
    char sentence[10];

    cout << "Enter a sentence:" << endl;
    cin.width(5);

    while (cin >> sentence) {
        cout.width(widthValue++);
        cout << sentence << endl;
        cin.width(5);
    }

    return 0;
}
/* execution result
 * Enter a sentence:
 * This is a test of the width member function
 * This
 *    is
 *      a
 *    test
 *       of
 *       the
 *       widt
 *           h
 *         memb
 *            er
 *           func
 *            tion
 */
