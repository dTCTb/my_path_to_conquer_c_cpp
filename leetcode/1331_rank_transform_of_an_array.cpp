#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using std::cout, std::vector, std::set, std::unordered_map, std::array,
    std::map;

class Solution {
  public:
    // faster but more code to write
    static vector<int> arrayRankTransform(vector<int> &arr) noexcept {
        if (arr.empty())
            return {};
        vector<int> ret{arr};

        sort(ret.begin(), ret.end());
        unordered_map<int, int> table;

        int rank{1};
        for (int i{}; i < arr.size() - 1; ++i) {
            table[ret[i]] = rank;
            if (ret[i] != ret[i + 1])
                ++rank;
        }
        table[ret.back()] = rank;

        for (int i{}; i < arr.size(); ++i)
            ret[i] = table[arr[i]];

        return ret;
    }

    // slower but using set and unordered_map
    vector<int> &arrayRankTransform2(vector<int> &arr) {
        set<int> sorted(arr.begin(), arr.end());
        unordered_map<int, int> rank;
        vector<int> ret;
        ret.reserve(arr.size());

        for (int i{}; const int &e : sorted)
            rank[e] = ++i;

        for (int i{}; i < arr.size(); ++i)
            arr[i] = rank[arr[i]];
        // for (int &e : arr) {
        // below method is ok, but will cause TLE
        // ret.push_back(std::distance(rank.cbegin(), rank.find(e)) + 1); //
        // }

        return arr;
    }
};

auto init = []() {
    std::cout.tie(0);
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
};

int main() {
    Solution s;
    vector<int> testCase1{40, 10, 20, 30};
    vector<int> testCase2{100, 100, 100};
    vector<int> testCase3{37, 12, 28, 9, 100, 56, 80, 5, 12};
    vector<int> eg1{s.arrayRankTransform(testCase1)};
    copy(eg1.cbegin(), eg1.cend(), std::ostream_iterator<int>{cout, " "});
    cout.put('\n');
    vector<int> eg2{s.arrayRankTransform(testCase2)};
    copy(eg2.cbegin(), eg2.cend(), std::ostream_iterator<int>{cout, " "});
    cout.put('\n');
    vector<int> eg3{s.arrayRankTransform(testCase3)};
    copy(eg3.cbegin(), eg3.cend(), std::ostream_iterator<int>{cout, " "});
    cout.put('\n');
}
