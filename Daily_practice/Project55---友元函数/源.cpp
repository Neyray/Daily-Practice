/*题目：设计一个矩形类，使用友元函数计算两个矩形的重叠面积。
要求：

创建一个Rectangle类，包含两个私有成员变量width（宽度）和height（高度），分别表示矩形的宽度和高度。
为Rectangle类添加构造函数、访问器（getter）和修改器（setter）函数。
创建一个友元函数overlapArea，该函数接受两个Rectangle对象，并计算它们的重叠面积。如果两个矩形没有重叠，则返回0。
在main函数中，创建两个矩形对象，并通过友元函数计算它们的重叠面积，输出结果。
*/
#include <iostream>
#include <algorithm>
using namespace std;

class Rectangle {
private:
	double x, y;
	double width, height;
public:
	Rectangle(double x_val, double y_val, double w, double h) :
		x(x_val), y(y_val), width(w), height(h) {
	}

	double getX() { return x; }
	double getY() { return y; }
	double getWidth() { return width; }
	double getHeight() { return height; }

	friend double overLapArea(Rectangle& re1, Rectangle& re2);
};

double overLapArea(Rectangle& re1,Rectangle& re2){
	double overLapWidth = max(0.0, min(re1.x + re1.width, re2.x + re2.width) - max(re1.x, re2.x));
	double overLapHeight = max(0.0, min(re1.y + re1.height, re2.y + re2.height) - max(re1.y, re2.y));

	return overLapWidth * overLapHeight;
}

int main() {
	Rectangle r1(1, 1, 3, 4);
	Rectangle r2(2, 2, 5, 6);

	cout << "重叠面积为：" << overLapArea(r1, r2);

	return 0;
}