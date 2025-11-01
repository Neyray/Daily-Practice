/*
编写函数，返回一个动态分配的 int 的 vector c 将此 ve c t or 传递给另
一个函数，这个函数读取标准输入，将读入的值保存在 vector 元素中 。 再将 vector
传递给另←个函数，打印读入的值。 记得在恰当的时刻 delete vector
*/

#include <iostream>
#include <vector>
using namespace std;

//函数声明
vector<int>* allocatorVector();
void readInput(vector<int>* vec);
void printVector(const vector<int>* vec);

int main() {
	//动态分配一个vector
	vector<int>* vec = allocatorVector();
	//等价于 auto vec = allocatorVector();

	//读取输入
	readInput(vec);

	//打印vector
	printVector(vec);

	//释放动态分配的vector
	delete vec;

	return 0;
}

//动态分配一个vector
vector<int>* allocatorVector() {
	//返回一个新的动态分配的vector
	return new vector<int>();
}

//从标准输入读取值并存储在vector中
void readInput(vector<int>* vec) {
	int value;
	cout << "请输入整数（输入-1结束）" << endl;
	while (cin >> value && value != -1) {
		vec->push_back(value);
	}
}

//打印vector中的值
void printVector(const vector<int>* vec) {
	cout << "您输入的整数是：" << endl;
	for (const int v : *vec) {
		cout << v << " ";
	}
	cout << endl;
}

/*
* 1.引用：vector<int>&vec,vec.push_back(value);
* 2.指针：vecotr<int>*vec,vec->push_back(value);
*/