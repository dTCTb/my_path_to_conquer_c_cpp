#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using std::string, std::vector, std::stoi, std::sort, std::cout, std::min,
    std::setw;

class Solution {
  public:
    int findMinDifference(vector<string> &timePoints) {
        unsigned hour, minute;
        unsigned minTimeDiff{0xffffffffU};
        vector<unsigned> minuteTP(timePoints.size());

        auto minute_of = [&hour, &minute](string &s) -> unsigned {
            hour = stoi(s.substr(0, 2));
            minute = stoi(s.substr(3, 2));
            return hour * 60 + minute;
        };

        for (size_t i{}; i < minuteTP.size(); ++i)
            minuteTP[i] = minute_of(timePoints[i]);

        sort(minuteTP.begin(), minuteTP.end());

        for (size_t i{}; i + 1 < minuteTP.size(); ++i)
            minTimeDiff = min(minuteTP[i + 1] - minuteTP[i], minTimeDiff);

        minTimeDiff =
            min(((minuteTP.front() + 24 * 60) - minuteTP.back()), minTimeDiff);
        print_out(timePoints, minuteTP, minTimeDiff);
        return minTimeDiff;
    }

    void print_out(vector<string> &testCase, vector<unsigned> &data,
                   unsigned min) {
        static unsigned count{1};

        cout << "\nTestcase #" << count++ << ": \n   ";
        for (string &time : testCase)
            cout << time << ' ';
        cout << "\n   ";
        for (unsigned &minute : data)
            cout << setw(5) << minute << ' ';
        cout << '\n';
        cout << min << " minute(s)\n";
    }
};

typedef std::vector<std::vector<std::string>> TimePoint;
int main() {
    Solution solution;
    TimePoint testCases{{{"23:59", "00:00"},
                         {"00:00", "23:59", "00:00"},
                         {"17:59", "16:04", "14:14"},
                         {"21:55", "19:07", "23:23"},
                         {"05:31", "22:08", "00:35"}}};

    for (size_t i{}; i < testCases.size(); ++i) {
        int x{solution.findMinDifference(testCases[i])};
        cout << "Minimum Time Difference in Example " << i + 1 << " is " << x
             << '\n';
    }
}
