// 盛最多水的容器
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 11：盛最多水的容器
// 双指针 + 贪心
// 时间复杂度 O(n)，空间复杂度 O(1)

// 贪心策略：每次移动较短的一边

int maxArea(vector<int>& height) {
    int p1 = 0, p2 = height.size() - 1;
    int ans = 0;

    while (p1 < p2) {
        int area = min(height[p1], height[p2]) * (p2 - p1);
        ans = max(ans, area);

        // 贪心：每次移动较短的那一边
        if (height[p1] < height[p2]) {
            p1++;
        } else {
            p2--;
        }
    }

    return ans;
}