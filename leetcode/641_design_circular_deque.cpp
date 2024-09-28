#include "../termcolor.h"
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <utility>
#include <vector>

// reference from the fastest man, Sergei @sergei99
#define NO_SAN                                                                 \
    __attribute__((no_sanitize("undefined", "address", "coverage", "thread")))
#define INL __attribute__((always_inline))

class MyCircularDeque {
  public:
    MyCircularDeque(int k) noexcept;
    ~MyCircularDeque() noexcept;
    bool insertFront(int value) noexcept;
    bool insertLast(int value) noexcept;
    bool deleteFront() noexcept;
    bool deleteLast() noexcept;
    int getFront() const noexcept INL;
    int getRear() const noexcept INL;
    bool isEmpty() const noexcept INL;
    bool isFull() const noexcept INL;
    void print() const noexcept;

  private:
    std::pair<int *, int *> bound;
    int *head, *back;

    int *next(int *ptr) const INL {
        if (ptr != bound.second - 1)
            return ptr + 1;
        return bound.first;
    }

    int *prev(int *ptr) const INL {
        if (ptr != bound.first)
            return ptr - 1;
        return bound.second - 1;
    }
};

// clang-format off
MyCircularDeque::MyCircularDeque(int k) noexcept
    : bound{nullptr, nullptr},
      head{nullptr},
      back{nullptr} {
    int *tmp{new int[k]}; // intended no `nothrow` so that abort immediately
    bound.first = tmp;
    bound.second = tmp + k;
}

MyCircularDeque::~MyCircularDeque() noexcept { delete[] bound.first; }

bool MyCircularDeque::insertFront(int value) noexcept {
    if (isFull()) return false;

    if (isEmpty()) head = back = bound.first;
    else           head = prev(head);

    *head = value;
    return true;
}

bool MyCircularDeque::insertLast(int value) noexcept {
    if (isFull()) return false;

    if (isEmpty()) back = head = bound.first;
    else           back = next(back);

    *back = value;
    return true;
}

bool MyCircularDeque::deleteFront() noexcept {
    if (isEmpty()) return false;

    if  (head == back) head = back = nullptr;
    else               head = next(head);

    return true;
}

bool MyCircularDeque::deleteLast() noexcept {
    if (isEmpty()) return false;

    if  (back == head) back = head = nullptr;
    else               back = prev(back);

    return true;
}

int MyCircularDeque::getFront() const noexcept { return isEmpty() ? -1 : *head; }

int MyCircularDeque::getRear() const noexcept { return isEmpty() ? -1 : *back; }

bool MyCircularDeque::isEmpty() const noexcept { return head == nullptr && back == nullptr; }

bool MyCircularDeque::isFull() const noexcept { return prev(head) == back && next(back) == head; }

void MyCircularDeque::print() const noexcept {
    for (size_t i{}; i < bound.second - bound.first; ++i)
        std::cout << bound.first[i] << ' ';
    std::cout.put('\n');
}
// clang-format on

// reference from the fastest man, Sergei @sergei99
std::function<char(void)> init = []() -> char {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 'c';
};

using namespace std;

// clang-format off
enum class i : unsigned short int {
    MyCircularDeque, insertFront, insertLast, deleteFront,
    deleteLast, getFront, getRear, isEmpty, isFull,
};

struct testCase {
    queue<i, list<i>> instruct;
    queue<int, list<int>> param;
    vector<int> ans, myAns;
    inline static size_t no{};

    testCase(list<i> &&instructions, list<int> &&parameters, vector<int> &&ans) noexcept
        : instruct{instructions},
          param{parameters}, ans{ans} {}

