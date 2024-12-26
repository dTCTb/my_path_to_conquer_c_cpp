#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
class Solution {
  public:
    static int findTargetSumWays(vInt &nums, int target) noexcept {
        int ans{};
        bt(ans, nums, 0, 0, target);
        return ans;
    }

    static void bt(int &ans, vInt &nums, int curIdx, int sum, int target) {
        if (curIdx >= nums.size()) {
            if (sum == target)
                ++ans;
            return;
        }

        bt(ans, nums, curIdx + 1, sum += nums[curIdx], target);
        sum -= nums[curIdx];

        bt(ans, nums, curIdx + 1, sum -= nums[curIdx], target);
        sum += nums[curIdx];

        return;
    }
};
/*
　　　　　　　＿＿＿
 　　　　　 ＞   　　フ
 　　　　　| 　_　 _ l
 　 　　　／` ミ＿xノ
 　　 　 /　　　 　 |
 　　　 /　 ヽ　　 ﾉ
 　 　 │　　|　|　|
 　／￣|　　 |　|　|
 　| (￣ヽ＿_ヽ_)__)
 　＼二つ
*/
int main() {
    vInt e1{1, 1, 1, 1, 1};
    Solution::findTargetSumWays(e1, 3);
    cout << "- -- - -- -\n";
    vInt e2{1};
    Solution::findTargetSumWays(e2, 1);
    cout << "- -- - -- -\n";
    vInt e3{1};
    Solution::findTargetSumWays(e3, 2);
    cout << "- -- - -- -\n";
    vInt e4{100, 100};
    Solution::findTargetSumWays(e4, -300);
    cout << "- -- - -- -\n";
    vInt e5{12, 25, 42, 49, 41, 15, 22, 34, 28, 31};
    Solution::findTargetSumWays(e5, 35);
    cout << "- -- - -- -\n";
    vInt e6{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    Solution::findTargetSumWays(e6, 1);
    cout << "- -- - -- -\n";
    vInt e7{3,  2, 3, 5, 7,  11, 13, 17, 19, 23,
            29, 2, 7, 9, 13, 27, 31, 37, 47, 53};
    Solution::findTargetSumWays(e7, 107);
    cout << "- -- - -- -\n";
    vInt e8{0,  5,  22, 39, 30, 5,  40, 23, 47, 43,
            19, 36, 10, 28, 46, 14, 11, 5,  50, 41};
    Solution::findTargetSumWays(e8, 48);
    cout << "- -- - -- -\n";
    vInt e9{30, 29, 48, 14, 29, 4,  31, 12, 40, 13,
            30, 1,  5,  32, 16, 17, 13, 20, 41, 38};
    Solution::findTargetSumWays(e9, 9);
    cout << "- -- - -- -\n";
    vInt e10{3,  2, 3,   5,   7,   11,  13,  17,  19, 23,
             29, 2, 107, 109, 113, 127, 131, 137, 47, 53};
    Solution::findTargetSumWays(e10, 4);
    cout << "- -- - -- -\n";
}
