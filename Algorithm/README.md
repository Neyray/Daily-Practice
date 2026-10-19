# Algorithm Practice

本目录用于《算法设计与分析》课程配套的算法训练与 LeetCode 练习。

当前目录包含：

- 9 个算法主题模块
- 共 69 道不同的 LeetCode 题目，其中动态规划模块 18 道、位运算模块 8 道
- 同题不同解法分别保留；模块题数包含交叉题目，总题数按题号去重
- 重点不是刷题数量，而是形成可以独立实现的算法模板

每个模块目录下的 `template.cpp` 提供算法参考实现。
题号命名的 `.cpp` 用于独立练习，部分题目已完成，部分仍待实现；
同一道题可以使用多个文件记录不同解法，例如 `169.cpp` 与 `169-1.cpp`。

目录按照「主要训练的算法模板」进行分类，而不是按照 LeetCode 的全部标签进行分类。

当前独立练习进度：`search/`、`divide-conquer/`、`greedy/`、`dp/` 的题号文件均已有实现；
`sort-structure/`、`backtracking/`、`graph/`、`dsu-mst/` 的题号文件仍为空白练习位。
新增 `bit-manipulation/` 的题号文件提供题目与思考提示，均待独立实现；
`template.cpp` 提供前七题参考实现，1143 保留为位并行专项研究任务。

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
│   ├── 50.cpp  53.cpp  169.cpp  169-1.cpp  108.cpp
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
│   ├── 72.cpp  139.cpp  152.cpp  674.cpp  1218.cpp
│   ├── 1446.cpp  45.cpp  377.cpp
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
├── dsu-mst/                # 并查集 / 最小生成树
│   ├── template.cpp
│   ├── 684.cpp  547.cpp  1584.cpp  721.cpp
│
└── bit-manipulation/       # 位运算 / 位掩码 / Bitset DP / LCS 位并行
    ├── template.cpp
    ├── 191.cpp  231.cpp  136.cpp  338.cpp
    ├── 78.cpp  318.cpp  416.cpp  1143.cpp
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
| 518 | 零钱兑换 II | Complete Knapsack / 组合计数 |
| 377 | 组合总和 IV | Complete Knapsack / 有序序列计数 |
| 45 | 跳跃游戏 II | DP / 对照贪心解法 |
| 300 | 最长递增子序列 | Sequence DP |
| 674 | 最长连续递增序列 | 连续序列 DP |
| 1218 | 最长定差子序列 | Sequence DP / 哈希表状态优化 |
| 1446 | 连续字符 | 连续字符 DP |
| 1143 | 最长公共子序列 | Sequence DP |
| 72 | 编辑距离 | String DP |
| 139 | 单词拆分 | DP |
| 152 | 乘积最大子数组 | DP |

`dp/45.cpp` 与 `greedy/45.cpp` 分别保留 DP 和贪心解法。
`dp/377.cpp` 先枚举目标和，统计不同顺序的序列；`dp/518.cpp` 先枚举硬币，统计组合。
`dp/416.cpp` 和 `dp/1143.cpp` 已有普通 DP 实现，对应位运算版本分别在新模块中练习。

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

# 9. Bit Manipulation

目录：[bit-manipulation/](bit-manipulation/)

学习路线：

```text
191 → 231 → 136 → 338 → 78 → 318 → 416 → 1143
基础位运算             位掩码      Bitset DP   LCS 位并行
```

| 阶段 | LeetCode | 题目 | 主要训练内容 |
|---|---|---|---|
| 基础位运算 | [191](bit-manipulation/191.cpp) | 位1的个数 | `n & (n - 1)` 清除最低位的 1 |
| 基础位运算 | [231](bit-manipulation/231.cpp) | 2 的幂 | 正整数且仅有一个二进制位为 1 |
| 基础位运算 | [136](bit-manipulation/136.cpp) | 只出现一次的数字 | XOR 抵消重复元素 |
| 基础位运算 | [338](bit-manipulation/338.cpp) | 比特位计数 | 位运算与 DP 结合 |
| 位掩码 | [78](bit-manipulation/78.cpp) | 子集 | 每一位表示一个元素是否被选中 |
| 位掩码 | [318](bit-manipulation/318.cpp) | 最大单词长度乘积 | 字母集合编码、按位与判断交集 |
| Bitset DP | [416](bit-manipulation/416.cpp) | 分割等和子集 | 每一位表示一个和是否可达 |
| LCS 位并行 | [1143](bit-manipulation/1143.cpp) | 最长公共子序列 | DP 行内差分、移位与减法借位 |

