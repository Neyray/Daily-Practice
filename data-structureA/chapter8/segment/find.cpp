#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

//1.1折半查找非递归
int BinSearch1(vector<int>& R, int k)   // 折半查找非递归算法
{
    int n = R.size();
    int low = 0, high = n - 1;

    while (low <= high)                 // 当前区间非空时
    {
        int mid = (low + high) / 2;      // 求查找区间的中间位置

        if (k == R[mid])                // 查找成功，返回其序号 mid
            return mid;

        if (k < R[mid])                 // 继续在 R[low..mid-1] 中查找
            high = mid - 1;
        else                            // k > R[mid]
            low = mid + 1;              // 继续在 R[mid+1..high] 中查找
    }

    return -1;                          // 当前查找区间为空时返回 -1
}

//1.2折半查找递归
int BinSearch2(vector<int>& R, int k)   // 折半查找递归算法
{
    return BinSearch21(R, 0, R.size() - 1, k);
}

int BinSearch21(vector<int>& R, int low, int high, int k)
// 被 BinSearch2 方法调用
{
    if (low <= high)                    // 当前查找区间非空时
    {
        int mid = (low + high) / 2;      // 求查找区间的中间位置

        if (k == R[mid])                // 查找成功返回其序号 mid
            return mid;

        if (k < R[mid])                 // 递归在左区间中查找
            return BinSearch21(R, low, mid - 1, k);
        else                            // k > R[mid]，递归在右区间中查找
            return BinSearch21(R, mid + 1, high, k);
    }
    else
    {
        return -1;                      // 当前查找区间为空时返回 -1
    }
}