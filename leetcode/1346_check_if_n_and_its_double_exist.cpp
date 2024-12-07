// clang-format off
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
class Solution {
  public:
    static bool checkIfExist(vInt &arr) {
        sort(arr.begin(), arr.end());

        function<void(int, int, int)> lmr = [&arr](int l, int m, int r) -> void {
            cout << "l: " << l << " r: " << r << " arr[" << m << "]: " << arr[m] << '\n';
        };

        function<bool(int)> bs = [&arr, &lmr](int x) -> bool {
            int l{arr[x] == 0 ? x + 1 : arr[x] < 0 ? 0 : x};
            int r{arr[x] >= 0 ? static_cast<int>(arr.size() - 1) : x};
            int target = arr[x] * 2;
            // cout << "target: " << target << '\n';
            while (l <= r) {
                int m = (l + r) / 2;
                // lmr(l, m, r);
                if (arr[m] == target)     return true;
                else if (arr[m] < target) l = m + 1;
                else if (arr[m] > target) r = m - 1;
            }
            return false;
        };

        for (int i{}; i < arr.size(); ++i)
            if (bs(i)) return true;

        return false;
    }
};


ostream &operator<<(ostream &c, vInt arr) {
    for (int &e : arr)
        c << e << ' ';
    c.put('\n');
    return c;
}

typedef std::unordered_map<size_t, std::pair<vInt, bool>> testcases;

ostream &operator<<(ostream &c, testcases::value_type &t) {
    auto &[no, testcase] = t;
    auto &[arr, answer] = testcase;

    c << "Testcase " << no << '\n';

    c << arr;
    sort(arr.begin(), arr.end());
    c << arr;

    bool myAnswer = Solution::checkIfExist(arr);

    c << (myAnswer == answer ? "Correct" : "Incorrect") << '\n';
    c << "- -- - -- -\n";
    return c;
}

// clang-format on
int main(int argc, char **argv) {
    testcases testcases{
        {1, {vInt{3, 1, 7, 11}, false}},
        {2, {vInt{0, 0}, true}},
        {3, {vInt{-2, 0, 10, -19, 4, 6, -8}, false}},
        {4, {vInt{-16, -13, 8}, false}},
        {5, {vInt{10, 2, 7, 3, 0, 0, -13}, true}},
        {6, {vInt{7, 15, 3, 4, 30}, true}},
        {7, {vInt{0, 2, -7, 11, 4, 18}, true}},
        {8,
         {vInt{357,  -53,  277,  -706, 980,  826,  93,   -352, -669, 989,  -193,
               920,  209,  -574, -389, 221,  383,  352,  665,  873,  759,  -480,
               -64,  -103, -721, -623, -642, -680, 20,   -168, 528,  -336, -656,
               264,  581,  -714, -458, 721,  815,  106,  328,  476,  351,  325,
               -954, 890,  -174, 635,  95,   -443, 338,  907,  -648, 113,  -278,
               498,  532,  -778, 95,   -487, -909, -642, 774,  296,  417,  -132,
               -951, 857,  -867, 321,  -960, 180,  108,  -984, -54,  103,  703,
               -118, -252, 235,  577,  -703, 842,  -638, -888, -981, -246, 484,
               202,  328,  661,  447,  -831, 946,  -888, -749, -702},
          true}},
        {9,
         {vInt{2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,
               43,  47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101,
               103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167,
               173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239,
               241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313,
               317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397,
               401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467,
               479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569,
               571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643,
               647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733,
               739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823,
               827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911,
               919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997},
          false}},
        {38, {vInt{10, 2, 5, 3}, true}},
        {106, {vInt{-10, 12, -20, -8, 15}, true}},
    };

    if (argc > 1) {
        for (int i{1}; i < argc; ++i) {
            try {
                if (int e{stoi(*(argv + i))}; testcases.count(e))
                    cout << *testcases.find(e);
            } catch (invalid_argument ex) {
                cout << "there is NO testcase " << quoted(*(argv + i)) << ", ";
                cout << "only accept testcases [";
                for (testcases::value_type &p : testcases)
                    cout << p.first << ' ';
                cout << "\b]\n";
            }
        }
    } else {
        cout << *testcases.find(1);
        cout << *testcases.find(2);
        cout << *testcases.find(3);
        cout << *testcases.find(4);
        cout << *testcases.find(5);
        cout << *testcases.find(6);
        cout << *testcases.find(7);
        cout << *testcases.find(8);
        cout << *testcases.find(9);
        cout << *testcases.find(38);
        cout << *testcases.find(106);
    }
}
