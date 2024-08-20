#include <algorithm>
#include <array>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <utility>

static bool print_once = true;

template <typename T>
constexpr std::pair<T, bool> bs(std::array<T, 9> &arr, int il, int ir, T t) {
    std::pair<int, bool> ret;
    int im = (il + ir) / 2;

    if (arr[im] == t)
        return {im, true};

    // il to im
    if (arr[im] > t && --im >= il)
        ret = bs(arr, il, im, t);

    // im to ir
    if (arr[im] < t && ++im <= ir)
        ret = bs(arr, im + 1, ir, t);

    return (ret.second ? ret : std::pair(0, false));
}

template <typename T> inline void print_arr(std::array<T, 9> &arr) {
    std::ostream_iterator<T> fo(std::cout, " ");
    std::copy(arr.cbegin(), arr.cend(), fo);
    std::cout.put('\n');
}

template <typename T> void unit_test(std::array<T, 9> &arr, T target) {
    if (print_once) {
        print_arr(arr);
        print_once = false;
    }

    std::pair<T, bool> ret = bs(arr, 0, 8, target);
    std::cout << "target: " << std::setw(2) << target << " at " << '['
              << (ret.second ? ret.first : 0) << "]\n";
}

int main() {
    std::array<int, 9> arr{1, 2, 3, 6, 7, 9, 11, 12, 20};
    // std::array<double, 9> arr{1, 2, 3, 6, 7, 9, 11, 12, 20};
    unit_test(arr, 2);
    unit_test(arr, 11);
    unit_test(arr, 7);
    unit_test(arr, 22);
    unit_test(arr, 20);
    return 0;
}
