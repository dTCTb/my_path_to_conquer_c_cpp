// Fig. 9.11: 9.11_Time.cpp
// Time class member-function definitions
#include "9.10_Time.h"
#include <stdexcept>
using namespace std;

Time::Time(int hr, int min, int sec) { setTime(hr, min, sec); }

void Time::setTime(int h, int m, int s) {
    if ((h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60)) {
        hour = h;
        minute = m;
        second = s;
    } else
        throw invalid_argument("hour, minute and/or second was out of range");
}

unsigned Time::getHour() const { return hour; }

// poor practice: returning a reference to a private data member
unsigned &Time::badSetHour(int hh) {
    if (hh >= 0 && hh < 24)
        hour = hh;
    else
        throw invalid_argument("hour must be 0-23");
    return hour; // dangerous reference return
}
