// 颜色分类
#include <iostream>
#include <vector>
using namespace std;

void sortColors(vector<int>& nums) {
    int n=nums.size();

    int p1=-1,p2=n;
    int i=0;

    while(i<p2){
        if(nums[i]==0){
            p1++;
            swap(nums[i],nums[p1]);

            // nums[p1]已经检查过了，所以不需要再次进行检查
            i++;
        }else if(nums[i]==1){
            i++;
        }else{
            p2--;
            swap(nums[i],nums[p2]);
            // 不移动 i，重新检查交换过来的数，nums[p2]未遍历过，所以需要再次检查
        }
    }
}