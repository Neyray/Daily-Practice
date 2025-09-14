#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

// 打印数组函数
void printArray(const vector<int>& arr, const string& title) {
    cout << title << ": ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// 10.2.1 直接插入排序
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // 将大于key的元素向后移动
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 10.2.2 折半插入排序
void binaryInsertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int left = 0, right = i - 1;

        // 使用二分查找找到插入位置
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > key) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        // 移动元素并插入
        for (int j = i - 1; j >= left; j--) {
            arr[j + 1] = arr[j];
        }
        arr[left] = key;
    }
}

// 10.2.3 希尔排序
void shellSort(vector<int>& arr) {
    int n = arr.size();
    // 选择增量序列
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 对每个子序列进行插入排序
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// 10.3.1 冒泡排序
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // 如果没有交换，说明已经有序
        if (!swapped) break;
    }
}

// 10.3.2 快速排序
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortHelper(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(vector<int>& arr) {
    quickSortHelper(arr, 0, arr.size() - 1);
}

// 10.4.1 简单选择排序
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
        }
    }
}

// 归并操作：合并两个有序子数组
void merge(vector<int>& arr, int left, int mid, int right) {
    // 创建临时数组存放合并结果
    vector<int> temp(right - left + 1);

    int i = left;      // 左子数组起始索引
    int j = mid + 1;   // 右子数组起始索引
    int k = 0;         // 临时数组索引

    // 合并两个有序子数组
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    // 复制左子数组剩余元素
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // 复制右子数组剩余元素
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // 将临时数组内容复制回原数组
    for (int p = 0; p < k; p++) {
        arr[left + p] = temp[p];
    }
}

// 递归实现二路归并排序
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        // 计算中间位置（避免溢出）
        int mid = left + (right - left) / 2;

        // 递归排序左半部分
        mergeSort(arr, left, mid);

        // 递归排序右半部分
        mergeSort(arr, mid + 1, right);

        // 合并两个有序部分
        merge(arr, left, mid, right);
    }
}

// 迭代实现二路归并排序（非递归）
void iterativeMergeSort(vector<int>& arr) {
    int n = arr.size();
    // 步长从1开始，每次加倍
    for (int curr_size = 1; curr_size <= n - 1; curr_size *= 2) {
        // 遍历所有子数组进行合并
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            // 计算中间位置和右端点
            int mid = min(left_start + curr_size - 1, n - 1);
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);

            // 合并子数组
            merge(arr, left_start, mid, right_end);
        }
    }
}


// 10.4.2 堆排序辅助函数
void heapify(vector<int>& arr, int n, int i) {              //n表示当前堆的大小
    int largest = i;          // 初始化最大元素为当前节点
    int left = 2 * i + 1;     // 计算左子节点位置
    int right = 2 * i + 2;    // 计算右子节点位置

    // 如果左子节点存在且大于当前最大元素
    if (left < n && arr[left] > arr[largest]) {
        largest = left;       // 更新最大元素位置
    }

    // 如果右子节点存在且大于当前最大元素
    if (right < n && arr[right] > arr[largest]) {
        largest = right;      // 更新最大元素位置
    }

    // 如果最大元素不是当前节点
    if (largest != i) {
        swap(arr[i], arr[largest]);  // 交换当前节点和较大子节点
        heapify(arr, n, largest);    // 递归调整受影响的子树
    }
}

// 10.4.2 堆排序
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // 1. 构建最大堆（自底向上）
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);  // 从最后一个非叶子节点开始调整
    }

    // 2. 逐元素提取
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // 将当前堆顶（最大值）移到末尾
        heapify(arr, i, 0);    // 调整剩余元素（堆大小减1）
    }
}

// 10.5.1 自底向上的二路归并排序辅助函数
void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int i = 0; i < temp.size(); i++) {
        arr[left + i] = temp[i];
    }
}

// 10.5.1 自底向上的二路归并排序
void mergeSortBottomUp(vector<int>& arr) {
    int n = arr.size();
    for (int size = 1; size < n; size *= 2) {
        for (int left = 0; left < n - size; left += 2 * size) {
            int mid = left + size - 1;
            int right = min(left + 2 * size - 1, n - 1);
            merge(arr, left, mid, right);
        }
    }
}

// 10.5.2 自顶向下的二路归并排序
void mergeSortTopDown(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortTopDown(arr, left, mid);
        mergeSortTopDown(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void mergeSortTopDownWrapper(vector<int>& arr) {
    mergeSortTopDown(arr, 0, arr.size() - 1);
}

// 10.6 基数排序
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    // 计算每个数字的出现次数
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // 累加计数
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // 构建输出数组
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // 复制回原数组
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(vector<int>& arr) {
    // 找到最大值
    int maxVal = *max_element(arr.begin(), arr.end());

    // 对每一位进行计数排序
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

// 测试函数
void testSortingAlgorithm(const string& algorithmName, void (*sortFunc)(vector<int>&)) {
    cout << "\n=== " << algorithmName << " ===" << endl;

    // 测试数据1：随机数组
    vector<int> test1 = { 64, 34, 25, 12, 22, 11, 90, 88, 76, 50 };
    printArray(test1, "测试数据1 - 排序前");
    sortFunc(test1);
    printArray(test1, "测试数据1 - 排序后");

    // 测试数据2：部分有序数组
    vector<int> test2 = { 5, 2, 8, 1, 9, 3, 7, 4, 6, 0 };
    printArray(test2, "测试数据2 - 排序前");
    sortFunc(test2);
    printArray(test2, "测试数据2 - 排序后");
}

// 特殊测试函数（用于归并排序的包装）
void testMergeSortTopDown() {
    cout << "\n=== 自顶向下的二路归并排序 ===" << endl;

    vector<int> test1 = { 64, 34, 25, 12, 22, 11, 90, 88, 76, 50 };
    printArray(test1, "测试数据1 - 排序前");
    mergeSortTopDownWrapper(test1);
    printArray(test1, "测试数据1 - 排序后");

    vector<int> test2 = { 5, 2, 8, 1, 9, 3, 7, 4, 6, 0 };
    printArray(test2, "测试数据2 - 排序前");
    mergeSortTopDownWrapper(test2);
    printArray(test2, "测试数据2 - 排序后");
}

int main() {
    cout << "========== 排序算法演示程序 ==========" << endl;
    cout << "根据教材10.2-10.8章节顺序实现各种排序算法" << endl;

    // 10.2 插入排序
    testSortingAlgorithm("10.2.1 直接插入排序", insertionSort);
    testSortingAlgorithm("10.2.2 折半插入排序", binaryInsertionSort);
    testSortingAlgorithm("10.2.3 希尔排序", shellSort);

    // 10.3 交换排序
    testSortingAlgorithm("10.3.1 冒泡排序", bubbleSort);
    testSortingAlgorithm("10.3.2 快速排序", quickSort);

    // 10.4 选择排序
    testSortingAlgorithm("10.4.1 简单选择排序", selectionSort);
    testSortingAlgorithm("10.4.2 堆排序", heapSort);

    // 10.5 归并排序
    testSortingAlgorithm("10.5.1 自底向上的二路归并排序", mergeSortBottomUp);
    testMergeSortTopDown();

    // 10.6 基数排序
    testSortingAlgorithm("10.6 基数排序", radixSort);

    cout << "\n========== 所有排序算法测试完成 ==========" << endl;

    return 0;
}