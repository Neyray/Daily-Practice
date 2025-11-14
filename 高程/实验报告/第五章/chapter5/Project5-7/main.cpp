/*、定义一个 Cat 类，拥有静态数据成员 numOfCats ，记录 Cat 的个体
数目；静态成员函数 getNumOfCats ()()，读取 numOfCats 。设计程序测
试这个类，体会静态数据成员和静态成员函数的用法。*/
#include <iostream>
using namespace std;

class Cat {
private:
	static int numOfCats;
public:
	static int getNumOfCats();
	//构造函数
	Cat(int x) {
		numOfCats = x;
	}
};

//定义静态对象
int Cat::numOfCats = 10;

int Cat::getNumOfCats() {
	return numOfCats;
}


int main() {

}