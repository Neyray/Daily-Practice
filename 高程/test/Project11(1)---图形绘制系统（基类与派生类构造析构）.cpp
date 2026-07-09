/*【问题描述】
设计一个图形绘制系统，包含基类Shape和两个派生类Circle（圆形）和Rectangle（矩形）。通过这个系统来理解和掌握：

基类和派生类的构造函数调用顺序
显式调用和隐式调用基类构造函数
虚析构函数的作用和重要性
对象创建和销毁的完整过程
*/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Shape {
protected:
    string name;
    string color;
    static int count;

public:
    // 默认构造函数
    Shape() : name("未命名"), color("无色") {
        count++;
        cout << "Shape默认构造: " << name << endl;
    }

    // 带参数构造函数
    Shape(string n, string c) : name(n), color(c) {
        count++;
        cout << "Shape带参构造: " << name << endl;
    }

    // 虚析构函数
    virtual ~Shape() {
        cout << "Shape析构: " << name << endl;
    }

    // 纯虚函数：计算面积
    virtual double getArea() const = 0;

    // 纯虚函数：绘制图形
    virtual void draw() const = 0;

    // 获取图形信息
    void displayInfo() const {
        cout << "名称: " << name << ", 颜色: " << color;
    }

    // 静态函数：获取图形总数
    static int getCount() {
        return count;
    }
};

// 静态成员初始化
int Shape::count = 0;

class Circle : public Shape {
private:
    double radius;

public:
    // 默认构造函数（隐式调用基类默认构造函数）
    Circle() : radius(1.0) {
        cout << "Circle默认构造, 半径: " << radius << endl;
    }

    // 带一个参数的构造函数（隐式调用基类默认构造函数）
    Circle(double r) : radius(r) {
        cout << "Circle带参构造, 半径: " << radius << endl;
    }

    // 带三个参数的构造函数（显式调用基类构造函数）
    Circle(string n, string c, double r) : Shape(n, c), radius(r) {
        cout << "Circle带参构造, 半径: " << radius << endl;
    }

    // 析构函数
    ~Circle() {
        cout << "Circle析构, 半径: " << radius << endl;
    }

    // 实现纯虚函数
    double getArea() const override {
        return 3.14159 * radius * radius;
    }

    void draw() const override {
        cout << "绘制圆形 ○" << endl;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    // 默认构造函数（隐式调用基类默认构造函数）
    Rectangle() : width(1.0), height(1.0) {
        cout << "Rectangle默认构造, " << width << "x" << height << endl;
    }

    // 带两个参数的构造函数（隐式调用基类默认构造函数）
    Rectangle(double w, double h) : width(w), height(h) {
        cout << "Rectangle带参构造, " << width << "x" << height << endl;
    }

    // 带四个参数的构造函数（显式调用基类构造函数）
    Rectangle(string n, string c, double w, double h) : Shape(n, c), width(w), height(h) {
        cout << "Rectangle带参构造, " << width << "x" << height << endl;
    }

    // 析构函数
    ~Rectangle() {
        cout << "Rectangle析构, " << width << "x" << height << endl;
    }

    // 实现纯虚函数
    double getArea() const override {
        return width * height;
    }

    void draw() const override {
        cout << "绘制矩形 □" << endl;
    }
};

int main() {
    cout << "=== 测试1：圆形对象创建 ===" << endl;
    Circle c1;
    Circle c2(5.0);
    Circle c3("圆形1", "红色", 3.5);

    cout << "\n=== 测试2：矩形对象创建 ===" << endl;
    Rectangle r1;
    Rectangle r2(4.0, 6.0);
    Rectangle r3("矩形1", "蓝色", 5.0, 8.0);

    cout << "\n=== 测试3：使用对象 ===" << endl;
    c3.displayInfo();
    cout << ", 面积: " << fixed << setprecision(2) << c3.getArea() << endl;
    c3.draw();

    r3.displayInfo();
    cout << ", 面积: " << r3.getArea() << endl;
    r3.draw();

    cout << "\n=== 测试4：多态性 ===" << endl;
    Shape* shapes[3];
    shapes[0] = new Circle("圆形2", "绿色", 4.0);
    shapes[1] = new Rectangle("矩形2", "黄色", 3.0, 7.0);
    shapes[2] = new Circle("圆形3", "紫色", 2.5);

    for (int i = 0; i < 3; i++) {
        shapes[i]->displayInfo();
        cout << ", 面积: " << shapes[i]->getArea() << endl;
        shapes[i]->draw();
    }

    cout << "\n=== 删除对象 ===" << endl;
    for (int i = 0; i < 3; i++) {
        delete shapes[i];
    }

    cout << "\n=== 静态成员 ===" << endl;
    cout << "图形总数: " << Shape::getCount() << endl;

    cout << "\n=== 程序结束 ===" << endl;
    return 0;
}