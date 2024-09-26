#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

ostream &operator<<(ostream &c, pair<int, int> &p) {
    c << p.first << ", " << p.second;
    return c;
}

class Schedule {
    friend class MyCalendar;

  public:
    typedef pair<int, int> booking;
    Schedule() : journal{new list<booking>} {}

    bool addBooking(const booking &newBooking) {
        if (journal->empty()) {
            journal->push_back(newBooking);
            return true;
        }

        list<booking>::const_iterator prev =
            find_if(journal->cbegin(), journal->cend(),
                    [&newBooking](booking e) -> bool {
                        return e.first > newBooking.first;
                    }); // return a booking that just later than the newBooking
        // called prev cause of postfix decrement ⤹ on it
        list<booking>::const_iterator next = prev--;

        if ((next == journal->cend() && newBooking.first >= prev->second) ||
            ((newBooking.first >= prev->second) &&
             (newBooking.second <= next->first))) {
            journal->insert(next, newBooking);
            return true;
        }

        return false;
    }

    ~Schedule() { delete journal; }

  private:
    list<booking> *journal;
    void print_journal() const {
        for (pair<int, int> &p : *journal)
            cout << p << '\n';
        cout.put('\n');
    }
};

class MyCalendar {
  public:
    MyCalendar() : schedule{new Schedule} {}

    bool book(int start, int end) {
        bool ret = schedule->addBooking(pair<int, int>{start, end});
        // schedule->print_journal();
        return ret;
    }

    ~MyCalendar() { delete schedule; }

  private:
    Schedule *schedule;
};

struct testCase {
    // clang-format off
    MyCalendar *obj;
    vector<Schedule::booking> startEnd;
    vector<bool> ans;

    testCase(vector<Schedule::booking> &&iStartEnd, vector<bool> &&iAns)
        : obj{new MyCalendar}, startEnd{iStartEnd}, ans{iAns} {}

    void test() {
        static size_t no{};
        vector<bool> myAns;

        for (Schedule::booking &book : startEnd) myAns.push_back(obj->book(book.first, book.second));

        cout << boolalpha << "\nTestcase " << ++no << ":\n";
        for (bool b : ans) cout << b << ' ';
        cout.put('\n');
        for (bool b : myAns) cout << b << ' ';
        cout.put('\n');
    }
    ~testCase() { delete obj; }
    // clang-format on
};

int main() {
    // clang-format off
    testCase eg1{{{10, 20}, {15, 25}, {20, 30}}, {true, false, true}};
    testCase eg2{{{47, 50}, {33, 41}, {39, 45}, {33, 42}, {25, 32},
                  {26, 35}, {19, 25}, {3, 8}, {8, 13}, {18, 27}},
                 {true, true, false, false, true, false, true, true, true, false}};
    testCase eg3{{{37, 50}, {33, 50}, {4, 17}, {35, 48}, {8, 25}},
                 {true, false, true, false, false}};
    testCase eg4{{{97, 100}, {33, 51},  {89, 100}, {83, 100}, {75, 92},
                  {76, 95},  {19, 30},  {53, 63},  {8, 23},   {18, 37},
                  {87, 100}, {83, 100}, {54, 67},  {35, 48},  {58, 75},
                  {70, 89},  {13, 32},  {44, 63},  {51, 62},  {2, 15}},
                 {true,  true,  false, false, true,  false, true,
                  true,  false, false, false, false, false, false,
                  false, false, false, false, false, true}};
    testCase eg5{{{20, 29}, {13, 22}, {44, 50}, {1, 7}, {2, 10}, {14, 20}},
                 {true, false, true, true, false, true}};
    testCase eg6{{{20, 29}, {13, 22}, {44, 50}, {1, 7},   {2, 10},  {14, 20},
                  {19, 25}, {36, 42}, {45, 50}, {47, 50}, {39, 45}, {44, 50},
                  {16, 25}, {45, 50}, {45, 50}, {12, 20}, {21, 29}, {11, 20},
                  {12, 17}, {34, 40}, {10, 18}, {38, 44}, {23, 32}, {38, 44},
                  {15, 20}, {27, 33}, {34, 42}, {44, 50}, {35, 40}, {24, 31}},
                 {true,  false, true,  true,  false, true,  false, true,
                  false, false, false, false, false, false, false, false,
                  false, false, false, false, false, false, false, false,
                  false, false, false, false, false, false}};
    // clang-format on

    eg1.test();
    eg2.test();
    eg3.test();
    eg4.test();
    eg5.test();
    eg6.test();
}
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
