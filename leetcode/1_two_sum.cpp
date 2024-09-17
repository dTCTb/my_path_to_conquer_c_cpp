#include <iostream>
#include <unordered_map>
#include <vector>

using std::vector, std::unordered_map, std::cout;

class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        return method1(nums, target);
    }

    vector<int> method1(vector<int> &nums, int target) {
        int x, y;
        unordered_map<int, int> table{};
        print_input(nums, target);

        // incorporated into below for-loop
        // for (size_t i{}; i < nums.size(); ++i)
        //     table.insert({target - nums[i], i});

        for (size_t i{}; i < nums.size(); ++i) {
            unordered_map<int, int>::const_iterator it = table.find(nums[i]);
            if (it != table.cend() &&
                (nums[i] + nums[(*it).second] == target) &&
                (i != (*it).second)) {
                x = (*it).second;
                y = i;
                break;
            } else {
                table[target - nums[i]] = i;
            }
        }

        print_output(vector<int>{x, y});
        return vector<int>{x, y};
    }

    // dump way, too slow compare to hash table
    vector<int> method2(vector<int> &nums, int target) {
        int x{}, y{};
        vector<int> ret;
        print_input(nums, target);
        for (size_t i{}; i < nums.size(); ++i) {
            ret.push_back(target - nums[i]);
            for (size_t j{}; j < ret.size(); ++j) {
                if ((i != j) && (nums[j] + nums[i] == target)) {
                    x = j;
                    y = i;
                    break;
                }
            }
        }
        print_output(vector<int>{x, y});
        return vector<int>{x, y};
    }

  private:
    void print_input(vector<int> &nums, int target) {
        static int count{};

        cout << "\nExample " << ++count << ":\n"
             << "   Input: nums = [";

        for (int &v : nums)
            cout << v << ',';
        cout << "\b], target = " << target << '\n';
    }
    void print_output(vector<int> indices) {
        cout << "   Output: [" << indices.front() << ',' << indices.back()
             << "]\n";
    }
};

int main() {
    Solution solution{};
    // the last element is target, NOT part of element inside the test case
    vector<vector<int>> testCases{{
        {2, 7, 11, 15, 9},
        {3, 2, 4, 6},
        {3, 3, 6},
    }};
    for (vector<int> &testCase : testCases) {
        int target{testCase.back()};
        testCase.pop_back();
        vector<int> indices{solution.twoSum(testCase, target)};
    }
}
