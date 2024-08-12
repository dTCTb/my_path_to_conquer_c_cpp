// 呢個係我靠本書嘅result 反推出嚟嘅source code，
// 因為個pdf scan 得唔好，miss 咗呢個嘅源代碼。
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int a;

    cout << "Before a bad input operation:\n";
    cout << setw(15) << "cin.rdstate(): " << cin.rdstate() << endl;
    cout << setw(15) << "cin.eof(): " << cin.eof() << endl;
    cout << setw(15) << "cin.fail(): " << cin.fail() << endl;
    cout << setw(15) << "cin.bad(): " << cin.bad() << endl;
    cout << setw(15) << "cin.good(): " << cin.good() << endl;

    cout << "\nExpects an integer, but enter a character: ";
    cin >> a;

    cout << "\nAfter a bad input operator:\n";
    cout << setw(15) << "cin.rdstate(): " << cin.rdstate() << endl;
    cout << setw(15) << "cin.eof(): " << cin.eof() << endl;
    cout << setw(15) << "cin.fail(): " << cin.fail() << endl;
    cout << setw(15) << "cin.bad(): " << cin.bad() << endl;
    cout << setw(15) << "cin.good(): " << cin.good() << endl;

    cin.clear();
    cout << "\nAfter cin.clear()\n";
    cout << setw(15) << "cin.fail(): " << cin.fail() << endl;
    cout << setw(15) << "cin.good(): " << cin.good() << endl;

    return 0;
}
/* execution result
 * Before a bad input operation:
 * cin.rdstate(): 0
 *     cin.eof(): 0
 *    cin.fail(): 0
 *     cin.bad(): 0
 *    cin.good(): 1
 *
 * Expects an integer, but enter a character: A
 *
 * After a bad input operator:
 * cin.rdstate(): 4
 *     cin.eof(): 0
 *    cin.fail(): 1
 *     cin.bad(): 0
 *    cin.good(): 0
 *
 * After cin.clear()
 *    cin.fail(): 0
 *    cin.good(): 1
 */
