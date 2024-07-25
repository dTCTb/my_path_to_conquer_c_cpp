// Fig. 9.10: 9.10_Time.h
// Time class definition
// Member-function defined in 9.11_Time.cpp

#ifndef TIME_H
#define TIME_H

class Time {
  public:
    explicit Time(int = 0, int = 0, int = 0);
    void setTime(int, int, int);
    unsigned getHour() const;
    unsigned &badSetHour(int); // dangerous reference return
    unsigned *badbad(int);

  private:
    unsigned hour;
    unsigned minute;
    unsigned second;
};

#endif
