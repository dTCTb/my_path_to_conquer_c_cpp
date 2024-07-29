// fig. 10.6: 10.6_Date.h
// Date class definition with overloaded increment operators
#ifndef DATE_H
#define DATE_H
#include <array>
#include <iostream>
class Date {
    friend std::ostream &operator<<(std::ostream &, const Date &);

  public:
    Date(int m = 1, int d = 1, int y = 1900);
    void setDate(int, int, int);
    Date &operator++();
    Date operator++(int);
    Date &operator+=(unsigned);
    static bool leapYear(int);
    bool endOfMonth(unsigned) const;

  private:
    unsigned month;
    unsigned day;
    unsigned year;
    static const std::array<unsigned, 13> days;
    void helpIncrement();
};
#endif
