/*【问题描述】定义Boat与Car两个类，二者都有weight属性，定义二者的一个友元函数getTotalWeight(),计算二者的重量和

【输入形式】用户从键盘输入Boat和Car的重量值，用空格分隔

【输出形式】对每组输入的重量值，使用友元函数getTotalWeight(),计算二者的重量和

【样例输入】66 77

【样例输出】143

【样例说明】66和77分别代表Boat和Car的重量值
*/
#include <iostream>
using namespace std;

class Car;
class Boat;

class Car {
private:
	int weight;
public:
	Car(int n) :weight(n) {}
	friend int getTotalWeight(Boat b1,Car c1);
};

class Boat {
private:
	int weight;
public:
	Boat(int n) :weight(n) {}
	friend int getTotalWeight(Boat b1, Car c1);
};

int getTotalWeight(Boat b, Car c) {
	return b.weight + c.weight;
}

int main() {
	int m, n;
	cin >> m >> n;
	Boat b(m);
	Car c(n);

	cout << getTotalWeight(b, c);

	return 0;
}