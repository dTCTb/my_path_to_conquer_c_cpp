// Fig. 9.5: 9.5_Time.cpp
// Member-function definitions for class Time
#include "9.4_Time.h"
#include <iomanip>
#include <iostream>
#include <stdexcept>
using namespace std;

// Time constructor initializes each data member
Time::Time(int hour, int minute, int second) { setTime(hour, minute, second); }

// set new Time value using universal time
void Time::setTime(int h, int m, int s) {
    setHour(h);   // set private field hour
    setMinute(m); //                   minute
    setSecond(s); //                   second
}

void Time::setHour(int h) {
    if (h >= 0 && h < 24)
        hour = h;
    else
        throw invalid_argument("hour must be 0-23");
}

void Time::setMinute(int m) {
    if (m >= 0 && m < 60)
        minute = m;
    else
        throw invalid_argument("minute must be 0-59");
}

void Time::setSecond(int s) {
    if (s >= 0 && s < 60)
        second = s;
    else
        throw invalid_argument("second must be 0-59");
}

unsigned Time::getHour() const { return hour; }

unsigned Time::getMinute() const { return minute; }

unsigned Time::getSecond() const { return second; }

void Time::printUniversal() const {
    cout << setfill('0') << setw(2) << getHour() << ':' << setw(2)
         << getMinute() << ':' << getSecond();
}

void Time::printStandard() const {
    cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ':'
         << setfill('0') << setw(2) << getMinute() << ':' << setw(2)
         << getSecond() << (hour < 12 ? " AM" : " PM");
}
