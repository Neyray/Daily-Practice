// 跳跃游戏II
// 贪心算法

// 动态规划关注：到达每个位置的最优解是多少？
// 贪心关注：能否不保存所有位置的最优解，只通过当前局部决策或某种汇总信息，保证得到全局最优解？
#include <iostream>
#include <vector>
using namespace std;

// 贪心算法不是每次在当前位置选择 nums[i] 最大的下一格，而是在当前跳跃次数能够覆盖的整个区间中，寻找下一跳可以覆盖的最远位置。
int jump(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    int end = 0;
    int farthest = 0;

    for (int i = 0; i < n - 1; ++i) {
        farthest = max(farthest, i + nums[i]);

        // 这里表示 在这里的第i处 和 之前一次二者相等的位置之间 需要进行一次跳跃（之前最远到达的点跟目前的点重合了），由于终点是n-1，在n-1一定不需要跳跃，所以遍历到n-2
        if (i == end) {
            ++ans;
            end = farthest;
        }
    }

    return ans;
}