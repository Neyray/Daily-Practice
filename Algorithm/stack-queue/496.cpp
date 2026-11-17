// 下一个更大元素I
// 单调栈，从右到左遍历，当前元素主动寻找右边第一个更大的元素
#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> mp;
    stack<int> st;

    for (int i = nums2.size() - 1; i >= 0; --i) {
        // 弹出所有不大于当前元素的数字
        while (!st.empty() && st.top() <= nums2[i]) {
            st.pop();
        }

        // 直接建立：数字 -> 下一个更大元素
        mp[nums2[i]] = st.empty() ? -1 : st.top();

        st.push(nums2[i]);
    }

    vector<int> ans;
    for (int x : nums1) {
        ans.push_back(mp[x]);
    }

    return ans;
}