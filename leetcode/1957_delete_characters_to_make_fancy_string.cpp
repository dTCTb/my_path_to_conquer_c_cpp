#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    static string makeFancyString(const string &s) noexcept {
        if (s.size() < 3)
            return s;

        return method1(s);
    }

    static string method1(const string &s) noexcept {
        string ret{s[0]};
        ret.reserve(s.size() - 1);

        for (size_t i{1}; i < s.size(); ++i) {
            if (ret.back() == s[i] && i < s.size() - 1 && s[i] == s[i + 1]) {
                char tmp{s[i]};
                while (s[i] == tmp)
                    ++i;
                ret.push_back(s[--i]);
            } else
                ret.push_back(s[i]);
        }

        return ret;
    }

    static string method2(const string &s) noexcept {
        string ret{};
        ret.reserve(s.size());
        int i{};

        for (const char &c : s) {
            ++i;
            if (!ret.empty() && ret.back() != c)
                i = 1;
            if (i < 3)
                ret.push_back(c);
        }
        return ret;
    }
};

int main() {
    ;
    ;
}
