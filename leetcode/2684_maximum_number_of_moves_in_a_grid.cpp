#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    static int maxMoves(const vector<vector<int>> &grid) noexcept {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        printTwoDArr(grid);
        int max{};
        for (int i{}; i < grid.size(); ++i) {
            // cout << "=== ";
            int tmp = go(dp, grid, i, 0, 0);
            // cout << "===\n";
            max = tmp > max ? tmp : max;
        }
        printTwoDArr(dp);
        return max - 1;
    }

  private:
    static int go(vector<vector<int>> &dp, const vector<vector<int>> &grid,
                  int i, int j, int prev) noexcept {
        if (i == grid.size() || i < 0 || j == grid[0].size() ||
            grid[i][j] <= prev)
            return 0;

        if (dp[i][j] != 0)
            return dp[i][j];

        // cout << grid[i][j] << ' ';

        int r[3]{0};
        r[0] = go(dp, grid, i - 1, j + 1, grid[i][j]);
        r[1] = go(dp, grid, i, j + 1, grid[i][j]);
        r[2] = go(dp, grid, i + 1, j + 1, grid[i][j]);
        dp[i][j] = 1 + max({r[0], r[1], r[2]});

        return dp[i][j];
    }

    template <int width = 7, typename T>
    static void printTwoDArr(const vector<vector<T>> &twoDArr) noexcept {
        if (twoDArr[0].size() < 15)
            for (const vector<int> &x : twoDArr) {
                for (const int &y : x)
                    cout << setw(width) << y;
                cout.put('\n');
            }
    }
};

int main() {
#include "TestCases/2684_testcase.txt"
    cout << Solution::maxMoves(eg1) << '\n';
    cout << Solution::maxMoves(eg2) << '\n';
    cout << Solution::maxMoves(eg3) << '\n';
    cout << Solution::maxMoves(eg4) << '\n';
    cout << Solution::maxMoves(eg5) << '\n';
    cout << Solution::maxMoves(eg6) << '\n';
    cout << Solution::maxMoves(eg7) << '\n';
    cout << Solution::maxMoves(eg8) << '\n';
    cout << Solution::maxMoves(eg9) << '\n';
    cout << Solution::maxMoves(eg10) << '\n';
}
