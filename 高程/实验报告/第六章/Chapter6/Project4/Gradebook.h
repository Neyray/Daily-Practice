#pragma once
#include<string>
using namespace std;

class GradeBook
{
public:
    static const int students = 10;

    GradeBook(string, const int[]);
    void setCourseName(string);
    string getCourseName();
    void displayMessage();
    void processGrades();
    int getMinimum();
    int getMaximum();
    double getAverage();
    void outputBarChart();
    void outputGrades();

private:
    string courseName;
    int grades[students];
};