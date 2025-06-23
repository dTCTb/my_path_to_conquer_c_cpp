#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    static bool canPartition(const vector<int> &nums) {
        int sum{}, targetSum{};
        for (const int num : nums)
            sum += num;
#ifdef DEBUG
        cout << "sum: " << sum << '\n';
#endif
        if (sum % 2 != 0)
            return false;
        else
            targetSum = sum / 2;
#ifdef DEBUG
        cout << "targetSum: " << targetSum << '\n';
#endif

        vector<bool> dp(targetSum + 1, false);
        dp[0] = true;

        for (const int num : nums) {
            for (int curSum = targetSum; curSum >= num; --curSum) {
                dp[curSum] = dp[curSum] || dp[curSum - num];
                if (dp[targetSum])
                    return true;
            }
        }

        return dp[targetSum];
    }
};

int main() {
    Solution::canPartition({1, 5, 11, 5}); // true
    Solution::canPartition({1, 2, 3, 5});  // false
    Solution::canPartition({1, 2, 5});     // false
}
