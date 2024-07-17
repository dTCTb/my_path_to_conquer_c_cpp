// clang-format off
#include <array>
#include <iomanip>
#include <iostream>
using namespace std;

// testing array in correct ascending order
array<int, 6> arr1{1, 2, 3, 7, 8, 9};
array<int, 6> arr2{1, 3, 3, 5, 6, 9};
array<double, 9> arr3{1.10, 2.00, 4.00,
       4.00, 6.60, 7.00, 8.00, 9.00, 9.00};
array<int, 5> arr4{9, 14, 22, 30, 46};
array<int, 8> arr5{1, 2, 4, 5, 6, 7, 8, 9};
array<int, 6> arr6{4, 21, 32, 55, 68, 77};
array<int, 6> arr7{-10, -1, 5, 12, 15, 33};
array<int, 5> arr8{1, 3, 4, 7, 9};
array<int, 9> arr9{1, 1, 2, 3, 4, 6, 7, 9, 10};
// global counter for testing count
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

template <typename a> void quick_sort_post(a &arr, int left, int pivot) {
    int p = left - 1;
    while (left <= pivot) {
        if (arr[left] <= arr[pivot]) {
            if (++p != left) arr_swap(arr, p, left);
        }
        left++;
    }
    if (p == --left) return;
    print_arr(arr);
    quick_sort_post(arr, 0, p - 1);
    quick_sort_post(arr, p + 1, left);
}

template <typename a> void quick_sort_mid(a &arr, int left, int right) {
    int l = left;
    int r = right;
    int m = (l + r) /2; // pivot
    while (arr[l] < arr[m]) l++; // find out the value > arr[m]
    while (arr[r] > arr[m]) r--; // find out the value < arr[m]
    arr_swap(arr, l, r);
    // print_arr(arr);
    if (--r > left)  quick_sort_mid(arr, left, r);
    if (++l < right) quick_sort_mid(arr, l, right);
}

template <typename a>void quick_sort(a &arr, int m) {
    cout << ++::count << ".\n";
    cout << "before: "; print_arr(arr);
    switch (m) {
        case 0:
            // there is a method that pivot at the beginning
            break;
        case 1:
            quick_sort_mid(arr, 0, arr.size() - 1);
            break;
        case 2:
            quick_sort_post(arr, 0, arr.size() - 1);
            break;
        default:
            cout << "0:pre (not available yet), 1:mid, 2:post" << endl;
            return;
    }
    cout << " after: "; print_arr(arr);
}

template <typename a> void assert(a &arr, a &ans) {
    if (arr == ans) cout << "Correct" << endl;
}

int main() {
    array<int, 6> arr1{7, 9, 2, 3, 1, 8};           quick_sort(arr1, 1); assert(arr1, ::arr1);
    array<int, 6> arr2{1, 9, 5, 3, 6, 3};           quick_sort(arr2, 1); assert(arr2, ::arr2);
    array<double, 9> arr3{1.1, 9.3, 4.3,
           9.1, 7.1, 6.6, 8.4, 4.3, 2.7};           quick_sort(arr3, 1); assert(arr3, ::arr3);
    array<int, 5> arr4{30, 9, 46, 14, 22};          quick_sort(arr4, 1); assert(arr4, ::arr4);
    array<int, 8> arr5{5, 2, 7, 6, 1, 9, 4, 8};     quick_sort(arr5, 1); // <-- has issue when using 0
                                                                         assert(arr5, ::arr5);
    array<int, 6> arr6{55, 21, 77, 68, 32, 4};      quick_sort(arr6, 1); assert(arr6, ::arr6);
    array<int, 6> arr7{-1, 5, 12, -10, 15, 33};     quick_sort(arr7, 1); // <-- got problem when using 0
                                                                         assert(arr7, ::arr7);
    array<int, 5> arr8{4, 1, 3, 9, 7};              quick_sort(arr8, 1); assert(arr8, ::arr8);
    array<int, 9> arr9{2, 1, 6, 10, 4, 1, 3, 9, 7}; quick_sort(arr9, 1); assert(arr9, ::arr9);
    return 0;
}

