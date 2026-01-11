#include <iostream>
#include <iomanip>
using namespace std;

const int MAXN = 15;
int a[MAXN][MAXN];

//x是列号，y是行号（开始时）；start是开始的值；n是矩阵大小
void Spiral(int x, int y, int start, int n) {
	//递归退出条件
	if (n <= 0)return;
	if (n == 1) {
		a[x][y] = start;
		return;
	}

	//上一行
	for (int j = x; j < x + n - 1; ++j) {
		a[y][j] = start++;
	}

	//右一列
	for (int j = y; j < y + n - 1; ++j) {
		a[j][x + n - 1] = start++;
	}

	//下一行
	for (int j = x + n - 1; j > x; --j) {
		a[y + n - 1][j] = start++;
	}

	//左一列
	for (int j = y + n - 1; j > y; --j) {
		a[j][x] = start++;
	}
	Spiral(x + 1, y + 1, start, n - 2);
}

int main() {
	int n = 4;
	Spiral(0, 0, 1, n);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << setw(3) << a[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}