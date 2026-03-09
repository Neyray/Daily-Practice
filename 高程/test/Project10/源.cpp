/*
【问题描述】
定义一个Circle类，该类包含一个数据成员radius（半径）和一个成员函数getArea()，
用于计算圆的面积。然后，通过构造Circle类的对象，输入圆的半径，并输出其面积。
*/

#include <iostream>
using namespace std;

class Circle {
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

int main() {
    double r;

    cout << "请输入圆的半径：";
    cin >> r;

    Circle c(r);

    cout << "圆的面积为：" << c.getArea() << endl;

    return 0;
}