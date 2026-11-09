# 双指针与滑动窗口 · 40 题学习路线

[返回算法总览](../README.md) · [双指针题单](../two-pointers/README.md) · [滑动窗口题单](../sliding-window/README.md)

依据上传题单整理，共 40 道不同题目：双指针 20 题、滑动窗口 20 题。先学双指针，再学定长窗口、不定长窗口，最后学习单调队列等特殊窗口。

“已有代码”仅表示对应专题中存在实现，未据此认定通过评测；只含注释或 TODO 的文件仍为待练。

| 阶段 | 学习内容 | 题数 | 已有代码 | 顺序 |
|---|---|---:|---:|---|
| 1 | 双指针基础 | 9 | 9 | [27](../two-pointers/27.cpp) → [26](../two-pointers/26.cpp) → [80](../two-pointers/80.cpp) → [283](../two-pointers/283.cpp) → [88](../two-pointers/88.cpp) → [344](../two-pointers/344.cpp) → [125](../two-pointers/125.cpp) → [167](../two-pointers/167.cpp) → [977](../two-pointers/977.cpp) |
| 2 | 双指针进阶 | 11 | 11 | [11](../two-pointers/11.cpp) → [15](../two-pointers/15.cpp) → [18](../two-pointers/18.cpp) → [75](../two-pointers/75.cpp) → [42](../two-pointers/42.cpp) → [392](../two-pointers/392.cpp) → [524](../two-pointers/524.cpp) → [141](../two-pointers/141.cpp) → [142](../two-pointers/142.cpp) → [19](../two-pointers/19.cpp) → [287](../two-pointers/287.cpp) |
| 3 | 定长滑动窗口 | 7 | 0 | [643](../sliding-window/643.cpp) → [1456](../sliding-window/1456.cpp) → [1343](../sliding-window/1343.cpp) → [1052](../sliding-window/1052.cpp) → [1423](../sliding-window/1423.cpp) → [567](../sliding-window/567.cpp) → [438](../sliding-window/438.cpp) |
| 4 | 不定长滑动窗口 | 9 | 0 | [209](../sliding-window/209.cpp) → [3](../sliding-window/3.cpp) → [1004](../sliding-window/1004.cpp) → [904](../sliding-window/904.cpp) → [424](../sliding-window/424.cpp) → [713](../sliding-window/713.cpp) → [1248](../sliding-window/1248.cpp) → [76](../sliding-window/76.cpp) → [30](../sliding-window/30.cpp) |
| 5 | 特殊窗口 | 4 | 0 | [239](../sliding-window/239.cpp) → [1438](../sliding-window/1438.cpp) → [480](../sliding-window/480.cpp) → [995](../sliding-window/995.cpp) |

当前进度：**20 / 40 题已有代码，2 / 5 阶段全部有代码**。

## 阶段 1：双指针基础

快慢指针原地操作、逆向归并、相向指针。

## 阶段 2：双指针进阶

排序去重、多指针边界、子序列匹配、Floyd 判环。

## 阶段 3：定长滑动窗口

维护固定长度的和、计数、额外收益与字母频次，理解补集窗口。

## 阶段 4：不定长滑动窗口

最短、最长、至多与恰好计数、覆盖窗口；30 需按单词长度分组扫描。

## 阶段 5：特殊窗口

239、1438：单调队列；480：双堆或有序集合；995：贪心与差分。

## 重点复盘

- 双指针：15（三数之和）、42（接雨水）、142（环入口）。
- 滑动窗口：3、209、438、76、239、1248。

每题记录状态与不变量、指针移动依据、时间与空间复杂度，并覆盖空输入、重复元素、窗口边界等适用用例。

本次对已有目录补齐 28 个练习文件，其中 4 个题号在排序或链表专题已收录；全库净新增 24 道不同题目。原有题号文件保留。

补充练习：[2747 统计没有收到请求的服务器数目](../sliding-window/2747.cpp) 已有代码，属于离线查询与时间窗口，不计入原 40 题和五阶段统计。
