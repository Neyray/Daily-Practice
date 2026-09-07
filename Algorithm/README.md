# Algorithm Practice

本目录用于《算法设计与分析》课程配套的算法训练与 LeetCode 练习。

当前计划共：

- 8 个算法主题模块
- 15 周，每周 4 题
- 共 60 道 LeetCode
- 重点不是刷题数量，而是形成可以独立实现的算法模板

每个模块目录下的 `template.cpp` 已经写好可直接编译的参考实现，
题号命名的 `.cpp` 留空，由自己动手完成。

目录按照「主要训练的算法模板」进行分类，而不是按照 LeetCode 的全部标签进行分类。

---

# Directory Structure

```text
Algorithm/
├── README.md
│
├── search/                 # 二分查找
│   ├── template.cpp
│   ├── 704.cpp  35.cpp  69.cpp  34.cpp  33.cpp
│
├── divide-conquer/         # 递归与分治
│   ├── template.cpp
│   ├── 50.cpp  53.cpp  169.cpp  108.cpp
│
├── sort-structure/         # 排序 / 选择 / 堆 / 单调队列
│   ├── template.cpp
│   ├── 912.cpp  215.cpp  75.cpp  347.cpp  239.cpp
│
├── greedy/                 # 贪心与区间
│   ├── template.cpp
│   ├── 455.cpp  860.cpp  55.cpp  45.cpp  435.cpp
│   ├── 452.cpp  763.cpp  134.cpp  56.cpp
│
├── dp/                     # 动态规划
│   ├── template.cpp
│   ├── 70.cpp  746.cpp  198.cpp  213.cpp  416.cpp
│   ├── 494.cpp  322.cpp  518.cpp  300.cpp  1143.cpp
│   ├── 72.cpp  139.cpp  152.cpp
│
├── backtracking/           # 回溯
│   ├── template.cpp
│   ├── 46.cpp  78.cpp  77.cpp  39.cpp  40.cpp
│   ├── 79.cpp  131.cpp  51.cpp
│
├── graph/                  # 树 / 图 / 拓扑排序 / 最短路
│   ├── template.cpp
│   ├── 94.cpp  102.cpp  104.cpp  236.cpp
│   ├── 200.cpp  994.cpp  207.cpp  210.cpp
│   ├── 743.cpp  787.cpp  1334.cpp  1631.cpp
│
└── dsu-mst/                # 并查集 / 最小生成树
    ├── template.cpp
    ├── 684.cpp  547.cpp  1584.cpp  721.cpp
```

---

# 1. Search

目录：

```text
Algorithm/search/
```

主要训练：

- Binary Search
- 二分边界
- 有序数组搜索
- 二分答案思想

| LeetCode | 题目 | 主要训练内容 |
|---|---|---|
| 704 | 二分查找 | Binary Search |
| 35 | 搜索插入位置 | Binary Search |
| 69 | x 的平方根 | Binary Search |
| 34 | 在排序数组中查找元素的第一个和最后一个位置 | Boundary Binary Search |
| 33 | 搜索旋转排序数组 | Binary Search |

重点掌握：

- `left`
- `right`
- `mid`
- 闭区间 `[left, right]`
- 半开区间 `[left, right)`
- 左边界 / 右边界
- 边界收缩

模板文件：

```text
search/template.cpp
```

模板内容：

| 函数 | 说明 |
|---|---|
| `binarySearch` | 闭区间二分，找精确值 |
| `lowerBound` | 第一个 `>= target` 的下标 |
| `upperBound` | 第一个 `> target` 的下标 |
| `searchRange` | 由左右边界组合出元素起止区间 |
| `binarySearchAnswer` | 二分答案（在单调 `check` 上二分）|
| `mySqrt` | 求最大可行值时 `mid` 上取整，防死循环 |
| `searchRotated` | 旋转有序数组，先判断哪半边有序 |

---

# 2. Divide and Conquer

目录：

```text
Algorithm/divide-conquer/
```

主要训练：

- Recursion
- Divide and Conquer
- 子问题拆分
- 子问题合并

| LeetCode | 题目 | 主要训练内容 |
|---|---|---|
| 50 | Pow(x, n) | Divide and Conquer |
| 53 | 最大子数组和 | Divide and Conquer |
| 169 | 多数元素 | Divide and Conquer |
| 108 | 将有序数组转换为二叉搜索树 | Recursion / Divide and Conquer |

重点掌握：

1. 递归函数的定义
2. Base Case
3. 如何拆分问题
4. 子问题是什么
5. 如何合并子问题答案

模板文件：

```text
divide-conquer/template.cpp
```

模板内容：

