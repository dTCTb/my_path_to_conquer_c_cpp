// Fig. 3.9: GradeBook.h
// GradeBook class definition in a separate file from main.
#include <iostream>
#include <string>

class GradeBook {
  public:
    explicit GradeBook(std::string name) : courseName(name) {
        // empty body
    }

    void setCourseName(std::string name) { courseName = name; }

    std::string getCourseName() const { return courseName; }

    void displayMessage() const {
        std::cout << "Welcome to the grade book for\n"
                  << getCourseName() << '!' << std::endl;
    }

  private:
    std::string courseName;
};
