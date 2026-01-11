/*【问题描述】

有一个含n（n<=200000）个整数的无序序列，采用快速排序实现递增排序

【输入形式】

一行字符串，包含多个整数，每个数之间用空格分开。

【输出形式】

递增排序的结果，每个数之间用空格分开。

【样例输入】

9 4 7 6 2 5 8 1 3

【样例输出】

1 2 3 4 5 6 7 8 9

【样例说明】

测试数据的文件名为in.txt，输出文件名为out.txt

【评分标准】

该题目有10个测试用例，每通过一个测试用例得10分

*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// 经典快速排序划分函数
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low]; // 选择第一个元素作为枢轴
    int i = low + 1;
    int j = high;

    while (true) {
        // 从左向右找第一个大于枢轴的元素
        while (i <= j && arr[i] <= pivot) i++;
        // 从右向左找第一个小于枢轴的元素
        while (i <= j && arr[j] >= pivot) j--;

        if (i >= j) break;
        swap(arr[i], arr[j]); // 交换这两个元素
    }
    swap(arr[low], arr[j]); // 将枢轴放到正确的位置
    return j;
}

// 经典快速排序递归实现
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // 划分数组
        quickSort(arr, low, pi - 1);  // 递归排序左半部分
        quickSort(arr, pi + 1, high); // 递归排序右半部分
    }
}

int main() {
    // 读取输入文件
    ifstream inFile("in.txt");
    if (!inFile) {
        cerr << "无法打开输入文件 in.txt" << endl;
        return 1;
    }

    vector<int> numbers;
    int num;
    while (inFile >> num) {
        numbers.push_back(num);
    }
    inFile.close();

    // 执行快速排序
    if (!numbers.empty()) {
        quickSort(numbers, 0, numbers.size() - 1);
    }

    // 写入输出文件
    ofstream outFile("out.txt");
    if (!outFile) {
        cerr << "无法创建输出文件 out.txt" << endl;
        return 1;
    }

    for (size_t i = 0; i < numbers.size(); i++) {
        if (i > 0) outFile << " ";
        outFile << numbers[i];
    }
    outFile.close();

    return 0;
}