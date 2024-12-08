#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// #define DEBUG
enum CONST { START, END, VALUE };
typedef std::vector<int> vInt;
typedef std::vector<vInt> vvInt;

struct byStartAsc {
    bool operator()(const vInt &l, const vInt &r) noexcept {
        return l[START] < r[START];
    }
};

class Solution {
  public:
    static int maxTwoEvents(vvInt &events) noexcept {
        int answer{};

        sort(events.begin(), events.end(), byStartAsc());
        vInt dp{dpMaxValue(events)};

#if defined DEBUG
        print(events, dp);
#endif
        for (int i{}; i < events.size(); ++i) {
            int nextEventIdx{nearestNextEvent(events, i)};
            answer = nextEventIdx != -1
                         ? max({answer, events[i][VALUE] + dp[nextEventIdx]})
                         : answer = max({answer, events[i][VALUE]});
#if defined DEBUG
            cout << "i: " << i << " -> " << nextEventIdx << '\n';
#endif
        }
        return answer;
    }

    // binary search to find next nearest non-overlapping event
    static int nearestNextEvent(const vvInt &e, int i) noexcept {
        if (e[i][END] >= e.back()[START])
            return -1;
        int l{i + 1}, m{}, r{static_cast<int>(e.size() - 1)};
        while (l <= r)
            if (m = (l + r) / 2; e[m][START] > e[i][END])
                r = m - 1;
            else
                l = m + 1;
        return e[m][START] > e[i][END] ? m : m + 1;
    }

    // dynamic programming to store maximum value for each event
    static vInt dpMaxValue(const vvInt &e) noexcept {
        vInt dp(e.size(), 0);
        dp.front() = e.front()[VALUE];
        dp.back() = e.back()[VALUE];
        int tmpMax{dp.back()};
        for (size_t i{e.size() - 2}; i > 0; --i)
            dp[i] = tmpMax = e[i][VALUE] > tmpMax ? e[i][VALUE] : tmpMax;
        return dp;
    }

#if defined DEBUG
    static void print(const vvInt &arr, const vInt &dp) noexcept {
        int count{};
        cout << setw(sizeof("[00000]") - 1) << "index" << setw(9) << "start"
             << setw(9) << "end" << setw(9) << "value" << setw(9) << "max"
             << '\n';
        for (const vInt &e : arr)
            cout << '[' << setw(5) << count << ']' << setw(9) << e[START]
                 << setw(9) << e[END] << setw(9) << e[VALUE] << setw(9)
                 << dp[count++] << '\n';
        cout.put('\n');
    }
#endif
};

typedef Solution S;
typedef std::tuple<std::vector<vector<int>>, int> testcase;
typedef std::unordered_map<size_t, testcase> testcases;

ostream &operator<<(ostream &c, testcases::value_type &t) noexcept {
    size_t no{t.first};
    auto &[events, answer]{t.second};
    c << "Testcase " << no << '\n';
    int myAnswer{S::maxTwoEvents(events)};
    c << (myAnswer == answer ? "Correct" : "Incorrect") << ", the answer is "
      << answer;
    cout << "\n- -- - -- - -- - -- - -- - -- -\n";
    return c;
}

int main() {
    // clang-format off
    testcases testcases{
        {1, {vvInt{{1, 3, 2}, {4, 5, 2}, {2, 4, 3}}, 4}},
        {2, {vvInt{{1, 3, 2}, {4, 5, 2}, {1, 5, 5}}, 5}},
        {3, {vvInt{{1, 5, 3}, {1, 5, 1}, {6, 6, 5}}, 8}},
        {4, {vvInt{{35, 90, 47}, {72, 80, 70}}, 70}},
        {5, {vvInt{{1, 3, 5}, {3, 7, 10}, {6, 7, 4}, {4, 8, 2}}, 10}},
        {6, {vvInt{{63, 87, 45}, {97, 100, 32}, {10, 83, 53}, {51, 61, 16}}, 85}},
        {7, {vvInt{{6, 6, 6}, {7, 9, 4}, {4, 5, 4}, {3, 7, 9}, {6, 10, 8}, {4, 7, 6}}, 12}},
        {8, {vvInt{{1, 2, 2}, {2, 2, 1}, {2, 2, 1}, {1, 2, 2}, {1, 1, 2}, {1, 2, 1}, {2, 2, 2}}, 4}},
        {9, {vvInt{{4, 9, 7}, {4, 5, 6}, {3, 6, 4}, {6, 6, 5}, {7, 9, 4}, {5, 10, 8}, {4, 9, 10}, {3, 5, 1}}, 11}},
        {10, {vvInt{{91, 100, 42}, {92, 100, 22}, {1, 77, 50}, {66, 97, 90}, {98, 98, 68}, {38, 49, 63}, {64, 72, 97}}, 165}}
    };
    cout << *testcases.find(1);
    cout << *testcases.find(2);
    cout << *testcases.find(3);
    cout << *testcases.find(4);
    cout << *testcases.find(5);
    cout << *testcases.find(6);
    cout << *testcases.find(7);
    cout << *testcases.find(8);
    cout << *testcases.find(9);
    cout << *testcases.find(10);
}
