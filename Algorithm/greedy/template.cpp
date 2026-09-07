// ============================================================
// Topic : Greedy / Interval
// Dir   : Algorithm/greedy/
//
// 贪心的核心不是「怎么写」，而是「凭什么对」：
//   1. 找到一个局部最优的选择策略
//   2. 论证「做了这个选择后，剩下的仍是同类子问题」
//   3. 论证「不会因为这次选择错过更优解」（交换论证）
//
// 区间题的固定套路：先排序，再一趟扫描
//   - 求「最多不重叠区间 / 最少删除」 -> 按右端点升序
//   - 求「合并区间 / 覆盖区间」       -> 按左端点升序
//
// 贪心不成立时，退回动态规划。
// ============================================================

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// ------------------------------------------------------------
// 1. 分发饼干（LeetCode 455）
//    双指针 + 排序：用刚好够用的饼干喂胃口最小的孩子
//    Time O(n log n) / Space O(1)
// ------------------------------------------------------------
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int child = 0, cookie = 0;
    while (child < (int)g.size() && cookie < (int)s.size()) {
        if (s[cookie] >= g[child]) ++child;   // 喂饱一个
        ++cookie;                             // 喂不饱就换更大的饼干
    }
    return child;
}

// ------------------------------------------------------------
// 2. 柠檬水找零（LeetCode 860）
//    找 15 时优先用「10 + 5」，把 5 元留给只能用 5 元的场合
//    Time O(n) / Space O(1)
// ------------------------------------------------------------
bool lemonadeChange(const vector<int>& bills) {
    int five = 0, ten = 0;
    for (int b : bills) {
        if (b == 5) ++five;
        else if (b == 10) { if (five == 0) return false; --five; ++ten; }
        else {                                        // 20 元
            if (ten > 0 && five > 0) { --ten; --five; }   // 优先消耗 10
            else if (five >= 3)      { five -= 3; }
            else return false;
        }
    }
    return true;
}

// ------------------------------------------------------------
// 3. 跳跃游戏（LeetCode 55）：维护能到达的最远下标
//    Time O(n) / Space O(1)
// ------------------------------------------------------------
bool canJump(const vector<int>& nums) {
    int farthest = 0;
    for (int i = 0; i < (int)nums.size(); ++i) {
        if (i > farthest) return false;                // 当前位置已不可达
        farthest = max(farthest, i + nums[i]);
    }
    return true;
}

// ------------------------------------------------------------
// 4. 跳跃游戏 II（LeetCode 45）：BFS 分层思想
//    end 是本层能到的边界，走到边界就必须多跳一步
//    Time O(n) / Space O(1)
// ------------------------------------------------------------
int jump(const vector<int>& nums) {
    int steps = 0, end = 0, farthest = 0;
    for (int i = 0; i + 1 < (int)nums.size(); ++i) {   // 不看最后一个，避免多算一步
        farthest = max(farthest, i + nums[i]);
        if (i == end) { ++steps; end = farthest; }     // 本层扫完，进入下一层
    }
    return steps;
}

// ------------------------------------------------------------
// 5. 无重叠区间（LeetCode 435）：按右端点升序
//    右端点越小，留给后面的空间越大
//    Time O(n log n) / Space O(1)
// ------------------------------------------------------------
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;
    sort(intervals.begin(), intervals.end(),
         [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });

    int keep = 1, prevEnd = intervals[0][1];
    for (size_t i = 1; i < intervals.size(); ++i)
        if (intervals[i][0] >= prevEnd) {   // 不重叠（端点相接不算重叠）
            ++keep;
            prevEnd = intervals[i][1];
        }
    return (int)intervals.size() - keep;
}

// ------------------------------------------------------------
// 6. 引爆气球（LeetCode 452）：本质是「最多有几组互不重叠的区间」
//    坐标可能到 INT 边界，比较用 a[1] < b[1] 而不是相减
//    Time O(n log n) / Space O(1)
// ------------------------------------------------------------
int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) return 0;
    sort(points.begin(), points.end(),
         [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });

    int arrows = 1, pos = points[0][1];
    for (size_t i = 1; i < points.size(); ++i)
        if (points[i][0] > pos) {           // 与上一箭错开，需要新的一箭
            ++arrows;
            pos = points[i][1];
        }
    return arrows;
}

// ------------------------------------------------------------
// 7. 合并区间（LeetCode 56）：按左端点升序
//    Time O(n log n) / Space O(n)
// ------------------------------------------------------------
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> res{intervals[0]};
    for (size_t i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] <= res.back()[1])                       // 有交叠 -> 扩右端
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        else
            res.push_back(intervals[i]);
    }
    return res;
}

// ------------------------------------------------------------
// 8. 划分字母区间（LeetCode 763）
//    先记录每个字母最后出现的位置，扫描时把当前段的右边界不断外推
//    Time O(n) / Space O(1)（字符集固定）
// ------------------------------------------------------------
vector<int> partitionLabels(const string& s) {
    int last[26] = {0};
    for (int i = 0; i < (int)s.size(); ++i) last[s[i] - 'a'] = i;

    vector<int> res;
    int start = 0, end = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        end = max(end, last[s[i] - 'a']);
        if (i == end) { res.push_back(end - start + 1); start = i + 1; }
    }
    return res;
}

// ------------------------------------------------------------
// 9. 加油站（LeetCode 134）
//    总和 < 0 必无解；若从 start 出发在 i 处断油，
//    则 [start, i] 中任何一点出发都走不到 i+1，起点直接跳到 i+1
//    Time O(n) / Space O(1)
// ------------------------------------------------------------
int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
    int total = 0, tank = 0, start = 0;
    for (int i = 0; i < (int)gas.size(); ++i) {
        int diff = gas[i] - cost[i];
        total += diff;
        tank  += diff;
        if (tank < 0) { start = i + 1; tank = 0; }
    }
    return total >= 0 ? start : -1;
}
