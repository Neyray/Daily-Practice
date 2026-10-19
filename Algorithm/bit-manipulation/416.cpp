// LeetCode 416：分割等和子集
// 训练主题：Bitset DP
// 思考方向：第 s 位表示和 s 是否可达，初始仅第 0 位为 1；每个数更新 bits |= bits << num。
// 对照：../dp/416.cpp；本文件练习位集合版本，注意容量上限。
// TODO: 独立实现本题，完成后对照 template.cpp。
