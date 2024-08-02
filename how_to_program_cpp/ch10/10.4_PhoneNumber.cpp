// Fig. 10.4: 10.4_PhoneNumber.cpp
// Overloaded stream insertion and stream extraction operators for class
// PhoneNumber
#include "10.3_PhoneNumber.h"
#include <iomanip>
using namespace std;

ostream &operator<<(ostream &output, const PhoneNumber &number) {
    output << '(' << number.areaCode << ") " << number.exchange << '-'
           << number.line;
    return output;
}

istream &operator>>(istream &input, PhoneNumber &number) {
    input.ignore(); // skip (
    input >> setw(3) >> number.areaCode;
    input.ignore(2); // skip ) and space
    input >> setw(3) >> number.exchange;
    input.ignore(); // skip dash (-)
    input >> setw(4) >> number.line;
    return input;
}
