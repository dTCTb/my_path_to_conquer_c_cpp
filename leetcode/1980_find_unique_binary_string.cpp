#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    static string findDifferentBinaryString(const vector<string> &nums) {
        return solve2(nums);
    }

    /* 卡咗喺testcast 157/184 度 */
    static string solve1(const vector<string> &nums) {
        string ans;
        const size_t len{nums.size()};
        for (size_t i{}; i < len; ++i) {
            ans.push_back(nums[i][0]);
            for (size_t j{1}; j < len; ++j)
                ans[i] = nums[j].back() == '0' ? '1' : '0';
        }
        cout << "check: " << ans << '\n';
        if (find(nums.cbegin(), nums.cend(), ans) != nums.cend())
            for (size_t i{}; i < ans.size(); ++i)
                ans[i] = ans[i] == '1' ? '0' : '1';
        cout << "ans  : " << ans << '\n';
        return ans;
    }

    /* 0ms 12.62mb Cantor's diagonal */
    static string solve2(const vector<string> &nums) {
        string ans;
        for (size_t i{}; const string &num : nums) {
            ans.push_back(num[i++] == '0' ? '1' : '0');
        }
        cout << "ans: " << ans << '\n';
        return ans;
    }
};

int main() {
    Solution::findDifferentBinaryString({"01", "10"});          // 11 or 00
    Solution::findDifferentBinaryString({"00", "01"});          // 11 or 10
    Solution::findDifferentBinaryString({"111", "011", "001"}); // 101, 000, ...
    Solution::findDifferentBinaryString(
        {"0111", "0000", "1001", "1111"}); // 157/184 "0001"
}
