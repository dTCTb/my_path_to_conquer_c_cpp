// clang-format off
// Fig. 16.10: fig16_10.cpp
// Algorithms includes, set_difference, set_intersection,
// set_symmetric_difference and set_union
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>

using std::array;
constexpr size_t SIZE1{10}, SIZE2{5}, SIZE3{20};
std::ostream_iterator<int> output{std::cout, " "};

template <typename T> void prompt(T arr, const char *const p) {
    std::cout << p;
    std::copy(arr.cbegin(), arr.cend(), output);
}
template <typename Iter>
void prompt(Iter begin, Iter end, const char *const p) {
    std::cout << p;
    std::copy(begin, end, output);
}

int main() {
    array<int, SIZE1> a1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    array<int, SIZE2> a2{4, 5, 6, 7, 8};
    array<int, SIZE3> a3{4, 5, 6, 11, 15};

    prompt(a1,   "a1 contains: ");
    prompt(a2, "\na2 contains: ");
    prompt(a3, "\na3 contains: ");

    // std::includes
    if (std::includes(a1.cbegin(), a1.cend(), a2.cbegin(), a2.cend()))
         std::cout << "\n\na1 includes a2";
    else std::cout << "\n\na1 does not include a2";

    if (std::includes(a1.cbegin(), a1.cend(), a3.cbegin(), a3.cend()))
         std::cout << "\na1 includes a3";
    else std::cout << "\na1 does not include a3";

    // std::set_difference
    array<int, SIZE1> difference;
    array<int, SIZE1>::const_iterator result1 = std::set_difference(
        a1.cbegin(), a1.cend(), a2.cbegin(), a2.cend(), difference.begin());
    prompt(difference.cbegin(), result1, "\n\nset_difference of a1 and a2 is: ");

    // std::set_intersection
    array<int, SIZE1> intersection;
    array<int, SIZE1>::const_iterator result2 = std::set_intersection(
        a1.cbegin(), a1.cend(), a2.cbegin(), a2.cend(), intersection.begin());
    prompt(intersection.cbegin(), result2, "\n\nset_intersection of a1 and a2 is: ");

    /* 下面兩個例子我用咗std::find_if，因為同本書出嚟嘅result 唔同
     * 我懷疑因為版本唔同algorithm 嘅implementation 都唔同咗？！
     * 因為我睇documentation 如果A比B短，最後係會std::copy 剩低喺B嘅
     * 所有元素，而且係根據begin() 同end()。以std::set_symmetric_difference 為例
     * a1 有10個，a2 有20個，當複製咗1, 2, 3, 7, 8, 9, 10 之後
     * 到咗a1 嘅盡頭，而呢個時刻a3 已經有7個元素，而剩低喺a2 嘅有2?
     * 錯！係有20 - 3 = 17 個，當中係11 , 15, 同15個0
     * 所以到最後，a3 係有17 + 7 = 24 個，所以就會print 咗：
     * 1 2 3 7 8 9 10 11 15 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
     * 但問題係，啲code 同書無咩唔同，但書就無print 到任何0，到15 就停咗。
     */

    // std::set_symmetric_difference
    array<int, SIZE1 + SIZE2> symmetric_difference;
    [[maybe_unused]] array<int, SIZE1 + SIZE2>::const_iterator result3 =
        std::set_symmetric_difference(a1.cbegin(), a1.cend(),
                                      a3.cbegin(), a3.cend(), symmetric_difference.begin());
    const int * newEnd = std::find_if(
        symmetric_difference.cbegin(), symmetric_difference.cend(), [](int x) { return x == 0; });
    prompt(symmetric_difference.cbegin(), newEnd,
           "\n\nset_symmetric_difference of a1 and a3 is: ");

    // std::set_union
    array<int, SIZE3> unionSet;
    [[maybe_unused]] array<int, SIZE3>::const_iterator result4 = std::set_union(
        a1.cbegin(), a1.cend(), a3.cbegin(), a3.cend(), unionSet.begin());
    newEnd = std::find_if(
        unionSet.cbegin(), unionSet.cend(), [](int x) { return x == 0; });
    prompt(unionSet.cbegin(), newEnd, "\n\nset_union of a1 and a3 is: ");

    std::cout.put('\n');
}

/* execution result
a1 contains: 1 2 3 4 5 6 7 8 9 10 
a2 contains: 4 5 6 7 8 
a3 contains: 4 5 6 11 15 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 

a1 includes a2
a1 does not include a3

set_difference of a1 and a2 is: 1 2 3 9 10 

set_intersection of a1 and a2 is: 4 5 6 7 8 

set_symmetric_difference of a1 and a3 is: 1 2 3 7 8 9 10 11 15 

set_union of a1 and a3 is: 1 2 3 4 5 6 7 8 9 10 11 15 
 */
