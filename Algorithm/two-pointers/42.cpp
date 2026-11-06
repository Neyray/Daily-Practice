// 接雨水
#include <iostream>
#include <vector>
using namespace std;

// 贪心思想：p1,p2高的那个不需要动
int trap(vector<int>& height) {
    int n=height.size();

    int p1=0,p2=n-1;
    int sum=0;

    while(p1<p2){
        if(height[p1]<=height[p2]){
            int temp1=height[p1];

            p1++; // 先移动指针

            while(p1<p2 && height[p1]<temp1){
                sum+=temp1-height[p1];
                p1++;
            }
        }else{
            int temp2=height[p2];

            p2--; // 先移动指针

            while(p1<p2 && height[p2]<temp2){
                sum+=temp2-height[p2];
                p2--;
            }
        }
    }

    return sum;
}