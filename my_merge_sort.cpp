// clang-format off
#include <array>
#include <iostream>
using namespace std;

template <typename aS> void merge_sort(aS &);
int *merge_sort_sub(int *const, const size_t);
void print_array(const int *, size_t);

int main(int argc, char **argv) {
    array<int, 6> arr1{7, 9, 1, 0, 7, 3};         merge_sort(arr1);
    array<int, 6> arr2{6, 5, 4, 3, 2, 1};         merge_sort(arr2);
    array<int, 6> arr3{13, -4, 5, 2, 9, 3};       merge_sort(arr3);
    array<int, 6> arr4{12, 11, 13, 5, 6, 7};      merge_sort(arr4);
    array<int, 12> arr5{92, 8, 123, 32, 4,
                        -1, -93, 9, 0, 23, 4, 9}; merge_sort(arr5);
    return 0;
}

template <typename aS> void merge_sort(aS &arr) {
    cout << "before: "; print_array(arr.data(), arr.size());
    merge_sort_sub(arr.data(), arr.size());
    cout << "sorted: "; print_array(arr.data(), arr.size());
    cout.put('\n');
}

int *merge_sort_sub(int *const p, const size_t size) {
    int *l, *r, lsize, rsize;

    if (size == 1) return p;
    else {
        lsize = size / 2;
        rsize = size - lsize;
        l = merge_sort_sub(p, lsize);
        r = merge_sort_sub(p + lsize, rsize);
    }

    int *tarr = new int[size]{};
    for (int i = 0; i < size; i++) {
        tarr[i] = (*l < *r) ? *l++ : *r++;
        if (l == p + lsize) {
            for (int j = i + 1; j < size; j++) tarr[j] = *r++;
            break;
        }
        if (r == p + size) {
            for (int j = i + 1; j < size; j++) tarr[j] = *l++;
            break;
        }
    }
    for (int i = 0; i < size; i++) *(p + i) = tarr[i];
    delete[] tarr;

    return p;
}

void print_array(const int *p, size_t s) {
    while (s--) cout << *p++ << ' ';
    cout.put('\n');
}
