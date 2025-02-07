#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
typedef std::vector<vInt> vvInt;
typedef std::unordered_map<int, int> iiMap;
class Solution {
  public:
    static vInt queryResults(int limit, const vvInt &queries) noexcept {
        int cnt{};
        vInt ans; // memory limit exceeded if using vector for balls(limit + 1);
        ans.reserve(queries.size());
        /* colors[x] to find the frequency of color 'x'
         * balls[x] to find the color painted on the ball 'x' */
        iiMap colors, balls;

        for (const vInt &query : queries) {
            int &current_ball_color = balls[query[0]];
            int &current_ball_color_freq = colors[balls[query[0]]];
            const int new_paint_color = query[1];
            int &new_paint_color_freq = colors[query[1]];

            if (/* current_ball_color != 0 && */
                current_ball_color != new_paint_color) {
                if (new_paint_color_freq == 0)
                    ++cnt;
                if (--current_ball_color_freq == 0)
                    --cnt;
            } else if (new_paint_color_freq == 0)
                ++cnt;

            if (current_ball_color != new_paint_color)
                ++new_paint_color_freq;
            current_ball_color = new_paint_color;

            ans.push_back(cnt);
        }

        copy(ans.cbegin(), ans.cend(),
             ostream_iterator<vInt::value_type>(cout, ", "));
        cout << "\b\b \n";

        return ans;
    }
};

// clang-format off
int main() {
    Solution::queryResults(4, {{1, 4}, {2, 5}, {1, 3}, {3, 4}}); // {1,2,2,3}
    Solution::queryResults(4, {{0, 1}, {1, 2}, {2, 2}, {3, 4}, {4, 5}});    // {1,2,2,3,4}
    Solution::queryResults(2, {{0, 1}, {1, 2}, {2, 3}}); // {1,2,3}
    Solution::queryResults( 1, {{0, 1}, {0, 4}, {0, 4}, {0, 1}, {1, 2}}); // {1,1,1,1,2}
    Solution::queryResults( 1, {{0, 2}, {1, 10}, {0, 10}, {0, 3}, {1, 5}}); // {1,2,1,2,2}
    Solution::queryResults( 5, {{1, 1}, {2, 1}, {3, 2}, {4, 3}, {5, 4}}); // {1,1,2,3,4}
    Solution::queryResults( 10, {{1, 5}, {2, 5}, {1, 5}, {3, 7}, {4, 8}}); // {1,1,1,2,3}
    Solution::queryResults( 6, {{1, 3}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {0, 3}}); // {1,1,2,3,4,4}
    Solution::queryResults(1000000000, {{500000000, 1}, {600000000, 1}}); // {1,1}
}