## 第一阶段：基本位运算

按 `191 → 231 → 136 → 338` 练习，熟悉 `&`、`|`、`^`、`~`、`<<`、`>>`。

- `n & (n - 1)`：当 `n != 0` 时清除最低位的 1。
- 2 的幂：必须先满足 `n > 0`，再判断 `(n & (n - 1)) == 0`。
- 异或：`x ^ x == 0`、`x ^ 0 == x`，结合交换律和结合律抵消成对元素。
- 计数 DP：`dp[i] = dp[i & (i - 1)] + 1`，`dp[0] = 0`。

C++ 中用无符号类型表示位集合；移位数必须小于类型位宽，并注意运算优先级。

## 第二阶段：位掩码 Bitmask

按 `78 → 318` 练习，把一个集合编码成整数。

- 78：枚举 `[0, 2^n)` 的掩码，第 i 位表示是否选择第 i 个元素；与 [回溯版本](backtracking/78.cpp) 对照。
- 318：使用 26 位表示小写英文字母集合，`(maskA & maskB) == 0` 表示没有公共字母。

## 第三阶段：Bitset DP

416 从 [普通 0/1 背包](dp/416.cpp) 过渡到位集合：第 s 位表示和 s 是否可达。

```text
bits = 1                 // 初始只有和 0 可达
bits |= bits << num      // 对每个数，用旧状态生成新状态后合并
```

总和为奇数时直接返回 false；否则检查第 `sum / 2` 位。
目标是理解一个整数或位集合如何同时保存、更新多个 DP 状态。
上述写法是位集合伪代码：C++ 可用 `std::bitset`，但容量需要在编译期确定并覆盖目标和。

## 第四阶段：LCS 位并行优化（最终目标）

先复现 [1143 普通二维 DP](dp/1143.cpp)，再在 [位运算练习文件](bit-manipulation/1143.cpp) 中实现、比较位并行版本。

固定第二个字符串，第 j 位对应它的第 j 个字符（从最低位开始）。
`mask[c]` 的第 j 位表示该位置是否为字符 c。
处理第一个字符串的前 i 个字符后，`S` 的第 j 位表示当前 DP 行的差分
`dp[i][j + 1] - dp[i][j]`；差分只能为 0 或 1，初始 `S = 0`。

对第一个字符串中的当前字符 c，使用旧 S 计算：

```text
X = S | mask[c]
Y = (S << 1) | 1
S_next = X & ~(X - Y)
```

更新 `S = S_next`，处理完所有字符后，`popcount(S)` 就是 LCS 长度。
重点研究 `X - Y` 中借位如何定位新的状态上升位置，不必一开始就死记公式。

单个 C++ 整数的位宽有限。多字位向量需要处理跨字移位进位、减法借位和末尾有效位；
`std::bitset` 没有减法运算符，不能直接套入整个 LCS 公式。
位并行优化的目标是利用机器字宽一次更新多个状态，仍需与普通 DP 对照验证正确性及实际性能。

## 三类方法的区别与练习安排

| 题目 | 核心知识 | 是否使用 LCS 位并行公式 |
|---|---|---|
| 191、231 | 基础位运算 | 否 |
| 136、338 | XOR、位运算与 DP | 否 |
| 78、318 | 位掩码 Bitmask | 否 |
| 416 | Bitset DP、状态压缩 | 否，用于建立位集合直觉 |
| 1143 | LCS、位并行 DP | 是，最终研究目标 |

Bitmask、Bitset DP 和 LCS 位并行优化有关联，但各自表示的状态、更新方式不同。
416 的可达和转移不涉及 LCS 公式中的减法借位机制。

