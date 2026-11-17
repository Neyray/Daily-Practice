// 下一个更大元素II
// 循环数组问题，不一定需要真的复制数组，可以通过 i % n 将遍历范围扩展到两倍
// 单调栈，从左到右遍历，st存储下标更加普适
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();

    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < 2 * n; ++i) {
        int idx = i % n;

        while (!st.empty() && nums[st.top()] < nums[idx]) {
            ans[st.top()] = nums[idx];
            st.pop();
        }

        // 只在第一遍入栈
        if (i < n) {
            st.push(i);
        }
    }

    return ans;
}