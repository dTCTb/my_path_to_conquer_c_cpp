#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
typedef std::vector<vInt> vvInt;

class Solution {
  public:
    static int findChampion(int n, vvInt &edges) noexcept {
        return in_degree(n, edges);
    }

    static int in_degree(int n, vvInt &edges) noexcept {
        vector<int> teams(n, 0);
        for (vInt &loser : edges)
            ++teams[loser[1]];

        int winner{-1}, potential_winner{};
        for (size_t i{}; i < teams.size(); ++i)
            if (teams[i] == 0) {
                ++potential_winner;
                winner = i;
            }
        return potential_winner == 1 ? winner : -1;
    }

    static int bruteForce(int n, vvInt &edges) noexcept {
        if (n == 1)
            return 0;
        vector<int> uni{};
        uni.reserve(n);
        set<int> win, lose;

        if (!edges.empty())
            for (vInt &edge : edges) {
                win.insert(edge[0]);
                lose.insert(edge[1]);
            }

        cout << "win: ";
        for (const int &e : win) {
            cout << e << ' ';
        }
        cout.put('\n');
        cout << "lose: ";
        for (const int &e : lose) {
            cout << e << ' ';
        }
        cout.put('\n');

        set_union(win.cbegin(), win.cend(), lose.cbegin(), lose.cend(),
                  back_inserter(uni));
        if (uni.size() != n)
            return -1;
        for (int &e : uni) {
            cout << e << ' ';
        }
        cout.put('\n');

        set<int> dup{win};
        for (set<int>::value_type e : win) {
            if (lose.find(e) != lose.end())
                dup.erase(e);
        }

        return dup.size() == 1 ? *dup.begin() : -1;
    }
};

typedef tuple<const int, const int, const vvInt, const int> testcase;

ostream &operator<<(ostream &c, const vvInt edges) {
    for (const vInt &edge : edges) {
        for (const int &team : edge)
            c << team << "->";
        c << "\b\b  \n";
    }
    return c;
}

ostream &operator<<(ostream &c, const testcase &t) {
    const auto &[no, n, edges_c, answer] = t;
    vvInt edges{edges_c};
    c << "Testcase " << no << '\n';
    c << "n: " << n << '\n';
    c << edges;
    int myAnswer = Solution::findChampion(n, edges);
    c << "answer: " << answer << "\n";
    c << "my answer: " << myAnswer << "\n";
    c << "\n- -- - -- - -- -\n";
    return c;
}

int main() {
    testcase e1{1, 3, {vInt{0, 1}, vInt{1, 2}}, 0};
    testcase e2{2, 4, {vInt{0, 2}, vInt{1, 3}, vInt{1, 2}}, -1};
    testcase e3{3, 5, {}, -1};
    testcase e4{4, 3, {vInt{0, 1}}, -1};
    testcase e5{5, 4, {vInt{1, 2}, vInt{1, 0}, vInt{1, 3}}, 1};
    testcase e6{6, 4, {vInt{1, 2}, vInt{0, 2}, vInt{0, 3}, vInt{1, 0}}, 1};
    testcase e7{7,
                9,
                {vInt{8, 6}, vInt{6, 3}, vInt{1, 5}, vInt{8, 1}, vInt{8, 5},
                 vInt{1, 4}, vInt{8, 4}, vInt{0, 2}, vInt{0, 6}},
                -1};
    testcase e748{748, 2, {}, -1};
    testcase e756{756, 1, {}, 0};
    cout << e1;
    cout << e2;
    cout << e3;
    cout << e4;
    cout << e5;
    cout << e6;
    cout << e7;
    cout << e748;
    cout << e756;
}
