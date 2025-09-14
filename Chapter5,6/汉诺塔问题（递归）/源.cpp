#include <iostream>
using namespace std;

void Hanoi(int n, char x, char y, char z) {
	//设置退出条件
	if (n == 1)
		cout << "将第" << n << "个盘片从" << x << "移到" << z << endl;
	else {
		Hanoi(n - 1, x, z, y);
		cout << "将第" << n << "个盘片从" << x << "移到" << z << endl;
		Hanoi(n - 1, y, x, z);
	}
}

int main() {
	int n;
	char x = 'x', y = 'y', z = 'z';

	cin >> n;

	Hanoi(n, x, y, z);

	return 0;
}