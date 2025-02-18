#include "lc_tools.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(), tiles.end());
        int box[26]{};

        for (const char tile : tiles)
            ++box[tile - 'A'];
        const int ans{bt(box)};
        cout << "ans: " << ans << '\n';
        return ans;
    }

    int bt(int *box) {
        int sum{};

        for (size_t i{}; i < 26; ++i) {
            if (!box[i])
                continue;

            ++sum;
            --box[i];
            sum += bt(box);
            ++box[i];
        }
        return sum;
    }
};

int main() {
    Solution s;
    s.numTilePossibilities("AAB");    // 8
    s.numTilePossibilities("AAABBC"); // 188
    s.numTilePossibilities("V");      // 1
}
