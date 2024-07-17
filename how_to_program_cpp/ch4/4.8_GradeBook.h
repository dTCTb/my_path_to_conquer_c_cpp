// Fig. 4.8: 4.8_GradeBook.h
// Definition of class GradeBook that determines a class average.
// Member functions are defined in 4.9_GradeBook.cpp
#include <string> // program uses C++ standard string class

class GradeBook {
  public:
    explicit GradeBook(std::string);    // initializes course name
    void setCourseName(std::string);    // set the course name
    std::string getCourseName() const;  // retrieve the course name
    void displayMessage() const;        // display a welcome message
    void determineClassAverage() const; // average user-entered grades

  private:
    std::string courseName; // course name for this GradeBook
};
