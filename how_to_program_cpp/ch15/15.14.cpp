// Fig. 15.14: fig15_14.cpp
// Standard Library deque class template
#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
using namespace std;

int main() {
    std::deque<double> values;
    std::ostream_iterator<double> output(std::cout, " ");

    values.push_front(2.2);
    values.push_front(3.5);
    values.push_back(1.1);

    std::cout << "values contains: ";

    for (size_t i = 0; i < values.size(); ++i)
        std::cout << values[i] << ' ';

    values.pop_front();
    std::cout << "\nAfter pop_front(), values contains: ";
    std::copy(values.cbegin(), values.cend(), output);

    values[1] = 5.4;
    std::cout << "\nAfter values[1] = 5.4, values contains: ";
    std::copy(values.cbegin(), values.cend(), output);
    std::cout.put('\n');

    return 0;
}
/* execution result
 * values contains: 3.5 2.2 1.1
 * After pop_front(), values contains: 2.2 1.1
 * After values[1] = 5.4, values contains: 2.2 5.4
 */
