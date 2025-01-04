#include <iomanip>
#include <iostream>
#include <list>
#include <string>
#include <unordered_map>

using namespace std;

typedef std::list<int> iList;
typedef std::unordered_map<char, iList> ciListMap;
void print_map(ciListMap) noexcept;
class Solution {
  public:
    static int countPalindromicSubsequence(const string &s) noexcept {
        cout << quoted(s) << ' ';
        int ans{}, mark[26]{};
        ciListMap map;

        for (size_t i{}; i < s.size(); ++i)
            map[s[i] - 'a'].push_back(i);

        print_map(map);

        for (size_t i{}; i < s.size(); ++i) {
            int cur{s[i] - 'a'};

            map[cur].pop_front();
            if (mark[cur] || map[cur].size() < 1) {
                if (map[cur].empty())
                    map.erase(cur);
                continue;
            }

            int bound{map[cur].back()};
            for (const auto &[c, e] : map)
                if (e.front() < bound)
                    ans += 1;

            ++mark[cur];
        }

        cout << "ans: " << ans << "\n\n";
        return ans;
    }
};

void print_map(ciListMap map) noexcept {
    cout.put('\n');
    for (auto &[c, e] : map) {
        cout << static_cast<char>(c + 'a') << ": ";
        while (!e.empty()) {
            cout << e.front() << ' ';
            e.pop_front();
        }
        cout.put('\n');
    }
}

int main() {
    Solution::countPalindromicSubsequence("aabca");     // 3
    Solution::countPalindromicSubsequence("adc");       // 0
    Solution::countPalindromicSubsequence("bbcbaba");   // 4
    Solution::countPalindromicSubsequence("bbaabb");    // 2
    Solution::countPalindromicSubsequence("aaaaaa");    // 1
    Solution::countPalindromicSubsequence("lhwtek");    // 0
    Solution::countPalindromicSubsequence("ckafnafqo"); // 4
    Solution::countPalindromicSubsequence(
        "narisoerjteokvhfupilrnuytrhrqcygiudbzptlxosjkdrxwx"); // 239
    Solution::countPalindromicSubsequence(
        "eensygaioqiwqueoxmnbcxmjgfvjshjhsjgshtnmnvsefghsgfjseegjywyrwourwppidm"
        "xdmxvxhdbzhjgfdjgeyssoefsjbfbbxnbdnfvdfvjhxdjfhgxdjfhxdjfxhbbxfvxdjfvj"
        "h"); // 369
    Solution::countPalindromicSubsequence(
        "aaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuuuvvvwwwx"
        "xxyyyzzzaaabbbcccdddeeefffggghhhiiijjjkkklllmmmnnnooopppqqqrrrssstttuu"
        "uvvvwwwxxxyyyzzz"); // 676
}
