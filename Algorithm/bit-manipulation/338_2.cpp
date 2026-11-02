// 比特位计数
#include <iostream>
#include <functional>
#include <vector>
using namespace std;

vector<int> countBits(int n) {
    vector<int> ans(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        // 不比较相邻数字，而是比较减少最后一位的数字，只关注最后一位是否是1
        ans[i] = ans[i >> 1] + (i & 1);
    }

    return ans;
}