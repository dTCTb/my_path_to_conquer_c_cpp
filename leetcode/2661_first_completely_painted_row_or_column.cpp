#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
typedef std::vector<vInt> vvInt;
typedef std::unordered_map<int, std::unordered_set<int>> vMap;
class Solution {
  public:
    static int firstCompleteIndex(const vInt &arr, const vvInt &mat) noexcept {
        return solve3(arr, mat);
    }
    /* O(m * n), 415ms 269.91mb */
    static int solve1(const vInt &arr, const vvInt &mat) noexcept {
        vMap matMap[2]{}; // 0: row, 1: col
        unordered_map<int, pair<int, int>> p{};
        size_t rows{mat.size()}, cols{mat[0].size()};
        for (size_t i{}; i < rows; ++i) {
            for (size_t j{}; j < cols; ++j) {
                matMap[0][i].insert(mat[i][j]);
                matMap[1][j].insert(mat[i][j]);
                p[mat[i][j]] = make_pair(i, j);
            }
        }
        cout << "rows:\n";
        print(matMap[0]);
        cout << "cols:\n";
        print(matMap[1]);
        for (size_t i{}; i < arr.size(); ++i) {
            const auto &[x, y] = p[arr[i]];
            matMap[0][x].erase(arr[i]);
            if (matMap[0][x].size() == 0)
                return i;
            matMap[1][y].erase(arr[i]);
            if (matMap[1][y].size() == 0)
                return i;
        }
        return 0;
    }
    /* 142ms 178.90mb */
    static int solve2(const vInt &arr, const vvInt &mat) noexcept {
        unordered_map<int, int> matMap[2]{}; // 0: row, 1: col
        unordered_map<int, pair<int, int>> p{};
        size_t rows{mat.size()}, cols{mat[0].size()};
        for (size_t i{}; i < rows; ++i) {
            for (size_t j{}; j < cols; ++j) {
                ++matMap[0][i];
                ++matMap[1][j];
                p[mat[i][j]] = make_pair(i, j);
            }
        }
        for (size_t i{}; i < arr.size(); ++i) {
            const auto &[x, y] = p[arr[i]];
            if (--matMap[0][x] == 0 || --matMap[1][y] == 0)
                return i;
        }
        return 0;
    }
    /* 35ms 129.9mb */
    static int solve3(const vInt &arr, const vvInt &mat) noexcept {
        int matMap[2][100'001]{}; // 0: row, 1: col
        pair<int, int> p[100'001]{};
        size_t rows{mat.size()}, cols{mat[0].size()};
        for (size_t i{}; i < rows; ++i) {
            for (size_t j{}; j < cols; ++j) {
                ++matMap[0][i];
                ++matMap[1][j];
                p[mat[i][j]] = make_pair(i, j);
            }
        }
        for (size_t i{}; i < arr.size(); ++i) {
            const auto &[x, y] = p[arr[i]];
            if (--matMap[0][x] == 0 || --matMap[1][y] == 0)
                return i;
        }
        return 0;
    }
    static void print(const vMap &matMap) noexcept {
        for (const auto &map : matMap) {
            cout << map.first << ": ";
            for (const auto v : map.second)
                cout << v << ", ";
            cout << "\b\b \n";
        }
    }
};

int main() {
    int ans1 = Solution::firstCompleteIndex({1, 3, 4, 2}, {{1, 4}, {2, 3}});
    cout << "ans: " << ans1 << '\n';
    int ans2 = Solution::firstCompleteIndex({2, 8, 7, 4, 1, 3, 5, 6, 9},
                                            {{3, 2, 5}, {1, 4, 6}, {8, 7, 9}});
    cout << "ans: " << ans2 << '\n';
    int tictactoe = Solution::firstCompleteIndex(
        {2, 5, 8}, {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    cout << "tictactoe: " << tictactoe << '\n';
}
