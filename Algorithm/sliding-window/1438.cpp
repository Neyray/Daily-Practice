// LeetCode 1438：绝对差不超过限制的最长连续子数组
// 题目链接：https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
// 难度：中等
// 训练主题：滑动窗口 / 最大/最小单调队列
// 思考方向：分别维护最大值与最小值的单调队列，二者差超过 limit 时收缩窗口并清理过期下标。
// TODO: 独立实现本题，并记录时间复杂度、空间复杂度及关键边界用例。
