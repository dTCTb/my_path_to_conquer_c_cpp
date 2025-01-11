#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
typedef std::vector<std::string> vStr;
void print_strArr(const vStr arr);
void print_intArr(const vInt arr[]);
class Solution {
  public:
    static vStr stringMatching(const vStr &words) noexcept {
        print_strArr(words);
        vStr ans{};
        ans.reserve(words.size());
        vInt k[31];

        for (int i{}; i < words.size(); ++i)
            k[words[i].size()].push_back(i);

        print_intArr(k);

        for (int i{}; i < words.size(); ++i) {
            bool found{false};
            for (int j{(int)words[i].size() + 1}; j < 31; ++j) {
                if (k[j].empty())
                    continue;
                for (int k : k[j]) {
                    for (int x{}; x < words[k].size(); ++x) {
                        int z{x}, y{};
                        while (z < words[k].size() &&
                               words[k][z] == words[i][y]) {
                            ++z, ++y;
                        }
                        if (y == words[i].size()) {
                            found = true;
                            break;
                        }
                    }
                    if (found)
                        break;
                }
                if (found) {
                    ans.push_back(words[i]);
                    break;
                }
            }
        }

        print_strArr(ans);

        cout << "\n\n";
        return ans;
    }
};

void print_strArr(const vStr words) {
    cout << "{";
    for (const string &word : words) {
        cout << quoted(word) << ", ";
    }
    cout << "\b\b}\n";
}

void print_intArr(const vInt k[]) {
    for (int i{1}; i < 31; ++i) {
        if (k[i].empty())
            continue;
        cout << i << ": ";
        for (int v : k[i])
            cout << v << ", ";
        cout << "\b\b \n";
    }
}

int main() {
    auto test = bind(Solution::stringMatching, placeholders::_1);
    test(vStr{"mass", "as", "hero", "superhero"});
    test(vStr{"leetcode", "et", "code"});
    test(vStr{"blue", "green", "bu"});
    test(vStr{"leetcoder", "leetcode", "od", "hamlet", "am"});
    test(vStr{"mass", "as", "hero", "superhero", "xyzuiov", "uiknhdi", "peuish",
              "peusih", "xyzui", "ov"});
    test(vStr{"leetcodeeeeeeee",
              "efse",
              "esfe",
              "fes",
              "sef",
              "eff",
              "se",
              "ef",
              "sem",
              "you",
              "yu",
              "o",
              "pen",
              "si",
              "enp",
              "p",
              "e",
              "n",
              "goal",
              "ol",
              "lol",
              "al",
              "midgo"});
    test(vStr{"this", "is", "the", "weather", "fish"});
    test(vStr{"eeeet", "eeet"}); // testcase 66
}
