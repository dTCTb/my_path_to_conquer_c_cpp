#include <iostream>
#include <vector>

using namespace std;

struct node;

std::ostream &operator<<(std::ostream &c, const std::vector<int> &arr);
std::ostream &operator<<(std::ostream &c,
                         const std::vector<std::vector<int>> &arr);
std::ostream &operator<<(std::ostream &c, const node *p /*arent*/);

typedef std::vector<int> vInt;
typedef std::vector<vInt> vvInt;

struct node {
    vector<node *> city;
    int value;
    node(int value) { this->value = value; }
};

class Solution {
  public:
    static vInt shortestDistanceAfterQueries(int n, const vvInt &queries) noexcept {
        vInt ans{};
        ans.reserve(queries.size());

        vector<node *> s(n, nullptr);
        s[0] = new node{0};

        for (int i{1}; i < n; ++i) {
            s[i] = new node{i};
            s[i - 1]->city.push_back(s[i]);
        }

        // cout << s[0] << '\n'; // check above initialization

        for (const vInt &query : queries) {
            queue<node *, deque<node *>> q{};
            s[query[0]]->city.push_back(s[query[1]]); // add new path
            q.push(s[0]);                             // bfs preparation

            vector<bool> visited(n, false);           // prevent from repetitive
            int count{};

            while (!q.empty()) {
                q.push(nullptr);
                const node *cur{q.front()};

                while (cur /* != nullptr */) {
                    if (cur->value == n - 1)
                        break;

                    for (node *n : cur->city)
                        if (!visited[n->value]) {
                            q.push(n);
                            visited[n->value] = true;
                        }

                    q.pop();
                    cur = q.front();
                }

                if (cur)
                    break;

                q.pop();
                ++count;
            }
            ans.push_back(count);
        }

        return ans;
    }
};

typedef tuple<const size_t, const int, const vvInt, const vInt> testcase;

ostream &operator<<(ostream &c, const testcase &t) {
    const auto &[no, n, queries, answer] = t;
    c << "Testcase " << no << '\n';
    c << "        n: " << n << '\n';
    c << "  queries: " << queries << '\n';
    c << "   answer: " << answer << '\n';
    vInt myAnswer{Solution::shortestDistanceAfterQueries(n, queries)};
    c << "my answer: " << myAnswer << '\n';
    c << (myAnswer == answer ? "Correct" : "Incorrect")
      << "\n- -- - -- - -- -\n";
    return c;
}

int main() {
#include "TestCases/3243_testcase.txt"
    cout << e1;
    cout << e2;
    cout << e3;
    cout << e4;
    cout << e5;
    cout << e6;
    cout << e7;
    cout << e8;
    cout << e9;
    cout << e10;
}

ostream &operator<<(ostream &c, const vInt &arr) {
    c << '{';
    for (const int &e : arr)
        c << e << ',';
    c << "\b}";
    return c;
}

ostream &operator<<(ostream &c, const vvInt &arr) {
    c << '{';
    for (const vInt &e : arr) {
        c << '{';
        for (const int &s : e)
            c << s << ',';
        c << "\b},";
    }
    c << "\b}";
    return c;
}

ostream &operator<<(ostream &c, const node *p /*arent*/) {
    queue<const node *> q /*ueue*/;
    q.push(p);
    while (!q.empty()) {
        const node *cur{q.front()};
        c << cur->value << ' ';
        for (node *n : cur->city)
            q.push(n);
        q.pop();
    }
    return c;
}
