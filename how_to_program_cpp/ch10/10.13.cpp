// clang-format off
// Fig. 10.12: fig10_12.cpp
// Single-argument constructors and implicit conversions
// Fig. 10.13: fig10_13.cpp
// Demonstrating an explicit constructor
#include <iomanip>
#include <iostream>
using namespace std;
class Array {
    friend ostream &operator<<(ostream &, const Array &);
  public:
// # define EXPLICIT // <-- TOGGLE THIS LINE
#ifndef EXPLICIT
    Array(int arraySize = 10)
#else
    explicit Array(int arraySize = 10)
#endif
        : size(arraySize), ptr(new int[size]) {}
    ~Array() { delete[] ptr; }
    size_t getSize() const { return size; }
    int operator[](int x) const { return *(ptr + x); }
  private:
    size_t size;
    int *ptr;
};

ostream &operator<<(ostream &output, const Array &a) {
    for (size_t i = 0; i < a.size; ++i) {
        output << setw(12) << a[i];
        if (!((i + 1) % 4) || i == a.size - 1) output << endl; }
    return output;
}

void outputArray(const Array &a);
int main() {
    Array integers1(7);
    outputArray(integers1); // output Array integers1
#ifndef EXPLICIT
    outputArray(3); // implicitly convert 3 to an Array and output Array's contents
                    // const Array &a = 3 <-> const Array &a = Array(3)
#else
    outputArray(Array(3));  // explicit single-argument constructor call
#endif
    return 0;
}

void outputArray(const Array &a) {
    cout << "The Array received has " << a.getSize()
         << " elements. The contents are:\n" << a << endl;
}
