/*
【问题描述】
用含C++定义了一个学生类，包含如下字段:

class Student {
private:
    int id;        // 学号
    int chinese;   // 语文
    int math;      // 数学
    int english;   // 英语
    int physics;   // 物理
    int chemistry; // 化学
    int biology;   // 生物
    int total;     // 总分
public:
    Student (int id, int chinese, int math, int english, int physics,
             int chemistry, int biology);
};

任务要求：
1. 补全Student类的构造函数，牛总分total字段。
2. 编写一个main函数，本题以下功能:
   接收用户从键盘输入的数据,输入学生对象存入STL顺序中。
   根据用户的命令输入一个字符串C行操作:输入学生学号判断该学生位置。
   输入三个学生的排名(不区分名次相同的),则展示该排名学生信息。
   生成一张成绩对比表,按学科合计排名(不区分名次相同)的Student类对比和数据评比。
   并按成绩最高类与Student类的构造数据求平过述。

建议: 使用std::sort进行排序。输出成绩单时决策输出语义建议。
可以使用Student类其他相关方法，可以进行类对象定义及简化代码展现的重用感。

【输入形式】
n个学生的测试用例n+2行输入。第一行，表示学生的数量n，接下+2行n-行，表示排序方式（1表示按学号排序，2表示按总分排序）。
学生信息包含学号 语文 数学 英语 物理 化学 生物，每一项之间以空格分隔，学号至少为1-40 数字，每一项大于0。

【输出形式】
学号、语文、数学、英语、物理、化学、生物、总分

注意:
- 学号后面显示空文或不空: "后面带空文显（spaces键）:
- 分数之后无空（spaces键）
- 总分后面没有分号，保有自然量行符。
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Student {
private:
    int id;
    int chinese;
    int math;
    int english;
    int physics;
    int chemistry;
    int biology;
    int total;

public:
    Student(int id, int chinese, int math, int english, int physics,
        int chemistry, int biology) {
        this->id = id;
        this->chinese = chinese;
        this->math = math;
        this->english = english;
        this->physics = physics;
        this->chemistry = chemistry;
        this->biology = biology;
        this->total = chinese + math + english + physics + chemistry + biology;
    }

    int getId() { return id; }
    int getTotal() { return total; }

    void display() {
        cout << id << ": " << chinese << " " << math << " "
            << english << " " << physics << " " << chemistry << " "
            << biology << " " << total << endl;
    }

    static bool compareById(Student a, Student b) {
        return a.id < b.id;
    }

    static bool compareByTotal(Student a, Student b) {
        return a.total > b.total;
    }
};

int main() {
    int n;
    cin >> n;

    Student* students[100];

    for (int i = 0; i < n; i++) {
        int id, chinese, math, english, physics, chemistry, biology;
        cin >> id >> chinese >> math >> english >> physics >> chemistry >> biology;
        students[i] = new Student(id, chinese, math, english, physics, chemistry, biology);
    }

    int sortType;
    cin >> sortType;

    if (sortType == 1) {
        sort(students, students + n, Student::compareById);
    }
    else {
        sort(students, students + n, Student::compareByTotal);
    }

    for (int i = 0; i < n; i++) {
        students[i]->display();
    }

    return 0;
}