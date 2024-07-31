// Fig. 10.11: 10.11_Array.cpp
// Array class member- and friend- function definitions
#include "10.10_Array.h"
#include <iomanip>
#include <iostream>
#include <stdexcept>
using namespace std;

std::ostream &operator<<(std::ostream &output, const Array &a) {
    for (size_t i = 0; i < a.size; ++i) {
        output << setw(12) << a[i];
        if (!((i + 1) % 4) || i == a.size - 1)
            output << endl;
        // whether after 4 elements printed or the last element printed
    }
    return output;
}

std::istream &operator>>(std::istream &input, Array &a) {
    for (size_t i = 0; i < a.size; ++i)
        input >> a[i];
    return input;
}

Array::Array(int arraySize)
    : size(arraySize > 0
               ? arraySize
               : throw invalid_argument("Array size must be greater than 0")),
      ptr(new int[size]) {
    // 其實我唔知點解書要咁做，因為就算無都好，啲element 都係set 咗做0
    // for (size_t i = 0; i < size; ++i)
    //     ptr[i] = 0;
}

Array::Array(const Array &other) : Array(other.size) { *this = other; }

Array::~Array() { delete[] ptr; }

size_t Array::getSize() const { return size; }

const Array &Array::operator=(const Array &other) {
    if (&other != this) { // avoid self-assignment
        if (size != other.size) {
            delete[] ptr;
            size = other.size;
            ptr = new int[size];
        }
        for (size_t i = 0; i < size; ++i)
            (ptr)[i] = other[i];
    }
    return *this;
}

bool Array::operator==(const Array &other) const {
    bool ret = true;
    if (size == other.size) {
        for (size_t i = 0; i < size; ++i)
            if ((ptr)[i] != other[i])
                return !ret;
        return ret;
    } else
        return !ret;
}

int &Array::operator[](int x) {
    rangeCheck(x);
    return *(ptr + x);
}
int Array::operator[](int x) const {
    rangeCheck(x);
    return *(ptr + x);
}

void Array::rangeCheck(int x) const {
    if (x < 0 || x >= static_cast<int>(size))
        throw out_of_range("OUT OF MOTHERFUCKER RANGE");
}
