/*【问题描述】

       给定一个包含N（N≤3000）个正整数的序列，每个数不超过5000，对它们两两相加得到N×(N-1)/2个和，求出其中前M大的数（M≤1000）并按从大到小的顺序排列。

【输入形式】

       输入可能包含多组数据，其中每组数据包括两行，第一行两个数N和M，第二行N个数，表示该序列。
【输出形式】

       对于输入的每组数据，输出M个数，表示结果。输出应当按照从大到小的顺序排序。
【样例输入】

      4 4 

      1 2 3 4
【样例输出】

     7 6 5 5
     */
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main() {
    // 打开输入文件
    ifstream fin("in.txt");
    if (!fin.is_open()) {
        cout << "无法打开文件 in.txt" << endl;
        return -1;
    }

    int n, m;

    // 读取多组数据，直到EOF
    while (fin >> n >> m) {
        vector<int> numbers(n);

        // 读取n个数
        for (int i = 0; i < n; i++) {
            fin >> numbers[i];
        }

        // 计算两两相加的结果
        vector<int> sums;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                sums.push_back(numbers[i] + numbers[j]);
            }
        }

        // 按照从大到小排序
        sort(sums.begin(), sums.end(), greater<int>());

        // 输出前m大的数
        for (int i = 0; i < m; i++) {
            if (i > 0) cout << " ";
            cout << sums[i];
        }
        cout << endl;
    }

    // 关闭文件
    fin.close();
    return 0;
}