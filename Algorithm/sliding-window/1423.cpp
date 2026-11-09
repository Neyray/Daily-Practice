// 可获得的最大点数
#include <iostream>
#include <vector>
using namespace std;

// 逆向思考：当题目要求从两端取元素时，可以尝试将问题转化成求中间连续子数组的最优值
int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();

    int total = 0;
    for (int x : cardPoints) {
        total += x;
    }

    int len = n - k;
    int sum = 0;

    // 初始化第一个窗口
    for (int i = 0; i < len; ++i) {
        sum += cardPoints[i];
    }

    int minSum = sum;

    // 定长滑动窗口，寻找最小窗口和
    for (int i = len; i < n; ++i) {
        sum += cardPoints[i] - cardPoints[i - len];
        minSum = min(minSum, sum);
    }

    return total - minSum;
}