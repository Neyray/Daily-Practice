#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minAmount(vector<int>& missiles) {
	int n = missiles.size();
	if (n == 0)return 0;

	vector<int>dp(n, 1);

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (missiles[i] > missiles[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	return *max_element(dp.begin(), dp.end());
}

int main() {
	vector<int> missiles = { 5, 3, 7, 4, 6, 8, 2, 3 };  // 示例输入
	cout << "最少需要的拦截系统数量是: " << minAmount(missiles) << endl;

	return 0;
}
