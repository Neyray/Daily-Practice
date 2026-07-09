#include <iostream>
using namespace std;

const int maxSize = 100;

class SqString {
public:
	char* data;
	int length;
};

//从i开始的j个字符
SqString& SubStr(int i, int j) {
	static SqString s;
	if (i < 0 || i >= s.length || j<0 || i + j>s.length)
		return s;
	for (int k = i; k < i + j; ++k) {
		s.data[k - i] = s.data[k];
	}
	s.length = j;
	return s;
}