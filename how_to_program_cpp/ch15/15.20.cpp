// Fig. 15.20: fig15_20.cpp
// Standard Library queue adapter class template
#include <iostream>
#include <queue>
// using namespace std;

int main() {
    std::queue<double> values;

    values.push(3.2);
    values.push(9.8);
    values.push(5.4);

    std::cout << "Popping from values: ";

    while (!values.empty()) {
        std::cout << values.front() << ' ';
        values.pop();
    }

    std::cout.put('\n');
}
/* execution result
 * Popping from values: 3.2 9.8 5.4
 */
