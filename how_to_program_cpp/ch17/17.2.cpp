// Fig. 17.2: fig17_02.cpp
// Example that throws exception on attempts to divide by zero
#include "./DivideByZeroException.h"
#include <iostream>

double quotient(int numerator, int denominator) {
    if (denominator == 0)
        throw new DivideByZeroException;
    return static_cast<double>(numerator) / denominator;
}

int main() {
    int number1;
    int number2;

    std::cout << "Enter two integers (end-of-file to end): ";

    while (std::cin >> number1 >> number2) {
        try {
            double result = quotient(number1, number2);
            std::cout << "The quotient is: " << result << '\n';
        } catch (std::exception *ex) {
            DivideByZeroException *e =
                dynamic_cast<DivideByZeroException *>(ex);
            if (e)
                std::cout << "Exception occured: " << e->what() << '\n';
            delete ex;
            // } catch (DivideByZeroException &ex) {
            // std::cout << "Exception occured: " << ex.what() << '\n';
        }
        std::cout << "\nEnter two integers (end-of-file to end): ";
    }
    std::cout.put('\n');
}

/* execution result
Enter two integers (end-of-file to end): 100 7
The quotient is: 14.2857

Enter two integers (end-of-file to end): 100 0
Exception occured: attempted to divide by zero

Enter two integers (end-of-file to end): ^D
*/
