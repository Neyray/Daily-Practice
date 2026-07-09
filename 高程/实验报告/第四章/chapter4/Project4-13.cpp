#include <iostream>
#include <cmath>
using namespace std;

class Circle {
private:
	double radius;
public:
	//构造函数
	Circle(double r) :radius(r) {
		cout << "Constructing Circle:" << radius << endl;
	}
	//析构函数
	~Circle() {
		cout << "Deconstructing" << endl;
	}
	//计算面积函数
	double getArea()const {
		return 3.14 * radius * radius;
	}
	//输出函数
	void show() const {
		cout << "半径: " << radius << "，面积: " << getArea() << endl;
	}
};

int main() {
	Circle c(5.0);
	c.show();

	return 0;
}