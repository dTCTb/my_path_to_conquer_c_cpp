// Fig. 6.13: fig06_13.cpp
// Scping example.
#include <iostream>
using namespace std;

void useLocal();
void useStaticLocal();
void useGlobal();

int x = 1; // global variable

int main() {
    cout << "global x in main is " << x << endl;

    int x = 5; // local variable to main

    cout << "local x in main's outer scope is " << x << endl;

    {              // start new scope
        int x = 7; // hides both x in outer scope and global x
        cout << "local x in main's inner scope is " << x << endl;
    } // end new scope

    cout << "local x in main's outer scope is " << x << endl;

    useLocal();       // useLocal has local x
    useStaticLocal(); // useStaticLocal has static local x
    useGlobal();      // useGlobal uses global x
    useLocal();       // useLocal reinitializes its local x
    useStaticLocal(); // static local x retains its prior value
    useGlobal();      // global x also retains its prior value

    cout << "\nlocal x in main is " << x << endl;
}

// useLocal reinitializes local variable x during each call
void useLocal() {
    int x = 25; // initialized each time useLocal is called
    cout << "\nlocal x is " << x << " on entering useLocal" << endl;
    ++x;
    cout << "local x is " << x << " on exiting useLocal" << endl;
}

/* useStaticLocal initialized static local variable x only the first time the
 * function is called; value of x is saved between calls to this function */
void useStaticLocal() {
    static int x = 50; // initialized first time useStaticLocal is called
    cout << "\nlocal static x is " << x << " on entering useStaticLocal"
         << endl;
    ++x;
    cout << "local static x is " << x << " on exiting useStaticLocal" << endl;
}

// useGlobal modifies global variable x during each call
void useGlobal() {
    cout << "\nglobal x is " << x << " on entering useGlobal" << endl;
    x *= 10;
    cout << "global x is " << x << " on exiting useGlobal" << endl;
}

/* execution result
 * global x in main is 1
 * local x in main's outer scope is 5
 * local x in main's inner scope is 7
 * local x in main's outer scope is 5
 *
 * local x is 25 on entering useLocal
 * local x is 26 on exiting useLocal
 *
 * local static x is 50 on entering useStaticLocal
 * local static x is 51 on exiting useStaticLocal
 *
 * global x is 1 on entering useGlobal
 * global x is 10 on exiting useGlobal
 *
 * local x is 25 on entering useLocal
 * local x is 26 on exiting useLocal
 *
 * local static x is 51 on entering useStaticLocal
 * local static x is 52 on exiting useStaticLocal
 *
 * global x is 10 on entering useGlobal
 * global x is 100 on exiting useGlobal
 *
 * local x in main is 5
 */
