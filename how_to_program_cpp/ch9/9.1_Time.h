// Fig. 9.1: 9.1_Time.h
// Time class definition
// Member functions are defined in 9.2_Time.cpp

// prevent multiple inclusions of header
#ifndef TIME_H
#define TIME_H

// Time class definition
class Time {
  public:
    Time();                      // constructor
    void setTime(int, int, int); // set hour, minute, and second
    void printUniversal() const; // print time in universal-time format
    void printStandard() const;  // print time in standard-time format
  private:
    unsigned hour;
    unsigned minute;
    unsigned second;
};

#endif
