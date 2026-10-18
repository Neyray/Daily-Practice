// 加油站
#include <iostream>
#include <vector>
using namespace std;

// 贪心算法
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();

    int total = 0;
    int tank = 0;
    int start = 0;

    for (int i = 0; i < n; ++i) {
        // 表示经过第i个加油站油量的变化
        int diff = gas[i] - cost[i];

        total += diff;
        tank += diff;

        if (tank < 0) {
            // 由于之前tank都>0，所以之前的start到i之间所有的点都不能用来当作起点（少了增量，更通不过），无法通过这个点
            start = i + 1;
            tank = 0;
        }
    }

    return total >= 0 ? start : -1;
}