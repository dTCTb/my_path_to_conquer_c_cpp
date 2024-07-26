// Fig. 9.4: 9.4_Time.h
// Time class containing a constructor with default arguments
// Member functions defined in 9.5_Time.cpp

#ifndef TIME_H
#define TIME_H

class Time {
  public:
    explicit Time(int = 0, int = 0, int = 0); // default constructor
    void setTime(int, int, int);
    void setHour(int);
    void setMinute(int);
    void setSecond(int);

    unsigned getHour() const;
    unsigned getMinute() const;
    unsigned getSecond() const;

    void printUniversal() const;
    void printStandard() const;

    // dedicate for 9.16.cpp
    void printStandard9_16();

  private:
    unsigned hour;
    unsigned minute;
    unsigned second;
};

#endif