| 函数 | 说明 |
|---|---|
| `myPow` / `powRecursive` | 快速幂，迭代与递归两种写法 |
| `maxSubArrayDC` | 分治求最大子数组和，含跨中点情况 |
| `maxSubArrayKadane` | 对照的 O(n) 线性解法 |
| `majorityElementDC` | 分治求众数 |
| `majorityElementVote` | 对照的 Boyer-Moore 投票法 |
| `buildBST` | 有序数组建平衡 BST |

---

# 3. Sort / Structure

目录：

```text
Algorithm/sort-structure/
```

主要训练：

- Merge Sort
- Quick Sort
- Quick Select
- Heap
- Bucket
- Partition
- Monotonic Queue

| LeetCode | 题目 | 主要训练内容 |
|---|---|---|
| 912 | 排序数组 | Merge Sort / Quick Sort |
| 215 | 数组中的第 K 个最大元素 | Quick Select / Heap |
| 75 | 颜色分类 | Partition |
| 347 | 前 K 个高频元素 | Heap / Bucket |
| 239 | 滑动窗口最大值 | Monotonic Queue |

重点掌握：

- 归并排序
- 快速排序
- 快速选择
- 堆
- Top-K
- Partition
- 单调队列

模板文件：

```text
sort-structure/template.cpp
```

模板内容：

| 函数 | 说明 |
|---|---|
| `mergeSort` | 归并排序，稳定，`tmp` 数组提到递归外 |
| `quickSort` | 随机 pivot + 三路切分 |
| `quickSelect` | 迭代式快速选择，期望 O(n) |
| `kthLargestByHeap` | 大小为 k 的小顶堆求第 k 大 |
| `siftDown` / `heapSort` | 手写下沉与堆排序 |
| `topKFrequent` | 桶排序求 Top-K 频次 |
| `sortColors` | 荷兰国旗三路 Partition |
| `maxSlidingWindow` | 单调队列（存下标）|

---

# 4. Greedy

目录：

```text
Algorithm/greedy/
```

主要训练：

- Greedy
- Interval Greedy
- 区间排序
- 区间覆盖
- 局部最优

| LeetCode | 题目 | 主要训练内容 |
|---|---|---|
| 455 | 分发饼干 | Greedy |
| 860 | 柠檬水找零 | Greedy |
| 55 | 跳跃游戏 | Greedy |
| 45 | 跳跃游戏 II | Greedy |
| 435 | 无重叠区间 | Interval Greedy |
| 452 | 用最少数量的箭引爆气球 | Interval Greedy |
| 763 | 划分字母区间 | Greedy |
| 134 | 加油站 | Greedy |
| 56 | 合并区间 | Sort + Interval |

重点掌握：

- 如何寻找局部最优策略
- 为什么局部最优能够得到全局结果
- 区间按照左端点或右端点排序
- 区间覆盖
- 区间合并

模板文件：

```text
greedy/template.cpp
```

模板内容：

| 函数 | 说明 |
|---|---|
| `findContentChildren` | 排序 + 双指针 |
| `lemonadeChange` | 找零时优先消耗大面额 |
| `canJump` / `jump` | 最远可达下标 / BFS 分层 |
| `eraseOverlapIntervals` | 按右端点排序 |
| `findMinArrowShots` | 同上，比较写法避免相减溢出 |
| `mergeIntervals` | 按左端点排序 |
| `partitionLabels` | 预处理字母最后出现位置 |
| `canCompleteCircuit` | 断油即换起点 |

---

# 5. Dynamic Programming

目录：

```text
Algorithm/dp/
```

主要训练：

- 1D DP
- 0/1 Knapsack
- Complete Knapsack
- Sequence DP
- String DP

| LeetCode | 题目 | 主要训练内容 |
|---|---|---|
| 70 | 爬楼梯 | 1D DP |
| 746 | 使用最小花费爬楼梯 | 1D DP |
| 198 | 打家劫舍 | 1D DP |
| 213 | 打家劫舍 II | 1D DP |
| 416 | 分割等和子集 | 0/1 Knapsack |
| 494 | 目标和 | 0/1 Knapsack |
| 322 | 零钱兑换 | Complete Knapsack |
| 518 | 零钱兑换 II | Complete Knapsack |
| 300 | 最长递增子序列 | Sequence DP |
| 1143 | 最长公共子序列 | Sequence DP |
| 72 | 编辑距离 | String DP |
| 139 | 单词拆分 | DP |
| 152 | 乘积最大子数组 | DP |

动态规划四件套：

1. 状态定义
2. 状态转移
3. 初始化
4. 遍历顺序

重点进一步区分：

```text
0/1 背包
vs
完全背包
```

以及：

```text
求最值
vs
求方案数量
```

模板文件：

```text
dp/template.cpp
```

模板内容：

