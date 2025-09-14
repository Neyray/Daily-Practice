/*题目：
编写一个C++程序，定义一个基类 Shape，并从 Shape 类派生出两个类 Circle 和 Rectangle。在基类 Shape 中定义一个纯虚函数 area()，该函数在派生类中实现，分别计算圆形和矩形的面积。

要求：

基类 Shape 中包含一个纯虚函数 area()。
派生类 Circle 和 Rectangle 分别实现函数 area()。
编写一个函数，接受一个 Shape 类型的指针数组，并计算所有形状的总面积。
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

#define M_PI 3.1415926

class Shape {
public:
	virtual double area() const = 0;
	virtual ~Shape() {}     //析构函数

};

class Circle :public Shape {
private:
	int radius;
public:
	//构造函数
	Circle(int r) :radius(r) {}

	double area()const override {
		return M_PI * radius * radius;
	}
};

class Rectangle :public Shape {
private:
	int length;
	int width;

public:
	Rectangle(int l, int w) :length(l), width(w) {}

	  double area()const override {
		  return length * width;
	  }
};

double totalArea(const vector<Shape*>& shapes) {
	double total = 0;
	for (const auto& shape : shapes) {
		total += shape->area();
	}
	return total;
}

int main() {
	vector<Shape*> shapes;

	shapes.push_back(new Circle(2));
	shapes.push_back(new Rectangle(3, 5));

	cout << "total area:" << totalArea(shapes) << endl;

	for (const auto& shape : shapes) {
		delete shape;
	}

	return 0;

}