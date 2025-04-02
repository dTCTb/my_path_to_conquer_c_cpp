#include "lc_tools.h"
#include <iostream>
#include <vector>

using namespace std;

function<bool(pair<int, int>, pair<int, int>)> indexing =
    [](const pair<int, int> &l, const pair<int, int> &r) -> bool {
    return l.second > r.second;
};
// struct indexing {
//     bool operator()(const pair<int, int> &l, const pair<int, int> &r) {
//         return l.second > r.second;
//     }
// };

typedef std::vector<int> vInt;
typedef long long ll;
class Solution {
  public:
    static ll maximumTripletValue(const vInt &nums) noexcept {
        return solve(nums);
    }
    static ll solve(const vInt &nums) noexcept {
        int n{(int)nums.size()};
        ll ans{}, imax{}, dmax{};
        for (int i{}; i < n; ++i) {
            ans = max(ans, dmax * nums[i]);
            dmax = max(dmax, imax - nums[i]);
            imax = max(imax, (ll)nums[i]);
        }
        return ans;
    }

    static ll trial1(const vInt &nums) noexcept {
        vector<pair<int, int>> n(nums.size());
        for (int i{}; i < nums.size(); ++i)
            n[i] = make_pair(i, nums[i]);
        sort(n.begin(), n.end(), indexing);
        for (pair<int, int> v : n)
            cout << v.first << ' ' << v.second << '\n';

        for (int i{}, j{(int)n.size() - 1}; j - i >= 2;) {
            if (n[i].first > n[j].first) {
                ++i;
                continue;
            } else if (n[i].second - n[j].second)
                return (n[i].second - n[j].second) * n[i + 1].second;
        }

        cout << '\n';
        return 0LL;
    }
    static ll trial2(const vInt &nums) noexcept {
        vInt a1(nums.size(), 0), a2(nums.size(), 0);
        int i{}, j{INT_MAX}, k{};
        for (int x{}, y{(int)nums.size() - 1}; x < nums.size(); ++x, --y) {
            a1[x] = i = max(i, nums[x]);
            a2[y] = j = min(j, nums[y]);
        }
        for (int z{}; z < nums.size(); ++z) {
            k = max(k, (a1[z] - a2[z]) * nums[z]);
        }
        cout << a1 << '\n' << a2 << '\n';
        cout << "k: " << k << "\n\n";
        return k;
    }
};

int main() {
    Solution::maximumTripletValue({12, 6, 1, 2, 7});
    // 12, 12, 12, 12, 12
    // 1, 1, 1, 2, 7
    Solution::maximumTripletValue({1, 10, 3, 4, 19});
    // 1, 10, 10, 10, 19
    // 1, 3, 3, 4, 19
    Solution::maximumTripletValue({1, 2, 3});
    Solution::maximumTripletValue({2, 3, 1});
}
