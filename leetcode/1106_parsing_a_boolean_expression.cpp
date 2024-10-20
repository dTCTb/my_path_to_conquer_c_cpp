#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
  public:
    static bool parseBoolExpr(string expression) noexcept {
        stack<char> sk;
        for (int i{(int)expression.size() - 1}; i >= 0; --i) {
            switch (expression[i]) {
            case ')':
            case 'f':
            case 't':
                sk.push(expression[i]);
                break;
            case '&':
                parse_and(sk);
                break;
            case '|':
                parse_or(sk);
                break;
            case '!':
                parse_not(sk);
                break;
            default: // ( ,
                break;
            }
        }
        return sk.top() == 't' ? true : false;
    }

  private:
    static void parse_and(stack<char> &sk) noexcept {
        array<char, 2> boolean{};
        parser(sk, boolean);
        if (boolean[0] == 0)
            sk.push('t');
        else
            sk.push('f');
    }
    static void parse_or(stack<char> &sk) noexcept {
        array<char, 2> boolean{};
        parser(sk, boolean);
        if (boolean[1] != 0)
            sk.push('t');
        else
            sk.push('f');
    }
    static void parse_not(stack<char> &sk) noexcept {
        char tmp{sk.top()};
        sk.pop();
        sk.pop(); // remove ')'
        if (tmp == 't')
            sk.push('f');
        else
            sk.push('t');
    }
    // extract and count 't' & 'f' until ')' then discard/pop ')'
    static void parser(stack<char> &sk, array<char, 2> &boolean) noexcept {
        while (sk.top() != ')') {
            if (sk.top() == 'f')
                ++boolean[0];
            else
                ++boolean[1];
            sk.pop();
        }
        sk.pop(); // remove ')'
    }
};

int main() {
    cout << boolalpha;
    cout << Solution::parseBoolExpr("&(|(f))") << '\n';    // false
    cout << Solution::parseBoolExpr("|(f,f,f,t)") << '\n'; // true
    cout << Solution::parseBoolExpr("!(&(f,t))") << '\n';  // true
    cout << Solution::parseBoolExpr("|(&(t,f,t,!(&(|(f,f,f,f)))),t)")
         << '\n'; // true
}
