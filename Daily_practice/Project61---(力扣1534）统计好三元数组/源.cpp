#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    int count = 0;
    int n = arr.size();

    // 遍历所有可能的三元组 (i, j, k)
    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            for (int k = j + 1; k < n; ++k) {
                // 检查三元组 (arr[i], arr[j], arr[k]) 是否符合条件
                if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                    count++;
                }
            }
        }
    }

    return count;
}

int main() {
    // 示例1
    vector<int> arr1 = { 3, 0, 1, 1, 9, 7 };
    int a1 = 7, b1 = 2, c1 = 3;
    cout << "输出: " << countGoodTriplets(arr1, a1, b1, c1) << endl; // 输出: 4

    // 示例2
    vector<int> arr2 = { 1, 1, 2, 2, 3 };
    int a2 = 0, b2 = 0, c2 = 1;
    cout << "输出: " << countGoodTriplets(arr2, a2, b2, c2) << endl; // 输出: 0

    return 0;
}
