#include <algorithm>
#include <array>
#include <iostream>
#include <numeric>

int main() {
    std::array<int, 100> arr{};
    std::iota(arr.begin(), arr.end(), 0);
    const int window{4};
    int new_r{}, new_l{}, inc{};
    for (size_t i{}; i < arr.size(); i = new_r) {
        int cur_l = i < 4 ? 0 : i - window + 1;
        int cur_r = i;

        std::cout.put('[');
        for (int from{cur_l}; from <= cur_r; ++from)
            std::cout << arr[from] << ' ';
        std::cout << "\b]\t";
        std::cin >> inc;
        if (!std::cin.good())
            break;
        if (i + inc < 0)
            i = -inc;
        if (i + inc >= arr.size())
            i = arr.size() - 1 - inc;

        int offset = (inc - window >= 0) ? inc - window : 0;
        new_r = i + inc;
        new_l = new_r - window + 1;

        // new item added to window
        std::cout << "(+ ";
        for (int from{cur_r + 1 + offset}; from <= new_r; ++from)
            std::cout << arr[from] << ' ';
        std::cout << "\b)\n";

        // old item removed from window
        std::cout << "(- ";
        for (int from{cur_r < window ? 0 : cur_r - window + 1};
             from <= new_r - window - offset; ++from)
            std::cout << arr[from] << ' ';
        std::cout << "\b)\n";
    }
}
