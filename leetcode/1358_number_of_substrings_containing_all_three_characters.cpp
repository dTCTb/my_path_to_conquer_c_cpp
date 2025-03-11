#include <iostream>
#include <string>

using namespace std;
class Solution {
  public:
    /* O(N) 0-10ms 10.32mb | dumb way but work */
    static int numberOfSubstrings(const string &s) noexcept {
        const int z{static_cast<int>(s.size())};
        int ans{}, slot[4]{0, 0, 0, 1};

        for (int i{}, j{-1}; i < z; ++i) {
            // 用subscript 同 logical OR operator 會遠遠快過call STL 嘅any_of
            // 前者係0ms，後者係9~10ms
            // while (any_of(cbegin(slot), cend(slot), [](int val) -> bool {
            // return val <= 0; })) {
            while (slot[0] <= 0 || slot[1] <= 0 || slot[2] <= 0)
                if (j < z)
                    ++slot[(++j < z ? s[j] : 'd') - 'a'];
                else
                    break;

            ans += s.size() - j;

            --slot[s[i] - 'a'];
        }

        return ans;
    }

    /* Last Position Tracking */
    static int ingeniusApproach(const string &s) noexcept {
        const int z{static_cast<int>(s.size())};
        int ans{}, slot[3]{-1, -1, -1}; // {'a', 'b', 'c'}

        for (int pos{}; pos < z; ++pos) {
            // update last position of current character
            slot[s[pos] - 'a'] = pos;
            // add count of valid substrings ending at current position
            // if any character is missing, min will be -1
            // else min gives leftmost required character position
            ans += 1 + min({slot[0], slot[1], slot[2]});
        }

        return ans;
    }

    static void test(const string &s, const int ans, int m = 0) noexcept {
        int myAns{};
        cout << (s.size() < 100 ? s : "too long") << ' '
             << (myAns = (m != 0 ? Solution::ingeniusApproach(s)
                                 : Solution::numberOfSubstrings(s)))
             << " / " << ans << (myAns == ans ? " Correct" : " Incorrect")
             << '\n';
    }
};

