#include <cctype>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
  public:
    static string clearDigits(const string &s) noexcept {
        cout << s << ' ';
        const string ans{mySolve(s)};
        cout << " ans: " << ans << '\n';
        return ans;
    }

    /* 0ms 9.86mb */
    static string mySolve(const string &s) noexcept {
        stack<char> sk, tmp;
        bool noDigit{true};
        for (const char ch : s) {
            if (isdigit(ch)) {
                noDigit = false;
                while (!sk.empty() && !isalpha(sk.top())) {
                    tmp.push(sk.top());
                    sk.pop();
                }
                sk.pop();
                while (!tmp.empty()) {
                    sk.push(tmp.top());
                    tmp.pop();
                }
                continue;
            }
            sk.push(ch);
        }
        if (noDigit)
            return s;

        string ans;
        ans.reserve(sk.size());
        while (!sk.empty()) {
            ans.push_back(sk.top());
            sk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// clang-format off
int main() {
    Solution::clearDigits("abc");           // "abc"
    Solution::clearDigits("cb34");          // ""
    Solution::clearDigits("a");             // "a"
    Solution::clearDigits("xzuzr2ghilydk"); // "xzuzghilydk"
    Solution::clearDigits("qm93xjkpaaovhqckjhg5j1o4rndtg3bobgeke"); // "xjkpaaovhqckjhrndtbobgeke"
    Solution::clearDigits("pl5v0jttxe9acvd0t9vtxwrhvwajpasfe2nhtws48pweam4vsomd79nw14ed");  // "pjttxacvvtxwrhvwajpasfnhtpweavsoed"
    Solution::clearDigits("rrytkz6w5qwniszr6duuec0lqbeds3qdbzimoszqwxng5c02vxse03hpoarbu"); // "rrytkqwniszduuelqbedqdbzimoszqwxvxhpoarbu"
    Solution::clearDigits("wezofxhb44upfwyci72gbi2jwdxxank64yxvr677aegwl7jzgqlof4z9neisjq88pj1pvq98q");        // "wezofxupfwygbjwdxxayaegwjzgqloneisppq"
    Solution::clearDigits("g8dsianl4u49d3froonbnkrw83qzmdbh114lidlc2bv95s2pzwzuimi3ef443txu5d6h8ng5j5stu32y"); // "dsiafroonbnkqzmlidlpzwzuitxnsy"
    Solution::clearDigits("sl2yqa6z8i0eqyqnla250rh8olipeu4oie5t16n8p2n67e391n01s7ol11qg93u6tuoy55no117861sj4wfno27p65212"); // "syqeqyq"
}
