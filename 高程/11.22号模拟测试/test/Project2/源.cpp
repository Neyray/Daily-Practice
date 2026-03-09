/*【问题描述】

编写递归函数getPower计算x^y，在同一个程序中针对整型和实型实现两个重载函数：

int getPower(int x, int y); // 整型版本，当y < 0时，返回0

double getPower(double x, int y); // 实型版本，当y < 0时，返回非0实数

在主程序中实现输入输出，分别输入一个整数a和一个实数b作为底数，再输入一个整数m作为指数，输出a^m和b^m。


【输入形式】

一个整数a，作为底数。

一个实数b，作为底数。

一个整数m，作为指数。


【输出形式】

输出a的m次幂的整型结果。

输出b的m次幂的实型结果。


【样例输入】

2

1.5

3

【样例输出】

8

3.375

【样例说明】

表示计算2^3和1.5^3，整型结果为8，实型结果为3.375
*/
#include <iostream>
#include <cmath>
using namespace std;

int getPower(int, int);
double getPower(double, int);

int getPower(int x, int y) {
    if (y < 0) return 0;  
    else if (y == 0) return 1;//处理递归的正常终止条件
    else {
        return x * getPower(x, y - 1);
    }
}

double getPower(double x, int y) {
    if (y == 0) return 1;
    else if (y < 0) {
        
        return 1.0 / getPower(x, -y);
    }
    else {
        return x * getPower(x, y - 1);
    }
}

int main() {
    int a;
    double b;
    int m;

    cin >> a >> b >> m;

    // 直接调用函数，让函数内部处理边界条件
    cout << getPower(a, m) << endl;
    cout << getPower(b, m) << endl;

    return 0;
}