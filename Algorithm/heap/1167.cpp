// LeetCode 1167：连接木棍的最低费用
// 题目链接：https://leetcode.cn/problems/minimum-cost-to-connect-sticks/
// 难度：中等
// 训练主题：堆与优先队列
// 课程源码：../../data-structureA/chapter6/homework3/project2.cpp
// 思考方向：等价于课程计算哈夫曼树的带权路径长度。用小根堆取出最短的两根木棍，累加合并代价，再把合并后的长度放回堆。
// TODO: 独立实现本题，并记录时间复杂度、空间复杂度及关键边界用例。
