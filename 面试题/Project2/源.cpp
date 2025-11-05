//根据输入来求出位数为n的小写字母的排列种数，相同字母的连续不能超过3个
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

//计算减去的种数,n表示位数
long long function(long long n) {
    long long result = 0;
    if (n <= 3) {
        return 1;
    }
    else {
        for (long long l = 4; l <= n; ++l) {
            long long sum = 26 * (n - l + 1) * function(n - l);
            result += sum;
        }
    }
    return result;
}

int main() {
    //处理输入
    long long n;
    cin >> n;
    cin.ignore();

    long long a;
    cin >> a;
    cin.ignore();

    long long b;
    cin >> b;

    //进行计算
    long long ans1 = 0, ans2 = 0;
    if (a <= 3) {
        ans1 = pow(26, a);
    }
    else {
        ans1 = pow(26, a) - function(a);
    }


    if (b <= 3) {
        ans2 = pow(26, b);
    }
    else {
        ans2 = pow(26, b) - function(b);
    }

    int num = pow(10, 9) + 7;
    ans1 = ans1 % num;
    ans2 = ans2 % num;

    printf("%lld", ans1);
    cout << endl;
    printf("%lld", ans1);

    return 0;
}