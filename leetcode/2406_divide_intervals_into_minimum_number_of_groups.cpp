#include <iostream>
#include <set>
#include <vector>

using namespace std;

void *operator new(size_t x) {
    static size_t cnt{1};
    cout << cnt++ << " new called\n";
    return malloc(x);
}

class Solution {
  public:
    // 35/35 testcases passed (runtime 315ms, memory 114.5MB)
    static int minGroups(const vector<vector<int>> &intervals) noexcept {
        multiset<pair<int, int>> sep;
        priority_queue<int, vector<int>, greater<int>> end;
        // priority_queue underlying container 改用deque 會慢好多
        for (const vector<int> &v : intervals)
            sep.insert({v[0], v[1]});

        print(sep);

        int lap{};
        for (const pair<int, int> &v : sep) {
            end.push(v.second);
            if (v.first <= end.top())
                ++lap;
            else /* if (v.first > end.top()) */
                end.pop();
        }

        return lap;
    }

  private:
    static void print(multiset<pair<int, int>> &sep) {
        for (const pair<int, int> &v : sep)
            cout << '[' << v.first << "," << v.second << "] ";
        cout.put('\n');
    }
};

// clang-format off
int main() {
    cout << Solution::minGroups({{5, 10}, {6, 8}, {1, 5}, {2, 3}, {1, 10}}) << '\n'; // 3
    cout << Solution::minGroups({{1, 3}, {5, 6}, {8, 10}, {11, 13}}) << '\n'; // 1
    cout << Solution::minGroups({{1, 10}, {2, 11}, {3, 100}}) << '\n'; // 3
    cout << Solution::minGroups({{100, 3005}, {100, 3005}, {100, 3005}, {100, 3005}}) << '\n'; // 4
}
// clang-format on
