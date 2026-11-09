// 大小为 K 且平均值大于等于阈值的子数组数目
#include <iostream>
#include <vector>
using namespace std;

int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int n = arr.size();
    int target = threshold * k;

    int sum = 0;

    // 初始化第一个窗口
    for (int i = 0; i < k; ++i) {
        sum += arr[i];
    }

    int ans = 0;
    if (sum >= target) ans++;

    // 定长滑动窗口
    for (int i = k; i < n; ++i) {
        sum += arr[i] - arr[i - k];

        if (sum >= target) ans++;
    }

    return ans;
}