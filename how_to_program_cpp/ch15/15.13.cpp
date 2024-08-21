// Fig. 15.13: fig15_13.cpp
// Standard library list class template
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <list>
// using namespace std;

template <typename T> void printList(const std::list<T> &listRef);

int main() {
    constexpr size_t SIZE{4};
    std::array<int, SIZE> ints{2, 6, 4, 8};
    std::list<int> values;
    std::list<int> otherValues;

    values.push_front(1);
    values.push_front(2);
    values.push_back(4);
    values.push_back(3);

    std::cout << "values contains: ";
    printList(values);

    values.sort();
    std::cout << "\nvalues after sorting contains: ";
    printList(values);

    otherValues.insert(otherValues.cbegin(), ints.cbegin(), ints.cend());
    std::cout << "\nAfter insert, otherValues contains: ";
    printList(otherValues);

    values.splice(values.cend(), otherValues);
    std::cout << "\nAfter splice, values contains: ";
    printList(values);

    values.sort();
    std::cout << "\nAfter sort, values contains: ";
    printList(values);

    otherValues.insert(otherValues.cbegin(), ints.cbegin(), ints.cend());
    otherValues.sort();
    std::cout << "\nAfter insert and sort, otherValues contains: ";
    printList(otherValues);

    values.merge(otherValues);
    std::cout << "\nAfter merge:\n   values contains: ";
    printList(values);
    std::cout << "\n   otherValues contains: ";
    printList(otherValues);

    values.pop_front();
    values.pop_back();
    std::cout << "\nAfter pop_front and pop_back:\n   values contains: ";
    printList(values);

    values.unique();
    std::cout << "\nAfter unique, values contains: ";
    printList(values);

    values.swap(otherValues);
    std::cout << "\nAfter swap:\n   values contains: ";
    printList(values);
    std::cout << "\n   otherValues contains: ";
    printList(otherValues);

    values.assign(otherValues.cbegin(), otherValues.cend());
    std::cout << "\nAfter assign, values contains: ";
    printList(values);

    values.merge(otherValues);
    std::cout << "\nAfter merge, values contains: ";
    printList(values);

    values.remove(4);
    std::cout << "\nAfter remove(4), values contains: ";
    printList(values);

    std::cout.put('\n');
}

template <typename T> void printList(const std::list<T> &listRef) {
    if (listRef.empty())
        std::cout << "List is empty";
    else {
        std::ostream_iterator<T> output(std::cout, " ");
        copy(listRef.cbegin(), listRef.cend(), output);
    }
}

/* execution result
values contains: 2 1 4 3
values after sorting contains: 1 2 3 4
After insert, otherValues contains: 2 6 4 8
After splice, values contains: 1 2 3 4 2 6 4 8
After sort, values contains: 1 2 2 3 4 4 6 8
After insert and sort, otherValues contains: 2 4 6 8
After merge:
   values contains: 1 2 2 2 3 4 4 4 6 6 8 8
   otherValues contains: List is empty
After pop_front and pop_back:
   values contains: 2 2 2 3 4 4 4 6 6 8
After unique, values contains: 2 3 4 6 8
After swap:
   values contains: List is empty
   otherValues contains: 2 3 4 6 8
After assign, values contains: 2 3 4 6 8
After merge, values contains: 2 2 3 3 4 4 6 6 8 8
After remove(4), values contains: 2 2 3 3 6 6 8 8
 */
