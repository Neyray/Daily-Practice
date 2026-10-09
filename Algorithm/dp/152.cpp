// 乘积最大子数组
#include <iostream>
#include <vector>
using namespace std;

// 实际上使用了两个压缩后的 DP 状态
// （1）max_prod=以nums[i]结尾的最大连续子数组乘积
// （2）min_prod=以nums[i]结尾的最小连续子数组乘积
// 由于每个位置的 max_prod 都可能是最终答案，而不是只有最后一个位置，所以维护result来存储最大值
int maxProduct(vector<int>& nums) {
    int max_prod=nums[0],min_prod=nums[0],result=nums[0];

    for(int i=1;i<nums.size();++i){
        // 由于有负数，所以必须考虑负数导致最小数成为最大数的情况
        if(nums[i]<0) swap(max_prod,min_prod);


        // 连续问题的基本模板，要么加上这个数，要么全部重来
        max_prod=max(nums[i],max_prod*nums[i]);
        min_prod=min(nums[i],min_prod*nums[i]);
        result= max(max_prod,result);
    }
    return result;
}