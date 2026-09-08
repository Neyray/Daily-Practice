// 左闭右开区间
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int searchInsert(vector<int> nums,int target){
    int low=0,high=nums.size();
    while(low<high){
        int mid=low+(high-low)/2;

        if(nums[mid]==target)return mid;
        else if(nums[mid]<target)low=mid+1;
        else high=mid;
    }
    return low;
}

int main(){
    vector<int>nums;

    int num;
    while(cin>>num){
        nums.push_back(num);
    }

    sort(nums.begin(),nums.end());

    int target=5;
    cout<<searchInsert(nums,target);

    return 0;
}