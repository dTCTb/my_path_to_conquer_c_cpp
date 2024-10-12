#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
    typedef pair<pair<unsigned int, char>, unsigned> timeSlot;

  public:
    static int smallestChair(vector<vector<int>> &times, int targetFriend) {
        set<timeSlot> t;
        // set<pair<size_t, int>> emptyChairs;
        // set<pair<size_t, int>> occupied;
        vector<int> chairs(times.size());

        for (unsigned i{}; i < times.size(); ++i) {
            t.insert({{times[i][0], 'Z'}, i}); // arrive time
            t.insert({{times[i][1], 'L'}, i}); // leave time
            // emptyChairs.insert({i, -1});
            chairs[i] = -1;
        }

        for (timeSlot v : t)
            cout << v.first.first << ' ' << v.first.second << ' ' << v.second
                 << '\n';

        for (timeSlot v : t) {
            if (v.first.second == 'L') {
                for (size_t i{}; i < chairs.size(); ++i)
                    if (chairs[i] == v.second) {
                        chairs[i] = -1;
                        break;
                    }
            } else /* if (v.first.second == 'Z') */ {
                for (size_t i{}; i < chairs.size(); ++i)
                    if (chairs[i] == -1) {
                        chairs[i] = v.second;
                        if (v.second == targetFriend)
                            return i;
                        break;
                    }
            }
        }
        return 0;
    }
};

typedef pair<vector<vector<int>>, int> testCase;

int main() {
    testCase eg1{{{1, 4}, {2, 3}, {4, 6}}, 1};
    testCase eg2{{{3, 10}, {1, 5}, {2, 6}}, 0};
    testCase eg3{{{4, 5}, {6, 8}, {8, 10}, {1, 8}}, 2};
    testCase edge1{{{1, 3}, {3, 4}, {4, 5}, {5, 6}}, 0};
    cout << Solution::smallestChair(eg1.first, eg1.second) << '\n';
    cout.put('\n');
    cout << Solution::smallestChair(eg2.first, eg2.second) << '\n';
    cout.put('\n');
    cout << Solution::smallestChair(edge1.first, edge1.second) << '\n';
    cout.put('\n');
    cout << Solution::smallestChair(eg3.first, eg3.second) << '\n';
    cout.put('\n');
}
