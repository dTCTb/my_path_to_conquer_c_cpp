#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef std::vector<int> vInt;
typedef std::unordered_map<ll, size_t> Map;
class Solution {
  public:
    static ll countBadPairs(const vInt &nums) noexcept {
        ll ans{my_solve(nums)};
        cout << "ans: " << ans << '\n';
        return ans;
    }

    /* 83ms 92.70mb
       actually, dunodoingwat*/
    static ll my_solve(const vInt &nums) noexcept {
        const size_t size{nums.size()};
        const size_t total{(size * (size - 1)) / 2};
        // for (size_t i{nums.size() - 1}; i > 0; --i)
        //     total += i;
        ll good{};
        Map map{};

        for (size_t i{}; i < nums.size(); ++i)
            ++map[nums[i] - i];

        for (size_t i{}; i < nums.size(); ++i) {
            good += --map[nums[i] - i];
            if (map[nums[i] - i] == 0)
                map.erase(nums[i] - i);
        }

        // cout << "total, good: " << total << ", " << good << '\n';

        return total - good;
    }

    static ll tle(const vInt &nums) noexcept {
        ll ans{};
        for (size_t i{}; i < nums.size() - 1; ++i)
            for (size_t j{i + 1}; j < nums.size(); ++j)
                ans += nums[j] - nums[i] != j - i ? 1 : 0;
        return ans;
    }
};

int main() {
    auto test = bind(Solution::countBadPairs, placeholders::_1);
    test(vInt{4, 1, 3, 3});    // 5
    test(vInt{1, 2, 3, 4, 5}); // 0
}
