#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;
#define INL __attribute__((always_inline))

class Solution {
  public:
    static void countSort(vector<int> &arr) noexcept INL {
        std::function<void(const char *, std::vector<int> &)> print_intArr =
            [](const char *prompt, std::vector<int> &arr) noexcept -> void {
            std::cout << (prompt ? prompt : "");
            std::copy(arr.cbegin(), arr.cend(),
                      std::ostream_iterator<int>(std::cout, " "));
            std::cout << "[size:" << arr.size() << "]\n";
        };

        vector<int> freq(*max_element(arr.cbegin(), arr.cend()) + 1);
        // counting the occurance of element from arr
        for (int n : arr)
            ++(freq[n]);
        print_intArr("freq: ", freq);

        // calculate prefix sum
        for (size_t i{1}; i < freq.size(); ++i)
            freq[i] += freq[i - 1];
        print_intArr("prefix sum: ", freq);

        // count sort (inplace)
        for (size_t i{}, j{}; i < arr.size();)
            if (i < freq[j])
                arr[i++] = j;
            else
                ++j;
        print_intArr("sorted: ", arr);

        // count sort (faster but require new array to store the result)
        // vector<int> sorted(arr.size());
        // for (auto crit{arr.crbegin()}; crit != arr.crend(); ++crit)
        //     sorted[--freq[*crit]] = *crit;
        // return sorted;
    }

    [[nodiscard("Answer")]] static long long
    proper_dividePlayers(vector<int> &skill) noexcept {
        countSort(skill);

        size_t players{skill.size()};
        size_t &&lastPlayer{players - 1};
        unsigned long long totalChemistry{};
        int skillPerTeam{skill[0] + skill[lastPlayer]};

        for (size_t i{}; i < players / 2; ++i) {
            int currentTeamSkill{skill[i] + skill[lastPlayer - i]};
            if (currentTeamSkill != skillPerTeam)
                return -1;
            totalChemistry += skill[i] * skill[lastPlayer - i];
        }

        return totalChemistry;
    }

    // My solution (really slow) using two sum
    static long long dividePlayers(vector<int> &skill) noexcept {
        size_t group{skill.size() / 2};
        unsigned long long totalSkills =
            accumulate(skill.cbegin(), skill.cend(), 0ULL,
                       [](unsigned long long acc, int v) { return acc += v; });
        size_t skillPerGroup{totalSkills / group};

        if (totalSkills % skillPerGroup != 0)
            return -1;

        unordered_multimap<int, size_t> table{};
        table.reserve(group);
        size_t teams{};
        unsigned long long chemistry{};

        // two sum
        for (size_t i{}; i < skill.size(); ++i) {
            unordered_multimap<int, size_t>::iterator it{table.find(skill[i])};
            if (it != table.end()) {
                chemistry += skill[i] * skill[it->second];
                ++teams;
                table.erase(it);
            } else
                table.insert({skillPerGroup - skill[i], i});
        }

        return (teams != group) ? -1 : chemistry;
    }
};

function<char(void)> _ = []() -> char {
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    return 'c';
};

struct TestCase {
    // clang-format off
    vector<int> skill;
    long long ans;
    TestCase(vector<int> skill, long long ans) : skill{skill}, ans{ans} {}
    void test(Solution &s) {
        static size_t no{};
        long long myAns{s.proper_dividePlayers(skill)};
        cout << "Testcase "; cout.width(2); cout << right << ++no;
        cout << "\nMy answer " << myAns;
        if (myAns == ans) cout << " is Correct!\n";
        else cout << " is Wrong, Correct answer is " << ans << '\n';
    }
    // clang-format on
};

int main() {
    Solution s;
#include "TestCases/2491_testcase.txt"
    TestCase eg1(input1, 22);
    TestCase eg2(input2, 12);
    TestCase eg3(input3, -1);
    TestCase eg4(input4, -1);
    TestCase eg5(input5, -1);
    TestCase eg6(input6, 5554083);
    TestCase eg7(input7, -1);
    TestCase eg8(input8, 15);
    TestCase eg9(input9, -1);
    TestCase eg10(input10, -1);
    TestCase eg11(input11, 133);
    TestCase *tc[]{&eg1, &eg2, &eg3, &eg4,  &eg5, &eg6,
                   &eg7, &eg8, &eg9, &eg10, &eg11};

    for (TestCase *p : tc)
        p->test(s);

    // Solution::countSort({2, 5, 3, 0, 2, 3, 0, 3});
    // Solution::countSort({9, 1, 2, 1, 3, 5, 9, 2, 3, 3, 1, 9, 7, 8});
}
