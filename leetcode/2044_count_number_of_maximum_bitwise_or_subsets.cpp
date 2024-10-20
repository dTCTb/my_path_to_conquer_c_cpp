#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int max_bitor{}, ret{};
    vector<int> wise{};

  public:
    Solution() : max_bitor{}, ret{}, wise{} { wise.reserve(16); }
    int countMaxOrSubsets(const vector<int> &nums) noexcept {
        max_bitor = cal_bitor(nums);
        // cout << "maximum bitor: " << max_bitor << '\n';
        backtracking(nums, 0);
        return ret;
    }

  private:
    void backtracking(const vector<int> &nums, size_t i) {
        for (; i < nums.size(); ++i) {
            wise.push_back(nums[i]);
            if (cal_bitor(wise) == max_bitor)
                ++ret;
            backtracking(nums, i + 1);
            wise.pop_back();
        }
    }

    int cal_bitor(const vector<int> &arr) {
        int tmp{};
        for (int e : arr)
            tmp = e bitor tmp;
        return tmp;
    }
};

// clang-format off
int main() {
    Solution s1;
    Solution s2;
    Solution s3;
    Solution s4;
    Solution s5;
    Solution s6;
    cout << s1.countMaxOrSubsets({3, 1}) << '\n';       // 2
    cout << s2.countMaxOrSubsets({2, 2, 2}) << '\n';    // 7
    cout << s3.countMaxOrSubsets({3, 2, 1, 5}) << '\n'; // 6
    cout << s4.countMaxOrSubsets({32,39,37,31,42,38,29,43,40,36,44,35,41,33,34,30}) << '\n'; // 57083
    cout << s5.countMaxOrSubsets({63609,94085,69432,15248,22060,76843,84075,835,23463,66399,95031,22676,92115}) << '\n'; // 3772
    cout << s6.countMaxOrSubsets({89260,58129,16949,64128,9782,26664,96968,59838,27627,68561,4026,91345,26966,28876,46276,19878}) << '\n'; // 52940
}