int main() {
    Solution::test("abcabc", 10);
    Solution::test("aaacb", 3);
    Solution::test("abc", 1);
    Solution::test("ababbbc", 3);
    Solution::test("acbbcac", 11);
    Solution::test("cabcac", 9);
    Solution::test("bcabac", 9);
    Solution::test("babcca", 7);
    Solution::test("cbacbccc", 15);
    Solution::test("cabbcbc", 8);
    Solution::test(
        "aacbacaaabababacabbaaabcacbccbbcbbbaabbbbababccacbaaabaacabcccbcacccba"
        "ccabccbccbacbaaabaabbcabcbaacacacbacccababaaccbcabacbbcbabcbbaaabcabba"
        "bcabcbccbcaacaaaaacabbccbbbbabaccbaccabababaabaccbaccacabbbccabbaabacc"
        "aabaaaacbaabacaacabbcbcbcbbaacbaaabccbbbbbaabcbabacccbcbbacabaabababac"
        "ccbabbababcbabaccccaaaaababcacaacabbbbaacbaccaaaabbacccbaaaccabcccccaa"
        "bbcaaccabacbbcbcbcbabbabbacbcaacbcacaabbbcbacaabaacbccbcccaabbcbacbbcc"
        "ccbcaaaccbacabbcbcbacccbcaacccbaabbaccabcbccbbcaccacabcabcaaccccababbb"
        "abbacbaabccbacbbabccaacbcaaccabaabacabbcbcbacbbbaacbabaaaccacbcccaacbc"
        "bbccbcbaabcbbbcbbcccbacbbacabccccccabccbccbcabcccabcacbcbbbcccccabcacc"
        "bcabccacbbaacabbcbccbabbbabcabcaccbabacbaaccacabccbcbacaabbaacccbbccca"
        "abccccbbccabcbabbcbcabccacacbbbabaaccacbccacbbcaaacbbbbaacaccbaaabbbaa"
        "aacaacabccccbbcbaccaaababbbaaabbccbabcbbbcaaaaaabbbcbabacaaabaccacbbaa"
        "bcbaacacaababaaabcacbcacbbbcbbccaaaccabbcccccabcbcaccbcacbcccabaaaaaba"
        "acacbcbabaacabcabcbaccbabbababacbbcabbacbabaccabbcbcbaacbcccccccabcaab"
        "bcbabbacaabccbbbbbbbccccacaabcbbcabbbbbcbacaaacbcbacccbbcbbbbcbccaaabc"
        "acaaabccaaccbcaabaccccaaacacbacbbcbaacbabbcbcabcabbaaccbcbabccccbabbaa"
        "bcccacabccbccccbcbccbcccbbbacbcacabcabcccabbbbccaaaabbbbbccbbbbabbabaa"
        "abbacbbbcbcbcbbbbacbbcbaaaaaacaabababccaaabcacacbbacacccbccabcbabcaacc"
        "abacbbccbbacbaabccaacbbccbbccacbbaaccbcbaccbbaacbbcabaababcccacccabbbb"
        "cbbbabbcbabacacccbcaacbccacabcbbbaaacbaacccacacaacacccbbbaabcaacabccbb"
        "cccbaabbaabaccabaacabbabcabaaabbcccaacbbacbabccacbbacccccbcbcbbacbcaac"
        "caaaabbcabcbcbbabcacbaccbccccccacbbcaaacacabbbbaabbbacabbccccacacabcca"
        "babccbbbbbcbaabacccaaacaccbcbccbbcacaacbaaacbbcbbccacbbbbbbbcacccaabca"
        "cacccbbcacababcabcaaabbcacbcbbbcccabbbcacbbaaabbaacaabbccbaacababbccca"
        "ccbacabacabcaaccaabcacabaaccaccccccaabbaccabacacbacaaabbbcbacaccbccbcb"
        "cacbcbabbbabcbaccacbbabbbbbbcbaaabaaacccacbcacacbbcaacaacaacbbbcaccacc"
        "caababaccbbcaabcabbcbacbacbabccacbbbcaabaacaabccacaccbacabccaccbcacaac"
        "bcbccabacaccccabbcbbbbacaacabababccbaaaccabbaaccacbcbaabccababacaabbac"
        "cacbabcccbbbbbacbabbccbacccbacbbbcaccaaccaabbbcacbcabcacbbccaabbaacaca"
        "bbcbbbbcbacacabbcbccaacabbaabcccbaaabcbaccbacacbbbcaabbcaabbcacacccccc"
        "baaaacaccacbbaabbbccbacaabaabcaaaacaacaabbabcbbbcaacaaccbcbcbbabaacccc"
        "cbccbbacbaccbcccccbccccbcbabccbcbccbbbacabbbacbacbbccabbacababccabbabb"
        "bcaacabaccaacbbcbaacccaccccbbbbbcbaabacacacaacbbacacbccbacccbbbacaabbc"
        "bcbbcaccbccbbabacbacaccccbbbaaaccccaabaaaacabccaaaaacbbacacababbcccbaa"
        "abaaccbabbbaacaccaaaaabaabcaabaaacbbacabaacaaaaaccaacabcbcbacacbabbbbc"
        "cbcbababbaccaaabbcbbbbbbbbbbcabababcacccaabccaaaacbabcbabbbabacbbaacba"
        "cabcaacacbcbcbcccbbcaababccaaabbcbabaabccaaaaabcbaaaabccccccbbccbacbab"
        "abaaaaaaabbaabacaccaabccacbaccccaabbcaabbcbabacbccccbcbcabbbabaccbaaba"
        "bbbbbbabacbaabbcabbcccbcbcbcabababbccccabbabcaaccaacaaccbcbcbcaccbbabc"
        "cccbaccbacbbbaccccbabbaaababcbacbbacacabcacabbabbaabaacccbaccbbbccbacc"
        "cbcabcacababbccccacbbcbbaaacaacbabbabbccacacbbbbbacbaacacacabbbbcabacb"
        "bbbbcaabcbccbcababacaaabcaacabababcbbbabbcbbccbccbbbaabababacacbbbcccb"
        "ccbccbbbcbcaaacacaabcabbabbbcccbababbcbcaabcbccaaacbbacbabababaaccabab"
        "bbccccbaaaacaaabccababccccbcaabaaacbcbacaacbcaabcabcbabbacbacaacaccbab"
        "caaaabbabcccccbcbabbcbbbbbcaaaaaaaacbbcbcaaacaabbbaaccbbbccacbaccbcaba"
        "accabaabaababcabacbabcccaacccbcccbacbbcbbaaacccbaabaaacccaacbaabbcacbc"
        "bbcaccabcbbabbbbcabcaccbbbccabccbccbcccbbcabaaababbbcbaacababbccbcbaca"
        "cabcabbacbcccacbaacbccccccbacbcbccaaaacaaaccbaacaaaacbccbbcabcaacbaabc"
        "bbbbaaacacbbbbcaaaaababbaabacccbabcccabbbcbaaccbcabbcaaabcabccbacbaaab"
        "caabbcccccbbcbacbabaabbcbcaacbbcbbcabacccbccacccabbbabaabcbabccacbbaca"
        "babcaacababcabaaaacbbbacbcbbacbcabcaaccabbcbcbcacbbcaaaaabbaaaccabbcaa"
        "ababacbaccbccbbaaaaacbccbacabbcaaaabaccbbbbbbaaacbaaabbcbaacaaaacacccc"
        "abcacabacaaaaaabcaccbabacbbbcbbcccbbaabcbacacacabaabbabccbcacaacbcbcbc"
        "aaabcbbcacbaccccaaaabaacbbaaaaccbbaacbcacbaaabcbbccbbcabbbbbcabcaacccb"
        "aabcbabaccabbcabcabcccbacabcbcbcabcbacbabbacabcccaabcaabbbcbcbccacbcac"
        "aaababbacbcccbabbaabccaabcabaaaabaababcccaababccbaaccbbbcbbbbcaabccbab"
        "accccccabbcbbbcbbcbbabcccccabacabcbabcbbaabaaaabaaaabcccbaabacbccabcba"
        "bbbcbbaacbcbbbcccbcbaaabbbaccbcaaccacabcabccccaabacacbbbbcacaabaaabbcc"
        "bbcbbbaccaaccbaaaaaabacbbcccbccbcbacbbaaccbaccaccbcabbcaccbbcacbcbccac"
        "cbcccabbcacaaccbbabcaabcccbcacbcbccbccabccbababbcccaccacccbbbbcaccbacb"
        "bbabaacababaaaaaaacaccaabbabaabccaaccbabcbcccabcacaacbabaacacbcbccbbba"
        "cabccacccabcbabcababbabcacacaacbbcabcbbcbabacbccbaaacabbbabcabbacbaaab"
        "baacbccaaabbcbbcbcaaabbccabaacabcaabcbcbaaabbcbcbbccbbcbbcabacbbbcaacc"
        "aacacbbbbcaabaccabcbbabcaccbacbcabbabccbbabbcbababccbbbbabbbabbcbcbcab"
        "aacabaccbabacccbaabacbcbcacaabacbaacbccabbcaaabbcccabbbaabbccbcacccabc"
        "bcaacbacbcbabababaacbbcbbabababcaaacbcaccbacbbabaccaaaccccbcccaabcacac"
        "bcaacbcbaaaacbccbccbaccbbacbcbcaccbbccbccaaccaaabacbaaccacabbbacbbaaac"
        "bbbbbbcabbbbcacbabaabababbabbacccbbbbbccbacbbbaacacbbcbcbababcaaacbbac"
        "aacacbbcbabcbcaacacaaabcaabbaabccaaacacbbaaaacbabcbacabaaacaaacccacbac"
        "babcbaccbbccccaaccabcbbabccbbccaaabcbaccbcbbabacbcbcaacabacacabcacbbca"
        "baccabcbcababbbacaacacbaacbbbcbacccbbacaccacacbaabcabaabcbcacaacbbbaac"
        "babaaaaccbccbbcccaabacaacbaccabcabcacacabccbbcabbabbabacbbcaabbbcabcca"
        "cbbaaaacacbbcabccbaccaaabbbbababcbaaccbcbaaabcabacacccaabacccbaaaccaaa"
        "cbbbaacaabcbcbbcabbbbbbbababacabaaacbacaacbccbaccbacaaabbaacaabccbcabc"
        "baacabacbcabbaaaccbbbbcbbccccaabbccbbcabbaabbccaabcccaacbacabccaacccbc"
        "abbaabbcbcbacbacccabbaccbccaacaaabaaccccbcbaaaaccacacaaacbabbcaabbbcac"
        "acbaccbbbccbbbbbcacccacabaaacaabaababbbbcccccacbbacaabccbacbbacccbbcba"
        "ababbbbbaccccaacbbabacaccbbbcaaccaacacccbcbbbaacbbcccbbcbabacbcbbccbbb"
        "baabbccbcacbaaabcabacbbaaaaabccbabcbbabaacbbccbcbcacccaaacbbaabcbbabba"
        "bbccabcbabcbcacaaabbbbababaccccabcbaccbaaccabababcabbcbaaabbbbccabbccb"
        "aababaabbaccbcaacbaabaacbccabcbcbbbcccbacaaabaccaaacabaabccbbcccbccccc"
        "bbbbaccababcabaabbccabcacabcccbbacccaccbcaaaacaaacbaabbcbcbacabababbbc"
        "aacaabccaaacabcabccbcbabaabaacbaabaabccbbaaabacaacaaccbaaacbccabaababb"
        "cababcabcaabbcaabbcabcbbbaabcaccccaabccacbbaaaabacaabbcbbbbccccccbbaac"
        "baccababaaccaacbabbcbaacacbbaccaabcaccbbbcaacbaaaaabacbbcbaacbcbbcbcbb"
        "aabbbaccbbabbcbcbcccaacabbabacacabbcbccaabacbcabbaabcaababccbccabaccbb"
        "baccbbabcabbbcaacaabcaabcbcaacbcabbcabbcbcbbcacaacaacccbbcaacabaabcccb"
        "cbcbbbbbbbbbccbaacbbccbbcbcabcbbbabaccbaabaccccbabcbbbacacbbabbcbbabbb"
        "cabaacbaababccbcabaaacbbccbbbabaaacbbbabbbbbccbacbabaccaccbabbabbbcbba"
        "baabbbabcaabaababbacccacacbbccbbbbbbaababacbcccbbaaabbbbbbcabcbcccacca"
        "bacababccaaacccaaacbaccccbbcbabcbbcbbbcccabcbbabbcabcaaaccaabbaabbcabc"
        "cbacbaaaacbcbbabcaccacaacacaaabcbbbcbcabacbbcacbacabbacbccbbacccacbbbb"
        "bccbbbcaabbaaabacacbaaabcaacbbcbaaabcbccbcbaabbaaaabababccbcabbcabcbaa"
        "ccabcabbabbbaaabacaacabbaccacacaaaabaabbabccbcbcacccaaabbacbacbabcbbaa"
        "abcaabaaaabaacbbccccbbcaaabccabababbbbccaaaaaacbcbaaccbacbcbaacbabaaab"
        "abacabbccccbbaacbbbcbacbacbbcacacbbbacaabbcbcaacbabbcabbcabababbaababa"
        "ccabababbccbcaccaccaabbbcbbcacccccbabccbaacbabacbbabacaabbcccbbccbabaa"
        "cbccaaacacbaaabacbccbbccbabbaababcbabcbbbabbcabccacbbabcbbbcaacacaabba"
        "cabbbcaccabcbbcccbbcbbaaacbcbabccaababbccbbcbabacabacbccaaababaaabaacb"
        "aaabacbbbbacbccacaccccbaacccaabaabcbcacbbbabbabbacccabcaccbabaccaaabcb"
        "cbcaabbcbacaabcabcccbaabbbbcbcbcbcccaaacaaccbbcaaaacbacacacacaabcbcccb"
        "bbbaaccbaabaaabbabcaabccabcbaacacaaabacbcbaccaacabcababbbbaccacacabacc"
        "bccbcabbbabcccbaaacabacabbcbcbaaabaccabcccccccbbcabccbcbbabccaaaaabcbc"
        "abcbabbbbbaabaaabcccccbccbbcbbcbbabbcbacacaccaabaccbbbabbabaababcccacc"
        "baaababcccabbcaaabacbabbacacababbcacbcccbaaaabbcaacabbcabaabcacbbcacac"
        "aacbbbcbacbaababbaacbbbbbccccacaabcaabbcbbcbabcbaabbabccbaccbccaacbbbb"
        "baacbaaabbacccaaabbbbabaaabbaaaabcbbbbacbabbbccbababbcccaabbaabbbaaccc"
        "cbbbbaabbacabacbcbabacbacbbcacaacccbcccaaacbbccbbcbcbcbcaababcbcbccaac"
        "bbcabbbcaaccccaacccbbaccaccaaccbccbccacbcaaaaaabbbaaabaaababbccabccacb"
        "bcababcabccbabcbabbbbaabcbcacabaabbbabbbcabaccaaacbbbaaaaabaababbabcab"
        "acaccaacabcbcaaacccccbcbcbcbbcccacbabaaaaaacbbcacaccabcccacccabbbcacbc"
        "baacbaccbacbabccbcaccabaaccaacaccaaacbbacccccabbccabbbabaaacacbaccaaba"
        "bccbcaccccacbabacacbcbcccbbbcbcbcabcbacbacbcabccccbcbacbbaabccabcabacb"
        "ababbaaabbbbaccbababcccbccaabaacababcbbaccacbcacabbcbbbabcacccaccbccca"
        "ababccaaccbccbcacabaaabbccbabccbabaccbabbbccccacababbaacbabcbbccccabab"
        "bcbbbaccacaabbaaccbabcbbabaabcbacacacbbacabcababacbcbaccbbabaaccccbccb"
        "bbababababaaaaaaabbbcccbabccbaccacabcbacacccbbbcccaabaacacbabbbcacbcca"
        "baccbacccabacaabbacabcabbbcaacbccbccbbbabccccbabacbabacabcccccbacbcabc"
        "aaacabaabacababcacbcbabcaacaacbaaabaacaaccaacbcacbbabbcbaccababbcaaacb"
        "baaaaccaaaccbccaccabaaabacbcaaabaccabcabbcccabcaacabbcacabbcbcaccaabba"
        "ababccbbccabaccacacbccbaaccbaacbbccabcababcbbacabbacabcbbacaabcbbcacca"
        "bcbcccbaccbbcbbbaaaccbcbaaabbbaccbcccbcbccacaabbbcbaabaaabaabcaacabbaa"
        "cacbcaabcbabccaccaabccaacbabcccbaaccccbbcbbabbabbcbababbabcacabbbbcbab"
        "ccaccaccababccccaacccabacbbccacacaacbaacaaaccaccccccacbbcacacacabbaacc"
        "bbbabbbbbbbccabacccbbcaabababcccbaacacabbccccaaaccbaccbaaacbbaacbbacaa"
        "bbcacbcbbbccacaccaccacabaabaabacbccbccaccbacbbacacabacbbcaabbacbcbabba"
        "abcacacabbcabbccaccbbcccccbbbbaaccaaabcabbcaabcbaaacacaabaabbbcacabbca"
        "ccaacbaaaccabcacaaccacbccbcabbaccbcccbaccbabccabaabbaccbbcaacbbbabbbaa"
        "bbbacbbbabccaccbbaacaacabbbcababbacbbbbcbccaccabbcaacbcbaacccaacaaaacc"
        "aabcbaccabccaacacaaababccacbbbacbbbcbaaacbabbbcccbacaabbcbcabcbbccbaac"
        "accacacbbbbcccccbbbbabcbacabccacaaabbbcbabcacacbbcabaaaabbccabaccaabac"
        "cbaccaacaccbaccaabcabacccbbaaccbabcbaacaaaccbcacbaacababacacbaaabcbbcc"
        "cacacbccaacccbcbcacabcabccbccbbbbbacaaabaaccccacbacbbacabccbccbcaababb"
        "bacabcbaaccaaccacacccccaaabbabbbcabaaaaaaabcbbbacababcbbaccbccccaabbba"
        "aabbbccbbcccaccacababbccaababcabbcababbaacacaaabcacbbccbccbbbbcbaaccbc"
        "acbbbcacaabcabaccaacacbcacbbccbabcbaccbccacbbcbaababaccaaccababbcbacab"
        "aabbaacccaaccaaaabcabcbbbabbccbcabbaaacabcaabccbcabcbabaac",
        45830534, 1);
}
