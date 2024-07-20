// Fig. 7.22: 7.22_GradeBook.h
// Definition of class GradeBook that uses a
// two-dimensional array to store test grades.
// Member functions are defined in 7.23_GradeBook.cpp
#include <array>
#include <string>

// GradeBook class definition
class GradeBook {
  public:
    static const size_t students = 10;
    static const size_t tests = 3;
    using gradeTable = std::array<std::array<int, tests>, students>; // my ver.

    GradeBook(const std::string &, const gradeTable &);

    void setCourseName(const std::string &);
    std::string getCourseName() const;
    void displayMessage() const;
    void processGrades() const;
    int getMinimum() const;
    int getMaximum() const;
    double getAverage(const std::array<int, tests> &) const;
    void outputBarChart() const;
    void outputGrades() const;

  private:
    std::string courseName;
    gradeTable grades; // my ver.
    // std::array<std::array<int, tests>, students> grades; // on9 ver. in book
};
// using gradeTable = GradeBook::gradeTable;
