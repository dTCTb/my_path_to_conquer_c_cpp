#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    typedef vector<int> intVec;
    typedef vector<int>::iterator intVec_it;

    inline static vector<int> prime{
        /* must include 0 */
        0,   2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,
        41,  43,  47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,
        101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163,
        167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233,
        239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311,
        313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389,
        397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463,
        467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563,
        569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641,
        643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727,
        733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821,
        823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907,
        911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

    Solution() {
        std::ios::sync_with_stdio(false);
        std::cout.tie(0);
        std::cin.tie(0);
    }

    static bool primeSubOperation(vector<int> &nums) noexcept {
        if (nums.size() == 1)
            return true;

        nums[0] -= *--lower_bound(prime.cbegin(), prime.cend(), nums[0]);
        for (int i{1}; i < nums.size(); ++i) {
            intVec_it it{--lower_bound(prime.begin(), prime.end(), nums[i])};
            while (it != prime.begin()) {
                if (int cur{nums[i] - *it}; cur > nums[i - 1]) {
                    nums[i] = cur;
                    break;
                }
                --it;
            }
            if (nums[i] <= nums[i - 1])
                return false;
        }
        return true;
    }
};

int main() {
    cout << boolalpha;
    auto test = bind(Solution::primeSubOperation, placeholders::_1);
    vector<int> e1{4, 9, 6, 10};
    vector<int> e2{6, 8, 11, 12};
    vector<int> e3{5, 8, 3};
    vector<int> e4{3, 4, 10, 15, 6};
    vector<int> e5{2, 2};
    cout << test(e1) << '\n'; // true
    cout << test(e2) << '\n'; // true
    cout << test(e3) << '\n'; // false
    cout << test(e4) << '\n'; // true
    cout << test(e5) << '\n'; // false
}
