// Fig. 9.9: 9.9_main.cpp
// Order in which constructors and destructors are called
#include "9.7_CreateAndDestroy.h"
#include <iostream>
using namespace std;

void create(void);

CreateAndDestroy first(1, "(global before main)");

int main() {
    cout << "\nMAIN FUNCTION: EXECUTION BEGINS" << endl;
    CreateAndDestroy second(2, "(local automatic in main)");
    static CreateAndDestroy third(3, "(local static in main)");

    create();

    cout << "\nMAIN FUNCTION: EXECUTION RESUMES" << endl;
    CreateAndDestroy fourth(4, "(local automatic in main)");
    cout << "\nMAIN FUNCTION: EXECUTION ENDS" << endl;
    return 0;
}

void create(void) {
    cout << "\nCREATE FUNCTION: EXECUTION BEGINS" << endl;
    CreateAndDestroy fifth(5, "(local automatic in create)");
    static CreateAndDestroy sixth(6, "(local static in create)");
    CreateAndDestroy seventh(7, "(local automatic in create)");
    cout << "\nCREATE FUNCTION: EXECUTION ENDS" << endl;
}

/* execution result
 * Object 1 constructor runs    (global before main)
 *
 * MAIN FUNCTION: EXECUTION BEGINS
 * Object 2 constructor runs    (local automatic in main)
 * Object 3 constructor runs    (local static in main)
 *
 * CREATE FUNCTION: EXECUTION BEGINS
 * Object 5 constructor runs    (local automatic in create)
 * Object 6 constructor runs    (local static in create)
 * Object 7 construction runs   (local automatic in create)
 *
 * CREATE FUNCTION: EXECUTION ENDS
 * Object 7 destructors runs    (local automatic in create)
 * Object 5 destructors runs    (local automatic in create)
 *
 * MAIN FUNCTION: EXECUTION RESUMES
 * Object 4 constructor runs    (local automatic in main)
 *
 * MAIN FUNCTION: EXECUTION ENDS
 * Object 4 destructors runs    (local automatic in main)
 * Object 2 destructors runs    (local automatic in main)
 *
 * Object 6 destructors runs    (local static in create)
 * Object 3 destructors runs    (local static in main)
 *
 * Object 1 destructors runs    (global before main)
 */
