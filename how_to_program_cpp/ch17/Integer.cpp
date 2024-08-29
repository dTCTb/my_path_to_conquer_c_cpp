// Fig. 17.8: Integer.cpp
// Integer member function definitions
#include "./Integer.h"
#include <iostream>

Integer::Integer(int i) : value{i} {
    std::cout << "Constructor for Integer " << this->value << '\n';
}

Integer::~Integer() {
    std::cout << "Destructor for Integer " << this->value << '\n';
}

void Integer::setInteger(int i) { this->value = i; }

int Integer::getInteger() const { return this->value; }