1. 基础练习：191、231、136、338。
2. 集合与并行状态：78、318、416。
3. 专项研究：1143，保留普通 DP，实现位并行版本并比较结果与耗时。

参考模板：[bit-manipulation/template.cpp](bit-manipulation/template.cpp)。
前七题提供参考实现；1143 提供状态定义、更新公式和实现注意点，待独立研究实现。

---

# Algorithm Knowledge Notes

## 1. 算法思想的整体框架

- **归纳法（Induction）**：关注如何由小规模问题的解，推导或构造大规模问题的解。
- **分治法（Divide and Conquer）**：关注如何将大问题拆分为小问题，分别求解，再合并得到原问题的解。
- **动态规划（Dynamic Programming）**：将大问题表示为有关联的子问题，通过状态转移保存并复用子问题的计算结果，避免重复计算。
- **贪心算法（Greedy）**：每一步选择当前最优的决策，不回退、不枚举所有可能的决策组合，要求局部最优能够导向全局最优。

归纳法侧重推导与构造，分治法侧重拆分与合并，动态规划侧重状态转移与结果复用，贪心算法侧重局部决策的正确性。

## 2. 分治法（Divide and Conquer）

### （1）核心思想

分治法一般分为三个步骤：

1. Divide：将原问题拆分成若干规模更小的子问题。
2. Conquer：递归求解各个子问题，直到达到基本情况（Base Case）。
3. Combine：将子问题的解合并，得到原问题的解。

分治通常要求子问题之间相对独立，能够分别计算。

### （2）判断方法

- 原问题能否拆分为结构相同、规模更小的问题？
- 子问题能否递归求解？
- 能否由子问题的结果构造原问题的答案？
- 递归边界和合并过程分别是什么？

### （3）典型例子

- LeetCode 50：快速幂。通过指数折半减少计算，时间复杂度 O(log n)。
- LeetCode 53：最大子数组和。答案可能位于左半部分、右半部分，或者跨越中点。采用线性扫描合并，时间复杂度 O(n log n)。
- LeetCode 912：归并排序。递归排序左右部分，再合并两个有序序列，时间复杂度 O(n log n)。

## 3. 归并排序（Merge Sort）

### （1）核心思想

归并排序是分治法的典型应用：

1. 将数组从中间划分为左右两个部分。
2. 递归地对左右两部分进行排序。
3. 通过双指针，将两个有序数组合并成一个有序数组。

分解过程主要负责缩小问题规模，真正形成整体有序结果的是合并过程。

### （2）归并过程

假设左右两个序列已经有序：

- 使用两个指针分别指向左右序列的起始位置。
- 比较两个指针指向的元素，选取较小的元素放入临时数组。
- 对应指针向后移动。
- 当其中一个序列遍历结束后，将另一个序列的剩余元素追加到结果中。

合并两个总长度为 n 的有序序列，时间复杂度为 O(n)。

### （3）复杂度与性质

- 递推关系：T(n) = 2T(n/2) + O(n)。
- 时间复杂度：O(n log n)，最好、平均、最坏情况相同。
- 额外空间复杂度：O(n)。
- 稳定性：稳定排序，前提是比较相等时优先取左侧元素。

归并排序与快速排序都使用分治法，但归并排序主要在合并阶段完成排序，快速排序主要通过划分（Partition）确定元素的相对位置。

## 4. 动态规划（Dynamic Programming）

### （1）核心思想

动态规划将原问题分解成具有依赖关系的子问题，并利用状态转移逐步求解。

两个重要特征：

- **最优子结构**：原问题的最优解可以由相关子问题的最优解构造。
- **重叠子问题**：不同求解路径会重复遇到相同子问题，适合保存并复用结果。

实现方式：

- 自顶向下：递归 + 记忆化搜索。
- 自底向上：从已知边界状态出发，按照依赖顺序迭代计算。

### （2）动态规划的分析步骤

