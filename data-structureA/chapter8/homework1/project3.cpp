#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

//找出差值<=mid的对数
long long countPairs(vector<int>& arr, long long mid) {
	//这个arr是已经从小到大排序好的
	long long n = arr.size();
	long long left = 0;
	long long count = 0;

	for (long long right = 0; right < n; ++right) {
		while (arr[right] - arr[left] > mid) {
			left++;
		}
		count += right - left;
	}

	return count;
}

int main() {
	ifstream in("in.txt");
	//ofstream out("out.txt");

	long long n;
	in >> n;
	vector<int>arr(n, 0);

	for (long long i = 0; i < n; ++i) {
		in >> arr[i];
	}

	//进行从小到大排序
	sort(arr.begin(), arr.end());

	//总差值个数是(n-1)n/2
	//必须要分开计算！！！
	long long target = n * (n - 1) / 2;
	//如果是偶数，+1后结果不变
	//如果是奇数，由于是中位数，例如7，那么应该是4，所以应该+1后/2（！！！这里和从0开始的下标直接/2不同）
	target = (target + 1) / 2;
	long long low = 0, high = arr[n - 1] - arr[0];
	//ans表示差值的中位数
	long long ans = high;

	while (low <= high) {
		//每次循环猜测一个目标值
		long long mid = low + (high - low) / 2;
		if (countPairs(arr, mid) >= target) {
			ans = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	cout << ans;

	return 0;
}