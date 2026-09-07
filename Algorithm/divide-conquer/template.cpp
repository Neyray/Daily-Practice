// ============================================================
// Topic : Recursion / Divide and Conquer
// Dir   : Algorithm/divide-conquer/
//
// 分治三步：
//   1. Divide  ：把问题拆成规模更小的同类子问题
//   2. Conquer ：递归解决子问题（Base Case 负责终止）
//   3. Combine ：把子问题的答案合并成原问题的答案
//
// 写递归前先回答：
//   - 递归函数的「定义」是什么？（返回值代表什么）
//   - Base Case 是什么？
//   - 怎么合并？合并需要子问题额外返回哪些信息？
//
// 复杂度用主定理估：T(n) = a·T(n/b) + f(n)
//   T(n) = 2T(n/2) + O(n)  -> O(n log n)   例：归并排序、53
//   T(n) =  T(n/2) + O(1)  -> O(log n)     例：快速幂
// ============================================================

#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

// ------------------------------------------------------------
// 0. 分治通用骨架
// ------------------------------------------------------------
// int solve(int l, int r) {
//     if (l == r) return baseCase(l);          // Base Case
//     int mid   = l + (r - l) / 2;
//     int left  = solve(l, mid);               // Divide + Conquer
//     int right = solve(mid + 1, r);
//     return merge(left, right);               // Combine
// }

// ------------------------------------------------------------
// 1. 快速幂（LeetCode 50）
//    x^n = (x^(n/2))^2 · (n 为奇数则再乘一个 x)
//    坑：n = INT_MIN 取负会溢出，先转成 long long
//    Time O(log n) / Space O(1)
// ------------------------------------------------------------
double myPow(double x, int n) {
    long long e = n;
    if (e < 0) { x = 1 / x; e = -e; }
    double res = 1.0;
    while (e > 0) {
        if (e & 1) res *= x;
        x *= x;
        e >>= 1;
    }
    return res;
}

// 递归写法，更贴近分治的形式
double powRecursive(double x, long long e) {
    if (e == 0) return 1.0;                 // Base Case
    double half = powRecursive(x, e / 2);   // 子问题只算一次
    return (e % 2 == 0) ? half * half : half * half * x;
}

// ------------------------------------------------------------
// 2. 最大子数组和（LeetCode 53，分治解法）
//    答案只有三种可能：全在左半 / 全在右半 / 跨越中点
//    跨越中点的部分从 mid 向两侧线性扩展
//    Time O(n log n) / Space O(log n)
// ------------------------------------------------------------
int maxSubArrayDC(const vector<int>& nums, int l, int r) {
    if (l == r) return nums[l];                       // Base Case
    int mid = l + (r - l) / 2;

    int leftBest  = maxSubArrayDC(nums, l, mid);
    int rightBest = maxSubArrayDC(nums, mid + 1, r);

    // 跨越中点：必须包含 nums[mid] 和 nums[mid + 1]
    int sum = 0, leftMax = INT_MIN;
    for (int i = mid; i >= l; --i) { sum += nums[i]; leftMax = max(leftMax, sum); }
    sum = 0;
    int rightMax = INT_MIN;
    for (int i = mid + 1; i <= r; ++i) { sum += nums[i]; rightMax = max(rightMax, sum); }

    return max(max(leftBest, rightBest), leftMax + rightMax);
}

// 对照：Kadane 线性解法，O(n)，实际写题更常用
int maxSubArrayKadane(const vector<int>& nums) {
    int best = nums[0], cur = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        cur  = max(nums[i], cur + nums[i]);   // 要么接上去，要么另起炉灶
        best = max(best, cur);
    }
    return best;
}

// ------------------------------------------------------------
// 3. 多数元素（LeetCode 169，分治解法）
//    若某元素是整体众数，它必然是左半或右半的众数
//    Time O(n log n) / Space O(log n)
// ------------------------------------------------------------
int countInRange(const vector<int>& nums, int target, int l, int r) {
    int cnt = 0;
    for (int i = l; i <= r; ++i) if (nums[i] == target) ++cnt;
    return cnt;
}

int majorityElementDC(const vector<int>& nums, int l, int r) {
    if (l == r) return nums[l];                       // Base Case
    int mid = l + (r - l) / 2;
    int lm = majorityElementDC(nums, l, mid);
    int rm = majorityElementDC(nums, mid + 1, r);
    if (lm == rm) return lm;                          // 合并：谁在整段出现更多
    return countInRange(nums, lm, l, r) > countInRange(nums, rm, l, r) ? lm : rm;
}

// 对照：Boyer-Moore 投票法，O(n) / O(1)
int majorityElementVote(const vector<int>& nums) {
    int cand = nums[0], cnt = 0;
    for (int v : nums) {
        if (cnt == 0) cand = v;
        cnt += (v == cand) ? 1 : -1;
    }
    return cand;
}

// ------------------------------------------------------------
// 4. 有序数组转平衡 BST（LeetCode 108）
//    每次取中点作根，左右区间递归建子树
//    Time O(n) / Space O(log n)
// ------------------------------------------------------------
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildBST(const vector<int>& nums, int l, int r) {
    if (l > r) return nullptr;                        // Base Case：空区间
    int mid = l + (r - l) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left  = buildBST(nums, l, mid - 1);
    root->right = buildBST(nums, mid + 1, r);
    return root;
}
