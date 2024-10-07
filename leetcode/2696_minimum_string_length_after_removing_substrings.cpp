#include "../termcolor.h"
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
  public:
    /* recursive (most concise but require lots of resource) */
    static int recursive_minLength(const string &s) noexcept {
        for (size_t i{}; i < s.size() - 1 && s.size() >= 2; ++i) {
            if (s.substr(i, 2) == "AB" || s.substr(i, 2) == "CD") {
                if (i == 0)
                    return minLength(s.substr(i + 2));
                else
                    return minLength(s.substr(0, i) + s.substr(i + 2));
            }
        }
        return static_cast<int>(s.size());
    }

    /* two stacks */
    static int minLength(const string &s) noexcept {
        stack<char> l{}, r{};

        for (int i{static_cast<int>(s.size()) - 1}; i >= 0; --i)
            r.push(s[i]);

        function<void(stack<char> &, stack<char> &)> shiftOne =
            [](stack<char> &from, stack<char> &to) -> void {
            to.push(from.top());
            from.pop();
        };

        shiftOne(r, l);
        while (!r.empty()) {
            if (l.top() == 'A' && r.top() == 'B' ||
                l.top() == 'C' && r.top() == 'D') {
                l.pop();
                r.pop();
                if (l.empty() && !r.empty())
                    shiftOne(r, l);
                continue;
            }
            shiftOne(r, l);
        }
        return l.size();
    }

    /* force, brutal & blood (dumb way) */
    static int brutal_minLength(const string &s) noexcept {
        stack<char> sk{}, tmp{};
        for (auto ri{s.crbegin()}; ri != s.crend(); ++ri)
            sk.push(*ri);
        while (true) {
            bool keepGoing{false};
            while (sk.size() >= 2) {
                char c1 = sk.top();
                sk.pop();
                if (c1 == 'A' && sk.top() == 'B' ||
                    c1 == 'C' && sk.top() == 'D') {
                    sk.pop();
                    keepGoing = true;
                    break;
                } else {
                    tmp.push(c1);
                }
            }

            while (!tmp.empty()) {
                sk.push(tmp.top());
                tmp.pop();
            }
            if (!keepGoing)
                break;
        }
        return sk.size();
    }
};

struct TestCase {
    // clang-format off
    string s;
    int ans;
    TestCase(const string &s, const int &ans) : s{s}, ans{ans} {}
    void test() {
        static size_t no{};
        int myAns{Solution::minLength(s)};
        cout << BLUC "Testcase "; cout.width(2); cout << right << ++no << RESET;
        cout << "\nMy answer " << PURC << myAns << RESET;
        if (myAns == ans) cout << " is " GRE("Correct!\n");
        else cout << " is " RED("Wrong") << ", Correct answer is " << ORAC << ans << RESET << '\n';
    }
    // clang-format on
};

int main() {
    TestCase eg1{"CCADDADDDBBCDDBABACADABAABADCABDCCBDACBDBAADDABCABBCABBDDAABC"
                 "BCBBCCCDBCDDDADAACBCACDDBBA",
                 62};
    TestCase eg2{"DCDCBCBDACBBABDABABCCCBABCCCCCCCBDDBCDACDADABADDCDBBC", 35};
    TestCase eg3{"BBBDCADCDACACDBBCACDACDABCBCDDADCDCACCDDBCACCDDDCCBCDBDCBDDCB"
                 "CBBCCBBBAACBBB",
                 47};
    TestCase eg4{
        "BCDDBCCCCBACCADDCBDADDCCABCCCBACAADDADCDAACABDDDDABBACBABCABCCDCABBA",
        48};
    TestCase eg5{"RZAAAACCCCCAABBDDDDDBBBBYAAAAAAACAACAACACCAAAACCACCDDBDDBBBBD"
                 "DBDBBDBBDBBBBBBBMBSCACCACDBDDBDACCDDBCD",
                 6};
    TestCase eg6{"DCAACCCCCCACCCAACAABBDBBDDDBDDDDDDBBDPCAACAAACAAAAAACDBBBBBBD"
                 "BBBDBBDACCCAAABBBDDDAACACDBDBBCAACDBBDP",
                 4};
    TestCase eg7{"AXFCCCCCACCACCCAACAACACACAACCAAABBBDDBBDBDBDBBDBBDDDBDDBDDDDD"
                 "CCACDBDDCABD",
                 3};
    TestCase eg8{"ACACACACACACACACACACACACACACACACACACACACACACACACACDBDBDBDBDBD"
                 "BDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDBDB",
                 0};
    TestCase *testCases[] = {&eg1, &eg2, &eg3, &eg4, &eg5, &eg6, &eg7, &eg8};
    for (TestCase *eg : testCases)
        eg->test();
}
