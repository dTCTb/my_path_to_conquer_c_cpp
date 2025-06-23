#include "./lc_tools.h"
#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
class Solution {
  public:
    static int minimumOperations(const vInt &nums) noexcept {
        int tb[101]{}, ans{};
        for (const int v : nums)
            ++tb[v];

        for (int i{}; i < nums.size(); ++ans) {
            int c{};
            bool flag{};
            // check the array is distinct or not, if not break immediately
            for (int j{}; j < 101; ++j)
                if (tb[j] > 1) {
                    flag = true;
                    break;
                }
            // if distinct then break
            if (!flag)
                break;
            // operations
            do {
                if (i + 1 < nums.size())
                    --tb[nums[i++]];
                else
                    ++i;
            } while (++c < 3);
        }
#ifdef DEBUG
        cout << "ans: " << ans << '\n';
#endif
        return ans;
    }
};

int main() {
    Solution::minimumOperations({1, 2, 3, 4, 2, 3, 3, 5, 7}); // 2
    Solution::minimumOperations({4, 5, 6, 4, 4});             // 2
    Solution::minimumOperations({6, 7, 8, 9});                // 0
    Solution::minimumOperations({1, 1, 1});
    Solution::minimumOperations({1, 2, 2, 3, 3, 4});
    Solution::minimumOperations({1});
    Solution::minimumOperations({1, 2, 3});
    Solution::minimumOperations({1, 2, 3, 4, 4, 4, 4, 4, 4});
    Solution::minimumOperations({10, 10, 10, 10, 10});
    Solution::minimumOperations({5, 5, 5, 5, 5, 5, 5, 5, 5, 5});
    Solution::minimumOperations({1, 2, 1, 2, 1, 2, 1, 2});
}
