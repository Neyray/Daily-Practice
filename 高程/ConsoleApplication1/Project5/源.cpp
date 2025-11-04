/*【问题描述】
一个百万富翁碰到一个陌生人，陌生人找他谈了一个换钱的计划。该计划如下:我每天给你10万元，而你第一天给我一元，第二天我仍给你十万，你给我二元，第三天我仍给你十万，你给我四元......你每天给我的钱是前一天的两倍，直到满n(0<=n<=30)天。百万富翁非常高兴，欣然接受了这个契约。
请编写一个程序，计算这n天中，陌生人给了富翁多少钱，富翁给了陌生人多少钱。
【输入形式】
输入天数n(0<=n<=30且为整数)

【输出形式】
分行输出这n天中，陌生人所付出的钱和富翁所付出的钱。*/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	int sum1, sum2;
	sum1 = n * 100000;

	//这是第一次
	int inc = 1;//每一天给的钱
	int curr = 1;//给的钱的总数
	for (int i = 1; i < n; ++i) {
		inc = 2 * inc;
		curr += inc;
	}
	sum2 = curr;
	cout << sum1 << endl;
	cout << sum2 << endl;

	return 0;
}