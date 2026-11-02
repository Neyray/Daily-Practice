# 滑动窗口

[返回总览](../README.md)

本专题共 **20 题**，已有代码 **0 题**，待练 **20 题**（同题多种实现不重复计数）。

## 建议刷题顺序

按以下阶段推进，同一阶段内按题号列出的顺序练习：

1. 定长窗口：和、计数与字符频次：[643](643.cpp) → [1456](1456.cpp) → [1343](1343.cpp) → [1052](1052.cpp) → [1423](1423.cpp) → [567](567.cpp) → [438](438.cpp)。
2. 不定长窗口：最短、最长、计数与覆盖：[209](209.cpp) → [3](3.cpp) → [1004](1004.cpp) → [904](904.cpp) → [424](424.cpp) → [713](713.cpp) → [1248](1248.cpp) → [76](76.cpp) → [30](30.cpp)。
3. 特殊窗口：单调队列、双堆与差分：[239](239.cpp) → [1438](1438.cpp) → [480](480.cpp) → [995](995.cpp)。

## 题目清单

| 顺序 | 题号 | 题目 | 难度 | 核心题型 | 进度 |
|---:|---|---|---|---|---|
| 1 | [643](643.cpp) | [子数组最大平均数 I](https://leetcode.cn/problems/maximum-average-subarray-i/) | 简单 | 定长窗口入门 | 待练 |
| 2 | [1456](1456.cpp) | [定长子串中元音的最大数目](https://leetcode.cn/problems/maximum-number-of-vowels-in-a-substring-of-given-length/) | 中等 | 定长窗口计数 | 待练 |
| 3 | [1343](1343.cpp) | [大小为 K 且平均值大于等于阈值的子数组数目](https://leetcode.cn/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/) | 中等 | 定长窗口统计 | 待练 |
| 4 | [1052](1052.cpp) | [爱生气的书店老板](https://leetcode.cn/problems/grumpy-bookstore-owner/) | 中等 | 定长窗口贡献 | 待练 |
| 5 | [1423](1423.cpp) | [可获得的最大点数](https://leetcode.cn/problems/maximum-points-you-can-obtain-from-cards/) | 中等 | 逆向窗口 / 补集 | 待练 |
| 6 | [209](209.cpp) | [长度最小的子数组](https://leetcode.cn/problems/minimum-size-subarray-sum/) | 中等 | 不定长窗口求最短 | 待练 |
| 7 | [3](3.cpp) | [无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/) | 中等 | 不定长窗口求最长 | 待练 |
| 8 | [1004](1004.cpp) | [最大连续 1 的个数 III](https://leetcode.cn/problems/max-consecutive-ones-iii/) | 中等 | 最多 K 次修改 | 待练 |
| 9 | [904](904.cpp) | [水果成篮](https://leetcode.cn/problems/fruit-into-baskets/) | 中等 | 最多 K 种元素 | 待练 |
| 10 | [424](424.cpp) | [替换后的最长重复字符](https://leetcode.cn/problems/longest-repeating-character-replacement/) | 中等 | 窗口频次 + 修改 | 待练 |
| 11 | [713](713.cpp) | [乘积小于 K 的子数组](https://leetcode.cn/problems/subarray-product-less-than-k/) | 中等 | 窗口计数 | 待练 |
| 12 | [1248](1248.cpp) | [统计优美子数组](https://leetcode.cn/problems/count-number-of-nice-subarrays/) | 中等 | 恰好 K 个 = 两次至多 K 个 | 待练 |
| 13 | [567](567.cpp) | [字符串的排列](https://leetcode.cn/problems/permutation-in-string/) | 中等 | 定长窗口字符频次 | 待练 |
| 14 | [438](438.cpp) | [找到字符串中所有字母异位词](https://leetcode.cn/problems/find-all-anagrams-in-a-string/) | 中等 | 定长窗口 + 频次数组 | 待练 |
| 15 | [76](76.cpp) | [最小覆盖子串](https://leetcode.cn/problems/minimum-window-substring/) | 困难 | 不定长覆盖窗口 | 待练 |
| 16 | [30](30.cpp) | [串联所有单词的子串](https://leetcode.cn/problems/substring-with-concatenation-of-all-words/) | 困难 | 分组滑动窗口 | 待练 |
| 17 | [239](239.cpp) | [滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum/) | 困难 | 单调双端队列 | 待练 |
| 18 | [1438](1438.cpp) | [绝对差不超过限制的最长连续子数组](https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/) | 中等 | 最大/最小单调队列 | 待练 |
| 19 | [480](480.cpp) | [滑动窗口中位数](https://leetcode.cn/problems/sliding-window-median/) | 困难 | 双堆 / 有序集合 | 待练 |
| 20 | [995](995.cpp) | [K 连续位的最小翻转次数](https://leetcode.cn/problems/minimum-number-of-k-consecutive-bit-flips/) | 困难 | 定长影响区间 + 差分 | 待练 |

建议按[双指针与滑动窗口五阶段路线](../docs/two-pointers-sliding-window.md)练习。

按定长窗口 → 不定长窗口 → 特殊窗口推进，重点复盘 3、209、438、76、239、1248。

239、1438 使用单调队列；480 研究双堆或有序集合，995 研究贪心与差分，不统一归为单调队列。

239 的单调队列参考实现见[原综合模板](../sorting/template.cpp)。
