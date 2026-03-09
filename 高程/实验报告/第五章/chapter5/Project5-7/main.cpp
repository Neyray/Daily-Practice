/*、定义一个 Cat 类，拥有静态数据成员 numOfCats ，记录 Cat 的个体
数目；静态成员函数 getNumOfCats ()()，读取 numOfCats 。设计程序测
试这个类，体会静态数据成员和静态成员函数的用法。*/
#include <iostream>
using namespace std;

class Cat {
private:
	static int numOfCats;
public:
	//静态变量
	static int getNumOfCats();

	//构造函数
	Cat(int x) {
		numOfCats = x;
		cout << numOfCats << endl;
	}

	//输出函数
	static void show();
};

//定义静态对象
int Cat::numOfCats = 10;

int Cat::getNumOfCats() {
	return numOfCats;
}

void Cat::show() {
	cout << ++numOfCats << endl;
}

int main() {
	Cat::show();//输出11

	Cat c1(6);//输出6
	Cat c2(7);//输出7

	cout << c1.getNumOfCats() << endl;//输出7
	cout << c2.getNumOfCats() << endl;//输出7

	c1.show();//输出8
	c2.show();//输出9

}