| 函数 | 说明 |
|---|---|
| `climbStairs` / `rob` / `robCircle` | 线性 DP，滚动变量压空间 |
| `knapsack01` | 0/1 背包，容量**倒序** |
| `canPartition` | 0/1 背包 · 可行性 |
| `findTargetSumWays` | 0/1 背包 · 计数 |
| `coinChange` | 完全背包 · 求最值，容量**正序** |
| `coinChangeCombinations` | 完全背包 · 组合数（物品在外层）|
| `lengthOfLIS` / `lengthOfLISFast` | O(n²) 与 贪心+二分 O(n log n) |
| `longestCommonSubsequence` | 双序列 DP |
| `minDistance` | 编辑距离 |
| `wordBreak` | 划分型 DP |
| `maxProduct` | 同时维护 max / min |

---

# 6. Backtracking

目录：

```text
Algorithm/backtracking/
```

主要训练：

- 排列
- 组合
- 子集
- 搜索树
- 去重
- 剪枝

| LeetCode | 题目 | 主要训练内容 |
|---|---|---|
| 46 | 全排列 | Backtracking |
| 78 | 子集 | Backtracking |
| 77 | 组合 | Backtracking |
| 39 | 组合总和 | Backtracking |
| 40 | 组合总和 II | Backtracking + Pruning |
| 79 | 单词搜索 | DFS + Backtracking |
| 131 | 分割回文串 | Backtracking |
| 51 | N 皇后 | Backtracking + Pruning |

基本结构：

```text
选择
↓
递归
↓
撤销选择
```

重点掌握：

- `path`
- `visited`
- 搜索树
- 去重
- 剪枝
- 递归边界

模板文件：

```text
backtracking/template.cpp
```

模板内容：

| 函数 | 说明 |
|---|---|
| `permute` | 排列，用 `used` 数组 |
| `subsets` | 子集，每个节点都收集 |
| `combine` | 组合，上界剪枝 |
| `combinationSum` | 可重复选：递归传 `i` |
| `combinationSum2` | 每个只用一次 + 同层去重 |
| `partitionPalindrome` | 分割型回溯 |
| `exist` | 网格 DFS，原地标记再还原 |
| `solveNQueens` | 列 / 两条对角线三个标记数组 |

---

# 7. Graph

目录：

```text
Algorithm/graph/
```

本模块统一训练：

- Tree
- DFS
- BFS
- Topological Sort
- Shortest Path

---

## Tree

| LeetCode | 题目 | 主要训练内容 |
|---|---|---|
| 94 | 二叉树的中序遍历 | DFS / Recursion |
| 102 | 二叉树的层序遍历 | BFS |
| 104 | 二叉树的最大深度 | DFS |
| 236 | 二叉树的最近公共祖先 | Tree Recursion |

重点掌握：

- 递归返回值
- 前中后序遍历思想
- 层序遍历
- Queue

---

## Graph Traversal

| LeetCode | 题目 | 主要训练内容 |
|---|---|---|
| 200 | 岛屿数量 | DFS / BFS |
| 994 | 腐烂的橘子 | BFS |
| 207 | 课程表 | Topological Sort |
| 210 | 课程表 II | Topological Sort |

重点掌握：

```text
DFS
BFS
visited
indegree
Topological Sort
```

---

## Shortest Path

| LeetCode | 题目 | 主要训练内容 |
|---|---|---|
| 743 | 网络延迟时间 | Dijkstra |
| 787 | K 站中转内最便宜的航班 | Bellman-Ford / DP |
| 1334 | 阈值距离内邻居最少的城市 | Floyd-Warshall |
| 1631 | 最小体力消耗路径 | Dijkstra |

重点区分：

```text
Dijkstra
Bellman-Ford
Floyd-Warshall
```

模板文件：

```text
graph/template.cpp
```

模板内容：

| 函数 | 说明 |
|---|---|
| `inorder` / `inorderIterative` | 递归与显式栈遍历 |
| `levelOrder` | 层序，进循环先固定本层大小 |
| `maxDepth` / `lowestCommonAncestor` | 树递归，重点是返回值含义 |
| `floodFill` / `numIslands` | 网格 DFS 沉岛 |
| `orangesRotting` | 多源 BFS 分层计数 |
| `topoSort` | Kahn 入度法，可判环 |
| `dijkstra` | 优先队列 + 懒删除 |
| `bellmanFordLimited` | 限制边数，每轮基于快照松弛 |
| `hasNegativeCycle` | 第 n 轮仍可松弛即有负环 |
| `floyd` | 中转点 k 必须在最外层 |
| `minimumEffortPath` | Dijkstra 变形：瓶颈路 |

---

# 8. DSU / MST

目录：

