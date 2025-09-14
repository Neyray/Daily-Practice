//寻找字符串 t 在字符串 s 中的位置
#include <iostream>
#include <string>
using namespace std;

//s的长度大于t
int BF(string s, string t) {
	int i = 0, j = 0;
	while (i < s.length() && j < t.length()) {
		if (s[i] == t[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= t.length())
		return i - t.length();
	else
		return -1;
}