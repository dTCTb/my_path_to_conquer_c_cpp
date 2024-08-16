// Fig. 15.4: fig15_04.cpp
// Demonstrating input and output with iterators
#include <iostream>
#include <iterator>
using namespace std;

int main() {
    std::cout << "Enter two integers: ";

    // create istream_iterator for reading int values from cin
    std::istream_iterator<int> inputInt{cin};

    int number1{*inputInt}; // read int from standard input
    ++inputInt;             // move iterator to next input value
    int number2{*inputInt}; // read int from standard input

    // create ostream_iterator for writing int values to cout
    std::ostream_iterator<int> outputInt{cout};

    std::cout << "The sum is: ";
    *outputInt = number1 + number2; // output result to cout
    std::cout << endl;
}
