// Fig. 7.23: 7.23_GradeBook.cpp
// Member-function defintions for class GradeBook that
// uses a two-dimensional array to store grades
#include <iomanip>
#include <iostream>
using namespace std;

#include "7.22_GradeBook.h"

GradeBook::GradeBook(const std::string &name, const gradeTable &gradesArray)
    : courseName{name}, grades{gradesArray} {}

void GradeBook::setCourseName(const std::string &name) { courseName = name; }

std::string GradeBook::getCourseName() const { return courseName; }

void GradeBook::displayMessage() const {
    cout << "Welcome to the grade book for\n" << getCourseName() << '!' << endl;
}

void GradeBook::processGrades() const {
    outputGrades();
    cout << "\nLowest grade in the grade book is " << getMinimum()
         << "\nHighest grade in the grade book is " << getMaximum() << endl;
    outputBarChart();
}

int GradeBook::getMinimum() const {
    int lowGrade = 100;
    for (const array<int, tests> &student : grades)
        for (const int grade : student)
            lowGrade = grade < lowGrade ? grade : lowGrade;
    return lowGrade;
}

int GradeBook::getMaximum() const {
    int highGrade = 0;
    for (const array<int, tests> &student : grades)
        for (const int &grade : student)
            highGrade = grade > highGrade ? grade : highGrade;
    return highGrade;
}

double GradeBook::getAverage(const array<int, tests> &setOfGrades) const {
    int total = 0;
    for (const int &grade : setOfGrades)
        total += grade;
    return static_cast<double>(total) / setOfGrades.size();
}

void GradeBook::outputBarChart() const {
    cout << "\nOverall Grade Distribution:" << endl;

    const size_t frequencySize = 11;
    array<unsigned, frequencySize> frequency{};
    for (auto const &student : grades)
        for (auto const &test : student)
            ++frequency[test / 10];

    for (size_t count = 0; count < frequencySize; count++) {
        if (0 == count)
            cout << "  0-9: ";
        else if (10 == count)
            cout << "  100: ";
        else
            cout << count * 10 << '-' << count * 10 + 9 << ": ";
        for (unsigned stars = 0; stars < frequency[count]; stars++)
            cout.put('*');
        cout.put('\n');
    }
}

void GradeBook::outputGrades() const {
    cout << "\nThe Grades are:\n\n";
    cout << setw(12) << ' ';
    for (size_t test(0); test < tests; test++)
        cout << "Test " << test + 1 << "  ";
    cout << "Average" << endl;

    for (size_t student = 0; student < grades.size(); student++) {
        cout << "Student " << setw(2) << student + 1;
        for (size_t test = 0; test < grades[student].size(); test++)
            cout << setw(8) << grades[student][test];
        double average = getAverage(grades[student]);
        cout << setw(9) << setprecision(2) << fixed << average << endl;
    }
}
