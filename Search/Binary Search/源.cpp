#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/**
 * 二分查找（Binary Search）
 * 适用于有序数组的查找算法
 * 时间复杂度：O(log n)
 * 空间复杂度：O(1)
 */

 // 递归版本的二分查找
int binarySearchRecursive(vector<int>& arr, int target, int left, int right) {
    // 基本情况：查找范围无效
    if (left > right) {
        return -1; // 未找到
    }

    // 计算中间位置，防止溢出
    int mid = left + (right - left) / 2;

    // 找到目标元素
    if (arr[mid] == target) {
        return mid;
    }
    // 目标在左半部分
    else if (arr[mid] > target) {
        return binarySearchRecursive(arr, target, left, mid - 1);
    }
    // 目标在右半部分
    else {
        return binarySearchRecursive(arr, target, mid + 1, right);
    }
}

// 迭代版本的二分查找
int binarySearchIterative(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        // 计算中间位置
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // 找到目标，返回索引
        }
        else if (arr[mid] > target) {
            right = mid - 1; // 在左半部分继续查找
        }
        else {
            left = mid + 1;   // 在右半部分继续查找
        }
    }

    return -1; // 未找到
}

// 查找第一个出现的位置（处理重复元素）
int findFirst(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;      // 记录当前位置
            right = mid - 1;   // 继续在左半部分查找
        }
        else if (arr[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return result;
}

// 查找最后一个出现的位置（处理重复元素）
int findLast(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;      // 记录当前位置
            left = mid + 1;    // 继续在右半部分查找
        }
        else if (arr[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return result;
}

// 测试函数
void testBinarySearch() {
    vector<int> arr = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
    int target = 7;

    cout << "数组: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "查找目标: " << target << endl;

    // 测试递归版本
    int result1 = binarySearchRecursive(arr, target, 0, arr.size() - 1);
    cout << "递归版本结果: " << (result1 != -1 ? to_string(result1) : "未找到") << endl;

    // 测试迭代版本
    int result2 = binarySearchIterative(arr, target);
    cout << "迭代版本结果: " << (result2 != -1 ? to_string(result2) : "未找到") << endl;

    // 测试重复元素的情况
    vector<int> arrWithDup = { 1, 2, 2, 2, 3, 4, 5 };
    cout << "\n带重复元素的数组: ";
    for (int num : arrWithDup) {
        cout << num << " ";
    }
    cout << endl;

    int dupTarget = 2;
    cout << "查找目标: " << dupTarget << endl;
    cout << "第一个出现位置: " << findFirst(arrWithDup, dupTarget) << endl;
    cout << "最后一个出现位置: " << findLast(arrWithDup, dupTarget) << endl;
}

int main() {
    testBinarySearch();
    return 0;
}