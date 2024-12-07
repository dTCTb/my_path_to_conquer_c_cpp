#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
class Solution {
  public:
    static int maxCount(vInt &banned, int n, int maxSum) noexcept {
        sort(banned.begin(), banned.end());
        size_t ans{}, sum{};

        for (size_t i{1}; i <= n; ++i)
            if (binary_search(banned.cbegin(), banned.cend(), i))
                continue;
            else if (sum += i; sum <= maxSum)
                ++ans;

        return ans;
    }
};

typedef std::tuple<std::vector<int>, int, int, int> testcase;
typedef std::unordered_map<size_t, testcase> testcases;

ostream &operator<<(ostream &c, const std::vector<int> arr) {
    c.put('[');
    if (arr.size() < 31)
        for (const int e : arr)
            c << e << ' ';
    else
        c << "\"array length " << arr.size() << " too long\" ";
    c << "\b]";
    return c;
}
ostream &operator<<(ostream &c, testcases::value_type &t) noexcept {
    size_t no = t.first;
    auto [banned, n, maxSum, answer] = t.second;
    int myAnswer = Solution::maxCount(banned, n, maxSum);
    c << "banned = " << banned << " , n = " << n << " , maxSum = " << maxSum
      << '\n';
    c << (myAnswer == answer ? "Correct" : "Incorrect") << " , answer is "
      << answer;
    c << "\n- -- - -- - -- -\n";
    return c;
}

int main() {
    testcases testcases{
        {1, {vInt{1, 6, 5}, 5, 6, 2}},
        {2, {vInt{1, 2, 3, 4, 5, 6, 7}, 8, 1, 0}},
        {3, {vInt{11}, 7, 50, 7}},
        {4, {vInt{1}, 10000, 1000000000, 9999}},
        {5, {vInt{12, 12}, 13, 2199, 12}},
        {6, {vInt{8108, 8155}, 2431, 7821, 124}},
        {7,
         {vInt{190, 123, 20,  139, 22,  140, 62,  58,  137, 68,  148, 172,
               76,  173, 189, 151, 186, 153, 57,  142, 105, 176, 36,  104,
               125, 188, 152, 101, 47,  51,  65,  39,  174, 29,  55,  13,
               138, 79,  81,  175, 178, 42,  108, 24,  80,  183, 133, 114,
               165, 118, 56,  59,  124, 82,  49,  94,  8,   146, 109, 14,
               85,  44,  60,  181, 95,  23,  150, 97,  28,  182, 157, 46,
               160, 155, 12,  67,  135, 117, 2,   25,  74,  91,  71,  98,
               127, 120, 130, 107, 168, 18,  69,  110, 61,  147, 145, 38},
          3016, 240, 17}},
        #include "TestCases/2554_testcase.txt"
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
    cout << *testcases.find(10);
    cout << *testcases.find(11);
}
