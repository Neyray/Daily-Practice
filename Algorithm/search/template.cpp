// ============================================================
// Topic : Binary Search
// Dir   : Algorithm/search/
//
// 本模板覆盖：
//   1. 闭区间二分（找精确值）
//   2. 左边界二分 / 右边界二分（lower_bound / upper_bound）
//   3. 二分答案（在单调判定函数上二分）
//   4. 旋转有序数组二分
//
// 记忆要点：
//   - 循环条件与区间定义必须匹配：
//       闭区间 [l, r]     -> while (l <= r)，r = mid - 1 / l = mid + 1
//       半开区间 [l, r)   -> while (l <  r)，r = mid     / l = mid + 1
//   - mid 用 l + (r - l) / 2，避免 l + r 溢出
//   - 死循环通常来自「区间没有真正缩小」
// ============================================================

#include <vector>
#include <functional>
using namespace std;

// ------------------------------------------------------------
// 1. 闭区间二分：找到返回下标，找不到返回 -1
//    区间 [left, right] 始终是「还没排除的候选」
//    Time O(log n) / Space O(1)
// ------------------------------------------------------------
int binarySearch(const vector<int>& nums, int target) {
    int left = 0, right = (int)nums.size() - 1;   // 闭区间
    while (left <= right) {                       // 区间非空
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) left = mid + 1;   // 排除 [left, mid]
        else                    right = mid - 1;  // 排除 [mid, right]
    }
    return -1;
}

// ------------------------------------------------------------
// 2.1 左边界：第一个 >= target 的下标（等价 std::lower_bound）
//     没有则返回 n（表示插入位置在末尾）
//     LeetCode 35 / 34 的左端点都用它
// ------------------------------------------------------------
int lowerBound(const vector<int>& nums, int target) {
    int left = 0, right = (int)nums.size();       // 半开区间 [left, right)
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid + 1;   // mid 不可能是答案
        else                    right = mid;      // mid 可能是答案，保留
    }
    return left;                                  // left == right
}

// ------------------------------------------------------------
// 2.2 右边界：第一个 > target 的下标（等价 std::upper_bound）
//     target 的最后一次出现 = upperBound(...) - 1
// ------------------------------------------------------------
int upperBound(const vector<int>& nums, int target) {
    int left = 0, right = (int)nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) left = mid + 1;
        else                     right = mid;
    }
    return left;
}

// 由上面两个函数直接得到「元素的起止区间」（LeetCode 34）
vector<int> searchRange(const vector<int>& nums, int target) {
    int lo = lowerBound(nums, target);
    if (lo == (int)nums.size() || nums[lo] != target) return {-1, -1};
    return {lo, upperBound(nums, target) - 1};
}

// ------------------------------------------------------------
// 3. 二分答案：在 [lo, hi] 上找「最小的满足 check 的值」
//    前提：check 关于 x 单调  false false ... false true true ... true
//    典型：LeetCode 69 / 1631 / 分割数组的最大值 / 最小速度
// ------------------------------------------------------------
int binarySearchAnswer(int lo, int hi, const function<bool(int)>& check) {
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) hi = mid;   // mid 可行，答案在 [lo, mid]
        else            lo = mid + 1;
    }
    return lo;
}

// 应用：整数平方根（LeetCode 69）
// 找最小的 x 满足 (x+1)*(x+1) > num，即最大的 x 满足 x*x <= num
int mySqrt(int num) {
    long long lo = 0, hi = num;
    while (lo < hi) {
        long long mid = lo + (hi - lo + 1) / 2;   // 求最大值时 mid 上取整，防死循环
        if (mid * mid <= num) lo = mid;
        else                  hi = mid - 1;
    }
    return (int)lo;
}

// ------------------------------------------------------------
// 4. 旋转有序数组（无重复元素，LeetCode 33）
//    关键：mid 一侧一定是有序的，先判断哪半边有序，
//          再判断 target 是否落在这个有序区间内
// ------------------------------------------------------------
int searchRotated(const vector<int>& nums, int target) {
    int left = 0, right = (int)nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[left] <= nums[mid]) {                       // 左半 [left, mid] 有序
            if (nums[left] <= target && target < nums[mid])  // 落在左半
                right = mid - 1;
            else
                left = mid + 1;
        } else {                                             // 右半 [mid, right] 有序
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}
