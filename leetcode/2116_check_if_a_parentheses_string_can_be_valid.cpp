#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
  public:
    static bool canBeValid(const string s, const string locked) noexcept {
        if (s.size() % 2) {
            cout << " false\n";
            return false;
        }

        stack<int> free{}, left{};
        for (size_t i{}; i < s.size(); ++i) {
            if (locked[i] == '0')
                free.push(i);
            else if (s[i] == '(')
                left.push(i);
            else /* if (s[i] == ')') */ {
                if (!left.empty())
                    left.pop();
                else if (!free.empty())
                    free.pop();
                else
                    return false;
            }
        }

        while (!left.empty() && !free.empty() && left.top() < free.top())
            left.pop(), free.pop();

        return left.empty();
    }
};

int main() {
    using namespace placeholders;
    auto test = bind(Solution::canBeValid, _1, _2);
    cout << boolalpha;
    test("))()))", "010100"); // true
    cout.put('\n');
    test("()()", "0000"); // true
    cout.put('\n');
    test(")", "0"); // false
    cout.put('\n');
    test("()))", "0010"); // true
    cout.put('\n');
    test("()", "11"); // true
    cout.put('\n');
    test("((())(((()()", "100000111010"); // false
    cout.put('\n');
    test("()()()()(((()(", "10000000000001"); // false
    cout.put('\n');
    test("((()(()()))()((()()))))()((()(()",  // 155/258
         "10111100100101001110100010001001"); // true
    cout.put('\n');
    test("(()())",  // 186/258
         "111111"); // true
    cout.put('\n');
    test("())()))()(()(((())(()()))))((((()())(())",  // 218/258
         "1011101100010001001011000000110010100101"); // true
    cout.put('\n');
}

/* class Solution {
  public:
    static bool canBeValid(const string s, const string locked) noexcept {
        if (s.size() % 2)
            return false;

        stack<char> sk{}, proc{};

        for (size_t i{}; i < s.size(); ++i)
            sk.push(locked[i] == '1' ? s[i] : '^');

        print_sk(sk);

        int count{};
        while (!sk.empty()) {
            if (count && sk.top() == '^')
                --count;
            proc.push(sk.top());
            sk.pop();
            if (proc.top() != '^')
                ++count;
        }

        cout << ' ' << (count == 0) << '\n';
        return count == 0;
    }
    static void print_sk(stack<char> sk) noexcept {
        while (!sk.empty()) {
            cout.put(sk.top());
            sk.pop();
        }
        // cout.put('\n');
    }
}; */
