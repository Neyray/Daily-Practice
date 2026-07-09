/*
【问题描述】
输入一组无序的整数，编程输出其中出现次数最多的整数及其出现次数。

【输入形式】
先从标准输入读入整数的个数（大于等于1，小于等于100），然后在下一行输入这些整数，各整数之间以一个空格分隔。

【输出形式】
在标准输出上输出出现次数最多的整数及其出现次数，两者以一个空格分隔；
若出现次数最多的整数有多个，则按照整数升序分行输出。
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int maxCount = 0;        // 记录最大连续出现次数
    int currentCount = 1;    // 当前元素的连续出现次数

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {      // 如果和前一个元素相同
            currentCount++;               // 计数+1
        }
        else {                            // 如果不同
            if (currentCount > maxCount) {
                maxCount = currentCount;  // 更新最大值
            }
            currentCount = 1;             // 重置计数
        }
    }
    // 循环结束后，处理最后一组元素
    if (currentCount > maxCount) {
        maxCount = currentCount;
    }

    currentCount = 1;  // 重置计数器

    for (int i = 1; i <= n; i++) {  // 注意：i <= n，会多循环一次
        if (i < n && arr[i] == arr[i - 1]) {  // 和前一个相同
            currentCount++;
        }
        else {  // 不同 或 到达数组末尾
            if (currentCount == maxCount) {   // 如果出现次数等于最大次数
                cout << arr[i - 1] << " " << maxCount << endl;  // 输出
            }
            currentCount = 1;  // 重置
        }
    }

    return 0;
}