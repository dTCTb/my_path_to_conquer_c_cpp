#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
typedef std::vector<vInt> vvInt;
typedef std::vector<bool> vBool;
typedef std::vector<vBool> vvBool;
class Solution {
  public:
    /* O(Row * Col) 6ms 96.53mb */
    static int findMaxFish(const vvInt &grid) noexcept {
        const size_t row{grid.size()}, col{grid[0].size()};
        vvBool visit(row, vBool(col, false));
        int ans{};

        for (int r{}; r < row; ++r) {
            for (int c{}; c < col; ++c) {
                int tmp{};
                if (visit[r][c] || grid[r][c] == 0)
                    continue;
                else
                    tmp = walk(grid, visit, r, c);
                ans = max(ans, tmp);
            }
        }

        // cout << "ans: " << ans << '\n';
        return ans;
    }

    static int walk(const vvInt &grid, vvBool &visit, const int r,
                    const int c) noexcept {
        const size_t row{grid.size()}, col{grid[0].size()};
        int ret{grid[r][c]};
        if (visit[r][c] || ret == 0)
            return 0;
        visit[r][c] = true;
        if (c > 0) // move left
            ret += walk(grid, visit, r, c - 1);
        if (c < col - 1) // move right
            ret += walk(grid, visit, r, c + 1);
        if (r > 0) // move up
            ret += walk(grid, visit, r - 1, c);
        if (r < row - 1) // move down
            ret += walk(grid, visit, r + 1, c);
        return ret;
    }
};

int main() {
    auto test = bind(Solution::findMaxFish, placeholders::_1);
    test(
        vvInt{vInt{0, 2, 1, 0}, {4, 0, 0, 3}, {1, 0, 0, 4}, {0, 3, 2, 0}}); // 7
    test(
        vvInt{vInt{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 1}}); // 1
    test(vvInt{vInt{4, 5, 5}, {0, 10, 0}}); // 24
}
