// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdio.h>
using namespace std;

class Calculator {
public:
	double Calculate(double x, char oper, double y);
};
double Calculator::Calculate(double x, char oper, double y) {
	switch (oper) {
	case '+': return x + y;
	case '-': return x - y;
	case '*': return x * y;
	case '/': return x / y;
	default: return 0.0;
	}
}

int main()
{
	double x = 0.0; double y = 0.0;
	double result = 0.0; char oper = '+';
	cout << "算术运算示例程序" << endl << endl;
	Calculator c;
	while (oper != '$') {
		cout << "请输入运算式，格式如： a + b | a - b | a*b | a / b" << endl; cin >> x >> oper >> y;
		if (oper == '/' && y == 0) {
			cout << "Division by 0 exception" << endl;
			continue;
		}
		else {
			result = c.Calculate(x, oper, y);
		}
		cout << "Result is: " << result << endl;
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
