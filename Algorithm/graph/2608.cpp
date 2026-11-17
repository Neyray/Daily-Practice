// LeetCode 2608：图中的最短环
// 题目链接：https://leetcode.cn/problems/shortest-cycle-in-a-graph/
// 难度：困难
// 训练主题：图搜索、拓扑排序与最短路
// 课程源码：../../data-structureA/chapter7/homework2/project2.cpp
// 思考方向：课程用 Floyd 求带权最小环。力扣为无权图，可以从各点做 BFS，记录距离与父节点，避开把同一条无向边的来回经过视为环。
// TODO: 独立实现本题，并记录时间复杂度、空间复杂度及关键边界用例。
