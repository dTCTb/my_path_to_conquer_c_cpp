// Fig. 9.2: 9.2_Time.cpp
// Time class member-function definitions
#include "9.1_Time.h"
#include <iomanip>
#include <iostream>
#include <stdexcept>

using namespace std;

Time::Time() : hour(0), minute(0), second(0) {}

void Time::setTime(int h, int m, int s) {
    // validate hour, minute and second
    if ((h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60)) {
        hour = h;
        minute = m;
        second = s;
    } else {
        throw invalid_argument("hour, minute and/or second was out of range");
    }
}

// print Time in universal-time format (HH:MM:SS)
void Time::printUniversal() const {
    cout << setfill('0') << setw(2) << hour << ':' << setw(2) << minute << ':'
         << setw(2) << second;
}

// print Time in standard=time format (HH:MM:SS AM or PM)
void Time::printStandard() const {
    cout << (hour == 0 || hour == 12 ? 12 : hour % 12) << ':' << setw(2)
         << minute << ':' << setw(2) << second << ' '
         << (hour >= 12 ? "PM" : "AM");
}
