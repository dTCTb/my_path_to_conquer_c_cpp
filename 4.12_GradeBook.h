// Fig. 4.12: 4.12_GradeBook.h
// Definition of class GradeBook that determines a class average.
// Member functions are defined in 4.13_GradeBook.cpp
#include <string> // program uses C++ standard string class

class GradeBook {
  private:
    std::string courseName;

  public:
    explicit GradeBook(std::string name);
    void setCourseName(std::string name);
    std::string getCourseName() const;
    void displayMessage() const;
    void determineClassAverage() const;
};
