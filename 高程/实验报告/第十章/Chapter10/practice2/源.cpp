// lab10_2.cpp
// 使用STL算法进行查找和排序
#include <iostream>
#include <algorithm>  // 包含find和sort算法
#include <functional> // 包含greater函数对象
using namespace std;

int main() {
    // 声明一个包含8个元素的整型数组
    int arr[] = { 45, 23, 78, 12, 90, 34, 67, 56 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "原始数组: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 使用find算法查找数据
    int target;
    cout << "\n请输入要查找的值: ";
    cin >> target;

    // find函数返回指向找到元素的迭代器（指针），如果没找到则返回end()
    int* result = find(arr, arr + size, target);

    if (result != arr + size) {
        cout << "找到元素 " << target << "，它在数组中的位置是: "
            << (result - arr) << endl; // 计算索引位置
    }
    else {
        cout << "未找到元素 " << target << endl;
    }

    // 对数组进行升序排序
    sort(arr, arr + size);
    cout << "\n升序排序后的数组: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 再次查找（演示查找已排序数组）
    cout << "\n再次查找（已排序数组）: ";
    cin >> target;
    result = find(arr, arr + size, target);

    if (result != arr + size) {
        cout << "找到元素 " << target << "，它在数组中的位置是: "
            << (result - arr) << endl;
    }
    else {
        cout << "未找到元素 " << target << endl;
    }

    // 对数组进行降序排序，使用greater<int>()函数对象
    sort(arr, arr + size, greater<int>());
    cout << "\n降序排序后的数组: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 使用二分查找（需要数组已排序）
    // 注意：binary_search只返回是否找到，不返回位置
    cout << "\n请输入要二分查找的值（数组已降序排序）: ";
    cin >> target;

    if (binary_search(arr, arr + size, target, greater<int>())) {
        cout << "二分查找: 找到元素 " << target << endl;
    }
    else {
        cout << "二分查找: 未找到元素 " << target << endl;
    }

    return 0;
}