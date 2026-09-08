#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int search(vector<int>& nums,int target){
    int low=0,high=nums.size()-1;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(nums[mid]==target)return mid;
        else if(nums[mid]<target)low=mid+1;
        else high=mid-1;
    }
    return -1;
}

int main(){
    vector<int>nums;

    int num;
    while(cin>>num){
        nums.push_back(num);
    }

    sort(nums.begin(),nums.end());

    int target=5;
    cout<<search(nums,target);

    return 0;
}