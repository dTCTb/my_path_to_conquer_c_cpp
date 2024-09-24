#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;
        for (size_t i{}; i < expression.size(); ++i) {
            char c{expression[i]};
            if (c == '+' || c == '-' || c == '*') {
                vector<int> left{diffWaysToCompute(expression.substr(0, i))};
                vector<int> right{diffWaysToCompute(expression.substr(i + 1))};
                for (int a : left)
                    for (int b : right) {
                        switch (c) {
                        case '+':
                            result.push_back(a + b);
                            break;
                        case '-':
                            result.push_back(a - b);
                            break;
                        case '*':
                            result.push_back(a * b);
                            break;
                        }
                    }
            }
        }
        if (result.empty())
            result.push_back(stoi(expression));
        return result;
    }
};

// 完敗。。。
class dumpedSolution {
  public:
    vector<int> diffWaysToCompute(string expression) {
        stringstream ss(expression);

        int itmp;
        char ctmp;
        ss >> itmp;
        nums.push_back(itmp);
        while (ss) {
            if (ss >> ctmp)
                operators.push_back(ctmp);
            if (ss >> itmp)
                nums.push_back(itmp);
        }

        for (int v : nums)
            cout << v << ' ';
        cout.put('\n');
        for (char v : operators)
            cout << v << ' ';
        cout.put('\n');

        size_t n{operators.size()}, pair{};
        for (size_t i{}; i < n; ++i) {
            pair += catalan(i) * catalan(n - i - 1);
        }

        cout << pair << '\n';

        return vector<int>{};
    }

    size_t catalan(size_t n) {
        size_t ret{};
        if (n == 0) {
            ret = 1;
            tmpExp += "(" + to_string(nums[a++]);
            if (b < operators.size())
                tmpExp += operators[b++];
            else
                tmpExp += ")";
        } else if (n == 1) {
            ret = 1;
            tmpExp += "(" + to_string(nums[a++]) + operators[b++];
            tmpExp += to_string(nums[a++]) + ")" + operators[b++];
        } else
            for (size_t i{}; i < n; ++i) {
                ret += catalan(i) * catalan(n - i - 1);
                // cout << tmpExp << '\n';
                // a = b = 0;
            }
        if (a >= nums.size()) {
            a = 0;
        } else if (b >= operators.size()) {
            b = 0;
        }
        cout << tmpExp << '\n';
        return ret;
    }

  private:
    size_t a{}, b{};
    string tmpExp;
    vector<int> nums;
    vector<char> operators;
    vector<string> expressions;
};

int main() {
    Solution s1, s2;
    vector<int> eg1{s1.diffWaysToCompute("2-1-1")};
    vector<int> eg2{s2.diffWaysToCompute("2*3-4*5")};
    for (int a : eg1)
        cout << a << ' ';
    cout.put('\n');
    for (int a : eg2)
        cout << a << ' ';
    cout.put('\n');
}
