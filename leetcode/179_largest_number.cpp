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
        map<size_t, vector<string>, greater<size_t>> indices{};
        string result{};

        // digit : [str, str, ...]
        for (size_t i{}; i < nums.size(); ++i) {
            string tmp{to_string(nums[i])};
            indices[tmp.front() - '0'].push_back(tmp);
        }

        for_each(indices.begin(), indices.end(), [&result](auto &e) {
            auto &m{e.second};
            sort(m.begin(), m.end(), [](string &l, string &r) -> bool {
                long L{atol((l + r).data())};
                long R{atol((r + l).data())};
                if (L > R)
                    return true;
                return false;
            });
            for (auto &p : m)
                result += p;
        });

        print_table(indices);
        return result[0] == '0' ? "0" : result;
    }

    // 其他勁人，寫得勁clean，我仲用咗好耐先睇到個核心！
    string learnTHIS(vector<int> &&nums) {
        auto compare = [](string &l, string &r) { return l + r > r + l; };

        vector<string> strs{};
        for (int &num : nums)
            strs.push_back(to_string(num));

        sort(strs.begin(), strs.end(), compare);

        string result{};
        for (string &str : strs)
            result += str;

        return result[0] == '0' ? "0" : result;
    }

  private:
    void print_table(map<size_t, vector<string>, greater<size_t>> &table) {
        for_each(table.cbegin(), table.cend(), [&table](auto e) {
            cout << e.first << ": ";
            for (auto p : e.second)
                cout << p << ' ';
            cout << '\n';
        });
    }
};

int main() {
    Solution s;
    cout << s.learnTHIS(vector<int>{3, 30, 34, 5, 9}) << '\n';
    cout << s.largestNumber(vector<int>{3, 30, 34, 5, 9}) << '\n';
    cout.put('\n');
    cout << s.learnTHIS(vector<int>{10, 2}) << '\n';
    cout << s.largestNumber(vector<int>{10, 2}) << '\n';
    cout.put('\n');
    cout << s.learnTHIS(vector<int>{111, 99, 110, 101, 121, 1, 10, 19}) << '\n';
    cout << s.largestNumber(vector<int>{111, 99, 110, 101, 121, 1, 10, 19})
         << '\n';
    cout.put('\n');
    cout << s.learnTHIS(vector<int>{100, 1, 10, 1, 1000}) << '\n';
    cout << s.largestNumber(vector<int>{100, 1, 10, 1, 1000}) << '\n';
    cout.put('\n');
    cout << s.learnTHIS(vector<int>{111311, 1113}) << '\n';     // 1113111311
    cout << s.largestNumber(vector<int>{111311, 1113}) << '\n'; // 1113111311
    cout.put('\n');
    cout << s.learnTHIS(vector<int>{8308, 8308, 830}) << '\n'; // 83088308830
    cout << s.largestNumber(vector<int>{8308, 8308, 830})
         << '\n'; // 83088308830
    cout.put('\n');
    cout << s.learnTHIS(vector<int>{0, 0}) << '\n';
    cout << s.largestNumber(vector<int>{0, 0}) << '\n';
}
