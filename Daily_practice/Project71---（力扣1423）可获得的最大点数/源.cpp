/*几张卡牌 排成一行，每张卡牌都有一个对应的点数。点数由整数数组 cardPoints 给出。

每次行动，你可以从行的开头或者末尾拿一张卡牌，最终你必须正好拿 k 张卡牌。

你的点数就是你拿到手中的所有卡牌的点数之和。

给你一个整数数组 cardPoints 和整数 k，请你返回可以获得的最大点数。*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int windowSize = n - k; // 需要维护的窗口大小（剩余未选择的卡片数）
    int totalSum = 0;       // 所有卡片的总和

    // 计算所有卡片的总和
    for (int i = 0; i < n; i++) {
        totalSum += cardPoints[i];
    }

    // 特殊情况：如果k等于n，直接返回总和（选择了所有卡片）
    if (k == n) {
        return totalSum;
    }

    // 计算初始窗口（前windowSize个元素）的和
    int windowSum = 0;
    for (int i = 0; i < windowSize; i++) {
        windowSum += cardPoints[i];
    }

    int minWindowSum = windowSum; // 记录最小窗口和（初始为第一个窗口的和）

    // 使用滑动窗口遍历所有可能的连续windowSize大小的子数组
    // 窗口范围：[i - windowSize, i - 1] → [i - windowSize + 1, i]
    for (int i = windowSize; i < n; i++) {
        // 窗口向右滑动：移除最左侧元素，添加当前元素
        windowSum = windowSum - cardPoints[i - windowSize] + cardPoints[i];

        // 更新最小窗口和
        if (windowSum < minWindowSum) {
            minWindowSum = windowSum;
        }
    }

    // 最大得分 = 总和 - 最小连续子数组和（剩余未选卡片的最小和）
    return totalSum - minWindowSum;
}


int main() {

}