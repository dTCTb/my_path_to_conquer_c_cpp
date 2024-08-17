// Fig. 15.4: fig15_04.cpp
// Demonstrating input and output with iterators
#include <iostream>
#include <iterator>
using namespace std;
// 咪撚睇啲英文comment，本on9 書完全講錯曬每個statement。
int main() {
    std::cout << "Enter two integers: ";

    // create istream_iterator for reading int values from cin
    std::istream_iterator<int> inputInt{cin}; // 真正嘅read operation 喺呢度發生

    int number1{*inputInt}; // read int from standard input
                            // 呢度只係return 一個啱啱讀取咗嘅值
    ++inputInt; // move iterator to next input value // 呢度++ 會再讀取另一個值
    int number2{*inputInt}; // read int from standard input

    // create ostream_iterator for writing int values to cout
    std::ostream_iterator<int> outputInt{cout};

    std::cout << "The sum is: ";
    *outputInt = number1 + number2; // output result to cout
                                    // 就算無dereference 都output 到
    std::cout << endl;
}
