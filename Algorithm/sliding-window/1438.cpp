// 绝对差不超过限制的最长连续子数组
#include <iostream>
#include <vector>
#include <deque>
using namespace std;


int longestSubarray(vector<int>& nums, int limit) {
    int n=nums.size();

    deque<int> maxQ,minQ;
    int left=0;
    int ans=0;

    for(int right=0;right<n;++right){
        // 维护单调递减队列（最大值）
        while(!maxQ.empty() && nums[maxQ.back()]<nums[right]){
            maxQ.pop_back();
        }
        maxQ.push_back(right);

        // 维护单调递增队列（最小值）
        while(!minQ.empty() && nums[minQ.back()]>nums[right]){
            minQ.pop_back();
        }
        minQ.push_back(right);

        // 最大值和最小值之差超过limit，收缩窗口
        while(nums[maxQ.front()]-nums[minQ.front()]>limit){
            if(maxQ.front()==left){
                maxQ.pop_front();
            }

            if(minQ.front()==left){
                minQ.pop_front();
            }

            left++;
        }

        ans=max(ans,right-left+1);
    }

    return ans;
}