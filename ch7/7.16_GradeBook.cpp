// Fig. 7.16: 7.16_GradeBook.cpp
// GradeBook class member functions manipulating an array of grades.
#include "7.15_GradeBook.h"
#include <iomanip>
#include <iostream>
using namespace std;

GradeBook::GradeBook(const string &name,
                     const array<int, students> &gradesArray)
    : courseName(name), grades(gradesArray) {}

void GradeBook::setCourseName(const string &name) { courseName = name; }

string GradeBook::getCourseName() const { return courseName; }

void GradeBook::displayMessage() const {
    cout << "Welcome to the grade book for\n" << getCourseName() << '!' << endl;
}

void GradeBook::processGrades() const {
    outputGrades();
    cout << setprecision(2) << fixed;
    cout << "\nClass average is " << getAverage() << endl;
    cout << "Lowest grade is " << getMinimum() << "\nHighest grade is "
         << getMaximum() << endl;
    outputBarChart();
}

int GradeBook::getMinimum() const {
    int lowGrade = 100; // assume lowest grade is 100
    for (int grade : grades)
        if (grade < lowGrade)
            lowGrade = grade;
    return lowGrade;
}

int GradeBook::getMaximum() const {
    int highGrade = 0; // assume lowest grade is 100
    for (int grade : grades)
        if (grade > highGrade)
            highGrade = grade;
    return highGrade;
}

double GradeBook::getAverage() const {
    int total = 0;
    for (int grade : grades)
        total += grade;
    return static_cast<double>(total) / grades.size();
}

void GradeBook::outputBarChart() const {
    cout << "\nGrade Distribution:" << endl;
    const size_t frequencySize = 11;
    array<unsigned, frequencySize> frequency{};
    for (int grade : grades)
        ++frequency[grade / 10];

    for (size_t count = 0; count < frequencySize; ++count) {
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

    for (size_t student = 0; student < grades.size(); ++student)
        cout << "Student " << setw(2) << student + 1 << ": " << setw(3)
             << grades[student] << endl;
}
