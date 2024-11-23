#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<char> vChar;
typedef std::vector<std::vector<char>> vvChar;

class Solution {
  public:
    static vvChar rotateTheBox(const vvChar &box) noexcept {
        int boxRow{(int)box.size()}, boxCol{(int)box[0].size()};
        int row{boxCol}, col{boxRow};
        vvChar ans(row, vChar(col, '.'));

        // rotate clockwise 90'
        for (int r{}; r < box.size(); ++r)
            for (int c{}; c < box[0].size(); ++c)
                ans[c][col - 1 - r] = box[r][c];

        // adding gravity
        for (int c{}, p{row - 1}, o{row - 1}; c < col; ++c) {
            for (int r{row - 1}; r >= 0; --r) {
                while (p >= 0 && (ans[p][c] != '#' || p == r))
                    --p;
                while (o >= 0 && (ans[o][c] != '*' || o == r))
                    --o;
                if (ans[r][c] == '.' && r > o && p > o && r > p)
                    swap(ans[r][c], ans[p--][c]);
            }
            p = o = row - 1;
        }

        return ans;
    }
};

struct Tools {
    static void pRowCol(const vvChar &arr) noexcept {
        cout << "row: " << arr.size() << " col: " << arr[0].size() << '\n';
    }

    static void pArr(const vvChar &arr) noexcept {
        for (const vChar &row : arr) {
            for (const char &col : row)
                cout << col << ' ';
            cout.put('\n');
        }
    }
};

typedef pair<const vvChar, const vvChar> testcase;
auto test = bind(Solution::rotateTheBox, placeholders::_1);
ostream &operator<<(ostream &c, const testcase &t) {
    static size_t no{1};
    auto &[testcase, answer] = t;

    cout << "Testcase " << no++ << ":\n";
    Tools::pRowCol(testcase);
    Tools::pArr(testcase);

    vvChar myAnswer = test(t.first);
    Tools::pRowCol(myAnswer);

    vvChar compare(myAnswer); // concat myAnswer and answer into one 2D-array
    for (size_t i{}; i < myAnswer.size(); ++i) {
        compare[i].insert(compare[i].end(), {' ', '|', ' '});
        compare[i].insert(compare[i].end(), answer[i].begin(), answer[i].end());
    }
    Tools::pArr(compare);
    c << (myAnswer == t.second ? "Correct" : "Incorrect") << '\n';
    c << "- -- - -- -\n";
    return c;
}

int main() {
#include "./TestCases/1861_testcase.txt"
    cout << e1;
    cout << e2;
    cout << e3;
    cout << e4;
    cout << e5;
    cout << e6;
    cout << e7;
    cout << e8;
    cout << e9;
    cout << e10;
    cout << e11;
}
