/*【问题描述】

从标准输入中输入两组整数(每行不超过20个整数，每组整数中元素不重复),合并两组整数，去掉在两组整数中都出现的整数，并按从大到小顺序排序输出（即两组整数集"异或"）。

【输入形式】

首先输入第一组整数的个数，然后在下一行输入第一组整数，以一个空格分隔各个整数；然后以同样的方式输入第二组整数。

【输出形式】

按从大到小顺序排序输出合并后的整数集（去掉在两组整数中都出现的整数，以一个空格分隔各个整数）。*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int>arr1, arr2;
	int m, n;

	cin >> m;
	int num;
	for (int k = 0; k < m; ++k) {
		cin >> num;
		arr1.push_back(num);
	}

	cin >> n;
	int data;
	for (int k = 0; k < n; ++k) {
		cin >> data;
		arr2.push_back(data);
	}

	sort(arr1.begin(), arr1.end(), [](int a, int b) {return a > b; });
	sort(arr2.begin(), arr2.end(), [](int a, int b) {return a > b; });
	vector<int>arr;
	int i = 0, j = 0;
	while (i < m && j < n) {
		if (arr1[i] > arr2[j]) {
			arr.push_back(arr1[i]);
			i++;
		}
		else if (arr1[i] < arr2[j]) {
			arr.push_back(arr2[j]);
			j++;
		}
		else {
			arr.push_back(arr1[i]);
			i++;
			j++;
		}
	}

	if (i < m) {
		for (int k = i; k < m; ++k) {
			arr.push_back(arr1[k]);
		}
	}
	if (j < n) {
		for (int k = j; k < n; ++k) {
			arr.push_back(arr2[k]);
		}
	}

	int size = arr.size();
	for (int k = 0; k < size; ++k) {
		cout << arr[k] << " ";
	}

	return 0;
}