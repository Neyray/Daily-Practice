#include <iostream>
#include <vector>
using namespace std;


int main() {
	int n, k, m;
	cin >> n >> k >> m;

	//n个人围成一圈，从第k个人开始从1报数，数到m的人出列


	vector<int> arr1(n, 1);//初始化为1
	vector<int> arr2;//存储出栈序列

	int curr = k - 1;//当前报数的人
	int count = 0;//用来计数


	//每次移动一格
	while (arr2.size() < n) {
		if (arr1[curr] == 1) {
			count++;
			if (count == m) {
				arr1[curr] = 0;
				arr2.push_back(curr + 1);
				count = 0;//再把这个count归零
			}
		}
		curr = (curr + 1) % n;
	}

	//输出出列顺序
	for (int num : arr2) {
		cout << num << " ";
	}

	return 0;
}