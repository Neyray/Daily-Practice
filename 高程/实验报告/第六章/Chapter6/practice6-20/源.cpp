#include <iostream>
#include <cmath>
using namespace std;

#define M_PI 3.1415926

class SimpleCircle {
private:
    int* itsRadius;
public:
    // 默认构造函数
    SimpleCircle() {
        itsRadius = new int(2);
    }

    // 带参数构造函数
    SimpleCircle(int a) {
        itsRadius = new int(a);  // 动态分配内存，而不是取局部变量地址
    }

    // 拷贝构造函数
    SimpleCircle(const SimpleCircle& other) {
        itsRadius = new int(*other.itsRadius);  // 深拷贝
    }

    // 赋值运算符重载（正确版本）
    SimpleCircle& operator=(const SimpleCircle& other) {
        if (this != &other) {  // 检查自我赋值
            delete itsRadius;  // 释放原有内存
            itsRadius = new int(*other.itsRadius);  // 深拷贝
        }
        return *this;  // 返回引用
    }

    // 析构函数
    ~SimpleCircle() {
        delete itsRadius;
    }

    // 获取半径
    int getRadius() const {
        return *itsRadius;
    }

    // 计算面积
    double getArea() const {
        return M_PI * pow(*itsRadius, 2);
    }

    // 计算周长
    double getLength() const {
        return 2 * M_PI * (*itsRadius);
    }

    // 修改半径（修正版）
    void changeRadius(int a) {
        *itsRadius = a;  // 修改指针指向的值，而不是改变指针本身
    }
};

int main() {
    int m;
    cin >> m;

    SimpleCircle c1;           // 使用默认构造函数
    SimpleCircle c2(m);        // 使用带参构造函数

    cout << "c1:" << c1.getRadius() << " " << c1.getArea() << " " << c1.getLength() << endl;
    cout << "c2:" << c2.getRadius() << " " << c2.getArea() << " " << c2.getLength() << endl;

    int n;
    cin >> n;
    c2.changeRadius(n);        // 修改半径
    cout << "c2:" << c2.getRadius() << " " << c2.getArea() << " " << c2.getLength() << endl;

    SimpleCircle c3 = c2;      // 使用拷贝构造函数
    cout << "c3:" << c3.getRadius() << " " << c3.getArea() << " " << c3.getLength() << endl;

    return 0;
}