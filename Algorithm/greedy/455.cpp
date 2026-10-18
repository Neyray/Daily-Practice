// 分发饼干
// 贪心
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0, j = 0;

    while (i < g.size() && j < s.size()) {
        // 给每个孩子分配满足要求的最小尺寸饼干
        if (s[j] >= g[i]) {
            ++i;
        }
        ++j;
    }

    return i;
}