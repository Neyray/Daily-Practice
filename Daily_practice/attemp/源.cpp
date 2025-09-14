#include <iostream>
#include <string>
using namespace std;

int main() {
	//输入一行数字
	string str;
	getline(cin, str);

	//进行遍历
	int n = str.size();
	bool result = false;
	for (int i = 0; i < n / 2; ++i) {
		if (str[i] == str[n - 1 - i]) {
			result = true;
		}
		else {
			result = false;
			break;
		}
	}

	if (result == true)cout << "Y";
	else cout << "N";

	return 0;
}