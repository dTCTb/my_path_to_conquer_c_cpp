#include "../termcolor.h"
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <unordered_map>

using namespace std;
#define INL __attribute__((always_inline))

// 呢題係我睇withaarzoo 嘅Solution 之後，好也就realize 到係點寫
// https://leetcode.com/problems/all-oone-data-structure/solutions/5845777/optimize-your-code-with-the-all-o-one-data-structure-hack
// 我要熟習一下set container 喇！！！
// 我就係卡咗好耐點樣用map 同list 嚟結構，將頭係min, 尾係max 苦腦咗好耐！
// 用set 就可以好完美咁解決到！因為set 嘅insert 會按order 插入，
// 但hashmap 有key, value 之分，成件事難度標升，
// 而list 又無得sort, insert 時要揾啱位又難⋯⋯
// 琴日design circular deque 爽完，今日又俾難度為hard 嘅LeetCode 虐>3<
// 又係睇完人地答案先知，又覺得shame，但呢個就係學習過程！加油ME！！！！
class AllOne {
  private:
    unordered_map<string, size_t> table;
    set<pair<size_t, string>> set;
    void printSet() const noexcept {
        for (std::set<pair<size_t, string>>::value_type const &node : set)
            cout << '(' << node.first << ", " << node.second << ") ";
        cout.put('\n');
    }
    void printTable() const noexcept {
        for (unordered_map<string, size_t>::value_type const &node : table)
            cout << node.first << ": " << node.second << '\n';
    }

  public:
    AllOne() noexcept;
    void inc(string key) noexcept;
    void dec(string key) noexcept;
    string getMaxKey() noexcept INL;
    string getMinKey() noexcept INL;

    void print(char c = 'a') const noexcept {
        if (c == 's') // s for set
            printSet();
        else if (c == 't') // t for table
            printTable();
        else { // a for all
            printTable();
            printSet();
        }
    }
};

AllOne::AllOne() noexcept : table{}, set{} {}

void AllOne::inc(string key) noexcept {
    set.erase({table[key], key});
    set.insert({++table[key], key});
}

void AllOne::dec(string key) noexcept {
    set.erase({table[key], key});
    if (--table[key] == 0)
        table.erase(key);
    else
        set.insert({table[key], key});
}

string AllOne::getMaxKey() noexcept {
    return set.empty() ? "" : set.rbegin()->second;
}

string AllOne::getMinKey() noexcept {
    return set.empty() ? "" : set.begin()->second;
}

enum class i : unsigned short int { AllOne, inc, dec, getMaxKey, getMinKey };

// 呢個TestCase 有啲kick，因為有時係佢expect 嘅output 同我嘅answer 唔同
// 但都照啱，所以安全起見係去返LeetCode 432 題度用佢嚟check 答案
// 至少呢個commit eg2,4,5,6,7 都話wrong，但其實係啱
struct TestCase {
    queue<i, list<i>> instruct;
    queue<string, list<string>> param;
    vector<string> ans, myAns;
    inline static size_t no{};

    TestCase(list<i> &&instructions, list<string> &&parameters,
             vector<string> &&ans) noexcept
        : instruct{instructions}, param{parameters}, ans{ans} {}

    void test(bool debug_print = false) noexcept {
        AllOne *obj{};
        while (!instruct.empty() && !param.empty()) {
            switch (instruct.front()) {
            case i::AllOne:
                obj = new (nothrow) AllOne{};
                myAns.push_back("null");
                break;
            case i::inc:
                obj->inc(param.front());
                myAns.push_back("null");
                if (debug_print) {
                    cout << "After inc " << param.front() << ",\n";
                    obj->print();
                }
                break;
            case i::dec:
                obj->dec(param.front());
                myAns.push_back("null");
                if (debug_print) {
                    cout << "After dec " << param.front() << ",\n";
                    obj->print();
                }
                break;
            case i::getMaxKey:
                myAns.push_back(obj->getMaxKey());
                if (debug_print) {
                    cout << "getMaxKey: ";
                    obj->print('s');
                }
                break;
            case i::getMinKey:
                myAns.push_back(obj->getMinKey());
                if (debug_print) {
                    cout << "getMinKey: ";
                    obj->print('s');
                }
                break;
            default:
                break;
            }
            instruct.pop();
            param.pop();
        }

        cout << BLUC "\nTestCase " << ++no << RESET ": "
             << (myAns == ans ? AQU("100% correct\n") : BRED("Wrong") "\n");

        parseOutput(ans);
        parseOutput(myAns);
        delete obj;
    }

