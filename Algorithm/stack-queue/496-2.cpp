// 下一个更大元素I
// 从左到右遍历，当前元素帮助左边更小的元素确定答案
#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> mp;
    stack<int> st;

    for (int x : nums2) {
        while (!st.empty() && st.top() < x) {
            mp[st.top()] = x;
            st.pop();
        }

        st.push(x);
    }

    vector<int> ans;
    for (int x : nums1) {
        ans.push_back(mp.count(x) ? mp[x] : -1);
    }

    return ans;
}