#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

typedef std::vector<std::string> vStr;
class Solution {
  public:
    static vStr wordSubsets(const vStr &words1, const vStr &words2) noexcept {
        vStr ans;
        int charset[26]{};

        for (const string &word : words2) {
            int tmp[26]{};
            for (const char ch : word)
                ++tmp[ch - 'a'];
            for (size_t i{}; i < 26; ++i)
                if (tmp[i] > charset[i])
                    charset[i] = tmp[i];
        }

        for (size_t i{}; i < 26; ++i)
            cout << static_cast<char>(i + 'a');
        cout.put('\n');
        for (int v : charset)
            cout << v;
        cout.put('\n');

        for (const string &word : words1) {
            int dupCharset[26]{};
            copy(cbegin(charset), cend(charset), begin(dupCharset));
            for (char ch : word)
                if (dupCharset[ch - 'a'])
                    --dupCharset[ch - 'a'];
            if (accumulate(cbegin(dupCharset), cend(dupCharset), 0) == 0)
                ans.push_back(word);
        }

        for (const string &word : ans)
            cout << word << ", ";
        cout << "\b\b \n";

        return ans;
    }
};

int main() {
    auto test = bind(Solution::wordSubsets, placeholders::_1, placeholders::_2);
    test(vStr{"amazon", "apple", "facebook", "google", "leetcode"},
         vStr{"e", "o"});
    test(vStr{"amazon", "apple", "facebook", "google", "leetcode"},
         vStr{"l", "e"});
    test(vStr{"leetcode"}, vStr{"lcodeee", "tcee", "eode"});
    test(vStr{"acaac", "cccbb", "aacbb", "caacc", "bcbbb"},
         vStr{"caccacacac", "ccaabbab", "b"});
    test(vStr{"amazon", "apple", "facebook", "google", "leetcode"},
         vStr{"e", "oo"});
}
