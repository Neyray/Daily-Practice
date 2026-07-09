#include <iostream>
#include <vector>
using namespace std;


int main() {
	int n;
	cin >> n;

	vector<vector<int>>matrix(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> matrix[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < n / 2; ++i) {
		for (int j = 0; j < n / 2; ++j) {
			swap(matrix[i][j], matrix[j][i]);
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}