#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    // 读入数据
    ifstream fin("in.txt");

    int n;
    fin >> n;

    vector<long long> x(n);  // 数据范围大，用long long
    for (int i = 0; i < n; i++) {
        fin >> x[i];
    }
    fin.close();

    // 把所有的差值都算出来存起来
    vector<long long> differences;

    // 两层循环算每对数的差值
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // 绝对值差
            long long diff = abs(x[i] - x[j]);
            differences.push_back(diff);
        }
    }

    // 排个序
    sort(differences.begin(), differences.end());

    // 找中位数
    // 题目说偶数个的话要第m/2个最小的
    // 要注意是从1开始数的，不是从0开始
    int m = differences.size();  // 一共C(n,2)个差值

    long long median;
    if (m % 2 == 0) {
        // 偶数个，要第m/2个，对应下标m/2-1
        median = differences[m / 2 - 1];
    }
    else {
        // 奇数个，要中间那个
        median = differences[m / 2];
    }

    // 输出答案
    cout << median << endl;

    return 0;
}