// clang-format off
#include <functional>
#include <iostream>
#include <stack>
#include <string>

#define BLUC "\033[38;5;109m"
#define ORAC "\033[38;5;208m"
#define RESET "\033[0m"
#define DEBUG
using namespace std;

class Solution {
  public:
    static long long minimumSteps(string s) {
        long long count{};
        stack<size_t> sk;

        for (size_t i{}; i < s.size(); ++i)
            if (s[i] == '1') sk.push(i);

#ifdef DEBUG
        print(s, true);
#endif
        for (size_t i{s.size() - 1}; i > 0 && !sk.empty(); --i) {
            if (i == sk.top()) {
                sk.pop();
                continue;
            }
            if (s[i] != '1') { // stop at '0'
                size_t cur = sk.top();
#ifdef DEBUG
                print(s, cur, i);
#endif
                swap(s, cur, i);
#ifdef DEBUG
                print(s, i, cur);
#endif
                count += i - cur;
                sk.pop();
            }
        }
#ifdef DEBUG
        print(s, true);
#endif

        return count;
    }

    static long long brutal_minimumSteps(string s) {
        if (s.size() > 50) {
            cout << "The string is too long with " << s.size()
                 << " characters consider not to use this brutal method\n";
            return -1;
        }

        long long count{};

        function<bool(size_t)> checkZero = [&s](size_t cur) -> bool {
            for (size_t i{}; i < cur; ++i)
                if (s[i] == '1') return false;
            return true;
        };

#ifdef DEBUG
        print(s, true);
#endif
        for (size_t i{s.size() - 1}; i > 0; --i) {
            if (checkZero(i)) break;
            if (s[i] != '1') { // stop at '0'
                size_t cur{i - 1};
                while (s[cur] != '1') // stop at the nearest '1'
                    --cur;
                for (; cur < i; ++cur, ++count) {
#ifdef DEBUG
                    print(s, cur, cur + 1);
#endif
                    swap(s, cur, cur + 1);
                }
            }
        }
#ifdef DEBUG
        print(s, true);
#endif
        return count;
    }

  private:
    static void swap(string &s, size_t l, size_t r) {
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
    }
    static void print(string &s, bool color = false) {
        if (!color) cout << s;
        else for (char e : s)
                cout << (e == '0' ? ORAC : BLUC) << e << RESET;
        cout.put('\n');
    }

    static void print(string &s, size_t l, size_t r) {
        for (size_t i{}; i < s.size(); ++i)
            if (i == l)      cout << BLUC << s[i] << RESET;
            else if (i == r) cout << ORAC << s[i] << RESET;
            else             cout << s[i];
        cout.put('\n');
    }
};

int main() {
#include "TestCases/2938_testcase.txt"
    cout << Solution::minimumSteps(s1) << '\n';
    cout << Solution::minimumSteps(s2) << '\n';
    cout << Solution::minimumSteps(s3) << '\n';
    cout << Solution::minimumSteps(s4) << '\n';
    cout << Solution::minimumSteps(s5) << '\n'; // 101010100010001
    cout << Solution::minimumSteps(s6) << '\n';
    // cout << Solution::minimumSteps(s7) << '\n';
    cout << Solution::brutal_minimumSteps(s5) << '\n';
}
