#include <array>
#include <iostream>
#include <vector>
using namespace std;
const int COUNT = 3;

istream &operator>>(istream &CIN, int *a) {
    cout << "overloaded >> for array of int:" << endl;
    for (size_t i = 0; i < COUNT; i++) {
        cout << i + 1 << ". ";
        CIN >> *(a + i);
    }
    return cin;
}
istream &operator>>(istream &CIN, array<int, COUNT> &b) {
    cout << "overloaded >> for array object:" << endl;
    for (int &v : b) {
        CIN >> v;
    }
    return cin;
}
istream &operator>>(istream &CIN, vector<int> &c) {
    cout << "overloaded >> for vector object:" << endl;
    int tmp = 0, count = 0;
    do {
        cout << ++count << ". ";
        CIN >> tmp;
        c.push_back(tmp);
    } while (tmp != 0); // sentinel
    c.pop_back();       // remove sentinel
    return cin;
}

int main() {
    int a[COUNT];
    array<int, COUNT> b{};
    vector<int> c{};

    cin >> a >> b >> c;

    cout << "Output from array of int: ";
    for (size_t i = 0; i < COUNT; i++)
        cout << a[i] << ' ';
    cout.put('\n');

    cout << "Output from array object: ";
    for (int v : b)
        cout << v << ' ';
    cout.put('\n');

    cout << "Output from vector object: ";
    for (int v : c)
        cout << v << ' ';
    cout.put('\n');
}
/* execution result
 * overloaded >> for array of int:
 * 1. 1
 * 2. 1
 * 3. 1
 * overloaded >> for array object:
 * 2
 * 2
 * 2
 * overloaded >> for vector object:
 * 1. 3
 * 2. 3
 * 3. 3
 * 4.
 * 0
 * Output from array of int: 1 1 1
 * Output from array object: 2 2 2
 * Output from vector object: 3 3 3
 */
