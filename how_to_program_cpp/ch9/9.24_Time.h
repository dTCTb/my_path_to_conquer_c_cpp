// Fig. 9.24: 9.24_Time.h
// Cascading member function calls
// Time class definition
// Member-function defined in 9.25_Time.cpp
#ifndef TIME_H
#define TIME_H
class Time {
  public:
    explicit Time(int = 0, int = 0, int = 0);

    // set functions (the Time & return types enable cascading)
    Time &setTime(int, int, int);
    Time &setHour(int);
    Time &setMinute(int);
    Time &setSecond(int);

    // get functions (normally declared const)
    unsigned getHour() const;
    unsigned getMinute() const;
    unsigned getSecond() const;

    // print functions (normally declared const)
    void printUniversal() const;
    void printStandard() const;

  private:
    unsigned hour;
    unsigned minute;
    unsigned second;
};
#endif
