// Fig. 5.9: 5.9_GradeBook.h
// GradeBook class definition that counts letter grades.
// Member functions are defined in 5.10_GradeBook.cpp
#include <string>

class GradeBook {
  public:
    explicit GradeBook(const std::string&);
    void setCourseName(const std::string&);
    std::string getCourseName() const;
    void displayMessage() const;
    void inputGrades(); // input arbitrary number of grades from user
    void displayGradeReport() const; // display report based on user input
  private:
    std::string courseName;
    unsigned aCount; // count
    unsigned bCount; // of
    unsigned cCount; // A
    unsigned dCount; // to
    unsigned eCount; // F
    unsigned fCount; // grades
};
