#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef std::vector<int> vInt;
typedef std::vector<vInt> vvInt;

class Solution {
  public:
    static ll maxMatrixSum(const vvInt &matrix) noexcept {
        ll sum{};
        int cnt{}, absMin{INT_MAX};

        for (const vInt &row : matrix)
            for (const int &col : row) {
                cnt += col < 0 ? 1 : 0;
                absMin = abs(col) < absMin ? abs(col) : absMin;
                sum += abs(col);
            }

        cout << "count: " << cnt << " sum: " << sum << " min: " << absMin
             << " answer: " << (cnt % 2 == 0 ? sum : sum - absMin * 2) << '\n';

        return cnt % 2 == 0 ? sum : sum - absMin * 2;
    }
};

typedef tuple<const size_t, const vvInt, const ll> testcase;
auto test = bind(Solution::maxMatrixSum, placeholders::_1);

ostream &operator<<(ostream &c, const testcase &t) {
    auto &[no, matrix, answer] = t;
    c << "Testcase " << no << ".\n" << showpos;
    for (const vInt &row : matrix) {
        for (const int &col : row)
            c << setw(8) << col << ' ';
        c.put('\n');
    }
    c << noshowpos;
    ll myAnswer = test(matrix);
    c << (myAnswer == answer ? "Correct" : "Incorrect") << '\n';
    return c;
}

int main() {
    testcase e1{1, {vInt{1, -1}, vInt{-1, 1}}, 4};
    testcase e2{2, {vInt{1, 2, 3}, vInt{-1, -2, -3}, vInt{1, 2, 3}}, 16};
    testcase e3{3, {vInt{2, 9, 3}, vInt{5, 4, -4}, vInt{1, 7, 1}}, 34};
    testcase e4{4, {vInt{0, 0, 0}, vInt{0, 0, 0}, vInt{0, 0, 0}}, 0};
    testcase e5{5,
                {vInt{-9, 9, 9, -9}, vInt{-10, 10, 7, 5}, vInt{4, -8, -9, 6},
                 vInt{10, 2, -6, 1}},
                114};
    cout << e1;
    cout << e2;
    cout << e3;
    cout << e4;
    cout << e5;
}
