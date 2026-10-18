// 跳跃游戏II
// 贪心策略
#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return true;

    int farthest = 0;

    for (int i = 0; i < n - 1; ++i) {
        // 不是最后一个位置之前的所有位置都可达
        if (i > farthest) return false;

        farthest = max(farthest, i + nums[i]);

        if (farthest >= n - 1) return true;
    }

    return false;
}