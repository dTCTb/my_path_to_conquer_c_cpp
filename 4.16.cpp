// Fig. 4.16: fig04_16.cpp
// Examination-results problem: Nested control statements.
#include <iostream>
using namespace std;

int main() {
    // initializing variables in declarations
    unsigned int passes = 0;         // number of passes
    unsigned int failures = 0;       // number of failures
    unsigned int studentCounter = 1; // student counter

    // process 10 students using counter-controlled loop
    while (studentCounter <= 10) {
        // prompt user for input and obtain value from user
        cout << "Enter result (1 = pass, 2 = fail): ";
        int result = 0; // one exam result (1 = pass, 2 - fail)
        cin >> result;  // input result

        // if...else nested in while
        if (result == 1) // if result is 1,
            passes++;    // increment passes;
        else             // else result is not 1, so
            failures++;  // increment failures

        // increment studentCounter so loop eventually terminates
        studentCounter++;
    }

    // termination phase; display number of passes and failures
    cout << "Passed " << passes << "\nFailed " << failures << endl;

    // determine whether more than eight students passed
    if (passes > 8)
        cout << "Bonus to instructor!" << endl;

    return 0;
}
/* execution result 1
 * Enter result (1 = pass, 2 = fail): 1
 * Enter result (1 = pass, 2 = fail): 2
 * Enter result (1 = pass, 2 = fail): 2
 * Enter result (1 = pass, 2 = fail): 1
 * Enter result (1 = pass, 2 = fail): 1
 * Enter result (1 = pass, 2 = fail): 1
 * Enter result (1 = pass, 2 = fail): 2
 * Enter result (1 = pass, 2 = fail): 1
 * Enter result (1 = pass, 2 = fail): 1
 * Enter result (1 = pass, 2 = fail): 2
 * Passed 6
 * Failed 4
 */
/* execution result 2
 * Enter result (1 = pass, 2 = fail): 1
 * Enter result (1 = pass, 2 = fail): 1
 * Enter result (1 = pass, 2 = fail): 1
 * Enter result (1 = pass, 2 = fail): 1
 * Enter result (1 = pass, 2 = fail): 2
 * Enter result (1 = pass, 2 = fail): 1
 * Enter result (1 = pass, 2 = fail): 1
 * Enter result (1 = pass, 2 = fail): 1
 * Enter result (1 = pass, 2 = fail): 1
 * Enter result (1 = pass, 2 = fail): 1
 * Passed 9
 * Failed 1
 * Bonus to instructor!
 */
