#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

// 学生类（基于常见的实验10学生类结构）
class Student {
private:
    string name;    // 姓名
    int id;         // 学号
    int age;        // 年龄
    double score;   // 分数

public:
    // 构造函数
    Student() : id(0), age(0), score(0.0) {}

    Student(string n, int i, int a, double s)
        : name(n), id(i), age(a), score(s) {
    }

    // 输入学生信息
    void input() {
        cout << "请输入学生信息:" << endl;
        cout << "姓名: ";
        cin >> name;
        cout << "学号: ";
        cin >> id;
        cout << "年龄: ";
        cin >> age;
        cout << "分数: ";
        cin >> score;

        // 清除输入缓冲区
        cin.ignore(1000, '\n');
    }

    // 显示学生信息
    void display() const {
        cout << setw(8) << name
            << setw(10) << id
            << setw(6) << age
            << setw(8) << fixed << setprecision(2) << score << endl;
    }

    // 写入二进制文件
    void writeToBinaryFile(ofstream& outFile) const {
        // 写入字符串长度和内容
        size_t nameLength = name.length();
        outFile.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
        outFile.write(name.c_str(), nameLength);

        // 写入其他数据
        outFile.write(reinterpret_cast<const char*>(&id), sizeof(id));
        outFile.write(reinterpret_cast<const char*>(&age), sizeof(age));
        outFile.write(reinterpret_cast<const char*>(&score), sizeof(score));
    }

    // 从二进制文件读取
    void readFromBinaryFile(ifstream& inFile) {
        // 读取字符串长度和内容
        size_t nameLength;
        inFile.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));

        char* buffer = new char[nameLength + 1];
        inFile.read(buffer, nameLength);
        buffer[nameLength] = '\0';
        name = string(buffer);
        delete[] buffer;

        // 读取其他数据
        inFile.read(reinterpret_cast<char*>(&id), sizeof(id));
        inFile.read(reinterpret_cast<char*>(&age), sizeof(age));
        inFile.read(reinterpret_cast<char*>(&score), sizeof(score));
    }

    // 写入文本文件
    void writeToTextFile(ofstream& outFile) const {
        outFile << name << " " << id << " " << age << " "
            << fixed << setprecision(2) << score << endl;
    }

    // 从文本文件读取
    void readFromTextFile(ifstream& inFile) {
        inFile >> name >> id >> age >> score;
    }

    // Getter方法（用于外部访问）
    string getName() const { return name; }
    int getId() const { return id; }
    int getAge() const { return age; }
    double getScore() const { return score; }
};

// 显示学生数组
void displayStudents(const vector<Student>& students, const string& title) {
    cout << "\n" << title << endl;
    cout << "==============================================" << endl;
    cout << setw(8) << "姓名"
        << setw(10) << "学号"
        << setw(6) << "年龄"
        << setw(8) << "分数" << endl;
    cout << "----------------------------------------------" << endl;

    for (const auto& student : students) {
        student.display();
    }

    cout << "==============================================" << endl;
    cout << "学生总数: " << students.size() << endl;
}

// 将学生数组写入二进制文件
void writeStudentsToBinaryFile(const vector<Student>& students, const string& filename) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "错误：无法创建二进制文件 '" << filename << "'" << endl;
        return;
    }

    // 先写入学生数量
    size_t count = students.size();
    outFile.write(reinterpret_cast<const char*>(&count), sizeof(count));

    // 写入每个学生的数据
    for (const auto& student : students) {
        student.writeToBinaryFile(outFile);
    }

    outFile.close();
    cout << "学生数据已保存到二进制文件: " << filename << endl;
}

