#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
class Solution {
  public:
    static string addSpaces(const string &s, const vInt &spaces) noexcept {
        string ans;
        ans.reserve(s.size() + spaces.size());

        size_t i{};
        for (const int &idx : spaces) {
            while (i < idx)
                ans.push_back(s[i++]);
            /* if (i == idx) */ ans.push_back(' ');
        }

        return ans.insert(ans.size(), s, i);
    }
};

int main() {
    cout << Solution::addSpaces("LeetcodeHelpsMeLearn", vInt{8, 13, 15})
         << '\n';
    cout << Solution::addSpaces("icodeincpp", vInt{1, 5, 7, 9}) << '\n';
    cout << Solution::addSpaces("spacing", vInt{0, 1, 2, 3, 4, 5, 6}) << '\n';
    cout << Solution::addSpaces("AllEyesOnHindu", vInt{7}) << '\n';
    cout << Solution::addSpaces("MakeIndiaGreatAgain", vInt{1, 7, 8, 9})
         << '\n';
    cout << Solution::addSpaces("DelhiMeiBJP", vInt{8, 9}) << '\n';
    cout << Solution::addSpaces("HinduMeansIndian", vInt{9, 11}) << '\n';
    cout << Solution::addSpaces("jaimatadi", vInt{7, 8}) << '\n';
}
