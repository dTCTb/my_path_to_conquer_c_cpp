#include <bitset>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
  public:
    static long long minEnd__(int n, int x) {
        long long result = x, mask;
        --n; // Reducing n by 1 to exclude x from the iteration

        // Step 1: Iterate over each bit position with mask starting at
        // 1 and shifting left
        for (mask = 1; n > 0; mask <<= 1) {
            // Step 2: If the corresponding bit in x is 0
            if ((mask & x) == 0) {
                // Set the bit in result based on the least significant
                // bit of n
                result |= (n & 1) * mask;
                // Shift n to the right by 1 to process the next bit
                n >>= 1;
            }
        }

        return result;
    }

    // brutal force (TLE)
    static long long minEnd(int n, int x) {
        unsigned long long t = x;
        while (n > 0) {
            if ((t & x) == x)
                --n;
            if (n == 0)
                return t;
            ++t;
        }
        return t;
    }

    // just another method that TLE
    static long long minEnd_(int n, int x) {
        unsigned long long t = x;

        unsigned long long p{1ULL};
        for (unsigned long long tmp = x; tmp; tmp >>= 1)
            p <<= 1;

        set<unsigned long long> tes;
        tes.insert(x);

        while (true) {
            for (unsigned long long e : tes) {
                unsigned long long p{1ULL};
                while (p < t) {
                    if ((e & p) == 0)
                        tes.insert(e + p);
                    p <<= 1;
                }
                if (tes.size() == n)
                    return *(--tes.end());
            }
            t += p;
            p <<= 1;
        }

        for (auto e : tes)
            cout << e << ' ';
        cout.put('\n');

        return 0;
    }
};

int main() {
    cout << Solution::minEnd__(3, 4) << "|6\n"; // 6
    // 100 4  101 5  110 6  111 7
    //&100 4 &100 4 &100 4 &100 4
    // 100    100    100    100
    cout << Solution::minEnd__(2, 7) << "|15\n"; // 15
    // 111 7  1111
    //&111 7 &0111
    // 111    0111
    cout << Solution::minEnd__(1, 1) << "|1\n";         // 1
    cout << Solution::minEnd__(21, 16) << "|52\n";      // 52
    cout << Solution::minEnd__(16, 16) << "|31\n";      // 31
    cout << Solution::minEnd__(18, 22) << "|151\n";     // 151
    cout << Solution::minEnd__(792, 283) << "|25471\n"; // 25471
}
