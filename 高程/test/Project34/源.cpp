#include <iostream>
using namespace std;

// 函数声明
void computeGCDandLCM(int a, int b, int& gcd, int& lcm);

int main() {
    int num1, num2, gcd, lcm;

    // 输入两个整数
    cout << "请输入两个正整数: ";
    cin >> num1 >> num2;

    // 确保输入为正数
    if (num1 <= 0 || num2 <= 0) {
        cout << "请输入正整数！" << endl;
        return 1;
    }

    // 计算GCD和LCM
    computeGCDandLCM(num1, num2, gcd, lcm);

    // 输出结果
    cout << "最大公约数 (GCD): " << gcd << endl;
    cout << "最小公倍数 (LCM): " << lcm << endl;

    return 0;
}

// 使用欧几里得算法计算最大公约数和最小公倍数
void computeGCDandLCM(int a, int b, int& gcd, int& lcm) {
    int originalA = a;
    int originalB = b;

    // 计算最大公约数（辗转相除法）
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    gcd = a;

    // 计算最小公倍数：LCM = (a * b) / GCD
    // 先进行除法避免溢出
    lcm = (originalA / gcd) * originalB;
}