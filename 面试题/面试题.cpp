//根据ASC码值来确定输出次数
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	int n = str.length();
	vector<int>arr(n, 0);//用来寄存每一位的ASC码值

	for (int i = 0; i < n; ++i) {
		char cr = str[i];
		int num = cr;//num中存储的是ASC码值

		if (num >= 100) {
			int a = num / 100;
			num = num - a * 100;
			int b = num / 10;
			int c = num - b * 10;
			arr[i] = a + b + c;
		}
		else {
			int a = num / 10;
			int b = num - a * 10;
			arr[i] = a + b;
		}
	}

	//进行输出
	for (int i = 0; i < n; ++i) {
		int num = arr[i];
		for (int j = 0; j < num; ++j) {
			cout << str[i];
		}
		cout << endl;
	}

	return 0;
}