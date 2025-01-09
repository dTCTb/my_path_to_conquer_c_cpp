#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef std::vector<string> vStr;
struct Node {
    char val;
    Node *next[26]{};

    Node() {}
    Node(char val) : val{val} {}

    static const Node *parse(const vStr &words) noexcept {
        const Node *root = new Node{};
        for (const string &word : words) {
            Node *cur{const_cast<Node *>(root)};
            for (const char c : word) {
                if (cur->next[c - 'a'] == nullptr)
                    cur->next[c - 'a'] = new Node(c);
                cur = cur->next[c - 'a'];
            }
        }
        return root;
    }
};

class Solution {
  public:
    static int prefixCount(const vStr &words, const string pref) noexcept {
        return useTrie(words, pref);
    }

    static int useTrie(const vStr &words, const string pref) noexcept {
        int ans{};
        const Node *root = Node::parse(words);

        for (size_t j{}; j < words.size(); ++j) {
            if (words[j].size() < pref.size())
                continue;
            Node *cur{const_cast<Node *>(root)};
            size_t i{};
            for (; i < pref.size(); ++i)
                if (cur->next[words[j][i] - 'a']->val == pref[i])
                    cur = cur->next[pref[i] - 'a'];
                else
                    break;
            ans += (i == pref.size()) ? 1 : 0;
        }

        cout << "ans: " << ans << '\n';
        return ans;
    }

    static int on9way(const vStr &words, const string pref) noexcept {
        int ans{};
        for (const string &word : words)
            if (word.size() >= pref.size() &&
                word.substr(0, pref.size()) == pref)
                ++ans;
        cout << "ans: " << ans << '\n';
        return ans;
    }
};

int main() {
    auto test = bind(Solution::prefixCount, placeholders::_1, placeholders::_2);
    test(vStr{"pay", "attention", "practice", "attend"}, "at");    // 2
    test(vStr{"leetcode", "win", "loops", "success"}, "code");     // 0
    test(vStr{"a", "ab", "abc", "bca", "bac"}, "a");               // 3
    test(vStr{"hello", "world", "prefix"}, "");                    // 3
    test(vStr{"cat", "dog", "bird"}, "elephant");                  // 0
    test(vStr{"foo", "foobar", "foo", "barfoo"}, "foo");           // 3
    test(vStr{"alpha", "beta", "gamma"}, "delta");                 // 0
    test(vStr{"pre", "prefix", "prelude", "presentation"}, "pre"); // 4
    test(vStr{"word"}, "wo");                                      // 1
    test(vStr{"prefix", "pre", "presentation", "prelude"}, "pre"); // 4
}
