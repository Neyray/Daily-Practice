#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    // 1. 对孩子的胃口值和饼干的尺寸进行排序
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int childIndex = 0;  // 当前孩子的索引
    int cookieIndex = 0; // 当前饼干的索引
    int satisfiedChildren = 0;  // 满意的孩子数

    // 2. 遍历孩子和饼干
    while (childIndex < g.size() && cookieIndex < s.size()) {
        // 如果当前饼干满足当前孩子的胃口
        if (s[cookieIndex] >= g[childIndex]) {
            satisfiedChildren++;  // 满足一个孩子
            childIndex++;         // 处理下一个孩子
        }
        cookieIndex++;  // 尝试下一个饼干
    }

    return satisfiedChildren;
}

int main() {
    // 示例 1
    vector<int> g1 = { 1, 2, 3 };
    vector<int> s1 = { 1, 1 };
    cout << "示例1的输出: " << findContentChildren(g1, s1) << endl;  // 输出 1

    // 示例 2
    vector<int> g2 = { 1, 2 };
    vector<int> s2 = { 1, 2, 3 };
    cout << "示例2的输出: " << findContentChildren(g2, s2) << endl;  // 输出 2

    return 0;
}
