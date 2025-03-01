#include <iostream>
#include <set>
#include <unordered_map>

using namespace std;

/* 101ms 196.14mb */
class NumberContainers {
  private:
    typedef unordered_map<int, set<int>> isMap;
    typedef unordered_map<int, int> iiMap;
    isMap *t1;
    iiMap *t2;

  public:
    NumberContainers() : t1{new isMap()}, t2{new iiMap()} {}

    void change(int index, int number) {
        if ((*t2)[index])
            (*t1)[(*t2)[index]].erase(index);
        (*t2)[index] = number;
        (*t1)[number].insert(index);
    }

    int find(int number) {
        if ((*t1)[number].empty())
            return -1;
        return *((*t1)[number].begin());
    }

    ~NumberContainers() {
        delete t1;
        delete t2;
    }

    typedef vector<pair<char, pair<int, int>>> Directives;
    static void test(const Directives &directives) noexcept {
        NumberContainers *nc = new NumberContainers;
        for (const auto &[cmd, args] : directives) {
            const auto &[index, number] = args;
            switch (cmd) {
            case 'f': /*find(number)*/
                cout << "find(" << number << ") " << nc->find(number) << '\n';
                break;
            case 'c': /*change(index, number)*/
                cout << "change(" << index << ',' << number << ") null\n";
                nc->change(index, number);
                break;
            default:
                break;
            }
        }
    }
};

int main() {
    NumberContainers::test({{'f', {0, 10}}, // -1
                            {'c', {2, 10}},
                            {'c', {1, 10}},
                            {'c', {3, 10}},
                            {'c', {5, 10}},
                            {'f', {0, 10}}, // 1
                            {'c', {1, 20}},
                            {'f', {0, 10}}}); // 2
    NumberContainers::test({{'f', {0, 5}},    // -1
                            {'c', {1, 10}},
                            {'c', {2, 10}},
                            {'f', {0, 10}}}); // 1
}
