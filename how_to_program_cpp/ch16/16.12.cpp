// Fig. 16.12: fig16_12.cpp
// Algorithms make_heap, push_heap, pop_heap, sort_heap
#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <vector>

constexpr std::size_t SIZE{10};
using std::cout, std::copy, std::array, std::vector;
static std::ostream_iterator<int> output(std::cout, " ");

void line(std::array<int, SIZE> a, const char *const p) {
    std::cout << p;
    std::copy(a.cbegin(), a.cend(), output);
}

int main() {
    array<int, SIZE> init{3, 100, 52, 77, 22, 31, 1, 98, 13, 40};
    array<int, SIZE> a{init};

    line(a, "Array a before make_heap:\n");

    std::make_heap(a.begin(), a.end());
    line(a, "\nArray a after make_heap:\n");

    std::sort_heap(a.begin(), a.end());
    line(a, "\nArray a after sort_heap:\n");

    line(init, "\n\nArray init contains: ");
    cout.put('\n');

    vector<int> v;

    for (std::size_t i{0}; i < SIZE; ++i) {
        v.push_back(init[i]);
        std::push_heap(v.begin(), v.end());
        cout << "\nv after push_heap(init[" << i << "]): ";
        copy(v.cbegin(), v.cend(), output);
    }

    cout.put('\n');

    for (std::size_t j{0}; j < v.size(); ++j) {
        cout << "\nv after " << std::setw(3) << v[0] << " popped from heap: ";
        std::pop_heap(v.begin(), v.end() - j);
        copy(v.cbegin(), v.cend(), output);
    }

    cout.put('\n');
    return 0;
}

/* execution result
Array a before make_heap:
3 100 52 77 22 31 1 98 13 40
Array a after make_heap:
100 98 52 77 40 31 1 3 13 22
Array a after sort_heap:
1 3 13 22 31 40 52 77 98 100

Array init contains: 3 100 52 77 22 31 1 98 13 40

v after push_heap(init[0]): 3
v after push_heap(init[1]): 100 3
v after push_heap(init[2]): 100 3 52
v after push_heap(init[3]): 100 77 52 3
v after push_heap(init[4]): 100 77 52 3 22
v after push_heap(init[5]): 100 77 52 3 22 31
v after push_heap(init[6]): 100 77 52 3 22 31 1
v after push_heap(init[7]): 100 98 52 77 22 31 1 3
v after push_heap(init[8]): 100 98 52 77 22 31 1 3 13
v after push_heap(init[9]): 100 98 52 77 40 31 1 3 13 22

v after 100 popped from heap: 98 77 52 22 40 31 1 3 13 100
v after  98 popped from heap: 77 40 52 22 13 31 1 3 98 100
v after  77 popped from heap: 52 40 31 22 13 3 1 77 98 100
v after  52 popped from heap: 40 22 31 1 13 3 52 77 98 100
v after  40 popped from heap: 31 22 3 1 13 40 52 77 98 100
v after  31 popped from heap: 22 13 3 1 31 40 52 77 98 100
v after  22 popped from heap: 13 1 3 22 31 40 52 77 98 100
v after  13 popped from heap: 3 1 13 22 31 40 52 77 98 100
v after   3 popped from heap: 1 3 13 22 31 40 52 77 98 100
v after   1 popped from heap: 1 3 13 22 31 40 52 77 98 100
 */
