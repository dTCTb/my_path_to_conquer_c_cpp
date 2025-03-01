#include <iostream>
#include <vector>

using namespace std;

#define MAX_ROW 250 + 1
#define MAX_COL 250 + 1
typedef std::vector<int> vInt;
typedef std::vector<vInt> vvInt;
class Solution {
  public:
    static int countServers(const vvInt &grid) noexcept { return solve2(grid); }

    /* O(n * km) 0ms 26.20mb */
    static int solve2(const vvInt &grid) noexcept {
        const size_t rowSize{grid.size()};
        const size_t colSize{grid[0].size()};
        int mark[MAX_ROW][MAX_COL]{};
        int atSameRow{}, atSameCol{};

        for (int i{}; i < rowSize; ++i) {
            int count{};
            for (int j{}; j < colSize; ++j)
                count += grid[i][j] ? 1 : 0;
            if (count > 1)
                for (int j{}; j < colSize; ++j)
                    mark[i][j] += grid[i][j] ? 1 : 0;
            atSameRow += count > 1 ? count : 0;
        }
        cout << "atSameRow: " << atSameRow << '\n';
        print_arr(mark, rowSize, colSize);

        for (int j{}; j < colSize; ++j) {
            int count{}, ddt{};
            for (int i{}; i < rowSize; ++i)
                if (grid[i][j] && (++count, ++mark[i][j] == 2))
                    ++ddt;
            atSameCol += count > 1 ? count - ddt : 0;
        }
        cout << "atSameCol: " << atSameCol << '\n';
        print_arr(mark, rowSize, colSize);

        cout << "ans: " << atSameRow + atSameCol << "\n\n";
        return atSameRow + atSameCol;
    }

    static void print_arr(const int (*p)[MAX_COL], const int r,
                          const int c) noexcept {
        for (int i{}; i < r; ++i) {
            for (int j{}; j < c; ++j)
                cout << *(*(p + i) + j) << ' ';
            cout.put('\n');
        }
    }

    /* trial 1: target O(n) but fail */
    static int solve1(const vvInt &grid) noexcept {
        int atSameRow{}, atSameCol{};
        int mark[2][250 + 1]{};
        const size_t rowSize{grid.size()};
        const size_t colSize{grid[0].size()};
        for (int i{}, j{}; i < rowSize || j < colSize; ++i, ++j) {
            int fi{i}, fj{j}, count{};

            while (fi < rowSize) {
                if (grid[fi][j]) {
                    ++count;
                    ++mark[0][fi];
                }
                ++fi;
            }
            cout << "row count: " << count << ", ";
            atSameRow += count > 1 ? count : 0;

            count = 0;
            while (fj < colSize) {
                if (grid[i][fj]) {
                    ++count;
                    ++mark[1][fj];
                }
                ++fj;
            }
            cout << "col count: " << count << "  ";
            cout << '(' << mark[0][i] << ", " << mark[1][j] << ")\n";
            atSameCol += count > 1 ? count : 0;
        }
        cout << "count: " << atSameRow + atSameCol << "\n\n";
        return atSameRow + atSameCol;
    }
};

int main() {
    auto test = bind(Solution::countServers, placeholders::_1);
    test(vvInt{vInt{1, 0}, {0, 1}}); // 0
    test(vvInt{vInt{1, 0}, {1, 1}}); // 3
    test(
        vvInt{vInt{1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}}); // 4
}
