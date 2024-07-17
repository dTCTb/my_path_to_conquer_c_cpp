// clang-format off
#include <array>
#include <iomanip>
#include <iostream>
using namespace std;
int count = 0;

template <typename a> void print_arr(a arr) {
    for (auto val : arr) cout << setprecision(2) << fixed << val << ' ';
    cout.put('\n');
}

template <typename a, typename t> void arr_swap(a &arr, t &x, t &y) {
    t tmp = arr[x];
    arr[x] = arr[y];
    arr[y] = tmp;
}

template <typename a> void quick_sort_sub(a &arr, int left, int pivot) {
    int p = left - 1;
    while (left <= pivot) {
        if (arr[left] <= arr[pivot]) {
            if (++p != left) arr_swap(arr, p, left);
        }
        left++;
    }
    if (p == --left) return;
    print_arr(arr);
    quick_sort_sub(arr, 0, p - 1);
    quick_sort_sub(arr, p + 1, left);
}

template <typename a>void quick_sort(a &arr) {
    cout << ++::count << ".\n";
    cout << "before: "; print_arr(arr);
    quick_sort_sub(arr, 0, arr.size() - 1);
    cout << " after: "; print_arr(arr);
    cout.put('\n');
}

int main() {
    array<int, 6> arr1{7, 9, 2, 3, 1, 8};  quick_sort(arr1);
    array<int, 6> arr2{1, 9, 5, 3, 6, 3};  quick_sort(arr2);
    array<double, 9> arr3{1.1, 9.3, 4.3,
           9.1, 7.1, 6.6, 8.4, 4.3, 2.7};  quick_sort(arr3);
    array<int, 5> arr4{30, 9, 46, 14, 22}; quick_sort(arr4);
    array<int, 8> arr5{5, 2, 7, 6, 1, 9, 4, 8}; quick_sort(arr5); // <-- only this has issue
    array<int, 6> arr6{55, 21, 77, 68, 32, 4}; quick_sort(arr6);
    array<int, 6> arr7{-1, 5, 12, -10, 15, 33}; quick_sort(arr7); // <-- this only got problem
    array<int, 5> arr8{4, 1, 3, 9, 7}; quick_sort(arr8);
    array<int, 9> arr9{2, 1, 6, 10, 4, 1, 3, 9, 7}; quick_sort(arr9);
    return 0;
}
/* execution result
* 1.
* before: 7 9 2 3 1 8 
* 7 2 3 1 8 9 
* 1 2 3 7 8 9 
*  after: 1 2 3 7 8 9 
* 
* 2.
* before: 1 9 5 3 6 3 
* 1 3 3 9 6 5 
* 1 3 3 5 6 9 
*  after: 1 3 3 5 6 9 
* 
* 3.
* before: 1.10 9.30 4.30 9.10 7.10 6.60 8.40 4.30 2.70 
* 1.10 2.70 4.30 9.10 7.10 6.60 8.40 4.30 9.00 
* 1.10 2.70 4.30 7.10 6.60 8.40 4.30 9.00 9.00 
* 1.10 2.70 4.30 4.30 6.60 8.40 7.00 9.00 9.00 
* 1.10 2.70 4.30 4.30 6.60 7.00 8.00 9.00 9.00 
*  after: 1.10 2.70 4.30 4.30 6.60 7.00 8.00 9.00 9.00 
* 
* 4.
* before: 30 9 46 14 22 
* 9 14 22 30 46 
*  after: 9 14 22 30 46 
* 
* 5.
* before: 5 2 7 6 1 9 4 8 
* 5 2 7 6 1 4 8 9 
* 2 1 4 6 5 7 8 9 
* 1 2 4 6 5 7 8 9 
*  after: 1 2 4 6 5 7 8 9 
* 
* 6.
* before: 55 21 77 68 32 4 
* 4 21 77 68 32 55 
* 4 21 32 55 77 68 
* 4 21 32 55 68 77 
*  after: 4 21 32 55 68 77 
* 
* 7.
* before: -1 5 12 -10 15 33 
*  after: -1 5 12 -10 15 33 
* 
* 8.
* before: 4 1 3 9 7 
* 4 1 3 7 9 
* 1 3 4 7 9 
*  after: 1 3 4 7 9 
* 
* 9.
* before: 2 1 6 10 4 1 3 9 7 
* 2 1 6 4 1 3 7 9 10 
* 2 1 1 3 6 4 7 9 10 
* 1 1 2 3 6 4 7 9 10 
* 1 1 2 3 4 6 7 9 10 
*  after: 1 1 2 3 4 6 7 9 10 
*/
