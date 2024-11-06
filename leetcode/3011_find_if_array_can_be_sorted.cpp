#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    static bool canSortArray(const vector<int> &nums) noexcept {
        if (is_sorted(nums.cbegin(), nums.cend(), less<int>()))
            return true;

        return solve(nums);
    }

    static bool solve(const vector<int> &nums) noexcept {
        vector<int> bitSet;
        bitSet.reserve(nums.size());

        function<void(const int &)> countSetBit =
            [&bitSet](const int &e) -> void {
            int tmp{e}, cnt{};
            while (tmp) {
                if (tmp & 1)
                    ++cnt;
                tmp >>= 1;
            }
            bitSet.push_back(cnt);
        };

        for_each(nums.begin(), nums.end(), countSetBit);

        // vector<int> bitSetDup{bitSet};
        // vector<pair<int, int>> bin(unique(bitSetDup.begin(), bitSetDup.end())
        // - bitSetDup.begin(), {256, 0});
        vector<pair<int, int>> bin{};
        bin.reserve(nums.size());
        int tmp{bitSet[0]}, min{256}, max{};
        for (size_t i{}, j{}; i < nums.size(); ++i) {
            if (bitSet[i] == tmp) {
                // bin[j].first = nums[i] < bin[j].first ? nums[i] :
                // bin[j].first; bin[j].second =
                //     nums[i] > bin[j].second ? nums[i] : bin[j].second;
                min = nums[i] < min ? nums[i] : min;
                max = nums[i] > max ? nums[i] : max;
            } else {
                tmp = bitSet[i--];
                bin.push_back({min, max});
                min = 256;
                max = 0;
                ++j;
            }
        }
        bin.push_back({min, max});

        // printArr(nums); cout.put('\n');
        // printArr(bitSet); cout.put('\n');
        // for (pair<int, int> &p : bin)
        //     cout << '(' << p.first << ',' << p.second << ") ";
        // cout.put('\n');

        for (size_t i{}; i < bin.size() - 1; ++i)
            if (bin[i].second > bin[i + 1].first)
                return false;

        return true;
    }

    static void printArr(const vector<int> &arr) noexcept {
        for (const int &e : arr)
            cout << setw(3) << e << ' ';
    }
};

int main() {
    function<void(const vector<int> &, bool)> test = [](const vector<int> &nums,
                                                        bool answer) -> void {
        size_t myAnswer = Solution::canSortArray(nums);
        cout << (myAnswer == answer ? "\033[32mCorrect\033[0m"
                                    : "\033[31mIncorrect\033[0m");
        cout << "! ";
        Solution::printArr(nums);
        cout << "\033[35m" << (answer ? " can be" : " cannot be") << "\033[0m"
             << " sorted\n";
    };
    cout << boolalpha;
    test({8, 4, 2, 30, 15}, true);
    test({1, 2, 3, 4, 5}, true);
    test({3, 16, 8, 4, 2}, false);
    test({75, 34, 30}, false);
    test({177, 29, 256}, true);
    test({33, 134, 56, 234}, true);
    test({174, 175, 234, 188}, true);
    test({20, 6, 7, 10, 20, 6, 20}, false);
    test({9, 9, 3, 15, 15, 18, 5}, false);
}
