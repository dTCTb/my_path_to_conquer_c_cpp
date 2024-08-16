// clang-format off
// Fig. 13.14: fig13_14.cpp
// Left and right justification with stream manipulators left and right
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int x = 12345;

    cout << "Default is right justified:\n" << setw(10) << x << "\n\n";
    cout << "Use std::left to left justified:\n" << left << setw(10) << x << "\n\n";
    cout << "Use std::right to right justified:\n" << right << setw(10) << x << "\n";
}
/* execution result
* Default is right justified:
*      12345
* 
* Use std::left to left justified:
* 12345     
* 
* Use std::right to right justified:
*      12345
*/
