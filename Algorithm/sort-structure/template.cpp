// ============================================================
// Topic : Sort / Select / Heap / Monotonic Queue
// Dir   : Algorithm/sort-structure/
//
// 本模板覆盖：
//   1. 归并排序（稳定，O(n log n) 最坏）
//   2. 快速排序（随机化 + 三路切分，防有序/大量重复退化）
//   3. 快速选择（求第 K 大 / 第 K 小，期望 O(n)）
//   4. 堆：优先队列用法 + 手写下沉建堆
//   5. 桶排序求 Top-K 频次
//   6. 荷兰国旗三路 Partition
//   7. 单调队列（滑动窗口最值）
// ============================================================

#include <algorithm>
#include <deque>
#include <queue>
#include <random>
#include <unordered_map>
#include <vector>
using namespace std;

// ------------------------------------------------------------
// 1. 归并排序：先分到底，再有序合并
//    Time O(n log n) 恒定 / Space O(n)，稳定
//    tmp 在外部开好，避免每层递归重复分配
// ------------------------------------------------------------
void mergeSort(vector<int>& a, int l, int r, vector<int>& tmp) {
    if (l >= r) return;                       // 区间长度 <= 1，天然有序
    int mid = l + (r - l) / 2;
    mergeSort(a, l, mid, tmp);
    mergeSort(a, mid + 1, r, tmp);

    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r)
        tmp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];   // <= 保证稳定
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r)   tmp[k++] = a[j++];
    for (int p = l; p <= r; ++p) a[p] = tmp[p];
}

void mergeSort(vector<int>& a) {
    vector<int> tmp(a.size());
    if (!a.empty()) mergeSort(a, 0, (int)a.size() - 1, tmp);
}

// ------------------------------------------------------------
// 2. 快速排序：先定好一个基准的最终位置，再分治两侧
//    随机选 pivot -> 期望 O(n log n)；三路切分让重复元素只扫一遍
//    Space O(log n)（递归栈），不稳定
// ------------------------------------------------------------
static mt19937 rng(20260907);

void quickSort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int p = l + (int)(rng() % (unsigned)(r - l + 1));
    swap(a[l], a[p]);
    int pivot = a[l];

    // 三路切分：[l, lt) < pivot，[lt, i) == pivot，(gt, r] > pivot
    int lt = l, i = l + 1, gt = r;
    while (i <= gt) {
        if      (a[i] < pivot) swap(a[lt++], a[i++]);
        else if (a[i] > pivot) swap(a[i], a[gt--]);   // 换来的元素还没看过，i 不动
        else                   ++i;
    }
    quickSort(a, l, lt - 1);
    quickSort(a, gt + 1, r);
}

void quickSort(vector<int>& a) {
    if (!a.empty()) quickSort(a, 0, (int)a.size() - 1);
}

// ------------------------------------------------------------
// 3. 快速选择：只递归「答案所在的那一侧」
//    第 k 大 == 升序下标 n - k
//    期望 Time O(n) / 最坏 O(n^2)（随机化后概率极低）/ Space O(1) 迭代版
// ------------------------------------------------------------
int quickSelect(vector<int>& a, int k) {          // 返回第 k 大
    int target = (int)a.size() - k;               // 转成「升序第 target 个」
    int l = 0, r = (int)a.size() - 1;
    while (true) {
        int p = l + (int)(rng() % (unsigned)(r - l + 1));
        swap(a[l], a[p]);
        int pivot = a[l];

        int lt = l, i = l + 1, gt = r;
        while (i <= gt) {
            if      (a[i] < pivot) swap(a[lt++], a[i++]);
            else if (a[i] > pivot) swap(a[i], a[gt--]);
            else                   ++i;
        }
        if      (target < lt) r = lt - 1;         // 答案在小于区
        else if (target > gt) l = gt + 1;         // 答案在大于区
        else return pivot;                        // 落在等于区，已定位
    }
}

// ------------------------------------------------------------
// 4.1 堆：用 priority_queue 维护大小为 k 的小顶堆求第 k 大
//     Time O(n log k) / Space O(k)
// ------------------------------------------------------------
int kthLargestByHeap(const vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;   // 小顶堆
    for (int v : nums) {
        minHeap.push(v);
        if ((int)minHeap.size() > k) minHeap.pop();           // 弹掉最小的
    }
    return minHeap.top();
}

// 4.2 手写堆：下沉 + 自底向上建堆（O(n)），再逐个弹出得到堆排序
void siftDown(vector<int>& a, int i, int n) {   // 大顶堆下沉
    while (true) {
        int largest = i, l = 2 * i + 1, r = 2 * i + 2;
        if (l < n && a[l] > a[largest]) largest = l;
        if (r < n && a[r] > a[largest]) largest = r;
        if (largest == i) break;
        swap(a[i], a[largest]);
        i = largest;
    }
}

void heapSort(vector<int>& a) {
    int n = (int)a.size();
    for (int i = n / 2 - 1; i >= 0; --i) siftDown(a, i, n);   // 建堆 O(n)
    for (int i = n - 1; i > 0; --i) {                         // 堆顶换到末尾
        swap(a[0], a[i]);
        siftDown(a, 0, i);
    }
}

// ------------------------------------------------------------
// 5. Top-K 高频元素（LeetCode 347）
//    频次上限是 n，用「频次」当桶下标从高往低取，Time O(n)
// ------------------------------------------------------------
vector<int> topKFrequent(const vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int v : nums) ++freq[v];

    vector<vector<int>> bucket(nums.size() + 1);   // bucket[f] = 出现 f 次的所有值
    for (auto& [val, f] : freq) bucket[f].push_back(val);

    vector<int> res;
    for (int f = (int)nums.size(); f >= 1 && (int)res.size() < k; --f)
        for (int val : bucket[f]) {
            res.push_back(val);
            if ((int)res.size() == k) break;
        }
    return res;
}

// ------------------------------------------------------------
// 6. 荷兰国旗三路 Partition（LeetCode 75）
//    循环不变量：[0,low) 全 0，[low,i) 全 1，(high,n-1] 全 2
//    Time O(n) / Space O(1)，一趟扫描
// ------------------------------------------------------------
void sortColors(vector<int>& nums) {
    int low = 0, i = 0, high = (int)nums.size() - 1;
    while (i <= high) {
        if      (nums[i] == 0) swap(nums[low++], nums[i++]);
        else if (nums[i] == 2) swap(nums[i], nums[high--]);   // 换来的没检查，i 不动
        else                   ++i;
    }
}

// ------------------------------------------------------------
// 7. 单调队列：滑动窗口最大值（LeetCode 239）
//    队列存下标，值从队头到队尾单调递减
//    每个下标进队出队各一次 -> Time O(n) / Space O(k)
// ------------------------------------------------------------
vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
    deque<int> dq;                       // 存下标
    vector<int> res;
    for (int i = 0; i < (int)nums.size(); ++i) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();      // 队头滑出窗口
        while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();// 比新元素小的没用了
        dq.push_back(i);
        if (i >= k - 1) res.push_back(nums[dq.front()]);                // 窗口成形才取答案
    }
    return res;
}
