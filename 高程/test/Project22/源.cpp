/*
【问题描述】
从标准输入中输入两组整数(每行不超过20个整数，每组整数中元素不重复)，
合并两组整数，去掉在两组整数中都出现的整数，并按从大到小顺序排序输出（即两组整数集"异或"）。

【输入形式】
首先输入第一组整数的个数，然后在下一行输入第一组整数，以一个空格分隔各个整数；
然后以同样的方式输入第二组整数。

【输出形式】
按从大到小顺序排序输出合并后的整数集（去掉在两组整数中都出现的整数，以一个空格分隔各个整数）。
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr1[20], arr2[20];
    int m, n;

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    // 降序排序
    sort(arr1, arr1 + m, [](int a, int b) { return a > b; });
    sort(arr2, arr2 + n, [](int a, int b) { return a > b; });

    int result[40];
    int count = 0;
    int i = 0, j = 0;

    while (i < m && j < n) {
        if (arr1[i] > arr2[j]) {
            result[count++] = arr1[i];
            i++;
        }
        else if (arr1[i] < arr2[j]) {
            result[count++] = arr2[j];
            j++;
        }
        else {
            // 相同的元素跳过，不加入结果
            i++;
            j++;
        }
    }

    while (i < m) {
        result[count++] = arr1[i];
        i++;
    }

    while (j < n) {
        result[count++] = arr2[j];
        j++;
    }

    for (int k = 0; k < count; k++) {
        cout << result[k];
        if (k < count - 1) cout << " ";
    }
    cout << endl;

    return 0;
}