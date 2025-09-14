/*
编写函数，返回一个动态分配的 int 的 vector c 将此 ve c t or 传递给另
一个函数，这个函数读取标准输入，将读入的值保存在 vector 元素中 。 再将 vector
传递给另←个函数，打印读入的值。 记得在恰当的时刻 delete vector
*/

//使用智能指针

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

unique_ptr<vector<int>> allocatorVector() {
	return make_unique<vector<int>>();
}

void readInput(vector<int>& vec) {
	int value;
	cout << "请输入整数（输入-1结束）：" << endl;
	while (cin >> value && value != -1) {
		vec.push_back(value);
	}
}

void printVector(vector<int>& vec) {
	cout << "你输入的整数是：" << endl;
	for (const int& v : vec) {
		cout << v << " ";
	}
	cout << endl;
}

int main() {
	auto vec = allocatorVector();
	readInput(*vec);
	printVector(*vec);
	return 0;
}