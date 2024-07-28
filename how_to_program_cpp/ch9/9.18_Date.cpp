// Fig. 9.18: 9.18_Date.cpp
// Date class member-function definitions
#include "9.17_Date.h"
#include <array>
#include <iostream>
#include <stdexcept>
using namespace std;

Date::Date(unsigned mn, unsigned dy, unsigned yr) {
    if ((mn > 0) && (mn <= monthsPerYear))
        month = mn;
    else
        throw invalid_argument("month must be 1-12");

    year = yr;
    day = checkDay(dy);

    cout << "Date object constructor for date: ";
    print();
    cout << endl;
}

void Date::print() const { cout << month << '/' << day << '/' << year; }

Date::~Date() {
    cout << "Date object destructor for date ";
    print();
    cout << endl;
}

Date::Date(const Date &s) {
    cout << "Date object copy constructor for date ";
    this->month = s.month;
    this->day = s.day;
    this->year = s.year;
    print();
    cout << endl;
}

unsigned Date::checkDay(unsigned testDay) const {
    static const array<unsigned, monthsPerYear + 1> daysPerMonth = {
        0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((testDay > 0) && (testDay <= daysPerMonth.at(month)))
        return testDay;

    if (month == 2 && testDay == 29 &&
        (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
        return testDay;

    throw invalid_argument("Invalid day for current month and year");
}
