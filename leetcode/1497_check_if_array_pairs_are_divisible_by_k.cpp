#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using std::vector, std::set, std::map, std::cout, std::unordered_map;

class Solution {
  public:
    // this brutal force solution can pass 78/97 testcases
    bool canArrange(const vector<int> &arr, int k) {
        // map<int, vector<int>> divisiblePair;
        map<int, int> mod;
        // set<pair<int, int>> divisiblePair;
        int skip{};
        for (int i{}; i < arr.size() - 1; ++i) {
            if (arr[i] == 0)
                ++skip;
            for (int j{i}; j < arr.size() - 1; ++j) {
                int tmp{};
                // tmp = ((arr[i] % k + arr[j + 1] % k) + k) % k;
                tmp = (((arr[i] + arr[j + 1]) % k) + k) % k;
                // tmp = ((k - (arr[i] + arr[j + 1]) % k)) % k;
                // tmp = (arr[i] % k + arr[j + 1] % k);
                ++mod[tmp];
                // divisiblePair.insert({arr[i], arr[j + 1]});
                // }
            }

            // if (!((((arr[i] + arr[j + 1]) % k) + k) % k))
            // divisiblePair[arr[i]].push_back(arr[j + 1]);
        }
        // cout << "pair: " << pair << '\n';

        // for (map<int, vector<int>>::value_type p : divisiblePair) {
        //     cout << p.first << ": ";
        //     for (int e : p.second)
        //         cout << e << ' ';
        //     cout.put('\n');
        // }
        for (map<int, int>::value_type p : mod) {
            cout << p.first << ": " << p.second << '\n';
        }
        // for (std::pair<int, int> p : divisiblePair) {
        //     cout << '(' << p.first << ", " << p.second << ")\n";
        // }

        // return pair == arr.size() / 2 ? true : false;
        // return mod.size() == arr.size() / 2 ? true : false;
        return mod[0] - skip >= arr.size() / 2 ? true : false;
    }

    bool others_canArrange(const vector<int> &arr, int k) {
        unordered_map<int, int> remainderCount;

        // Store the count of remainders in a map.
        for (auto i : arr)
            remainderCount[(i % k + k) % k]++;

        for (auto i : arr) {
            int rem = (i % k + k) % k;

            // If the remainder for an element is 0, then the count
            // of numbers that give this remainder must be even.
            if (rem == 0) {
                if (remainderCount[rem] % 2 == 1)
                    return false;
            }

            // If the remainder rem and k-rem do not have the
            // same count then pairs can not be made.
            else if (remainderCount[rem] != remainderCount[k - rem])
                return false;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.others_canArrange({1, 2, 3, 4, 5, 10, 6, 7, 8, 9}, 5) << '\n';
    cout << s.others_canArrange({1, 2, 3, 4, 5, 6}, 7) << '\n';
    cout << s.others_canArrange({1, 2, 3, 4, 5, 6}, 10) << '\n';
    cout << s.others_canArrange({-1, 0, -2, 2, -3, 3}, 4) << '\n';
}
