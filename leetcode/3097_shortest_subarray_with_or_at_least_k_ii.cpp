#include <bitset>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
  public:
    static int minimumSubarrayLength(const vector<int> &nums, int k) {
        if (nums.size() == 1)
            return nums.front() >= k ? 1 : -1;

        for (const int &e : nums)
            cout << e << ' ';
        cout << '(' << k << ") ";

        auto calOr = [&nums](int l, int r) -> int {
            int ret{};
            while (l < r)
                ret |= nums[l++];
            // cout << "bitor: " << ret << '\n';
            return ret;
        };

        size_t arrSize = nums.size();
        long ret{LONG_MAX};
        for (size_t i{0}, j{0}; i < arrSize && j < arrSize; ++i) {
            unsigned int cur = nums[i];
            if (nums[i] >= k)
                return 1;
            while (cur < k && j < arrSize) {
                cur |= nums[j++];
                if (cur >= k) {
                    ret = j - i < ret ? j - i : ret;
                    if (ret == 1)
                        return ret;
                    j = i + 1;
                    break;
                }
            }
            while (j < arrSize && nums[i] == nums[j])
                ++i, ++j;

            /* if (nums[i] == k)
                return 1;
            // cout << "i: " << i << " j: " << j << ' ';
            if (calOr(i, j) >= k) {
                subArr.insert((j - i == 0 ? 1 : j - i));
                ++i;
                continue;
            }
            if (j < nums.size())
                ++j;
            else
                ++i; */

            /* not correct but good try
            if (nums[i] == k || nums[j] == k)
                return 1;
            if (cur >= k) {
                // cout << "j - i == " << j << " - " << i << " == " << j - i
                //      << '\n';
                subArr.insert((j - i) == 0 ? 1 : j - i);
                // cout << "cur before " << cur << " ^= " << nums[i];
                // cin.ignore();
                // cur = cur ^ ~nums[i++];
                cur = calOr(++i, j);
                // cout << "cur after shift (XOR) " << cur;
                // cin.ignore();
            }
            if (j < nums.size()) {
                // cout << "cur before " << cur << " |= " << nums[j];
                // cin.ignore();
                cur |= nums[j++];
                // cout << "cur after OR " << cur;
                // cin.ignore();
            } else {
                // cout << "cur before " << cur << " ^= " << nums[i];
                // cin.ignore();
                // cur = cur ^ ~nums[i++];
                cur = calOr(++i, j);
                // cout << "cur after shift (XOR) " << cur;
                // cin.ignore();
            }
            */
        }

        return ret /* == LONG_MAX ? -1 : ret */;
    }
};

int main() {
    auto test = bind(Solution::minimumSubarrayLength, placeholders::_1,
                     placeholders::_2);
    cout << test(vector<int>{1, 2, 3}, 2) << '\n';               // 1
    cout << test(vector<int>{2, 1, 8}, 10) << '\n';              // 3
    cout << test(vector<int>{1, 2}, 0) << '\n';                  // 1
    cout << test(vector<int>{1, 2, 32, 21}, 55) << '\n';         // 3
    cout << test(vector<int>{5, 1, 32, 86, 2}, 117) << '\n';     // 2
    cout << test(vector<int>{2, 1, 6, 32, 86, 56}, 123) << '\n'; // 2
    cout << test(vector<int>{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                             0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                 0)
         << '\n'; // 1
    cout << test(vector<int>{12, 42, 42, 1, 36, 57, 45, 57, 2}, 62)
         << '\n'; // 3
}
