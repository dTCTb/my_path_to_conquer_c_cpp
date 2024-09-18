#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <vector>

// check the size of 'x'
#define len(x) (std::cout << "size of " << #x << ": " << x.size() << '\n')
// check the type name of 'x'
#define tyn(x)                                                                 \
    (std::cout << "type of " << #x << ": " << typeid((x)).name() << '\n')

using namespace std;

class Solution {
  public:
    string largestNumber(vector<int> &&nums) {
        /* map<char, map<size_t, vector<pair<int, size_t>>, greater<size_t>>>
            table{};
        // 'digit' : { digit : [(int, index), ...]}
        for (size_t i{}; i < nums.size(); ++i) {
            string tmp{to_string(nums[i])};
            (table[tmp.front()])[tmp.size()].push_back({nums[i], i});
        }

        for_each(table.cbegin(), table.cend(), [](auto e) {
            auto &n{e.second};
            for (auto &m : n)
                sort((m.second).begin(), (m.second).end(),
                     [](auto l, auto r) -> bool { return l.first > l.second; });
        });

        for_each(table.cbegin(), table.cend(), [](auto e) {
            cout << '\'' << e.first << "' | ";
            auto &n{e.second};
            for (auto &m : n) {
                cout << m.first << ": ";
                for (auto &p : m.second)
                    cout << p.first << '[' << p.second << ']' << ' ';
            }
            cout << '\n';
        }); */
        map<size_t, vector<pair<int, size_t>>, greater<size_t>> indices{};
        string result{};

        // digit : [(int, index), ...]
        for (size_t i{}; i < nums.size(); ++i) {
            // indices[(tmp = to_string(nums[i])).size()].push_back({tmp, i});
            indices[to_string(nums[i]).front() - '0'].push_back({nums[i], i});
        }

        for_each(indices.begin(), indices.end(), [&result](auto &e) {
            size_t d{e.first};
            auto &m{e.second};
            sort(m.begin(), m.end(), [&d](auto l, auto r) -> bool {
                // auto L{l.first}, R{r.first};
                auto lStr{to_string(l.first)}, rStr{to_string(r.first)};
                long ll = atol((lStr + rStr).data());
                long rr = atol((rStr + lStr).data());
                if (ll > rr)
                    return true;
                return false;
                /* if (lStr.size() == rStr.size()) {
                    for (size_t i{}; i < min({lStr.size(), rStr.size()}); ++i) {
                        if (lStr[i] != rStr[i])
                            return l.first > r.first;
                    }
                } else {
                    size_t lSum{}, rSum{};
                    for (char v : lStr)
                        lSum += v - '0';
                    for (char v : rStr)
                        rSum += v - '0';
                    if (lSum != rSum)
                        return lSum > rSum;
                }
                return l.first < r.first; */

                // return l.first < r.first;
                // if (lSum == rSum && (L == d || R == d))
                //     return L < R;
                // else if (lSum == rSum)
                //     return L < R;
                // else
                //     return lSum > rSum;
                // return ((L == d || L == d * 10) && (R == d || R == d *
                // 10))
                //            ? false
                //            : lSum > rSum;
                // if (to_string(L).size() > to_string(R).size()) {
                //     return L < R;
                // } else {
                //     return L > R;
                // }
                /* ((l.first == d || l.first == d * 10) &&
                        (r.first == d || r.first == d * 10))
                           ? false
                           : l.first > r.first; */
            });
            for (auto &p : m)
                result += to_string(p.first);
        });

        // for (map<size_t, vector<pair<int, size_t>>>::value_type &kv :
        // indices)
        //     sort((kv.second).begin(), (kv.second).end(),
        //          [&indices](auto l, auto r) -> bool {
        //          return (l.first > 0 || r.frist > 9) ? l.first > r.first
        //          : ;
        //          });

        print_table(indices);
        return result[0] == '0' ? "0" : result;
    }

  private:
    void print_table(
        map<size_t, vector<pair<int, size_t>>, greater<size_t>> &table) {
        for_each(table.cbegin(), table.cend(), [&table](auto e) {
            cout << e.first << ": ";
            for (auto p : e.second)
                cout << p.first << '[' << p.second << ']' << ' ';
            cout << '\n';
        });
    }
};

int main() {
    Solution s;
    cout << s.largestNumber(vector<int>{3, 30, 34, 5, 9}) << '\n';
    cout.put('\n');
    cout << s.largestNumber(vector<int>{10, 2}) << '\n';
    cout.put('\n');
    cout << s.largestNumber(vector<int>{111, 99, 110, 101, 121, 1, 10, 19})
         << '\n';
    cout.put('\n');
    cout << s.largestNumber(vector<int>{100, 1, 10, 1, 1000}) << '\n';
    cout.put('\n');
    cout << s.largestNumber(vector<int>{111311, 1113}) << '\n'; // 1113111311
    cout.put('\n');
    cout << s.largestNumber(vector<int>{8308, 8308, 830})
         << '\n'; // 83088308830
    cout.put('\n');
    cout << s.largestNumber(vector<int>{0, 0}) << '\n';
}
