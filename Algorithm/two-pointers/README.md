# 双指针

[返回总览](../README.md)

本专题共 **20 题**，已有代码 **20 题**，待练 **0 题**（同题多种实现不重复计数）。

## 建议刷题顺序

按以下阶段推进，同一阶段内按题号列出的顺序练习：

1. 基础：原地修改、归并与相向指针：[27](27.cpp) → [26](26.cpp) → [80](80.cpp) → [283](283.cpp) → [88](88.cpp) → [344](344.cpp) → [125](125.cpp) → [167](167.cpp) → [977](977.cpp)。
2. 进阶：去重、边界、子序列与链表判环：[11](11.cpp) → [15](15.cpp) → [18](18.cpp) → [75](75.cpp) → [42](42.cpp) → [392](392.cpp) → [524](524.cpp) → [141](141.cpp) → [142](142.cpp) → [19](19.cpp) → [287](287.cpp)。

## 题目清单

| 顺序 | 题号 | 题目 | 难度 | 核心题型 | 进度 |
|---:|---|---|---|---|---|
| 1 | [27](27.cpp) | [移除元素](https://leetcode.cn/problems/remove-element/) | 简单 | 快慢指针 | 已有代码 |
| 2 | [26](26.cpp) | [删除有序数组中的重复项](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/) | 简单 | 快慢指针 | 已有代码 |
| 3 | [80](80.cpp) | [删除有序数组中的重复项 II](https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/) | 中等 | 快慢指针 | 已有代码 |
| 4 | [283](283.cpp) | [移动零](https://leetcode.cn/problems/move-zeroes/) | 简单 | 原地修改 | 已有代码 |
| 5 | [88](88.cpp) | [合并两个有序数组](https://leetcode.cn/problems/merge-sorted-array/) | 简单 | 逆向双指针 | 已有代码 |
| 6 | [344](344.cpp) | [反转字符串](https://leetcode.cn/problems/reverse-string/) | 简单 | 相向双指针 | 已有代码 |
| 7 | [125](125.cpp) | [验证回文串](https://leetcode.cn/problems/valid-palindrome/) | 简单 | 相向双指针 | 已有代码 |
| 8 | [167](167.cpp) | [两数之和 II](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/) | 中等 | 相向双指针 | 已有代码 |
| 9 | [977](977.cpp) | [有序数组的平方](https://leetcode.cn/problems/squares-of-a-sorted-array/) | 简单 | 两端归并 | 已有代码 |
| 10 | [11](11.cpp) | [盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/) | 中等 | 相向指针 + 贪心 | 已有代码 |
| 11 | [15](15.cpp) | [三数之和](https://leetcode.cn/problems/3sum/) | 中等 | 排序 + 去重 | 已有代码 |
| 12 | [18](18.cpp) | [四数之和](https://leetcode.cn/problems/4sum/) | 中等 | 排序 + 多层枚举 | 已有代码 |
| 13 | [75](75.cpp) | [颜色分类](https://leetcode.cn/problems/sort-colors/) | 中等 | 三指针 / 荷兰国旗 | 已有代码 |
| 14 | [42](42.cpp) | [接雨水](https://leetcode.cn/problems/trapping-rain-water/) | 困难 | 双指针维护边界 | 已有代码 |
| 15 | [392](392.cpp) | [判断子序列](https://leetcode.cn/problems/is-subsequence/) | 简单 | 同向双指针 | 已有代码 |
| 16 | [524](524.cpp) | [通过删除字母匹配到字典里最长单词](https://leetcode.cn/problems/longest-word-in-dictionary-through-deleting/) | 中等 | 子序列匹配 | 已有代码 |
| 17 | [141](141.cpp) | [环形链表](https://leetcode.cn/problems/linked-list-cycle/) | 简单 | 快慢指针判环 | 已有代码 |
| 18 | [142](142.cpp) | [环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii/) | 中等 | Floyd 判环 | 已有代码 |
| 19 | [19](19.cpp) | [删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/) | 中等 | 固定间距双指针 | 已有代码 |
| 20 | [287](287.cpp) | [寻找重复数](https://leetcode.cn/problems/find-the-duplicate-number/) | 中等 | Floyd 判环建模 | 已有代码 |

建议按[双指针与滑动窗口五阶段路线](../docs/two-pointers-sliding-window.md)练习。

先完成基础 9 题，再完成进阶 11 题，重点复盘 15、42、142。

跨专题对照：[75 排序版本](../sorting/75.cpp)、[141](../linked-list/141.cpp)、[142](../linked-list/142.cpp)、[19 链表版本](../linked-list/19.cpp)。各专题进度按本目录实现独立记录。

数据结构对照：[顺序表归并](../../data-structureA/chapter2/segment1/merge.cpp)。

同题其他实现（不重复计数）：[80 原地写入](80-2.cpp)、[42 双指针](42-2.cpp)、[142 快慢指针](142-2.cpp)、[392 位置索引与二分](392-2.cpp)、[392 后继位置预处理](392-3.cpp)。
