#include <iostream>
#include <vector>
using namespace std;

// 快速排序的分区操作
int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[high];  // 选择最后一个元素作为基准
    int i = low - 1;  // i表示小于基准的元素区域的最后一个位置

    // 遍历数组，将小于基准的元素交换到数组的前面
    for (int j = low; j < high; ++j) {
        if (nums[j] < pivot) {
            i++;
            swap(nums[i], nums[j]);  // 交换nums[i]和nums[j]
        }
    }
    // 将基准元素放到它的正确位置
    swap(nums[i + 1], nums[high]);
    return i + 1;  // 返回基准元素的索引
}

// 快速排序的递归实现
void quickSort(vector<int>& nums, int low, int high) {
    if (low < high) {
        // 分区，返回基准的索引
        int pi = partition(nums, low, high);

        // 对基准左侧和右侧的子数组递归排序
        quickSort(nums, low, pi - 1);
        quickSort(nums, pi + 1, high);
    }
}

int main() {
    vector<int> nums = { 10, 7, 8, 9, 1, 5 };

    // 调用快速排序进行排序
    quickSort(nums, 0, nums.size() - 1);

    // 输出排序后的数组
    cout << "排序后的数组: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
