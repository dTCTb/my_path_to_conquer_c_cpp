#include <iostream>
#include <iterator>
#include <queue>
#include <vector>

using namespace std;

typedef std::vector<int> vInt;
typedef std::vector<vInt> vvInt;
class Solution {
  public:
    static vInt eventualSafeNodes(const vvInt &graph) noexcept {
        return solve1(graph);
    }
    /* 54ms 66.06mb */
    static vInt solve1(const vvInt &graph) noexcept {
        vvInt m(graph.size());
        vInt outdeg(graph.size());
        queue<int> q{};

        for (int no{}; const vInt &node : graph) {
            if (node.empty())
                q.push(no);
            else
                for (const int adjacent : node) {
                    m[adjacent].push_back(no);
                    ++outdeg[no];
                }
            ++no;
        }

        vector<bool> visited(graph.size());
        while (!q.empty()) {
            visited[q.front()] = true;
            for (const int adjacent : m[q.front()])
                if (--outdeg[adjacent] == 0)
                    q.push(adjacent);
            q.pop();
        }

        vInt ans{};
        for (int no{-1}; const bool val : visited)
            if (++no, val)
                ans.push_back(no);

        // cout << "ans: ";
        // copy(ans.cbegin(), ans.cend(), ostream_iterator<int>(cout, ", "));
        // cout << "\b\b \n";
        return ans;
    }
};

int main() {
    auto test = bind(Solution::eventualSafeNodes, placeholders::_1);
    test(vvInt{vInt{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}});    // {2,4,5,6}
    test(vvInt{vInt{1, 2, 3, 4}, {1, 2}, {3, 4}, {0, 4}, {}}); // {4}
    test(vvInt{vInt{}, {0, 2, 3, 4}, {3}, {4}, {}});           // {0,1,2,3,4}
}
