#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // 动态分配数组
    int** arr = new int* [n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int[m];
    }

    // 输入数组矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    unsigned long long totalScore = 0;

    for (int round = 0; round < m; round++) {
        unsigned long long roundScore = 0;

        for (int i = 0; i < n; i++) {
            // 选择行首或行尾的较大值
            int chosen_value = max(arr[i][0], arr[i][m - 1]);
            roundScore += chosen_value;

            // 更新行中的元素，移除已选择的元素
            if (arr[i][0] >= arr[i][m - 1]) {
                // 选择行首
                for (int j = 0; j < m - 1; j++) {
                    arr[i][j] = arr[i][j + 1];
                }
                m--;  // 删掉一列
            }
            else {
                // 选择行尾
                m--;  // 删掉一列
            }
        }

        totalScore += roundScore * (1ULL << (round + 1));  // 计算得分
    }

    cout << "结果为：" << totalScore << endl;

    // 释放内存
    for (int i = 0; i < n; ++i) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
