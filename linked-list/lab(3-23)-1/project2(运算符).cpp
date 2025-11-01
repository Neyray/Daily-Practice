#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int procedure(char op);
int evaluate(const string& str);

int evaluate(const string& str) {
	stack<int>operands;
	stack<char>operators;

	//其实是边放入边计算
	for (size_t i = 0; i < str.size(); ++i) {
		char ch = str[i];

		//空格
		if (ch == ' ') {
			continue;
		}
		//数字
		if (isdigit(ch)) {
			int num = 0;
			//内置一个小循环
			while (i < str.size() && isdigit(str[i])) {
				num = num * 10 + int(str[i] - '0');
				i++;
			}
			--i;
			operands.push(num);
		}
		//字母
		else if (isalpha(ch)) {
			operands.push(int(ch));
		}

		//括号优先
		
		//左括号
		else if (ch == '(') {
			operators.push(ch);
		}
		
		//实际上是在计算ch前面的一个符号
		
		//右括号
		else if (ch == ')') {
			//这是个循环！
			while (operators.top() != '(' && !operands.empty()) {
				//弹出运算符
				char op = operators.top();
				operators.pop();
				//数据
				int a = operands.top();
				operands.pop();
				int b = operands.top();
				operands.pop();
				//进行计算，需要分情况讨论
				if (op == '+')operands.push(a + b);
				else if (op == '-')operands.push(b - a);
				else if (op == '*')operands.push(b * a);
				else if (op == '/')operands.push(b / a);
			}

			// 弹出左括号!!!
			if (!operators.empty()) {
				operators.pop(); 
			}
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			while (!operands.empty() && !operators.empty() && operators.top() != '(' && procedure(operators.top()) >= procedure(ch)) {
				//弹出运算符
				char op = operators.top();
				operators.pop();
				//数据
				int a = operands.top();
				operands.pop();
				int b = operands.top();
				operands.pop();
				//进行计算，需要分情况讨论
				if (op == '+')operands.push(a + b);
				else if (op == '-')operands.push(b - a);
				else if (op == '*')operands.push(b * a);
				else if (op == '/')operands.push(b / a);
			}

			//一定不要忘了将运算符放入栈中！！！
			operators.push(ch);
		}
	}

	while (!operators.empty() && !operands.empty()) {
		//弹出运算符
		char op = operators.top();
		operators.pop();
		//数据
		int a = operands.top();
		operands.pop();
		int b = operands.top();
		operands.pop();
		//进行计算，需要分情况讨论
		if (op == '+')operands.push(a + b);
		else if (op == '-')operands.push(b - a);
		else if (op == '*')operands.push(b * a);
		else if (op == '/')operands.push(b / a);
	}
	return operands.top();
}

int procedure(char op) {
	if (op == '*' || op == '/')return 2;
	if (op == '+' || op == '-')return 1;
	return 0;
}

int main() {
	int n;
	cin >> n;

	//忽略换行符
	cin.ignore();

	while (n--) {
		//每次只读两行
		string str1, str2;
		getline(cin, str1);
		getline(cin, str2);

		if (evaluate(str1) == evaluate(str2)) {
			cout << "TRUE" << endl;
		}
		else {
			cout << "FALSE" << endl;
		}
	}

	return 0;
}