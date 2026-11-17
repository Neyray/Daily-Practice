// 每日温度
// 单调栈：最近更大/更小元素
// 单调队列：滑动窗口最大/最小值
#include <iostream>
#include <stack>
#include <vector>
using namespace std;


vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> ans(n, 0);

    // 单调栈，保存下标
    stack<int> st;

    for (int i = n - 1; i >= 0; --i) {
        // 弹出所有不高于当前温度的元素
        while (!st.empty() &&
               temperatures[st.top()] <= temperatures[i]) {
            st.pop();
        }

        // 栈顶就是右侧最近的更高温度
        if (!st.empty()) {
            ans[i] = st.top() - i;
        }

        st.push(i);
    }

    return ans;
}
