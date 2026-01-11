/*
【问题描述】
声明一个Employee类，包括name、ID、Salary等属性，以及chang_name()和display()等函数，
输入ID，可以更改该ID对应的姓名

【输入形式】
ID

【输出形式】
名字占用8个字符，ID占用3个字符，Salary占用10个字符
所有属性

【样例输入】
1
Betty

【样例输出】
Betty, 1, $5000
Bob, 2, $5500
Charlie, 3, $6000
David, 4, $6500
Eve, 5, $7000
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int ID;
    int Salary;

public:
    Employee(string n = "", int id = 0, int sal = 0) : name(n), ID(id), Salary(sal) {}

    void change_name(string newName) {
        name = newName;
    }

    void display() {
        cout << name << ", " << ID << ", $" << Salary << endl;
    }

    int getID() {
        return ID;
    }
};

int main() {
    Employee employees[5] = {
        Employee("Betty", 1, 5000),
        Employee("Bob", 2, 5500),
        Employee("Charlie", 3, 6000),
        Employee("David", 4, 6500),
        Employee("Eve", 5, 7000)
    };


    // 方法2：指针数组
    /*
    Employee* empPtrs[5] = {
        new Employee("Betty", 1, 5000),
        new Employee("Bob", 2, 5500),
        new Employee("Charlie", 3, 6000),
        new Employee("David", 4, 6500),
        new Employee("Eve", 5, 7000)
    };
    
    cout << "\n使用指针数组：" << endl;
    for(int i = 0; i < 5; i++) {
        empPtrs[i]->display();
        delete empPtrs[i];
    }
    */
    int id;
    string newName;
    cin >> id >> newName;

    for (int i = 0; i < 5; i++) {
        if (employees[i].getID() == id) {
            employees[i].change_name(newName);
        }
        employees[i].display();
    }

    return 0;
}