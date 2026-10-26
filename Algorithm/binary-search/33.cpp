//旋转数组
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int search(vector<int>& nums,int target){
    int low=0,high=nums.size()-1;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(nums[mid]==target)return mid;

        if(nums[low]<=nums[mid]){
            //说明左边有序
            if(nums[low]<=target && target<nums[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        else{
            //右边有序
            if(nums[mid]<target && target<=nums[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return -1;
}
//核心仍是折半查找，只不过是在找有序区间，找到之后再进行折半查找，一定注意边界问题

int main(){
    vector<int>nums;

    int num;
    while(cin>>num){
        nums.push_back(num);
    }

    int target=5;
    cout<<search(nums,target);
    return 0;
}