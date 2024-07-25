#include <iostream>
using namespace std;
int x = 5, y; // global variable

// 8.10: Attempting to modify data via a nonconstant pointer to constant data
void NONConst_ptr_n_Const_data() {
    /* constant variable cannot be modified through ptr */
    const int *ptr = &x;
    *ptr = 7; // error: cannot modify a const object
    ptr = &y;
}

// 8.11: Attempting to modify a constant pointer to nonconstant data
void Const_ptr_n_NONConst_data() {
    /* ptr is a constant pointer to an integer that can be modified via ptr, but
     * ptr always points to the same memory location. */
    int *const ptr = &x;
    *ptr = 7;
    ptr = &y; // error: ptr is const; cannot assign to it a new address
}

// 8.12: Attempting to modify a constant pointer to constant data
void Const_ptr_n_Const_data() {
    /* ptr is a constant pointer to a constant integer.
     * ptr always points to the same location; the integer at that location
     * cannot be modified. */
    const int *const ptr = &x;
    cout << *ptr << endl;
    *ptr = 7; // error: *ptr is const; cannot assign new value
    ptr = &y; // error: ptr is const; cannot assign new address
}
