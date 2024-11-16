#include <iostream>
#include <vector>

using namespace std;
using namespace placeholders;

typedef std::vector<int> vInt;
typedef std::tuple<int, std::vector<int>, int, std::vector<int>> testcase;

class Solution {
  public:
    static vInt resultsArray(vInt &nums, int k) noexcept {
        int numsSize{static_cast<int>(nums.size())};
        int wSize{k - 1}; // indexing problem
        vInt ans{};
        ans.reserve(numsSize - k + 1);

        for (int i{}, j{}, c{}; j < numsSize; ++j) {
            if (j > 0)
                c += nums[j] - nums[j - 1] == 1 ? 1 : -1;

            if (j - i > wSize) // sliding window when member exceed k
                (c += nums[i + 1] - nums[i] == 1 ? -1 : 1), ++i;

            if (j - i == wSize) // processing when window member == k
                c == k - 1 ? ans.push_back(nums[j]) : ans.push_back(-1);
        }

        return ans;
    }
};

auto test = bind(Solution::resultsArray, _1, _2);

template <typename T>
std::ostream &operator<<(std::ostream &c, const std::vector<T> &arr) noexcept {
    if (arr.empty())
        return (c << "[]"), c;

    c << '[';
    for (const T &col : arr)
        c << col << ',';
    c << "\b]";

    return c;
}

ostream &operator<<(ostream &c, testcase &t) {
    auto &[no, nums, k, ans] = t;
    c << "- -- - -- -" << "\nTestcase " << no << '\n';
    c << "           " << nums << ", k = " << k << '\n';
    c << "   Answer: " << ans << '\n';
    vInt myAns{test(nums, k)};
    c << "My Answer: " << myAns << '\n';
    return c;
}

int main() {
    // testcase _{no : int, nums : vector<int>, k : int, ans : vector<int>};
    testcase e1{1, {1, 2, 3, 4, 3, 2, 5}, 3, {3, 4, -1, -1, -1}};
    testcase e2{2, {2, 2, 2, 2, 2}, 4, {-1, -1}};
    testcase e3{3, {3, 2, 3, 2, 3, 2}, 2, {-1, 3, -1, 3, -1}};
    testcase e4{4, {1}, 1, {1}};
    testcase e5{5, {1, 1, 1, 2}, 2, {-1, -1, 2}};
    testcase e6{6, {1, 2, 2, 4, 2}, 4, {-1, -1}};
    testcase e7{7, {42, 43, 44, 95, 12}, 3, {44, -1, -1}};
    testcase e8{8, {20, 28, 29, 30}, 3, {-1, 30}};
    cout << e1;
    cout << e2;
    cout << e3;
    cout << e4;
    cout << e5;
    cout << e6;
    cout << e7;
    cout << e8;
}
