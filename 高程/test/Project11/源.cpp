/*
【问题描述】
定义一个基类Shape，在此基础上派生出Rectangle和Circle，二者带有getArea()函数计算对象的面积。
使用Rectangle类创建一个派生类Square()。请自行完善各类的数据成员和成员函数以及主函数测试语句。
*/

#include <iostream>
using namespace std;

class Shape {
public:
    virtual double getArea() = 0;
};

class Rectangle : public Shape {
protected:
    double length;
    double width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double getArea() {
        return length * width;
    }
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double getArea() {
        return 3.14 * radius * radius;
    }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {
    }
};

int main() {
    double length, width, radius;

    cout << "请输入矩形的长和宽：";
    cin >> length >> width;
    Rectangle rect(length, width);

    cout << "请输入圆的半径：";
    cin >> radius;
    Circle circle(radius);

    cout << "请输入正方形的边长：";
    double side;
    cin >> side;
    Square square(side);

    cout << "矩形的面积：" << rect.getArea() << endl;
    cout << "圆的面积：" << circle.getArea() << endl;
    cout << "正方形的面积：" << square.getArea() << endl;

    return 0;
}