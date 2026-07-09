#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    vector<int> arr1(n, 1); // 1表示在圈内
    vector<int> arr2; // 存储出列顺序

    int curr = k - 1; // 当前报数的人
    int count = 0; // 当前已报数的人数（用于跳过已出列者）

    while (arr2.size() < n) {
        // 如果当前人在圈内，直接出列
        if (arr1[curr] == 1) {
            arr1[curr] = 0; // 标记出列
            arr2.push_back(curr + 1); // 记录出列顺序
            count++; // 出列人数+1
        }

        // 寻找下一个起始位置：需要跳过m-1个在圈内的人
        int steps = 0;
        while (steps < m) {
            curr = (curr + 1) % n; // 移动到下一个人
            if (arr1[curr] == 1) { // 如果在圈内，算一步
                steps++;
            }
        }
    }

    // 输出出列顺序
    for (int num : arr2) {
        cout << num << " ";
    }
    return 0;
}