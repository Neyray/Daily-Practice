//哈夫曼编码
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;

    //priority_queue<数据类型, 底层容器, 比较规则>
    //默认是最大，这里是要弹出最小的
	priority_queue<long long, vector<long long>, greater<long long>>q;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		q.push(num);
	}

	long long wpl = 0;
	while (q.size()>1) {
		long long a = q.top(); q.pop();
		long long b = q.top(); q.pop();

		long long sum = a + b;
		wpl += sum;//之所以不需要乘路径长度，是因为同一个数字会被计算多次

		q.push(sum);
	}

	cout << wpl;

	return 0;
}