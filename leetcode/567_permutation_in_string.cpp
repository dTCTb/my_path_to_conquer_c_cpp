#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

// clang-format off
class Solution {
  public:
    static bool checkInclusion(string s1, string s2) noexcept
    {
        const size_t window{s1.size()};
        // char charset[26]{0};
        array<int, 26> charset{};

        for (char c : s1)
            ++charset[c - 'a'];
        // copy(charset.cbegin(), charset.cend(), ostream_iterator<int>(cout, " "));
        // cout.put('\n');

        // for (size_t i{}; i < s2.size() && i + window - 1 < s2.size(); ++i)
        // {
        //     array<int, 26> tmpCharset{charset};
        //     for (size_t j{}; tmpCharset[s2[i + j] - 'a']-- != 0 && j < window; ++j)
        //         if (j == window - 1) return true;
        // }

        function<bool(array<int, 26> &)> allZero =
            [](array<int, 26> &arr) noexcept -> bool {
            for (int v : arr)
                if (v != 0) return false;
            return true;
        };

        for (size_t i{}; i < s2.size(); ++i)
        {
            --charset[s2[i] - 'a'];
            // choose either (due to ULONG 0 minus 1 equal to ULONG_MAX)
            // if (size_t x{i - window}; x >= 0 && x <= s2.size())
            // or
            if ((int)i - (int)window >= 0) ++charset[s2[i - window] - 'a'];
            if (allZero(charset))          return true;
        }

        return false;
    }
};
// clang-format on

#include "../termcolor.h"
typedef std::pair<std::array<std::string, 2>, bool> dataSet;

// clang-format off
struct TestCase {
    string s1, s2;
    bool ans;
    TestCase(dataSet &&eg) : s1{(eg.first)[0]}, s2{(eg.first)[1]}, ans{eg.second} {}
    void test() {
        static size_t no{};
        cout << boolalpha;
        cout << AQUC "Testcase "; cout.width(2); cout << right << ++no << RESET << '\n';
        bool myAns{Solution::checkInclusion(s1, s2)};
        cout << "My answer \"" << BLUC << myAns << RESET "\"";
        if (myAns == ans) cout << " is " << GRE("Correct!\n");
        else cout << " is " << RED("Wrong") << ", Correct answer is \"" << ORAC << ans << RESET "\"\n";
    }
};
// clang-format on

int main() {
    Solution s;
#include "TestCases/567_testcase.txt"
    TestCase eg1{std::move(input1)};
    TestCase eg2{std::move(input2)};
    TestCase eg3{std::move(input3)};
    TestCase eg4{std::move(input4)};
    TestCase eg5{std::move(input5)};
    TestCase eg6{std::move(input6)};
    TestCase eg7{std::move(input7)};
    TestCase eg8{std::move(input8)};
    TestCase eg9{std::move(input9)};
    TestCase eg10{std::move(input10)};
    TestCase eg11{std::move(input11)};
    TestCase eg12{std::move(input12)};
    TestCase eg13{std::move(input13)};
    TestCase *testCases[13]{&eg1, &eg2, &eg3,  &eg4,  &eg5,  &eg6, &eg7,
                            &eg8, &eg9, &eg10, &eg11, &eg12, &eg13};
    for (TestCase *&eg : testCases)
        eg->test();
}
