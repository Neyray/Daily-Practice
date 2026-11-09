// 爱生气的书店老板
#include <iostream>
#include <vector>
using namespace std;

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int n = customers.size();

    int sum = 0;

    // 计算原本就满意的顾客数量
    for (int i = 0; i < n; ++i) {
        if (grumpy[i] == 0) {
            sum += customers[i];
        }
    }

    // 初始化第一个窗口，增加原本不满意的顾客
    for (int i = 0; i < minutes; ++i) {
        if (grumpy[i] == 1) {
            sum += customers[i];
        }
    }

    int ans = sum;

    // 定长滑动窗口
    for (int i = minutes; i < n; ++i) {
        // 右侧进入窗口
        if (grumpy[i] == 1) {
            sum += customers[i];
        }

        // 左侧离开窗口
        if (grumpy[i - minutes] == 1) {
            sum -= customers[i - minutes];
        }

        ans = max(ans, sum);
    }

    return ans;
}