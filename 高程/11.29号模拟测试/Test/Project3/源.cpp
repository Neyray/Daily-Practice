/*【问题描述】

从键盘输入两个字符串，用字符数组保存字符串，不要使用系统函数。
【输入形式】

输入第一个字符串，换行后输入第二个字符串

【输出形式】

把连接好后的字符串输出到屏幕上

【样例输入】

hello

world


【样例输出】

helloworld
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	//输入处理
	string str1, str2;
	getline(cin, str1);
	//cin.ignore();
	getline(cin, str2);

	string result = str1 + str2;

	cout << result;

	return 0;
}