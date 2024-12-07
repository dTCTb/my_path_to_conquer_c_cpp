#include <iomanip>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    static bool canChange(const string start, const string target) noexcept {
        // constraint: start.length == target.length
        for (size_t s{}, t{}; s < start.size() || t < target.size(); ++s, ++t) {
            while (t < target.size() && target[t] == '_')
                ++t;
            while (s < start.size() && start[s] == '_')
                ++s;
            if ((start[s] == 'L' && s < t) || (start[s] == 'R' && t < s) ||
                (start[s] != target[t]))
                return false;
        }
        return true;
    }
};

typedef std::tuple<string, string, bool> testcase;
typedef std::unordered_map<size_t, testcase> testcases;

ostream &operator<<(ostream &c, const testcases::value_type &p) {
    const auto &[no, testcase] = p;
    const auto &[start, target, answer] = testcase;
    c << "Testcase " << no << '\n';
    c << "start = " << quoted(start) << ", target = " << quoted(target) << '\n';
    bool myAnswer = Solution::canChange(start, target);
    c << (myAnswer == answer ? "Correct" : "Incorrect") << '\n';
    c << "- -- - -- - -- -\n";
    return c;
}

int main() {
    testcases testcases{
        {1, {"_L__R__R_", "L______RR", true}},
        {2, {"R_L_", "__LR", false}},
        {3, {"_R", "R_", false}},
        {4, {"LL_R", "L_RR", false}},
        {5, {"R_L_", "R__L", false}},
        {6, {"RR__L", "_R_RL", true}},
        {7, {"R__R_", "_RR__", false}},
        {8, {"_LL___R__R_", "L___L____RR", false}},
        {9, {"_L__R__R_L", "L_____RL_R", false}},
#include "TestCases/2337_testcase.txt"
    };
    cout << *testcases.find(1);
    cout << *testcases.find(2);
    cout << *testcases.find(3);
    cout << *testcases.find(4);
    cout << *testcases.find(5);
    cout << *testcases.find(6);
    cout << *testcases.find(7);
    cout << *testcases.find(8);
    cout << *testcases.find(9);
    // cout << *testcases.find(10);
    // cout << *testcases.find(11);
}
