//栈的应用——带权重的括号深度计算
#include <iostream>
#include <string>
#include <algorithm> // 为了使用 std::max
using namespace std;

class Stack {
public:
	int top;
	int size;
	char* data;

	Stack(int d) {
		top = -1;
		size = d;
		data = new char[size];
	}

	// 优化：补充析构函数，防止内存泄漏
	~Stack() {
		delete[] data;
	}

	bool push(char e) {
		if (top == size - 1) return false;
		top++;
		data[top] = e;
		return true;
	}

	bool pop(char& e) {
		if (top == -1) return false;
		e = data[top];
		top--;
		return true;
	}

	bool isempty() {
		return top == -1;
	}

	bool gettop(char& e) {
		if (top == -1) return false;
		e = data[top];
		return true;
	}
};

int main() {
	string str;
	cin >> str;
	if (str == "") {
		cout << "0";
		return -1;
	}

	//新建一个栈
	Stack st(1000);

	int result = 0;
	int ans = 0;

	for (char ch : str) {
		if (isalpha(ch)) {
			// 如果是字母直接舍弃
			continue;
		}
		else if (ch == '(' || ch == '[' || ch == '{') {
            //说明之前的嵌套已经结束了，此时需要重置ans的值，同时更新result
			result = max(ans, result);
			ans = 0;
			st.push(ch); // 优化：去掉了未使用的 bool 变量，消除警告
		}
		else if (ch == ')') {
			char e;
			if (!st.gettop(e) || e != '(') {
				cout << "-999";
				return -1;
			}
			else {
				ans += 1;
				char e2;
				st.pop(e2); // 优化：去掉了未使用的 bool 变量，消除警告
			}
		}
		else if (ch == ']') {
			char e;
			if (!st.gettop(e) || e != '[') {
				cout << "-999";
				return -1;
			}
			else {
				ans += 2;
				char e2;
				st.pop(e2); // 优化：去掉了未使用的 bool 变量，消除警告
			}
		}
		else if (ch == '}') {
			char e;
			if (!st.gettop(e) || e != '{') {
				cout << "-999";
				return -1;
			}
			else {
				ans += 3;
				char e2;
				st.pop(e2); // 优化：去掉了未使用的 bool 变量，消除警告
			}
		}

		result = max(ans, result);
	}

	// 关键修复：如果循环结束后栈不为空，说明有多余的左括号未匹配
	if (!st.isempty()) {
		cout << "-999";
		return -1;
	}

	cout << result;
	return 0;
}