// Fig. 15.21: fig15_21.cpp
// Standard Library priority_queue adapter class
#include <iostream>
#include <queue>
// using namespace std;

int main() {
    std::priority_queue<double> priorities;

    priorities.push(3.2);
    priorities.push(9.8);
    priorities.push(5.4);

    std::cout << "Popping from priorities: ";

    while (!priorities.empty()) {
        std::cout << priorities.top() << ' ';
        priorities.pop();
    }

    std::cout.put('\n');
}
/* execution result
 * Popping from priorities: 9.8 5.4 3.2
 */
