#pragma once
#include<string>
using namespace std;

class GradeBook
{
public:
    // 常量
    static const int students = 10; // 学生数量
    static const int tests = 3;     // 测试数量

    // 构造函数
    GradeBook(string, const int[][tests]);

    void setCourseName(string);
    string getCourseName();
    void displayMessage();
    void processGrades();
    int getMinimum();
    int getMaximum();
    double getAverage(const int[], const int);
    void outputBarChart();
    void outputGrades();

private:
    string courseName;
    int grades[students][tests]; // 二维数组存储成绩
};