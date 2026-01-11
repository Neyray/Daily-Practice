/*【问题描述】

给定一个数组，输入一个整数N，计算该数组中最小的N个数的和。

【输入形式】

第一行两个整数M和N，空格隔开，M代表数组中元素的个数，N代表需要计算的元素个数。
【输出形式】

一个整数
【样例输入】

10 2

1 2 3 5 0 5 6 7 8 8
【样例输出】

1
【样例说明】

最小的两个数是1和0,和是1
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int M, N;//M代表数组元素个数，N表示需要计算的元素个数
	cin >> M >> N;

	cin.ignore();

	//将数据存入数组
	vector<int>arr(M, 0);
	for (int i = 0; i < M; ++i) {
		int num;
		cin >> num;
		arr[i] = num;
	}

	//进行排序操作
	sort(arr.begin(), arr.end());

	int sum = 0;
	for (int j = 0; j < N; ++j) {
		sum += arr[j];
	}

	cout << sum;

	return 0;
}