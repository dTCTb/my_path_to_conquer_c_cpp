#include <iomanip>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
  public:
    typedef pair<int, int> set_v;      // set value
    typedef set<pair<int, int>> set_t; // set type
    typedef set_t::iterator setIt;     // set iterator

    static int maxWidthRamp(const vector<int> &nums) {
        // 94/101 testcases passed
        /* set<pair<int, int>> s;
        for (int i{}; i < nums.size(); ++i)
            s.insert({nums[i], i});

        for (pair<int, int> p : s)
            cout << setw(2) << p.first << ' ';
        cout.put('\n');
        for (pair<int, int> p : s)
            cout << setw(2) << p.second << ' ';
        cout.put('\n');

        int max{INT_MIN};
        for (int i = nums.size() - 1; i >= 0; --i) {
            set<pair<int, int>>::iterator it = s.find({nums[i], i});
            // set<pair<int, int>>::iterator minIt = s.begin();
            // cout << '>' << it->first << ' ' << it->second << "\n";
            for (auto bit{s.begin()}; bit != it; ++bit) {
                // cout << bit->first << ' ' << bit->second << ", ";
                set<pair<int, int>>::iterator minIt = s.find({});
                if (int tmpMax = it->second - bit->second;
                    bit->second < it->second) {
                    max = tmpMax > max ? tmpMax : max;
                    // break;
                }
                // cout << "\n-- - -- - -- - --\n";
            }
        }
        return max != INT_MIN ? max : 0; */

        // 94/101 testcases passed
        /* int max{INT_MIN};
        pair<size_t, size_t> ramp;
        for (size_t i{}, j{nums.size() - 1}; i != j;) {
            if (nums[i] > nums[j]) {
                ++i;
                continue;
            }
            if (nums[j] < nums[i]) {
                --j;
                continue;
            }
            if (int tmpMax = j - i; tmpMax > max) {
                max = tmpMax;
                ramp.first = i++;
                ramp.second = j--;
                cout << "i: " << ramp.first << " j: " << ramp.second
                     << " max: " << max << '\n';
                break;
            }
        }
        return max != INT_MIN ? ramp.second - ramp.first : 0; */
    }
};

// clang-format off
int main() {
    // cout << Solution::maxWidthRamp({6, 0, 8, 2, 1, 5}) << '\n';             // 4
    // cout << Solution::maxWidthRamp({9, 8, 1, 0, 1, 9, 4, 0, 4, 1}) << '\n'; // 7
    cout << Solution::maxWidthRamp({29, 28, 28, 26, 25, 24, 9, 23, 21, 9,  18,
                                    17, 14, 12, 3,  11, 10, 8, 8,  10, 22, 6,
                                    5,  20, 5,  2,  1,  1,  1, 0}) // 17
         << '\n';
}
