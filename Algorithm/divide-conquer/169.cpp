// 多数元素
// 哈希表计数法解法，构造unordered_map
// 时间：O(n)
// 空间：O(n)
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int majorityElements(vector<int>& nums){
    unordered_map<int,int>mp;

    for(int i=0;i<nums.size();++i){
        mp[nums[i]]++;
    }

    for(const auto& pair:mp){
        if(pair.second>nums.size()/2){
            return pair.first;
        }
    }


    return 0;
}