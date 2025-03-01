#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

typedef long long ll;
typedef std::vector<int> vInt;
typedef std::vector<vInt> vvInt;
class Solution {
  public:
    static ll gridGame(vvInt grid) noexcept { return solve(grid); }
    static ll solve(vvInt grid) noexcept {
        long long firstRowSum = accumulate(begin(grid[0]), end(grid[0]), 0LL),
                  secondRowSum = 0;
        long long minimumSum = LONG_LONG_MAX;
        for (int turnIndex = 0; turnIndex < grid[0].size(); ++turnIndex) {
            firstRowSum -= grid[0][turnIndex];
            minimumSum = min(minimumSum, max(firstRowSum, secondRowSum));
            secondRowSum += grid[1][turnIndex];
        }
        return minimumSum;
    }
    static ll myTrial(vvInt grid) noexcept {
        ll row1Sum{}, row2Sum{};

        for (const int point : grid[0])
            row1Sum += point;
        for (const int point : grid[1])
            row2Sum += point;

        cout << "row 1 sum: " << row1Sum << ", row 2 sum: " << row2Sum << '\n';

        row1Sum -= grid[0][0];
        row2Sum -= grid[1][grid[1].size() - 1];
        grid[0][0] = 0;
        grid[1][grid[1].size() - 1] = 0;

        run(grid, row1Sum, row2Sum);

        for (const vInt row : grid) {
            for (const int col : row) {
                cout << col << ' ';
            }
            cout.put('\n');
        }

        ll ans = run(grid, row1Sum, row2Sum);

        cout << "ans: " << ans << '\n';

        return ans;
    }
    static ll run(vvInt &grid, ll &row1Sum, ll &row2Sum) noexcept {
        ll acc{};
        for (size_t i{}, j{}; j < grid[0].size() - 1;) {
            if (i == 0 && row1Sum > row2Sum) {
                row1Sum -= grid[i][++j];
                row2Sum -= grid[1][j - 1];
            } else if (i == 0) {
                row2Sum -= grid[++i][j];
            } else {
                row2Sum -= grid[i][++j];
            }
            acc += grid[i][j];
            grid[i][j] = 0;
            if (i == 0 && j == grid[0].size() - 1) {
                acc += grid[++i][j];
                grid[i][j] = 0;
                break;
            }
        }
        cout << "row 1 sum: " << row1Sum << ", row 2 sum: " << row2Sum << '\n';
        return acc;
    }
};

int main() {
    auto test = bind(Solution::gridGame, placeholders::_1);
    test(vvInt{vInt{2, 5, 4}, {1, 5, 1}});        // 4
    test(vvInt{vInt{3, 3, 1}, {8, 5, 2}});        // 4
    test(vvInt{vInt{1, 3, 1, 15}, {1, 3, 3, 1}}); // 7
}
