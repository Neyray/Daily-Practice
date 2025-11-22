#include<iostream>
#include<iomanip>
#include"GradeBook.h"
using namespace std;

// 构造函数
GradeBook::GradeBook(string name, const int gradesArray[][tests])
{
    setCourseName(name);

    // 复制成绩数组
    for (int student = 0; student < students; student++)
    {
        for (int test = 0; test < tests; test++)
        {
            grades[student][test] = gradesArray[student][test];
        }
    }
}

void GradeBook::setCourseName(string name)
{
    courseName = name;
}

string GradeBook::getCourseName()
{
    return courseName;
}

void GradeBook::displayMessage()
{
    cout << "Welcome to the grade book for\n" << getCourseName() << "!" << endl;
}




void GradeBook::processGrades()
{
    outputGrades(); // 输出成绩数组

    // 显示所有测试中的最低分和最高分
    cout << "\nLowest grade in the grade book is " << getMinimum()
        << "\nHighest grade in the grade book is " << getMaximum() << endl;

    outputBarChart(); // 输出成绩分布图
}

int GradeBook::getMinimum()
{
    int lowGrade = 100; // 假设最低分是100

    // 遍历成绩数组的所有元素
    for (int student = 0; student < students; student++)
    {
        for (int test = 0; test < tests; test++)
        {
            if (grades[student][test] < lowGrade)
                lowGrade = grades[student][test];
        }
    }
    return lowGrade;
}

int GradeBook::getMaximum()
{
    int highGrade = 0; // 假设最高分是0

    // 遍历成绩数组的所有元素
    for (int student = 0; student < students; student++)
    {
        for (int test = 0; test < tests; test++)
        {
            if (grades[student][test] > highGrade)
                highGrade = grades[student][test];
        }
    }
    return highGrade;
}


//注意这里的SetOfGrades[]是二维数组，调用的时候使用grades[student]
double GradeBook::getAverage(const int setOfGrades[], const int gradesCount)
{
    int total = 0;

    // 求成绩总和
    for (int grade = 0; grade < gradesCount; grade++)
        total += setOfGrades[grade];//这里的grade表示第几次测试

    // 返回平均分
    return static_cast<double>(total) / gradesCount;
}

void GradeBook::outputBarChart()
{
    cout << "\nOverall grade distribution:" << endl;

    // 存储每10分范围内的成绩频率
    const int frequencySize = 11;
    int frequency[frequencySize] = {}; // 初始化为0

    // 统计每个分数段的频率
    for (int student = 0; student < students; student++)
    {
        for (int test = 0; test < tests; test++)
        {
            ++frequency[grades[student][test] / 10];
        }
    }

    // 输出分布图
    for (int count = 0; count < frequencySize; count++)
    {
        // 输出标签
        if (count == 0)
            cout << "  0-9: ";
        else if (count == 10)
            cout << "  100: ";
        else
            cout << count * 10 << "-" << (count * 10) + 9 << ": ";

        // 输出星号
        for (int stars = 0; stars < frequency[count]; stars++)
            cout << '*';

        cout << endl;
    }
}

void GradeBook::outputGrades()
{
    cout << "\nThe grades are:\n\n";
    cout << "            "; // 对齐列标题

    // 为每个测试创建列标题
    for (int test = 0; test < tests; test++)
        cout << "Test " << test + 1 << "  ";

    cout << "Average" << endl; // 学生平均分列标题

    // 创建表示数组成绩的行/列文本
    for (int student = 0; student < students; student++)
    {
        cout << "Student " << setw(2) << student + 1;

        // 输出学生成绩
        for (int test = 0; test < tests; test++)
            cout << setw(8) << grades[student][test];

        // 调用成员函数计算学生平均分
        double average = getAverage(grades[student], tests);
        cout << setw(9) << setprecision(2) << fixed << average << endl;
    }
}