#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
typedef std::unordered_map<int, int> Map;
class Solution {
  public:
    /* O(N^2) 295ms 84.84mb */
    /* 我似為有更好嘅solution，點知Editorial 最好嘅Solution (更worse 嘅係N^3)
     * 已經係我自己諗嘅呢個，Editor 叫呢個方法做Product Frequency Hash Map... */
    static int tupleSameProduct(const vInt &nums) noexcept {
        if (nums.size() < 4)
            return 0;

        int ans{}; /*, n[101] = {0, 0, 8}; */
        Map map;

        /* much faster used with unordered_map, but in convenience reason, this
         * member function takes const vector<int> as argument so we cannot
         * modified the vector unless remove the const keyword
         */
        // sort(nums.begin(), nums.end());

        // for (int i{2}; i < 100; ++i)
        //     n[i + 1] = 8 * i + n[i];

        for (size_t i{}; i < nums.size(); ++i)
            for (size_t j{i + 1}; j < nums.size(); ++j)
                ++map[nums[i] * nums[j]];

        for (const /*Map::value_type*/ auto &[prod, freq] : map)
            ans += freq * 4 * (freq - 1);
        // ans += n[freq];
        //  cout << prod << ' ' << freq << '\n';

        cout << "ans: " << ans << '\n';
        return ans;
    }
};

int main() {
    Solution::tupleSameProduct(vInt{2, 3, 4, 6});                  // 8
    Solution::tupleSameProduct(vInt{1, 2, 4, 5, 10});              // 16
    Solution::tupleSameProduct(vInt{2, 3, 5, 7});                  // 0
    Solution::tupleSameProduct(vInt{2, 3, 4, 6, 8, 12});           // 40
    Solution::tupleSameProduct(vInt{1, 2, 4, 8, 16, 32});          // 56
    Solution::tupleSameProduct(vInt{10, 5, 15, 8, 6, 12, 20, 4});  // 72
    Solution::tupleSameProduct(vInt{20, 10, 6, 24, 15, 5, 4, 30}); // 48
    Solution::tupleSameProduct(vInt{19, 32, 39, 38, 43, 47, 9, 5, 35, 22});
    // 0
    Solution::tupleSameProduct(vInt{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024,
                                    2048, 4096, 8192}); // 1288
}
