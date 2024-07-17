// Fig. 7.15: 7.15_GradeBook.h
// Definition of class GradeBook that uses an array to store test grades.
// Member functions are defined in 7.16_GradeBook.cpp
#include <array>
#include <string>

// GradeBook Class Definition
class GradeBook {
  public:
    // constant -- number of students who took the test
    static const size_t students = 10; // note public data

    // constructor initializes course name and array of grades
    explicit GradeBook(const std::string &, const std::array<int, students> &);

    void setCourseName(const std::string &); // set the course name
    std::string getCourseName() const;       // retrieve the course name
    void displayMessage() const;             // display a welcome message
    void processGrades() const;  // perform operations on the grade data
    int getMinimum() const;      // find the minimum grade for the test
    int getMaximum() const;      // find the maximum grade for the test
    double getAverage() const;   // determine the average grade for the test
    void outputBarChart() const; // output bar chart of grade distribution
    void outputGrades() const;   // output the contents of the grades array

  private:
    std::string courseName;           // course name for this grade book
    std::array<int, students> grades; // array of student grades
};
