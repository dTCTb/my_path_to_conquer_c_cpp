#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    typedef vector<vector<int>> vvInt;
    typedef vector<int> vInt;

    static vector<int> maximumBeauty(vvInt &items, vInt &queries) noexcept {
        array<pair<int, int>, 100'000> arr{};
        vector<int> answer{};
        answer.reserve(queries.size());

        sort(items.begin(), items.end(),
             [](const vInt &l, const vInt &r) -> bool { return l[0] < r[0]; });

        arr[0] = {items[0][0], items[0][1]};
        int j /*count of unique price*/ {};
        for (size_t i{1}; i < items.size(); ++i) {
            if (items[i][0] != arr[j].first)
                arr[++j].first = items[i][0];
            arr[j].second =
                items[i][1] > arr[j].second ? items[i][1] : arr[j].second;
        }

        for (int i{}, max{arr[0].second}; i <= j; ++i) {
            arr[i].second = max = max > arr[i].second ? max : arr[i].second;
        }

        /* for (size_t i{}; i <= j; ++i)
            cout << get<0>(arr[i]) << ',' << get<1>(arr[i]) << '\n'; */

        function<int(int, int, int)> binarySearch = [&arr](int q, int l,
                                                           int r) -> int {
            int m{};
            while (l <= r) {
                m = l + (r - l) / 2;
                if (arr[m].first == q)
                    break;
                else if (arr[m].first > q)
                    r = m - 1;
                else if (arr[m].first < q)
                    l = m + 1;
            }
            return m;
        };

        for (const int query : queries) {
            int m{binarySearch(query, 0, j)};
            /* cout << "query: " << query << " m: " << m
                 << " price: " << arr[m].first << '\n'; */
            if (arr[m].first > query && m - 1 >= 0)
                answer.push_back(arr[--m].second);
            else if (query < arr[m].first)
                answer.push_back(0);
            else
                answer.push_back(arr[m].second);
        }

        return answer;
    }
};

// clang-format off
ostream &operator<<(ostream &c, vector<int> arr) {
    c << '[';
    for (int &e : arr) c << e << ',';
    c << "\b]\n---\n";
    return c;
}

typedef pair<vector<vector<int>>, vector<int>> testcase;

int main() {
    auto test = bind(Solution::maximumBeauty, placeholders::_1, placeholders::_2);
    testcase e1{{{{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}}},
        {1,2,3,4,5,6}};
    testcase e2{{{{1, 2}, {1, 2}, {1, 3}, {1, 4}}},
        {1}};
    testcase e3{{{{10, 1000}}},
        {5}};
    testcase e4{{{{1, 1}, {2, 1}}},
        {1}};
    testcase e5{{{{1'000'000'000, 1'000'000'000}}},
        {1}};
    testcase e6{{{{1'000'000'000, 1'000'000'000}}},
        {1'000'000'000}};
    testcase e7{{{{2000, 1}, {1'000'000'000, 1}}},
        {1'000'000'000}};
    testcase e8{{{{1, 1,}, {2, 2}, {1'000'000'000, 1'000'000'000}, {3, 100'000}}},
        {1, 2, 1'000'000'000, 3}};
    cout << test(e1.first, e1.second); // [2,4,5,5,6,6]
    cout << test(e2.first, e2.second); // [4]
    cout << test(e3.first, e3.second); // [0]
    cout << test(e4.first, e4.second); // [1]
    cout << test(e5.first, e5.second); // [0]
    cout << test(e6.first, e6.second); // [1000000000]
    cout << test(e7.first, e7.second); // [1]
    cout << test(e8.first, e8.second); // [1,2,1000000000,100000]
}
