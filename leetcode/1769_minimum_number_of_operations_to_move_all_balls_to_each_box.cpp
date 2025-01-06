#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printArr(std::vector<int> arr) {
    for (int e : arr)
        cout << e << ' ';
    cout.put('\n');
}

typedef std::vector<int> vInt;
class Solution {
  public:
    static vInt minOperations(string boxes) noexcept {
        vInt ans;
        ans.reserve(boxes.size());
        int prefixSum{}, postfixSum{}, one{};

        for (size_t i{}; i < boxes.size(); ++i) {
            if (boxes[i] == '1') {
                prefixSum += i;
                ++one;
            }
        }

        cout << "prefixSum: " << prefixSum << " one: " << one << '\n';

        for (size_t i{}; i < boxes.size(); ++i) {
            if (boxes[i] == '1') {
                prefixSum -= i;
                --one;
            }
            ans.push_back(prefixSum - i * one);
        }

        printArr(ans);

        for (int i{(int)boxes.size() - 1}; i >= 0; --i) {
            if (boxes[i] == '1') {
                postfixSum += boxes.size() - 1 - i;
                ++one;
            }
        }

        cout << "postfixSum: " << postfixSum << " one: " << one << '\n';

        for (int i{(int)boxes.size() - 1}; i >= 0; --i) {
            if (boxes[i] == '1') {
                ans[i] += postfixSum;
                postfixSum -= --one;
            } else {
                ans[i] += postfixSum;
                postfixSum -= one;
            }
            if (!one)
                break;
        }

        printArr(ans);

        return ans;
    }
};

int main() {
    auto test = bind(Solution::minOperations, placeholders::_1);
    test("110");
    test("001011");
    test("10000000001");
    test("1");
    test("00");
    test("10000000001");
    test("110010111101111010");
    test("00000100000000000010");
    test("000000011111001100001001101100001100110000000111010101011111011111011"
         "10100010010000111111001010101101010001011101");
}
