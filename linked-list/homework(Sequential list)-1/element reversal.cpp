//要求空间复杂度为O(1),即不受输入数据大小的影响，这里采用临时变量
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int>numbers(N);
	for (int i = 0; i < N; ++i) {
		cin >> numbers[i];
	}

	for (int i = 0; i < N; ++i) {
		cout << numbers[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < N / 2; ++i) {
		int temp = numbers[i];
		numbers[i] = numbers[N - 1 - i];
		numbers[N - 1 - i] = temp;
	}

	for (int i = 0; i < N; ++i) {
		cout << numbers[i] << " ";
	}
	cout << endl;

	return 0;
}