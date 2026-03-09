//把字符串的重复字符只留下一个，并在第一个出现的后面加上出现次数
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

vector<string>changedSubstring(const string& s) {
	vector<string>str;
	map<char, int>charCount;

	int n = s.size();
	if (n == 1) {
		str.push_back(s);
	}

	//统计每个字符的出现次数
	for (char c : s) {
		++charCount[c];
	}

	//在一个新的vector空间中写入该数据
	for (const auto& pair : charCount) {
		str.push_back(string(1, pair.first));
		str.push_back(to_string(pair.second));
	}
	return str;
}

void printSubstring(const vector<string>& str) {
	int n = str.size();
	if (n == 0)return;

	for (size_t i = 0; i < n; ++i) {
		cout << str[i];
	}
}

int main() {
	string s;
	cout << "请输入字符串：";
	cin >> s;

	vector<string>substring = changedSubstring(s);
	printSubstring(substring);

	return 0;
}