    void test() noexcept {
        MyCircularDeque *obj{};
        while (!instruct.empty() && !param.empty()) {
            switch (instruct.front()) {
            case i::MyCircularDeque:
                obj = new(nothrow) MyCircularDeque{param.front()}; break;
            case i::insertFront:
                myAns.push_back(obj->insertFront(param.front())); break;
            case i::insertLast:
                myAns.push_back(obj->insertLast(param.front())); break;
            case i::deleteFront:
                myAns.push_back(obj->deleteFront()); break;
            case i::deleteLast:
                myAns.push_back(obj->deleteLast()); break;
            case i::getFront:
                myAns.push_back(obj->getFront()); break;
            case i::getRear:
                myAns.push_back(obj->getRear()); break;
            case i::isEmpty:
                myAns.push_back(obj->isEmpty()); break;
            case i::isFull:
                myAns.push_back(obj->isFull()); break;
            default: break;
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

    void parseOutput(vector<int> &input) const noexcept {
        for (const int &e : input) {
            if (e == 0 || e == 1) cout << (e ? GRE("true ") : RED("false "));
            else                  cout << e << ' ';
        }
        cout.put('\n');
    }
};
// clang-format on

int main() {
    // -1 means nothing, as the instructions and parameters are pair up but
    // the testcase provided separately, so `-1` was used to fill the gap
    testCase eg1{{i::MyCircularDeque, i::insertLast, i::insertLast,
                  i::insertFront, i::insertFront, i::getRear, i::isFull,
                  i::deleteLast, i::insertFront, i::getFront},
                 {3, 1, 2, 3, 4, -1, -1, -1, 4, -1},
                 {true, true, true, false, 2, true, true, true, 4}};
    testCase eg2{{i::MyCircularDeque, i::insertFront, i::insertFront,
                  i::insertFront, i::deleteLast, i::deleteLast, i::deleteLast},
                 {3, 1, 2, 3, -1, -1, -1},
                 {true, true, true, true, true, true}};
    testCase eg3{{i::MyCircularDeque, i::insertLast, i::insertLast,
                  i::insertLast, i::deleteFront, i::deleteLast, i::deleteFront},
                 {3, 1, 2, 3, -1, -1, -1},
                 {true, true, true, true, true, true}};
    testCase eg4{{i::MyCircularDeque, i::insertLast, i::insertLast,
                  i::insertLast, i::deleteLast, i::deleteLast, i::deleteLast,
                  i::deleteLast},
                 {3, 1, 2, 3, -1, -1, -1, -1},
                 {true, true, true, true, true, true, false}};
    testCase eg5{{i::MyCircularDeque, i::insertFront, i::insertFront,
                  i::insertFront, i::deleteLast, i::deleteLast, i::deleteLast,
                  i::deleteLast},
                 {3, 1, 2, 3, -1, -1, -1, -1},
                 {true, true, true, true, true, true, false}};
    testCase eg6{{i::MyCircularDeque, i::insertFront, i::insertLast, i::getRear,
                  i::getFront, i::getFront, i::deleteLast, i::deleteFront,
                  i::getRear},
                 {41, 70, 11, -1, -1, -1, -1, -1, -1},
                 {true, true, 11, 70, 70, true, true, -1}};
    testCase eg7{{i::MyCircularDeque, i::insertFront, i::insertFront,
                  i::getRear, i::getFront, i::getFront, i::deleteLast,
                  i::deleteFront, i::getRear},
                 {41, 70, 11, -1, -1, -1, -1, -1, -1},
                 {true, true, 70, 11, 11, true, true, -1}};
    testCase eg8{
        {i::MyCircularDeque, i::insertFront, i::insertLast, i::deleteFront,
         i::getFront,        i::deleteLast,  i::insertLast, i::isEmpty,
         i::deleteLast,      i::insertFront, i::getRear,    i::deleteFront,
         i::insertFront,     i::insertLast,  i::deleteLast, i::getFront,
         i::getRear,         i::insertFront, i::getRear,    i::getFront},
        {999, 93, 578, -1, -1, -1, 533, -1,  -1, 913,
         -1,  -1, 100, 57, -1, -1, -1,  900, -1, -1},
        {true, true, true, 578, true, true, false, true, true, 913, true, true,
         true, true, 100, 100, true, 100, 900}};
    testCase eg9{
        {i::MyCircularDeque, i::insertFront, i::getRear,     i::deleteLast,
         i::getRear,         i::insertFront, i::insertFront, i::insertFront,
         i::insertFront,     i::isFull,      i::insertFront, i::isFull,
         i::getRear,         i::deleteLast,  i::getFront,    i::getFront,
         i::insertLast,      i::deleteFront, i::getFront,    i::insertLast,
         i::getRear,         i::insertLast,  i::getRear,     i::getFront,
         i::getFront,        i::getFront,    i::getRear,     i::getRear,
         i::insertFront,     i::getFront,    i::getFront,    i::getFront,
         i::getFront,        i::deleteFront, i::insertFront, i::getFront,
         i::deleteLast,      i::insertLast,  i::insertLast,  i::getRear,
         i::getRear,         i::getRear,     i::isEmpty,     i::insertFront,
         i::deleteLast,      i::getFront,    i::deleteLast,  i::getRear,
         i::getFront,        i::isFull,      i::isFull,      i::deleteFront,
         i::getFront,        i::deleteLast,  i::getRear,     i::insertFront,
         i::getFront,        i::insertFront, i::insertFront, i::getRear,
         i::isFull,          i::getFront,    i::getFront,    i::insertFront,
         i::insertLast,      i::getRear,     i::getRear,     i::deleteLast,
         i::insertFront,     i::getRear,     i::insertLast,  i::getFront,
         i::getFront,        i::getFront,    i::getRear,     i::insertFront,
         i::isEmpty,         i::getFront,    i::getFront,    i::insertFront,
         i::deleteFront,     i::insertFront, i::deleteLast,  i::getFront,
         i::getRear,         i::getFront,    i::insertFront, i::getFront,
         i::deleteFront,     i::insertFront, i::isEmpty,     i::getRear,
         i::getRear,         i::getRear,     i::getRear,     i::deleteFront,
         i::getRear,         i::isEmpty,     i::deleteFront, i::insertFront,
         i::insertLast,      i::deleteLast},
        {77, 89, -1, -1, -1, 19, 23, 23, 82, -1, 45, -1, -1, -1, -1, -1, 74,
         -1, -1, 98, -1, 99, -1, -1, -1, -1, -1, -1, 8,  -1, -1, -1, -1, -1,
         75, -1, -1, 35, 59, -1, -1, -1, -1, 22, -1, -1, -1, -1, -1, -1, -1,
         -1, -1, -1, -1, 21, -1, 26, 63, -1, -1, -1, -1, 87, 76, -1, -1, -1,
         26, -1, 67, -1, -1, -1, -1, 36, -1, -1, -1, 72, -1, 87, -1, -1, -1,
         -1, 85, -1, -1, 91, -1, -1, -1, -1, -1, -1, -1, -1, -1, 34, 44, -1},
        {true, 89,    true, -1,   true,  true,  true, true, false, true,  false,
         19,   true,  45,   45,   true,  true,  82,   true, 98,    true,  99,
         82,   82,    82,   99,   99,    true,  8,    8,    8,     8,     true,
         true, 75,    true, true, true,  59,    59,   59,   false, true,  true,
         22,   true,  98,   22,   false, false, true, 75,   true,  74,    true,
         21,   true,  true, 74,   false, 63,    63,   true, true,  76,    76,
         true, true,  74,   true, 26,    26,    26,   67,   true,  false, 36,
         36,   true,  true, true, true,  87,    74,   87,   true,  85,    true,
         true, false, 74,   74,   74,    74,    true, 74,   false, true,  true,
         true, true}};
    eg1.test();
    eg2.test();
    eg3.test();
    eg4.test();
    eg5.test();
    eg6.test();
    eg7.test();
    eg8.test();
    eg9.test();
}
