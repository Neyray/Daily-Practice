// 在排序数组中查找元素的第一个和最后一个位置
#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int>ans(2,-1);


    // 找最左边
    int low=0,high=nums.size()-1;
    int start=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            start=mid;
            high=mid-1;
        }
        else if(nums[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }

    if(start==-1)return ans;

    //找最右边
    low=0,high=nums.size()-1;
    int end=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            end=mid;
            low=mid+1;
        }
        else if(nums[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    ans[0]=start;
    ans[1]=end;

    return ans;
}