1. **定义状态**：明确 `dp[i]` 或 `dp[i][j]` 的具体含义。
2. **建立状态转移**：分析当前状态由哪些已有状态得到。
3. **确定边界和初始化**：处理最小规模问题。
4. **确定遍历顺序**：保证计算当前状态时，依赖的状态已经得到。
5. **提取最终答案**：判断返回最后一个状态，还是所有状态中的最优值。
6. **考虑空间优化**：根据状态依赖关系决定能否使用滚动数组或变量。

状态定义是动态规划最重要的一步。不能先写递推公式，再反过来解释状态含义。

### （3）连续子数组与非连续子序列

**连续子数组（Subarray）**

- 要求元素在原数组中连续。
- 如果状态定义为以 `i` 结尾的最优解，通常可以从相邻状态 `dp[i-1]` 转移。
- 常见例子：最长连续递增子序列、最大连续子数组和。
- 如果只依赖前一个状态，可以使用滚动变量压缩空间。

**非连续子序列（Subsequence）**

- 允许跳过部分元素，但必须保持相对顺序。
- 对于以 `i` 结尾的状态，可能需要枚举之前所有符合条件的位置 `j < i`。
- 常见例子：最长递增子序列（LIS）。
- 并不是所有非连续子序列问题都必须枚举 `j`，具体取决于状态定义。

本目录中的 `dp/1218.cpp` 是一个例子：最长定差子序列使用哈希表按元素值保存状态。对于当前值 `x`，只需查询固定前驱 `x - difference`，再更新 `dp[x] = dp[x - difference] + 1`，无需枚举所有前序位置。

例如：

- 最长连续递增子序列：`nums[i] > nums[i-1]` 时，`dp[i] = dp[i-1] + 1`，否则为 1。
- 最长递增子序列：枚举 `j < i` 且 `nums[j] < nums[i]`，更新 `dp[i] = max(dp[i], dp[j] + 1)`。

序列问题中的连接条件也需要区分：

- 严格递增：前面的元素 `<` 当前元素。
- 严格递减：前面的元素 `>` 当前元素。
- 相同字符或元素：使用 `==` 判断是否满足连接条件。

但连接关系只是状态转移的一部分，不能单独决定整个 DP 算法。

### （4）状态定义的两种常见形式

**第一种：以当前位置结尾的最优解**

例如：`dp[i]` 表示必须以 `nums[i]` 结尾的最大连续子数组和。

状态转移：

`dp[i] = max(nums[i], dp[i-1] + nums[i])`

由于最优子数组不一定以最后一个元素结尾，因此答案为：

`max(dp[0], dp[1], ..., dp[n-1])`

**第二种：前 i 个元素范围内的最优解**

例如：`dp[i]` 表示考虑前 i 个元素时能够获得的最大价值。

这种状态已经包含当前范围内的最优结果，因此最终通常可以返回 `dp[n]`。

两种状态定义不能混淆，否则容易出现最终答案提取错误。

### （5）一维 DP 与二维 DP

一维 DP：

- 使用一个变量描述子问题状态。
- 常见于爬楼梯、打家劫舍、最长递增子序列等问题。

二维 DP：

- 单个变量不足以描述子问题，需要使用两个维度。
- 常见于双序列匹配、编辑距离、最长公共子序列等问题。

例如最长公共子序列（LCS）：

`dp[i][j]` 表示第一个字符串的前 i 个字符与第二个字符串的前 j 个字符的最长公共子序列长度。

- 当前字符相等：`dp[i][j] = dp[i-1][j-1] + 1`。
- 当前字符不等：`dp[i][j] = max(dp[i-1][j], dp[i][j-1])`。

编辑距离则通过插入、删除、替换三种操作建立状态转移。

### （6）背包问题与空间优化

**0/1 背包**

- 每个物品最多选一次。
- 一维空间优化时，容量通常倒序遍历。
- 防止同一个物品在一轮内重复使用。

**完全背包**

- 每种物品可以重复选择。
- 一维空间优化时，容量通常正序遍历。
- 允许当前状态使用本轮更新的结果。

**求最值与求方案数量**

- 求最值：通常使用 `min` 或 `max` 转移。
- 求方案数量：通常累加不同合法选择产生的方案数。
- 统计组合数与排列数时，需要注意物品和容量的循环顺序。