    void parseOutput(vector<string> &input) const noexcept {
        // for (const string &e : input) {
        for (size_t i{}; i < myAns.size(); ++i) {
            if (input[i] == "")
                cout << PUR("\"\"") << ' ';
            else if (input[i] == "null")
                cout << ORA("null") << ' ';
            else if (input[i] == ans[i])
                cout << GREC << input[i] << RESET << ' ';
            else
                cout << REDC << input[i] << RESET << ' ';
        }
        cout.put('\n');
    }
};

int main() {
    TestCase eg1{
        {i::AllOne, i::inc, i::inc, i::getMaxKey, i::getMinKey, i::inc,
         i::getMaxKey, i::getMinKey},
        {"nulll", "hello", "hello", "null", "null", "leet", "null", "null"},
        {"null", "null", "null", "hello", "hello", "null", "hello", "leet"}};
    TestCase eg2{
        {i::AllOne, i::inc, i::inc, i::inc, i::dec, i::getMaxKey, i::getMinKey,
         i::dec, i::getMaxKey, i::getMinKey},
        {"null", "a", "a", "b", "a", "null", "null", "b", "null", "null"},
        {"null", "null", "null", "null", "null", "a", "a", "null", "a", "a"}};
    TestCase eg3{{i::AllOne, i::getMaxKey, i::getMinKey},
                 {"null", "null", "null"},
                 {"null", "", ""}};
    TestCase eg4{
        {i::AllOne, i::inc, i::inc, i::inc, i::inc, i::getMaxKey, i::getMinKey},
        {"null", "a", "b", "c", "d", "null", "null"},
        {"null", "null", "null", "null", "null", "a", "a"}};
    TestCase eg5{{i::AllOne, i::inc, i::inc, i::inc, i::inc, i::inc, i::inc,
                  i::getMaxKey, i::getMinKey, i::inc, i::getMaxKey,
                  i::getMinKey, i::inc, i::dec, i::dec, i::getMaxKey,
                  i::getMinKey},
                 {"null", "a", "b", "c", "d", "a", "d", "null", "null", "c",
                  "null", "null", "b", "d", "d", "null", "null"},
                 {"null", "null", "null", "null", "null", "null", "null", "a",
                  "c", "null", "a", "b", "null", "null", "null", "a", "a"}};
    TestCase eg6{
        {i::AllOne, i::inc,       i::inc,       i::inc,       i::inc,
         i::inc,    i::inc,       i::inc,       i::inc,       i::inc,
         i::inc,    i::inc,       i::inc,       i::dec,       i::dec,
         i::dec,    i::dec,       i::dec,       i::dec,       i::inc,
         i::inc,    i::inc,       i::inc,       i::getMaxKey, i::getMinKey,
         i::inc,    i::inc,       i::getMaxKey, i::getMinKey, i::inc,
         i::dec,    i::getMaxKey, i::getMinKey},
        {"null", "a",    "b", "c", "d",    "e",    "f",    "g", "h",
         "i",    "j",    "k", "l", "a",    "b",    "c",    "d", "e",
         "f",    "g",    "h", "i", "j",    "null", "null", "k", "l",
         "null", "null", "a", "j", "null", "null"},
        {"null", "null", "null", "null", "null", "null", "null", "null", "null",
         "null", "null", "null", "null", "null", "null", "null", "null", "null",
         "null", "null", "null", "null", "null", "i",    "k",    "null", "null",
         "g",    "g",    "null", "null", "g",    "a"}};
    TestCase eg7{{i::AllOne, i::inc, i::inc, i::inc, i::inc, i::inc, i::dec,
                  i::dec, i::getMaxKey, i::getMinKey},
                 {"null", "a", "b", "c", "d", "c", "c", "a", "null", "null"},
                 {"null", "null", "null", "null", "null", "null", "null",
                  "null", "c", "c"}};
    eg1.test();
    eg2.test();
    eg3.test();
    eg4.test();
    eg5.test();
    eg6.test();
    eg7.test();
}
