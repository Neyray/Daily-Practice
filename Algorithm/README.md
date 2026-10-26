# Algorithm · 200 题

按题号去重共 **200 题**，分为 **18 个主题**。同题的跨主题练习与多种实现保留，不重复计数。

当前 **45 题已有代码，155 题待练**。“已有代码”仅表示文件中存在实现，不代表已通过评测；完成后同步更新对应题单。

## 题单导航

| 专题 | 题数 | 已有代码 | 待练 |
|---|---:|---:|---:|
| [数组与哈希](array-hash/README.md) | 6 | 0 | 6 |
| [双指针](two-pointers/README.md) | 4 | 0 | 4 |
| [滑动窗口](sliding-window/README.md) | 8 | 0 | 8 |
| [前缀和与差分](prefix-sum/README.md) | 6 | 0 | 6 |
| [二分查找与二分答案](binary-search/README.md) | 11 | 5 | 6 |
| [递归与分治](divide-conquer/README.md) | 5 | 4 | 1 |
| [排序与选择](sorting/README.md) | 5 | 0 | 5 |
| [链表](linked-list/README.md) | 11 | 0 | 11 |
| [栈、队列与单调栈](stack-queue/README.md) | 10 | 0 | 10 |
| [堆与优先队列](heap/README.md) | 5 | 0 | 5 |
| [位运算与位集合](bit-manipulation/README.md) | 14 | 0 | 14 |
| [二叉树与二叉搜索树](tree/README.md) | 22 | 0 | 22 |
| [图搜索、拓扑排序与最短路](graph/README.md) | 20 | 0 | 20 |
| [并查集与最小生成树](dsu-mst/README.md) | 8 | 0 | 8 |
| [字符串、KMP 与 Trie](string-trie/README.md) | 8 | 0 | 8 |
| [动态规划](dp/README.md) | 32 | 18 | 14 |
| [贪心与区间](greedy/README.md) | 15 | 9 | 6 |
| [回溯与剪枝](backtracking/README.md) | 14 | 10 | 4 |

表内按专题计数，45、78、416、1143 跨专题出现。

## 学习顺序

1. 位运算：191 → 231 → 136 → 338，再练位掩码与位集合；1143 位并行留到最后。
2. 双指针、滑动窗口、前缀和 → 排序、栈与队列、堆。
3. 二叉树递归与遍历 → 图 DFS / BFS → 拓扑排序 → 最短路。
4. 并查集 → Kruskal / Prim，再补字符串、二分答案和 DP 等专题。

课堂进度优先；每题复盘问题模型、算法依据、复杂度与边界情况。

## 笔记与目录

- [算法知识笔记](docs/algorithm-notes.md) · [位运算专题](docs/bit-manipulation.md)
- [数据结构代码与索引](../data-structureA/README.md) · [历史日常练习](../Daily_practice/)
- `search/` → `binary-search/`；`sort-structure/` → `sorting/`。
- 原 `graph/` 中的 94、102、104、236 移至 `tree/`；239 移至 `sliding-window/`，347 移至 `heap/`。

题目名称、难度与链接核对自[力扣官方题库](https://leetcode.cn/problemset/)；扩充参考粘贴建议，并兼顾[官方 150 题学习计划](https://leetcode.com/studyplan/top-interview-150/)。
