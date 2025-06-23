#include <iostream>
#include <vector>

using namespace std;
typedef std::vector<int> vInt;
class Solution {
  public:
    static int maximumCount(const vInt &nums) noexcept {
        vInt numsMut{nums};
#if defined(BINARY)
        return binary(numsMut);
#else
        return brute(numsMut);
#endif
    }

  private:
    static int brute(vInt &nums) noexcept {

        const int s{static_cast<int>(nums.size())};
        int neg{}, zero{}, pos{};

        sort(nums.begin(), nums.end());

        while (neg < s && nums[neg] < 0)
            ++neg;

        while (neg + zero < s && nums[neg + zero] == 0)
            ++zero;

        pos = s - zero - neg;

#if defined(DEBUG)
        cout << "neg: " << neg << ' ';
        cout << "zero: " << zero << ' ';
        cout << "pos: " << (int)nums.size() - zero - neg << '\n';
        cout << "ans: " << max(neg, pos) << '\n';
#endif
        return max(neg, pos);
    }

    static int binary(vInt &nums) noexcept {
        const int s{static_cast<int>(nums.size())};
        return max(lowerBound(nums, 0, s - 1, s),
                   s - upperBound(nums, 0, s - 1, s));
    }

    static int lowerBound(const vInt &nums, int l, int r, const int s) {
        int idx{s};

        while (l <= r)
            if (int m{(l + r) / 2}; nums[m] < 0)
                l = m + 1;
            else if (nums[m] >= 0)
                r = (idx = m) - 1;

        return idx;
    }

    static int upperBound(const vInt &nums, int l, int r, const int s) {
        int idx{s};

        while (l <= r)
            if (int m{(l + r) / 2}; nums[m] <= 0)
                l = m + 1;
            else if (nums[m] > 0)
                r = (idx = m) - 1;

        return idx;
    }
};

int main() {
    Solution::maximumCount({-2, -1, -1, 1, 2, 3});    // 3
    Solution::maximumCount({-3, -2, -1, 0, 0, 1, 2}); // 3
    Solution::maximumCount({5, 20, 66, 1314});        // 4
    Solution::maximumCount({-2, -2, -1});             // testcase 161/167 3
    Solution::maximumCount({0});                      // testcase 166/167 0
#if defined(BINARY)
    cout << "\n- -- - -- - -- -\nbinary solution had been called\n";
#else
    cout << "\n- -- - -- - -- -\ntip: by default brute force solution will be "
            "called, unless adds "
            "`FLAG='-DBINARY'`\n";
#endif
}
