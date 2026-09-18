// 多数元素
// Boyer-Moore 投票法
// 相互抵消
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums){
    int candidate=0;int count=0;
    for(int x: nums){
        if(count==0){
            candidate=x;
        }

        if(candidate==x){
            count++;
        }
        else{
            count--;
        }
    }
    return candidate;
}