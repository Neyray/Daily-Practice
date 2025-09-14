/*若一个线性表采用顺序表L存储，其中所有元素为整数。

设计一个时间空间两方面尽可能高效的算法，将所有元素划分为三部分，三部分以K1和K2为界。左边部分的元素全部小于K1，右边部分的元素全部大于或等于K2，中间部分的元素介于K1和K2之间（大于或等于K1,且小于K2）。

划分举例：

对于（6，4，20，7，9，2，10，1，3，30），已知K1=5，K2=8，一种划分结果为：（4，3，1，2，6，7，10，9，20，30）。其中，左边=（4,3,1,2）,中间=（6,7），右边=(10,9,20,30)。我们称左边部分最右元素的位置（序号）为左划分序号，右边部分最左元素的位置（序号）为右划分序号。在上例中，左划分序号为3（元素2的序号），右划分序号为6（元素10的序号）。

如果K1<=K2,输出一种划分；否则输出false。
【输入形式】

第一行输入两个数K1和K2。

第二行输入线性表的数据个数N（N<30）。

第三行输入线性表的整数数据。
【输出形式】

如果K1<=K2,输出左划分序号和右划分序号（用空格隔开）；否则输出false。*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int>& nums, int low, int high) {
	int pivot = nums[high];
	int i = low - 1;
	for (int j = low; j < high; ++j) {
		if (nums[j] < pivot) {
			i++;
			swap(nums[i], nums[j]);
		}
	}
	swap(nums[i + 1], nums[high]);
	//返回索引值
	return i + 1;
}

void quickSort(vector<int>& nums, int low, int high) {
	if (low < high) {
		int pi = partition(nums, low, high);
		quickSort(nums, low, pi - 1);
		quickSort(nums, pi + 1, high);
	}
}


int main() {
	int K1, K2;
	cin >> K1 >> K2;

	int N;
	cin >> N;

	vector<int>numbers(N);
	for (int i = 0; i < N; ++i) {
		cin >> numbers[i];
	}

	if (K1 > K2) {
		cerr << "false" << endl;
	}

	quickSort(numbers, 0, numbers.size() - 1);


	int left = -1;
	int right = N;

	//找到左边的索引
	for (int i = 0; i < N; ++i) {
		if (numbers[i] > K1) {
			left = i - 1;
			break;
		}
	}

	//找到右边的索引
	for (int i = 0; i < N; ++i) {
		if (numbers[i] >= K2) {
			right = i;
			break;
		}
	}


	cout << left << " " << right << endl;

	return 0;
}