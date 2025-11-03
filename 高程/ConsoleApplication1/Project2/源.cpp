/*【问题描述】

给定一个精度e，用下列Taylor公式计算(1+x)a,|x|<1的近似值。

(1+x)a=1+ax+a(a-1)x2/2!+...+[a(a-1)×...×(a-n+1)]xn/n!+..., |x|<1

其中|x|<1，e为实数，a为实数。编写程序根据用户输入的x(|x|<1)、a和e的值，利用上述Taylor展开式计算(1+x)a的近似值，要求前后两次迭代之差的绝对值小于e，给出相应的最小迭代次数n和最后一次计算的(1+x)a的值。
【输入形式】

从控制台输入小数x(|x|<1且x不等于0)、实数a和实数e(0<e<|x|)，两数中间用空格分隔。

【输出形式】

控制台输出公式结果：输出迭代次数n和最后一次计算的(1+x)a的值（以一个空格分隔，并且输出(1+x)a时要求小数点后保留8位有效数字）。
*/
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	double x, a, e;
	cin >> x >> a >> e;

	double curr = 1.0;
	double prev;
	double inc = 1.0;//每一次的增量
	int n = 0;//迭代次数

	do {
		prev = curr;
		n++;
		inc = inc * x * (a - n + 1) / n;
		curr += inc;
	} while (fabs(curr - prev) >= e);

	cout << n << " " << fixed << setprecision(8) << curr;

	return 0;
}