// 寻找重复数
// 位运算
#include <iostream>
#include <vector>
using namespace std;


// 核心：假设一个数字重复k次，由于数组长度n+1，数组元素范围[1,n]，所以k+((n-1)-m)=n+1,m=k-2，即：其他元素缺失k-2次，
// 当重复的这个数字某一位为1，即1的个数为：x+k(x为其他只出现一次数字的1数量)，对于1-n，最多为：x+(k-2)+1，表示
// 其他元素+没出现的元素+重复元素 1的数量，所以只要count1>count2，表示重复数字这一位一定为1
int findDuplicate(vector<int>& nums) {
    int n = nums.size() - 1;
    int ans = 0;

    // 逐位判断重复数字的二进制表示
    for (int bit = 0; (1LL << bit) <= n; ++bit) {
        int count1 = 0;
        int count2 = 0;

        // 实际数组中当前位为1的数量
        for (int x : nums) {
            count1 += (x >> bit) & 1;
        }

        // 正常集合1~n中当前位为1的数量
        for (int i = 1; i <= n; ++i) {
            count2 += (i >> bit) & 1;
        }

        // 实际数量更多，说明重复数字这一位为1
        if (count1 > count2) {
            ans |= (1 << bit);
        }
    }

    return ans;
}