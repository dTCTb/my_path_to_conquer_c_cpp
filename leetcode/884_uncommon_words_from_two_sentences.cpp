/* 884. Uncommon Words from Two Sentences
 * A sentence is a string of single-space separated words where each word
 * consists only of lowercase letters.
 *
 * A word is uncommon if it appears exactly once in one of the sentences, and
 * does not appear in the other sentence.
 *
 * Given two sentences s1 and s2, return a list of all the uncommon words. You
 * may return the answer in any order.
 */
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using std::vector, std::string, std::cout, std::unordered_map;

class Solution {
  public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, size_t> table{};

        auto count = [&table](string s) {
            for (string::const_iterator i{s.cbegin()}, j{s.cbegin()};
                 i <= s.cend(); ++i) {
                if (*i == ' ' || i == s.cend()) {
                    string tmp{j, i};
                    j = i + 1;
                    // cout << tmp << '\n';
                    ++table[tmp];
                }
            }
        };

        auto count_stringstream = [&table](std::stringstream ss) {
            string s{};
            while (ss >> s)
                ++table[s];
        };

        // count(s1);
        // count(s2);
        count_stringstream(std::stringstream{s1});
        count_stringstream(std::stringstream{s2});
        print_input(s1, s2);
        return print_output(using_for_loop(table));
    }

  private:
    // using for_each (but I don't know why unordered..iterator as p is wrong)
    vector<string> using_for_each(unordered_map<string, size_t> table) {
        vector<string> uncommon;
        std::for_each(table.cbegin(), table.cend(),
                      [&uncommon](std::pair<string, size_t> p) {
                          if (p.second == 1)
                              uncommon.push_back(p.first);
                      });
        return uncommon;
    }

    vector<string> using_for_loop(unordered_map<string, size_t> table) {
        vector<string> uncommon;
        for (unordered_map<string, size_t>::const_iterator i{table.cbegin()};
             i != table.cend(); ++i) {
            if (i->second == 1)
                uncommon.push_back(i->first);
        }
        return uncommon;
    }

    void print_input(string s1, string s2) {
        static size_t count{};
        cout << "\nExample " << ++count << ":\n";
        cout << "   Input: s1 = \"" << s1 << "\", s2 = \"" << s2 << "\"\n";
    }

    vector<string> print_output(vector<string> uncommon) {
        cout << "   Output: [";
        for (string &s : uncommon)
            cout << "\"" << s << "\",";
        cout << "\b]\n";
        return uncommon;
    }
};

int main() {
    vector<vector<string>> testCases{
        {"this apple is sweet", "this apple is sour"},
        {"apple apple", "banana"},
    };
    Solution s;
    for (vector<string> &testCase : testCases)
        vector<string> uncommon{
            s.uncommonFromSentences(testCase[0], testCase[1])};
}
