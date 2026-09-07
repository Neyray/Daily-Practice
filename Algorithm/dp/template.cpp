// ============================================================
// Topic : Dynamic Programming
// Dir   : Algorithm/dp/
//
// 动态规划四件套（写之前先在纸上写清楚）：
//   1. 状态定义：dp[i] / dp[i][j] 到底代表什么
//   2. 状态转移：dp 由哪些更小的状态推出来
//   3. 初始化  ：边界状态的值，注意「空」这个状态
//   4. 遍历顺序：保证用到的状态都已经算好
//
// 两条最容易混的分界线：
//   0/1 背包  vs  完全背包   -> 体积维度的遍历方向（倒序 / 正序）
//   求最值    vs  求方案数   -> 转移用 max/min，还是用 +
//
// 滚动数组：dp[i] 只依赖 dp[i-1] 时，二维可以压成一维。
// ============================================================

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

// ------------------------------------------------------------
// 1. 线性 DP：爬楼梯（LeetCode 70）
//    dp[i] = 到第 i 阶的方案数 = dp[i-1] + dp[i-2]
//    Time O(n) / Space O(1)
// ------------------------------------------------------------
int climbStairs(int n) {
    int prev = 1, cur = 1;                    // dp[0] = dp[1] = 1
    for (int i = 2; i <= n; ++i) {
        int next = prev + cur;
        prev = cur;
        cur  = next;
    }
    return cur;
}

// ------------------------------------------------------------
// 2. 线性 DP：打家劫舍（LeetCode 198）
//    dp[i] = 前 i 家能偷到的最大值 = max(不偷第 i 家, 偷第 i 家)
//    Time O(n) / Space O(1)
// ------------------------------------------------------------
int rob(const vector<int>& nums) {
    int notTake = 0, take = 0;                // dp[i-1], dp[i]
    for (int v : nums) {
        int next = max(take, notTake + v);
        notTake = take;
        take    = next;
    }
    return take;
}

// 环形版（LeetCode 213）：首尾不能同时偷 -> 分成两段线性问题取最大
int robCircle(const vector<int>& nums) {
    int n = (int)nums.size();
    if (n == 1) return nums[0];
    auto robRange = [&](int l, int r) {
        int notTake = 0, take = 0;
        for (int i = l; i <= r; ++i) {
            int next = max(take, notTake + nums[i]);
            notTake = take;
            take    = next;
        }
        return take;
    };
    return max(robRange(0, n - 2), robRange(1, n - 1));   // 弃尾 / 弃首
}

// ------------------------------------------------------------
// 3. 0/1 背包：每件物品最多选一次
//    二维：dp[i][j] = 前 i 件物品、容量 j 时的最大价值
//    一维滚动：容量必须【倒序】遍历，
//              否则 dp[j - w] 已被本轮更新过，物品会被重复选
//    Time O(n·W) / Space O(W)
// ------------------------------------------------------------
int knapsack01(const vector<int>& weight, const vector<int>& value, int W) {
    vector<int> dp(W + 1, 0);
    for (size_t i = 0; i < weight.size(); ++i)
        for (int j = W; j >= weight[i]; --j)              // 倒序！
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    return dp[W];
}

// 应用：分割等和子集（LeetCode 416）—— 0/1 背包的「可行性」版本
bool canPartition(const vector<int>& nums) {
    int sum = 0;
    for (int v : nums) sum += v;
    if (sum % 2) return false;
    int target = sum / 2;

    vector<char> dp(target + 1, false);
    dp[0] = true;                                          // 容量 0 恒可达
    for (int v : nums)
        for (int j = target; j >= v; --j)
            dp[j] = dp[j] || dp[j - v];
    return dp[target];
}

// 应用：目标和（LeetCode 494）—— 0/1 背包的「计数」版本
// 设取正号的子集和为 p，则 p - (sum - p) = target => p = (sum + target) / 2
int findTargetSumWays(const vector<int>& nums, int target) {
    int sum = 0;
    for (int v : nums) sum += v;
    if (abs(target) > sum || (sum + target) % 2) return 0;
    int cap = (sum + target) / 2;

    vector<int> dp(cap + 1, 0);
    dp[0] = 1;                                             // 装满容量 0 有 1 种方案（什么都不选）
    for (int v : nums)
        for (int j = cap; j >= v; --j)
            dp[j] += dp[j - v];                            // 计数用 +，不是 max
    return dp[cap];
}

