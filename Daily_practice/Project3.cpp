#include <iostream>
#include <string>
using namespace std;



int main() {
	extern int b;

	double i = 3.17;
	//引用
	double& I = i;

	//指针
	double* p = &i;

	//p = &I;
	//p = &i;
	
	//解指针
	*p = 0;

	//auto类型
	auto c = b + i;

	//string的新定义方式
	string s(15, 'c');

	//typedef用于替换数据类型
	typedef unsigned long long unLL;
	unLL M_PI = 31415926535;

	
}


