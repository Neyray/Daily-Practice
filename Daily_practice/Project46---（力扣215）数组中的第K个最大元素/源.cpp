#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 快速选择的分区操作
int partition(vector<int>& nums, int low, int high) {
    int pivot = nums[high];  // 选择最后一个元素作为基准
    int i = low - 1;  // i表示小于基准的元素区域的最后一个位置

    for (int j = low; j < high; ++j) {
        if (nums[j] > pivot) {  // 因为我们要找第k个最大元素，所以小于基准的元素放到右边
            i++;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[high]);  // 将基准元素放到它的正确位置
    return i + 1;  // 返回基准元素的索引
}

// 快速选择算法
int quickSelect(vector<int>& nums, int low, int high, int k) {
    if (low <= high) {
        int pi = partition(nums, low, high);  // 获取分区的基准位置

        if (pi == k) {
            return nums[pi];  // 找到了第k个最大元素
        }
        else if (pi < k) {
            return quickSelect(nums, pi + 1, high, k);  // 如果基准位置小于k，去右侧部分查找
        }
        else {
            return quickSelect(nums, low, pi - 1, k);  // 如果基准位置大于k，去左侧部分查找
        }
    }
    return -1;  // 这行一般不会被执行
}

int findKthLargest(vector<int>& nums, int k) {
    return quickSelect(nums, 0, nums.size() - 1, k - 1);  // k - 1是因为索引是从0开始的
}

int main() {
    vector<int> nums1 = { 3, 2, 1, 5, 6, 4 };
    int k1 = 2;
    cout << "第 " << k1 << " 个最大的元素是: " << findKthLargest(nums1, k1) << endl;  // 输出: 5

    vector<int> nums2 = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
    int k2 = 4;
    cout << "第 " << k2 << " 个最大的元素是: " << findKthLargest(nums2, k2) << endl;  // 输出: 4

    return 0;
}
