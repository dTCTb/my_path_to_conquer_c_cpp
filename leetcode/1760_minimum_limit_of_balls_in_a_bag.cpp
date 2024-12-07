#include <iostream>
#include <list>
#include <vector>

using namespace std;

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

typedef std::vector<int> vInt;
class Solution {
  public:
    static int minimumSize(const vInt &nums, const int maxOperations) noexcept {
        priority_queue<int> pq{nums.cbegin(), nums.cend()};
        for (int i{}; i < maxOperations; ++i) {
            int tmp = pq.top();
            // cout << tmp << ' ';
            pq.pop();
            // if (pq.empty())
            //     break;
            if (tmp % 2 == 0) {
                pq.push(tmp / 2);
                pq.push(tmp / 2);
            } else {
                if ((tmp / 2 + 1) % 2 == 0) {
                    pq.push(tmp / 2);
                    pq.push(tmp - tmp / 2);
                } else {
                    pq.push(tmp / 2 - 1);
                    pq.push(tmp / 2 + 1);
                }
            }
        }
        return pq.top();
    }
};

typedef std::tuple<std::vector<int>, int, int> testcase;
typedef std::unordered_map<size_t, testcase> testcases;

ostream &operator<<(ostream &c, const testcases::value_type &pair) noexcept {
    size_t no = pair.first;
    auto &[nums, maxOperations, answer] = pair.second;
    c << "Testcase " << no << '\n';
    c << "nums = " << nums << '\n';
    c << "maxOperations = " << maxOperations << '\n';
    int myAnswer = Solution::minimumSize(nums, maxOperations);
    c << (myAnswer == answer ? "Correct" : "Incorrect") << ", the answer is "
      << answer;
    if (myAnswer != answer)
        c << " but my answer is " << myAnswer;
    c << "\n- -- - -- - -- -\n";
    return c;
}

int main() {
    testcases testcases{
        {1, {vInt{9}, 2, 3}},
        {2, {vInt{2, 4, 8, 2}, 4, 2}},
        {3, {vInt{1}, 1, 1}},
        {4, {vInt{7, 17}, 2, 7}},
        {5, {vInt{1, 1, 1}, 2, 1}},
        {6, {vInt{1000000000}, 1, 500000000}},
        {7,
         {vInt{146, 788, 775, 772, 792, 68,  143, 376, 375, 877,
               516, 595, 82,  56,  704, 160, 403, 713, 504, 431,
               922, 158, 60,  192, 14,  788, 67,  332, 26},
          80, 129}},
        {8,
         {vInt{556, 96,  205, 188, 505, 14,  602, 591, 802, 662, 543, 781, 878,
               812, 539, 981, 587, 716, 531, 354, 92,  4,   412, 354, 607, 587,
               28,  136, 327, 929, 905, 671, 811, 572, 152, 165, 352, 522, 983,
               966, 378, 911, 873, 606, 392, 927, 426, 726, 892, 939, 96,  419,
               769, 387, 178, 895, 41,  291, 437, 513, 37,  569, 945, 102, 460},
          33, 531}},
    };
    cout << *testcases.find(1);
    cout << *testcases.find(2);
    cout << *testcases.find(3);
    cout << *testcases.find(4);
    cout << *testcases.find(5);
    cout << *testcases.find(6);
    cout << *testcases.find(7);
    cout << *testcases.find(8);
}
