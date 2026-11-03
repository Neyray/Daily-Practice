// 有序数组的平方
#include <iostream>
#include <vector>
using namespace std;


vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);

    int p1 = 0, p2 = n - 1;
    int p = n - 1;

    while (p1 <= p2) {
        int left = nums[p1] * nums[p1];
        int right = nums[p2] * nums[p2];

        if (left > right) {
            ans[p--] = left;
            p1++;
        } else {
            ans[p--] = right;
            p2--;
        }
    }

    return ans;
}