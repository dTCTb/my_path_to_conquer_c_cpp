#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    static int maximumSwap(int num) noexcept {
        string str{to_string(num)};

        char max{str.back()};
        size_t max_i{str.size() - 1}, swap_i{}, swap_j{str.size() - 1};
        for (int i{(int)str.size() - 1}; i >= 0; --i) {
            if (str[i] > max) {
                max = str[i];
                max_i = i;
            } else {
                swap_i = str[i] <= str[swap_i] ? i : swap_i;
                swap_j = max_i;
            }
        }
        char tmp = str[swap_i];
        str[swap_i] = str[swap_j];
        str[swap_j] = tmp;
        return stoi(str);
    }
};

int main(int argc, char **argv) {
    // Solution::maximumSwap(98368);
    Solution::maximumSwap(98800435);
}
