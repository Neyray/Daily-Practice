/*有一个书店老板，他的书店开了 n 分钟。每分钟都有一些顾客进入这家商店。给定一个长度为 n 的整数数组 customers ，其中 customers[i] 是在第 i 分钟开始时进入商店的顾客数量，所有这些顾客在第 i 分钟结束后离开。

在某些分钟内，书店老板会生气。 如果书店老板在第 i 分钟生气，那么 grumpy[i] = 1，否则 grumpy[i] = 0。

当书店老板生气时，那一分钟的顾客就会不满意，若老板不生气则顾客是满意的。

书店老板知道一个秘密技巧，能抑制自己的情绪，可以让自己连续 minutes 分钟不生气，但却只能使用一次。

请你返回 这一天营业下来，最多有多少客户能够感到满意 。*/
//这个题值得注意的点是存在窗口外的部分，这一部分需要单独拿出来计算！！！
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
    int n = customers.size();
    int base = 0; // 基础满意顾客数
    int extra = 0; // 当前窗口额外满意顾客数
    int max_extra = 0; // 最大额外满意顾客数

    // 计算基础满意顾客 + 初始化第一个窗口
    for (int i = 0; i < n; ++i) {
        if (grumpy[i] == 0) {
            base += customers[i];
        }
        else if (i < minutes) {
            extra += customers[i]; // 初始窗口内的生气顾客
        }
    }
    max_extra = extra;

    // 滑动窗口 [i-minutes, i-1] -> [i-minutes+1, i]
    for (int i = minutes; i < n; ++i) {
        // 新进入窗口的元素（右边界）
        if (grumpy[i] == 1) {
            extra += customers[i];
        }
        // 离开窗口的元素（左边界）
        if (grumpy[i - minutes] == 1) {
            extra -= customers[i - minutes];
        }

        //在处理最大值（即存在回溯要求的题目时，可直接在循环内部进行处理，如最大值最小值处理）
        max_extra = max(max_extra, extra);
    }

    return base + max_extra;
}