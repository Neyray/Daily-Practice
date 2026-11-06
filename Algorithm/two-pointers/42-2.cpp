#include <iostream>
#include <vector>
using namespace std;


int trap(vector<int>& height) {
    int n=height.size();

    int p1=0,p2=n-1;
    int leftMax=0,rightMax=0;
    int sum=0;

    while(p1<p2){
        if(height[p1]<=height[p2]){
            leftMax=max(leftMax,height[p1]);
            sum+=leftMax-height[p1];
            p1++;
        }else{
            rightMax=max(rightMax,height[p2]);
            sum+=rightMax-height[p2];
            p2--;
        }
    }

    return sum;
}