空间优化的原则是：只有压缩后仍然保留全部必要的状态信息，并且更新顺序不破坏依赖关系，才能安全压缩。

## 5. 贪心算法（Greedy）

### （1）核心思想

贪心算法在每一步选择当前看起来最优的决策，并希望通过连续的局部最优选择得到全局最优解。

特点：

- 通常不保存完整的子问题状态。
- 不尝试所有可能的决策组合。
- 作出选择后通常不回退。
- 时间和空间复杂度往往较低，但并非一定优于动态规划。

### （2）贪心算法的适用条件

贪心并不是只要选择当前最大或最小就一定正确。

需要证明：

- **贪心选择性质**：存在一个全局最优解包含当前的贪心选择。
- **最优子结构**：完成当前选择后，剩余问题仍可通过求解子问题得到最优结果。

常见证明方法：

- 交换论证：证明某个最优解能够调整为包含贪心选择的解，而不降低最优性。
- 领先性质：证明贪心方案在关键指标上始终不劣于其他方案。
- 循环不变式：证明算法执行过程中始终保持某种正确性质。

### （3）典型例子

- LeetCode 455：分发饼干，排序后优先满足胃口较小的孩子。
- LeetCode 55：跳跃游戏，维护当前能够到达的最远位置。
- LeetCode 435：无重叠区间，按右端点排序，优先保留结束更早的区间。
- LeetCode 53：最大子数组和，可以采用舍弃负前缀的贪心解释。

### （4）贪心与动态规划的区别

动态规划会保存不同状态的计算结果，比较多个候选方案；贪心则试图直接确定当前最优选择。

例如，零钱兑换问题中硬币面额为 `[1,3,4]`，目标金额为 6：

- 每次优先选择最大面额：`4+1+1`，使用 3 枚硬币。
- 全局最优方案：`3+3`，只需要 2 枚硬币。

因此，一般的零钱兑换问题不能直接使用“每次选最大硬币”的贪心策略，动态规划能够通过比较不同转移得到最优解。

## 6. 算法选择与相互联系

| 方法   | 核心问题            | 典型特征            |
| ---- | --------------- | --------------- |
| 归纳法  | 如何从小规模推导大规模？    | 递推、构造、数学证明      |
| 分治法  | 如何拆分并合并子问题？     | 递归、子问题相对独立      |
| 归并排序 | 如何合并两个有序序列？     | 分治、双指针、有序合并     |
| 动态规划 | 如何复用子问题的计算结果？   | 状态定义、状态转移、重叠子问题 |
| 贪心算法 | 当前最优选择能否保证全局最优？ | 局部决策、贪心正确性证明    |

判断算法类型时：

1. 能否拆分成相对独立、结构相同的子问题，并合并结果？优先考虑分治。
2. 是否存在重复计算的子问题，并且能够建立状态依赖关系？考虑动态规划。
3. 是否存在可以证明正确的局部最优选择？考虑贪心。
4. 是否需要递归地排序并合并有序序列？考虑归并排序。

**同一道题可以具有多种算法解法。**

例如 LeetCode 53 最大子数组和：

- 分治法：拆分为左半、右半、跨中点三种情况，O(n log n)。
- 动态规划：维护以当前元素结尾的最大子数组和，O(n)。
- 贪心解释：当前累计和为负时舍弃此前前缀，重新开始，O(n)。

这道题中，贪心思路与一维动态规划的空间优化实现可以完全一致，只是理解和证明角度不同。

算法分类不是互斥的。分治可以结合记忆化，动态规划可以进行空间优化，贪心也可以与二分查找等方法结合。

最终目标是：**根据问题结构判断算法，而不是仅凭题目标签套用模板。**

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
Bit Manipulation / Bitmask / Bitset DP
        ↓
LCS Bit-Parallel Optimization
        ↓
Review
```

实际执行时：

> 课堂进度优先，不机械按照周数推进。

如果老师提前讲动态规划，就提前完成 `dp/` 中相应题目。

位运算专项可在动态规划基础之后推进，按第 9 节路线学习；1143 位并行优化放在普通 LCS DP 之后。
