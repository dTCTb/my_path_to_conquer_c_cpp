#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    static int minimumLength(const string &s) noexcept { return solve2(s); }
    /* slower */
    static int solve1(const string &s) noexcept {
        unordered_map<char, size_t> m;
        size_t ans{};
        for (const char ch : s)
            ++m[ch];
        // print_map(m);
        for (const auto &[ch, count] : m)
            ans += count % 2 ? 1 : 2;
        // cout << "ans: " << ans << '\n';
        return ans;
    }
    /* faster */
    static int solve2(const string &s) noexcept {
        size_t m[26]{};
        size_t ans{};
        for (const char ch : s)
            ++m[ch - 'a'];
        // print_map(m);
        for (const int count : m)
            if (count)
                ans += count % 2 ? 1 : 2;
        // cout << "ans: " << ans << '\n';
        return ans;
    }

    static void print_map(const unordered_map<char, size_t> &m) noexcept {
        for (const auto &[ch, count] : m)
            cout << ch << ": " << count << '\n';
    }
    static void print_map(const size_t *m) noexcept {
        for (size_t i{}; i < 26; ++i)
            cout << *(m + i) << ' ';
        cout.put('\n');
    }
};

int main() {
    using namespace placeholders;
    auto test = bind(Solution::minimumLength, _1);
    test("abaacbcbb");
    test("aa");
    test("ucvbutgkohgbcobqeyqwppbxqoynxeuuzouyvmydfhrprdbuzwqebwuiejoxsxdhbmuai"
         "scalnteocghnlisxxawxgcjloevrdcj");
    test("ggggfhhfuhjsjiksjsjs");
    test("a");
    test("cc");
    test("fffdhsylokalskhgdfkajlskaldskjf");
    test("ecdxxxxhhhhhhhhhhhhhhbbfgfujjiisssjsjjs");
    test("imjustmakeingsomthing");
    test("justaboutparity");
}
