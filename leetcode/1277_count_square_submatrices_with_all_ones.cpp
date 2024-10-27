// clang-format off
#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<std::vector<int>> input;

class Solution {
  public:
    static int countSquares(input &matrix) noexcept
    {
        int result{};

        for (size_t i{}; i < matrix.size(); ++i)
            for (size_t j{}; j < matrix[i].size(); ++j)
                if (matrix[i][j] == 1)
                {
                    ++result;
                    if (i + 1 < matrix.size() && j + 1 < matrix[i].size())
                        check(matrix, i, j, 1, result);
                }

        return result;
    }

  private:
    static void check(const input &m, size_t i, size_t j, size_t o /*ffset*/, int &r) noexcept
    {
        for (size_t i_i{}; i_i < o; ++i_i)
            if (m[i + i_i][j + o] == 0)
                return;

        for (size_t j_j{}; j_j < o; ++j_j)
            if (m[i + o][j + j_j] == 0)
                return;

        if (m[i + o][j + o] == 0)
            return;

        ++r;

        if (i + o + 1 < m.size() && j + o + 1 < m[i].size())
            check(m, i, j, o + 1, r);
    }
};

void print_matrix(input &m) noexcept
{
    function<void(const char *, const char *)> p = [&m](const char *a, const char *b) -> void
    {
        cout << a;
        for (size_t i{}; i < m[0].size(); ++i) cout << "  ";
        cout << '\b' << b << '\n';
    };

    p("┌ "," ┐");

    for (vector<int> &inner : m)
    {
        cout << "  ";
        for (int &e : inner) cout << e << ' ';
        cout << "\b \n";
    }

    p("└ ", " ┘");
}

void runTest(input &eg) noexcept {
    static int i{};
    cout << "\nTestCase #" << ++i << ":\n";
    if (eg.size() < 30 && eg[0].size() < 30) print_matrix(eg);
    cout << Solution::countSquares(eg) << '\n';
}

int main() noexcept {
#include "TestCases/1277_testcase.txt"
    runTest(e1);  // 15
    runTest(e2);  // 7
    runTest(e3);  // 3
    runTest(e4);  // 9
    runTest(e5);  // 13
    runTest(e6);  // 14
    runTest(e7);  // 19
    runTest(e8);  // 1450
    runTest(e9);  // 2644
    runTest(e10); // 4996
}
