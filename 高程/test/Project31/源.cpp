/*
【问题描述】
从键盘中读入最多不超过50个学生的学生信息（包括空格隔开的姓名、学号、年龄信息，
以学号从低到高排序）

【输入形式】
每次键盘读入最多不超过50个学生的学生信息：
第一行为学生人数；
后面每一行为空格隔开的学生学号、姓名、年龄，其中学号和年龄都是整数。

【输出形式】
分别以姓名顺序（从低到高）和年龄顺序（从低到高）将学生信息输出，每行输出一位学生的信息，
其中学号占3位，姓名（英文）占6位，年龄占3位，均为右对齐。年龄相同时按姓名从低到高排序。
两种顺序的输出结果用一行空行相隔。
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

class Student {
public:
    int id;
    string name;
    int age;

    Student() : id(0), name(""), age(0) {}
    Student(int i, string n, int a) : id(i), name(n), age(a) {}

    static bool compareByName(const Student& a, const Student& b) {
        if (a.name != b.name) return a.name < b.name;
        return a.id < b.id;
    }

    static bool compareByAge(const Student& a, const Student& b) {
        if (a.age != b.age) return a.age < b.age;
        return a.name < b.name;
    }

    void display() const {
        cout << setw(3) << id << setw(6) << name << setw(3) << age << endl;
    }
};

int main() {
    int n;
    cin >> n;

    Student students[50];
    for (int i = 0; i < n; i++) {
        cin >> students[i].id >> students[i].name >> students[i].age;
    }

    // 按姓名排序
    sort(students, students + n, Student::compareByName);
    for (int i = 0; i < n; i++) {
        students[i].display();
    }

    cout << endl;

    // 按年龄排序
    sort(students, students + n, Student::compareByAge);
    for (int i = 0; i < n; i++) {
        students[i].display();
    }

    return 0;
}