// 从二进制文件读取学生数组
vector<Student> readStudentsFromBinaryFile(const string& filename) {
    vector<Student> students;
    ifstream inFile(filename, ios::binary);

    if (!inFile) {
        cerr << "错误：无法打开二进制文件 '" << filename << "'" << endl;
        return students;
    }

    // 读取学生数量
    size_t count;
    inFile.read(reinterpret_cast<char*>(&count), sizeof(count));

    // 读取每个学生的数据
    for (size_t i = 0; i < count; i++) {
        Student student;
        student.readFromBinaryFile(inFile);
        students.push_back(student);
    }

    inFile.close();
    cout << "从二进制文件读取了 " << students.size() << " 个学生数据" << endl;
    return students;
}

// 将学生数组写入文本文件
void writeStudentsToTextFile(const vector<Student>& students, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "错误：无法创建文本文件 '" << filename << "'" << endl;
        return;
    }

    // 先写入学生数量
    outFile << students.size() << endl;

    // 写入每个学生的数据
    for (const auto& student : students) {
        student.writeToTextFile(outFile);
    }

    outFile.close();
    cout << "学生数据已保存到文本文件: " << filename << endl;
}

// 从文本文件读取学生数组
vector<Student> readStudentsFromTextFile(const string& filename) {
    vector<Student> students;
    ifstream inFile(filename);

    if (!inFile) {
        cerr << "错误：无法打开文本文件 '" << filename << "'" << endl;
        return students;
    }

    // 读取学生数量
    size_t count;
    inFile >> count;

    // 读取每个学生的数据
    for (size_t i = 0; i < count; i++) {
        Student student;
        student.readFromTextFile(inFile);
        students.push_back(student);
    }

    inFile.close();
    cout << "从文本文件读取了 " << students.size() << " 个学生数据" << endl;
    return students;
}

int main() {
    vector<Student> students;
    int choice;
    string filename;

    do {
        cout << "\n======= 学生信息管理系统 =======" << endl;
        cout << "1. 输入学生数据" << endl;
        cout << "2. 显示学生数据" << endl;
        cout << "3. 保存到二进制文件" << endl;
        cout << "4. 从二进制文件读取" << endl;
        cout << "5. 保存到文本文件" << endl;
        cout << "6. 从文本文件读取" << endl;
        cout << "7. 显示文件中的内容" << endl;
        cout << "0. 退出" << endl;
        cout << "请选择操作: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int n;
            cout << "请输入学生数量: ";
            cin >> n;

            for (int i = 0; i < n; i++) {
                cout << "\n学生 #" << i + 1 << ":" << endl;
                Student student;
                student.input();
                students.push_back(student);
            }
            break;
        }

        case 2:
            displayStudents(students, "当前学生数据");
            break;

        case 3:
            cout << "请输入二进制文件名: ";
            cin >> filename;
            writeStudentsToBinaryFile(students, filename);
            break;

        case 4:
            cout << "请输入二进制文件名: ";
            cin >> filename;
            students = readStudentsFromBinaryFile(filename);
            break;

        case 5:
            cout << "请输入文本文件名: ";
            cin >> filename;
            writeStudentsToTextFile(students, filename);
            break;

        case 6:
            cout << "请输入文本文件名: ";
            cin >> filename;
            students = readStudentsFromTextFile(filename);
            break;

        case 7: {
            cout << "请输入文件名: ";
            cin >> filename;

            ifstream file(filename, ios::binary);
            if (!file) {
                cerr << "错误：无法打开文件" << endl;
                break;
            }

            cout << "\n文件 '" << filename << "' 内容：" << endl;
            cout << "==================================" << endl;

            char ch;
            int byteCount = 0;
            while (file.get(ch)) {
                if (isprint(ch) || ch == '\n' || ch == '\r' || ch == '\t') {
                    cout << ch;
                }
                else {
                    cout << "[" << hex << (int)(unsigned char)ch << dec << "]";
                }
                byteCount++;
            }

            file.close();
            cout << "\n==================================" << endl;
            cout << "文件大小: " << byteCount << " 字节" << endl;
            break;
        }

        case 0:
            cout << "程序结束，再见！" << endl;
            break;

        default:
            cout << "无效选择，请重新输入！" << endl;
        }

    } while (choice != 0);

    return 0;
}