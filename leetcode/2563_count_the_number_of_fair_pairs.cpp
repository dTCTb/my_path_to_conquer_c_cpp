#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
typedef long long ll;

class Solution {
  public:
    typedef std::pair<size_t, int> idxInt_p;
    static ll countFairPairs(vInt &nums, int lower, int upper) {
        ll ans{};
        sort(nums.begin(), nums.end());

        for (int &e : nums)
            cout << e << ' ';
        cout.put('\n');

        size_t l{}, m{}, r{nums.size() - 1};
        auto bs = [&nums](int l, int r, int t) -> size_t {
            while (l <= r) {
                size_t m = l + (r - l) / 2;
                if (nums[m] >= t)
                    r = m - 1;
                else if (nums[m] < t)
                    l = m + 1;
            }
            return l;
        };
        for (size_t i{}; i < nums.size(); ++i) {
            size_t low{bs(i + 1, nums.size() - 1, lower - nums[i])};
            size_t high{bs(i + 1, nums.size() - 1, upper - nums[i] + 1)};
            ans += high - low;
        }
        return ans;
    }

    static ll countFairPairs_TLE(vInt &nums, int lower, int upper) {
        ll ans{};

        for (int &e : nums)
            cout << e << ' ';
        cout.put('\n');

        sort(nums.begin(), nums.end());

        for (int &e : nums)
            cout << e << ' ';
        cout.put('\n');

        for (size_t i{}, j{}, k{}, z{}; i < nums.size() - 1; ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                if (z - k == 0)
                    continue;
                if (i == k)
                    ++k;
                ans += z - k;
                continue;
            }

            j = i + 1;
            for (; j < nums.size() && nums[j] < lower - nums[i]; ++j)
                ;
            k = j;

            for (; j < nums.size() && nums[j] <= upper - nums[i]; ++j)
                ++ans;
            z = j;
        }

        return ans;
    }
};

typedef tuple<std::vector<int>, int, int, long long> testcase;

ostream &operator<<(ostream &c, testcase &t) {
    auto &[nums, lower, upper, answer] = t;
    c << "- -- - -- -\n";
    c << "nums: [";
    for (int &e : nums)
        c << e << ',';
    c << "\b]\n";
    c << "lower: " << lower << '\n';
    c << "upper: " << upper << '\n';
    c << "answer: " << answer << '\n';
    ll myAnswer{Solution::countFairPairs(nums, lower, upper)};
    c << "my answer: " << myAnswer << '\n';
    return c;
}

int main() {
    using namespace placeholders;
    testcase e1{{0, 1, 7, 4, 4, 5}, 3, 6, 6};
    testcase e2{{1, 7, 9, 2, 5}, 11, 11, 1};
    testcase e3{{-1, 0}, 1, 1, 0};
    testcase e4{{0, 0, 0, 0, 0, 0, 0}, 0, 0, 21};
    testcase e5{{1, 7, 5, 9, 2, 11}, 12, 12, 2};
    testcase e6{{-8}, -8, -7, 0};
    testcase e7{{-5, -7, -7, -5, -5}, -12, -12, 6};
    cout << e1;
    cout << e2;
    cout << e3;
    cout << e4;
    cout << e5;
    cout << e6;
    cout << e7;
}
