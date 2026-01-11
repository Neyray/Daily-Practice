#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// 判断一个数是否为素数
bool isPrime(int num) {
    if (num <= 1) return false;     // 0和1不是素数
    if (num == 2) return true;      // 2是素数
    if (num % 2 == 0) return false; // 排除偶数（除了2）

    // 只需检查到sqrt(num)的奇数因子
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// 计算小于n的素数个数（基础方法）
int countPrimes(int n) {
    if (n <= 2) return 0; // 小于2没有素数

    int count = 1; // 2是素数，从1开始计数

    // 从3开始检查所有奇数
    for (int i = 3; i < n; i += 2) {
        if (isPrime(i)) {
            count++;
        }
    }

    return count;
}

int main() {
    int n;

    cout << "求小于n的素数个数" << endl;
    cout << "请输入正整数 n: ";
    cin >> n;

    if (n < 0) {
        cout << "错误：请输入非负整数！" << endl;
        return 1;
    }

    if (n == 0 || n == 1) {
        cout << "小于 " << n << " 的素数个数: 0" << endl;
        return 0;
    }

    // 计算素数个数
    int primeCount = countPrimes(n);

    // 输出结果
    cout << "\n计算结果：" << endl;
    cout << "小于 " << n << " 的素数个数: " << primeCount << endl;

    // 可选：显示所有找到的素数
    if (n <= 1000) { // 限制显示范围，避免输出过多
        cout << "\n所有素数列表：" << endl;

        int count = 0;
        if (n > 2) {
            cout << "2 ";
            count++;
        }

        for (int i = 3; i < n; i += 2) {
            if (isPrime(i)) {
                cout << i << " ";
                count++;

                // 每行显示10个素数
                if (count % 10 == 0) {
                    cout << endl;
                }
            }
        }

        if (count % 10 != 0) {
            cout << endl;
        }

        cout << "\n总共 " << count << " 个素数" << endl;
    }
    else {
        cout << "\n注意：n > 1000，不显示素数列表（避免输出过多）" << endl;
        cout << "如需查看素数列表，请修改程序中的显示条件" << endl;
    }

    // 一些已知结果的验证
    cout << "\n参考信息：" << endl;
    cout << "10以内的素数个数: 4 (2, 3, 5, 7)" << endl;
    cout << "100以内的素数个数: 25" << endl;
    cout << "1000以内的素数个数: 168" << endl;
    cout << "10000以内的素数个数: 1229" << endl;
    cout << "100000以内的素数个数: 9592" << endl;

    return 0;
}