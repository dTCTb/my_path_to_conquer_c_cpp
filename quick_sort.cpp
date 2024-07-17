#include <array>
#include <iostream>
using namespace std;

template <typename a> void print_arr(a arr) {
    for (int val : arr)
        cout << val << ' ';
    cout.put('\n');
}

template <typename a, typename t> void arr_swap(a &arr, t &x, t &y) {
    t tmp = arr[x];
    arr[x] = arr[y];
    arr[y] = tmp;
}

template <typename a> void quick_sort(a &arr, int start, int pivot) {
    bool printed = false;
    if (pivot == start)
        return;
    int i = start - 1, j = start;
    while (j < pivot) {
        if (arr[j] <= arr[pivot]) {
            i++;
            if (i != j)
                if (!printed) {
                    arr_swap(arr, i, j);
                    printed = true;
                }
        }
        j++;
        if (!printed) {
            print_arr(arr);
            printed = true;
        }
    }
    // here got problem
    if (arr[++i] > arr[pivot]) {
        arr_swap(arr, i, pivot);
        quick_sort(arr, 0, i);
        quick_sort(arr, i + 1, arr.size() - 1);
    } else {
        quick_sort(arr, 0, pivot - 1);
        quick_sort(arr, pivot + 1, arr.size() - 1);
    }

    print_arr(arr);
}

int main() {
    // array<int, 6> arr{7, 9, 2, 3, 1, 8};
    array<int, 6> arr{1, 9, 5, 3, 6, 3};
    // array<float, 9> arr{1.1, 9.3, 4.3, 9.1, 7.1, 6.6, 8.4, 4.3, 2.7};
    quick_sort(arr, 0, arr.size() - 1);
    // int pivot = arr.size() - 1;
    return 0;
}
