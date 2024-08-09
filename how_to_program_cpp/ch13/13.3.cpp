// Fig. 13.3: fig13_03.cpp
// Printing the address stored in a char * variable
#include <iostream>
using namespace std;

int main() {
    const char *const word = "again";
    cout << "Value of word is: " << word << endl;
    cout << "Value of static_castconst <void *>(word) is: "
         << static_cast<const void *>(word) << endl;
}
/* execution result
 * Value of word is: again
 * Value of static_castconst <void *>(word) is: 0x102defec0
 */
