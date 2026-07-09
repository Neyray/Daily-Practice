/*
��д����������һ����̬����� int �� vector c ���� ve c t or ���ݸ���
һ�����������������ȡ��׼���룬�������ֵ������ vector Ԫ���� �� �ٽ� vector
���ݸ���������������ӡ�����ֵ�� �ǵ���ǡ����ʱ�� delete vector
*/

//ʹ������ָ��

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

unique_ptr<vector<int>> allocatorVector() {
	return make_unique<vector<int>>();
}

void readInput(vector<int>& vec) {
	int value;
	cout << "����������������-1��������" << endl;
	while (cin >> value && value != -1) {
		vec.push_back(value);
	}
}

void printVector(vector<int>& vec) {
	cout << "������������ǣ�" << endl;
	for (const int& v : vec) {
		cout << v << " ";
	}
	cout << endl;
}

int main() {
	auto vec = allocatorVector();
	readInput(*vec);
	printVector(*vec);
	return 0;
}