// ------------------------------------------------------------
// 4. 完全背包：每件物品可选无限次 -> 容量【正序】遍历
//    求最值：外层物品、内层容量，两层顺序可换
//    Time O(n·W) / Space O(W)
// ------------------------------------------------------------
// 应用：零钱兑换（LeetCode 322），求最少硬币数
int coinChange(const vector<int>& coins, int amount) {
    const int INF = INT_MAX / 2;                           // 防止 +1 溢出
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;
    for (int c : coins)
        for (int j = c; j <= amount; ++j)                  // 正序！允许重复选同一面额
            dp[j] = min(dp[j], dp[j - c] + 1);
    return dp[amount] >= INF ? -1 : dp[amount];
}

// 应用：零钱兑换 II（LeetCode 518），求「组合数」
// 组合数：外层物品、内层容量（同一组硬币只按一种顺序统计）
// 排列数：外层容量、内层物品（顺序不同算不同方案）—— 顺序不能换！
int coinChangeCombinations(const vector<int>& coins, int amount) {
    vector<unsigned long long> dp(amount + 1, 0);
    dp[0] = 1;
    for (int c : coins)                                    // 物品在外
        for (int j = c; j <= amount; ++j)
            dp[j] += dp[j - c];
    return (int)dp[amount];
}

// ------------------------------------------------------------
// 5. 序列 DP：最长递增子序列（LeetCode 300）
//    dp[i] = 以 nums[i] 结尾的最长上升子序列长度
//    Time O(n^2) / Space O(n)
// ------------------------------------------------------------
int lengthOfLIS(const vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    int best = nums.empty() ? 0 : 1;
    for (size_t i = 1; i < nums.size(); ++i) {
        for (size_t j = 0; j < i; ++j)
            if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
        best = max(best, dp[i]);
    }
    return best;
}

// 贪心 + 二分优化：tails[k] = 长度为 k+1 的上升子序列的最小结尾
// tails 单调递增，用 lower_bound 找第一个 >= num 的位置替换
// Time O(n log n) / Space O(n)。注意 tails 不是真正的 LIS，只有长度有意义
int lengthOfLISFast(const vector<int>& nums) {
    vector<int> tails;
    for (int v : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), v);
        if (it == tails.end()) tails.push_back(v);
        else                   *it = v;
    }
    return (int)tails.size();
}

// ------------------------------------------------------------
// 6. 双序列 DP：最长公共子序列（LeetCode 1143）
//    dp[i][j] = text1 前 i 个字符与 text2 前 j 个字符的 LCS 长度
//    下标错开一位，dp[0][*] / dp[*][0] 代表空串，天然为 0
//    Time O(m·n) / Space O(m·n)
// ------------------------------------------------------------
int longestCommonSubsequence(const string& a, const string& b) {
    int m = (int)a.size(), n = (int)b.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            dp[i][j] = (a[i - 1] == b[j - 1])
                     ? dp[i - 1][j - 1] + 1                // 字符匹配，同时后退一位
                     : max(dp[i - 1][j], dp[i][j - 1]);    // 不匹配，各让一步
    return dp[m][n];
}

// ------------------------------------------------------------
// 7. 字符串 DP：编辑距离（LeetCode 72）
//    dp[i][j] = a 前 i 个变成 b 前 j 个的最少操作数
//    三个来源：删除 dp[i-1][j] / 插入 dp[i][j-1] / 替换 dp[i-1][j-1]
//    Time O(m·n) / Space O(m·n)
// ------------------------------------------------------------
int minDistance(const string& a, const string& b) {
    int m = (int)a.size(), n = (int)b.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; ++i) dp[i][0] = i;             // b 为空：全删
    for (int j = 0; j <= n; ++j) dp[0][j] = j;             // a 为空：全插

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            dp[i][j] = (a[i - 1] == b[j - 1])
                     ? dp[i - 1][j - 1]
                     : 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
    return dp[m][n];
}

// ------------------------------------------------------------
// 8. 划分型 DP：单词拆分（LeetCode 139）
//    dp[i] = 前 i 个字符能否被完整拆分
//    Time O(n^2 · L) / Space O(n)
// ------------------------------------------------------------
bool wordBreak(const string& s, const vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    int n = (int)s.size();
    vector<char> dp(n + 1, false);
    dp[0] = true;                                          // 空串可拆
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < i; ++j)
            if (dp[j] && dict.count(s.substr(j, i - j))) { dp[i] = true; break; }
    return dp[n];
}

// ------------------------------------------------------------
// 9. 状态机 DP：乘积最大子数组（LeetCode 152）
//    负数会让最大变最小，所以必须同时维护 max 和 min
//    Time O(n) / Space O(1)
// ------------------------------------------------------------
int maxProduct(const vector<int>& nums) {
    int best = nums[0], curMax = nums[0], curMin = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        int v = nums[i];
        int prevMax = curMax, prevMin = curMin;
        curMax = max({v, prevMax * v, prevMin * v});
        curMin = min({v, prevMax * v, prevMin * v});
        best   = max(best, curMax);
    }
    return best;
}