```text
Algorithm/dsu-mst/
```

主要训练：

- Disjoint Set Union
- Path Compression
- Union by Rank
- Kruskal
- Prim
- Minimum Spanning Tree

| LeetCode | 题目 | 主要训练内容 |
|---|---|---|
| 684 | 冗余连接 | DSU |
| 547 | 省份数量 | DSU |
| 1584 | 连接所有点的最小费用 | MST |
| 721 | 账户合并 | DSU |

重点掌握：

```text
find()
union()
路径压缩
按秩合并
Kruskal
Prim
```

模板文件：

```text
dsu-mst/template.cpp
```

模板内容：

| 函数 | 说明 |
|---|---|
| `DSU` | 路径压缩（迭代式）+ 按大小合并 |
| `findRedundantConnection` | `unite` 返回 false 即成环 |
| `findCircleNum` | 连通分量计数 |
| `accountsMerge` | 用 map 把非整数元素映射成下标 |
| `kruskal` | 边排序 + 并查集判环 |
| `minCostConnectPoints` | 完全图建边后跑 Kruskal |
| `prim` / `primDense` | 优先队列版 / 稠密图 O(V²) 版 |

---

# Learning Order

本学期整体学习顺序：

```text
Binary Search
        ↓
Divide and Conquer
        ↓
Sort / Select / Heap
        ↓
Greedy
        ↓
Dynamic Programming
        ↓
Backtracking
        ↓
Tree
        ↓
DFS / BFS
        ↓
Topological Sort
        ↓
Shortest Path
        ↓
DSU / MST
        ↓
Review
```

实际执行时：

> 课堂进度优先，不机械按照周数推进。

如果老师提前讲动态规划，就提前完成 `dp/` 中相应题目。

---

# Weekly Practice

正常情况下：

```text
周一算法课：2 题
周五算法课：2 题
```

每周：

```text
4 题
```

完整计划：

```text
15 周 × 4 题 = 60 题
```

---

# Minimum Requirements

第一次做题：

```text
独立思考 20-30 分钟
```

如果仍然不会，再查看提示或题解。

不要一开始直接照抄模板。

每道题完成后，至少能够回答：

1. 这道题属于什么算法？
2. 为什么这个算法能够解决问题？
3. 时间复杂度是多少？
4. 空间复杂度是多少？
5. 自己在哪里卡住？
6. 哪个边界最容易出错？

---

# Error Record

建议在每个 `.cpp` 文件开头记录：

```cpp
// Problem: LeetCode 704
// Topic: Binary Search
//
// Time Complexity: O(log n)
// Space Complexity: O(1)
//
// Mistake:
// right 边界更新错误
```

常见错误：

```text
不会建模
边界错误
状态定义错误
数据结构选择错误
实现细节错误
```

---

# Template Goal

每个模块的 `template.cpp` 都已给出参考实现（含复杂度与易错点注释），
但目标不是照抄，而是最终能**合上文件独立默写**出下面这些：

```text
Binary Search
Merge Sort
Quick Sort
Quick Select
Heap

Greedy / Interval

Dynamic Programming
0/1 Knapsack
Complete Knapsack

Backtracking

DFS
BFS
Topological Sort

Dijkstra
Bellman-Ford
Floyd-Warshall

DSU
Kruskal
Prim

Monotonic Queue
```

---

# File Naming

LeetCode 题目统一使用：

```text
题号.cpp
```

例如：

```text
704.cpp
215.cpp
416.cpp
743.cpp
```

算法模板统一保存在：

```text
template.cpp
```

例如：

```text
Algorithm/search/template.cpp
Algorithm/dp/template.cpp
Algorithm/graph/template.cpp
```

---

# Build

`template.cpp` 只包含函数定义、不含 `main`，用于查阅和语法检查：

```bash
g++ -std=c++17 -fsyntax-only dp/template.cpp
```

题号文件按 VS Code 的 `build` 任务（`.vscode/tasks.json`）编译即可：

```bash
g++ -g -std=c++17 dp/70.cpp -o dp/70.exe
```

本地调试建议开上越界检查：

```bash
g++ -std=c++17 -fsanitize=address,undefined -g dp/70.cpp -o dp/70.exe
```

---

# Goal

本阶段目标不是刷完 60 道题本身。

真正目标是完成一轮基础算法体系训练：

```text
搜索
分治
排序 / 选择 / 堆
贪心
动态规划
回溯
树
图
最短路
并查集
最小生成树
```

最终形成：

```text
看到题目
   ↓
判断算法类型
   ↓
建立模型
   ↓
写出算法
   ↓
处理边界
   ↓
分析时间复杂度
   ↓
分析空间复杂度
```

并逐渐形成自己的可复用算法模板。
