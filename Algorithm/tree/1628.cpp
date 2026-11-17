// LeetCode 1628：设计带解析函数的表达式树
// 题目链接：https://leetcode.cn/problems/design-an-expression-tree-with-evaluate-function/
// 难度：中等
// 训练主题：二叉树与二叉搜索树
// 课程源码：../../data-structureA/daily-practice2/project14.cpp
// 思考方向：课程按节点和孩子编号建树，力扣从后缀表达式建树。用栈组装运算符节点，再递归计算两棵子树，注意减法和除法的左右顺序。
// TODO: 独立实现本题，并记录时间复杂度、空间复杂度及关键边界用例。
