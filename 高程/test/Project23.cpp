/*
【问题描述】
一个百万富翁碰到一个陌生人，陌生人找他谈了一个换钱的计划。该计划如下：
我每天给你10万元，而你第一天给我一元，第二天我仍给你十万，你给我二元，
第三天我仍给你十万，你给我四元......你每天给我的钱是前一天的两倍，直到满n(0<=n<=30)天。
百万富翁非常高兴，欣然接受了这个契约。
请编写一个程序，计算这n天中，陌生人给了富翁多少钱，富翁给了陌生人多少钱。

【输入形式】
输入天数n(0<=n<=30且为整数)

【输出形式】
分行输出这n天中，陌生人所付出的钱和富翁所付出的钱。
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long strangerPay = (long long)n * 100000;

    long long richPay = 0;
    long long dailyPay = 1;

    for (int i = 0; i < n; i++) {
        //这个先后顺序很关键！
        richPay += dailyPay;
        dailyPay *= 2;
    }

    cout << strangerPay << endl;
    cout << richPay << endl;

    return 0;
}