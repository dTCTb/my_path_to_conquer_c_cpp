#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef std::vector<int> vInt;
typedef std::unordered_map<int, int> mII;

class Solution {
  public:
    static ll maximumSubarraySum(const vInt &nums, int k) noexcept {
        mII table;
        ll max{};
        ll sum{};

        for (int i{}, j{}; j < nums.size(); ++j) {
            if (++table[nums[j]] == 1)
                sum += nums[j];

            if (j - i > k - 1) {
                if (--table[nums[i]] == 0) {
                    sum -= nums[i];
                    table.erase(nums[i]);
                }
                ++i;
            }

            if (table.size() == k)
                max = sum > max ? sum : max;
        }

        cout << "max: " << max << '\n';

        return max;
    }
};

int main() {
    using namespace placeholders;
    auto test = bind(Solution::maximumSubarraySum, _1, _2);
    test(vector<int>{1, 5, 4, 2, 9, 9, 9}, 3);                // 15
    test(vector<int>{4, 4, 4}, 3);                            // 0
    test(vector<int>{1, 1, 1, 7, 8, 9}, 3);                   // 24
    test(vector<int>{5, 5, 3, 3, 1}, 3);                      // 0
    test(vector<int>{100, 1, 2, 100}, 2);                     // 102
    test(vector<int>{9, 9, 9, 1, 2, 3}, 3);                   // 12
    test(vector<int>{1, 3, 3, 3, 3, 2, 1, 3, 1, 1, 2}, 3);    // 6
    test(vector<int>{3, 3, 5, 5, 3, 3, 1, 1, 4, 2, 5, 1}, 4); // 12
}
