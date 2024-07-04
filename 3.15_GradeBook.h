// Fig. 3.15: 3.15_GradeBook.h
// GradeBook class definition presents the public interface of
// the class. Member-function definitions appear in 3.16_GradeBook.cpp.
#include <string> // program uses C++ standard string class

// GradeBook class definition
class GradeBook {
  public:
    explicit GradeBook(std::string);   // constructor initialize courseName
    void setCourseName(std::string);   // sets the course name
    std::string getCourseName() const; // gets the course name
    void displayMessage() const;       // displays a welcome message
  private:
    std::string courseName; // course name for this GradeBook
};                          // end class GradeBook
