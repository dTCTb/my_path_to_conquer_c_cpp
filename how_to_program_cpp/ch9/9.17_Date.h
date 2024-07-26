// Fig. 9.17: 9.17_Date.h
// Date class definition; Member functions defined in 9.18_Date.cpp
#ifndef DATE_H
#define DATE_H

class Date {
  public:
    static const unsigned monthsPerYear = 12;
    explicit Date(unsigned = 1, unsigned = 1, unsigned = 1900);
    void print() const;
    ~Date();

  private:
    unsigned month;
    unsigned day;
    unsigned year;

    // utility function to check if day is proper for month and year
    unsigned checkDay(unsigned) const;
};

#endif
