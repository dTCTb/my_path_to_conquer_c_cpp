#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
class Solution {
  public:
    static bool doesValidArrayExist(const vInt &derived) noexcept {
        return solve2(derived);
    }
    /* 12ms 264.99mb */
    static bool solve1(const vInt &derived) noexcept {
        const vInt &der{derived};

        bitset<100'001> ori{};
        size_t size{der.size()};

        if (size == 1)
            return !der.front();

        if (der.back())
            ori[size - 1] = 1;
        else // i.e. 0, then original front & back must 1 or 0
            ori[0] = ori[size - 1] = 1;

        cout << ori << '\n'; // ! reserved order after printing out

        for (size_t i{}; i < size - 2; ++i)
            if (der[i])
                ori[i + 1] = !ori[i];
            else
                ori[i + 1] = ori[i];

        cout << ori << '\n';

        return (ori[size - 2] ^ ori[size - 1]) == der[size - 2];
    }

    /* cumulative XOR */
    static bool solve2(const vInt &derived) noexcept {
        int XOR{};
        for (const int e : derived)
            XOR = XOR ^ e;
        cout << "ans: " << (XOR == 0) << '\n';
        return XOR == 0;
    }
};

int main() {
    auto test = bind(Solution::doesValidArrayExist, placeholders::_1);
    test(vInt{1, 1, 0}); // true
    test(vInt{1, 1});    // true
    test(vInt{1, 0});    // false
}
