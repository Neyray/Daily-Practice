// 滑动窗口最大值
// deque：当滑动窗口需要统计最大&最小值时，使用单调队列，最大值单调递减(nums[maxQ.back()]<nums[right],pop_back())，最小值单调递增(nums[minQ.back()]>nums[right],pop_back())
#include <iostream>
#include <vector>
#include <deque>
using namespace std;


vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n=nums.size();

    deque<int> q;
    vector<int> ans;

    for(int right=0;right<n;++right){
        // 1. 移除不在窗口内的下标
        while(!q.empty() && q.front()<=right-k){
            q.pop_front();
        }

        // 2. 维护单调递减队列
        while(!q.empty() && nums[q.back()]<=nums[right]){
            q.pop_back();
        }

        // 3. 插入当前元素的下标
        q.push_back(right);

        // 4. 窗口长度达到k，记录最大值
        if(right>=k-1){
            ans.push_back(nums[q.front()]);
        }
    }

    return ans;
}