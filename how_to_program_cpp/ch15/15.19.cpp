// Fig. 15.19: fig15_19.cpp
// Standard Library stack adapter class
#include <iostream>
#include <list>
#include <stack>
#include <vector>
// using namespace std;
using std::stack;

template <typename T> void pushElements(T &stackRef);
template <typename T> void popElements(T &stackRef);

int main() {
    stack<int> intDequeStack; // stack with default underlying deque
    stack<int, std::vector<int>> intVectorStack; // stack with underlying vector
    stack<int, std::list<int>> intListStack;     // stack with underlying list

    std::cout << "Pushing onto intDequeStack: ";
    pushElements(intDequeStack);
    std::cout << "\nPushing onto intVectorStack: ";
    pushElements(intVectorStack);
    std::cout << "\nPushing onto intListStack: ";
    pushElements(intListStack);
    std::cout.put('\n').put('\n');

    std::cout << "Popping from intDequeStack: ";
    popElements(intDequeStack);
    std::cout << "\nPopping from intVectorStack: ";
    popElements(intVectorStack);
    std::cout << "\nPopping from intListStack: ";
    popElements(intListStack);
    std::cout.put('\n').put('\n');

    return 0;
}

template <typename T> void pushElements(T &stackRef) {
    for (int i{0}; i < 10; ++i) {
        stackRef.push(i);                   // push element onto stack
        std::cout << stackRef.top() << ' '; // view (and display) top element
    }
}
template <typename T> void popElements(T &stackRef) {
    while (!stackRef.empty()) {
        std::cout << stackRef.top() << ' ';
        stackRef.pop(); // remove top element
    }
}

/* execution result
 * Pushing onto intDequeStack: 0 1 2 3 4 5 6 7 8 9
 * Pushing onto intVectorStack: 0 1 2 3 4 5 6 7 8 9
 * Pushing onto intListStack: 0 1 2 3 4 5 6 7 8 9
 *
 * Popping from intDequeStack: 9 8 7 6 5 4 3 2 1 0
 * Popping from intVectorStack: 9 8 7 6 5 4 3 2 1 0
 * Popping from intListStack: 9 8 7 6 5 4 3 2 1 0
 */
