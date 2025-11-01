/*给你一个整数数组 nums 和两个正整数 m 和 k 。

请你返回 nums 中长度为 k 的 几乎唯一 子数组的 最大和 ，如果不存在几乎唯一子数组，请你返回 0 。

如果 nums 的一个子数组有至少 m 个互不相同的元素，我们称它是 几乎唯一 子数组。

子数组指的是一个数组中一段连续 非空 的元素序列。
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

long long maxSum(vector<int>& nums, int m, int k) {
    long long ans = 0, s = 0;
    unordered_map<int, int> cnt;
    for (int i = 0; i < nums.size(); i++) {
        // 1. 进入窗口
        s += nums[i];
        cnt[nums[i]]++;

        int left = i - k + 1;
        if (left < 0) { // 窗口大小不足 k
            continue;
        }

        // 2. 更新答案
        if (cnt.size() >= m) {
            ans = max(ans, s);
        }

        // 3. 离开窗口
        int out = nums[left];
        s -= out;
        if (--cnt[out] == 0) {
            cnt.erase(out);
        }
    }

    return ans;
}
