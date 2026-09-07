// ============================================================
// Topic : Backtracking
// Dir   : Algorithm/backtracking/
//
// 回溯 = 在「搜索树」上做 DFS，本质是暴力枚举 + 剪枝
//
//   void backtrack(路径 path, 选择列表) {
//       if (满足结束条件) { 收集结果; return; }
//       for (选择 : 选择列表) {
//           if (需要剪枝) continue;
//           做选择;              // path.push_back
//           backtrack(...);      // 进入下一层
//           撤销选择;            // path.pop_back —— 和「做选择」严格对称
//       }
//   }
//
// 三个必须想清楚的问题：
//   1. 路径 path 是什么？
//   2. 选择列表怎么表示？（start 下标 / used 数组）
//   3. 结束条件是什么？
//
// 去重两件事（必须同时做）：
//   - 先排序，让相同元素相邻
//   - 同一层内跳过重复值：i > start && nums[i] == nums[i-1]
//     注意是「同一层」重复，不是「同一路径」重复
// ============================================================

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// ------------------------------------------------------------
// 1. 全排列（LeetCode 46，元素互不相同）
//    选择列表 = 所有还没用过的元素，用 used 标记
//    Time O(n · n!) / Space O(n)
// ------------------------------------------------------------
void permuteDfs(const vector<int>& nums, vector<char>& used,
                vector<int>& path, vector<vector<int>>& res) {
    if (path.size() == nums.size()) { res.push_back(path); return; }
    for (int i = 0; i < (int)nums.size(); ++i) {
        if (used[i]) continue;
        used[i] = true;  path.push_back(nums[i]);
        permuteDfs(nums, used, path, res);
        path.pop_back(); used[i] = false;              // 撤销
    }
}

vector<vector<int>> permute(const vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    vector<char> used(nums.size(), false);
    permuteDfs(nums, used, path, res);
    return res;
}

// ------------------------------------------------------------
// 2. 子集（LeetCode 78）
//    每个节点都是一个答案 -> 进入递归就收集，没有额外的结束条件
//    start 保证组合不重复（只往后取）
//    Time O(n · 2^n) / Space O(n)
// ------------------------------------------------------------
void subsetsDfs(const vector<int>& nums, int start,
                vector<int>& path, vector<vector<int>>& res) {
    res.push_back(path);                               // 每个节点都收集
    for (int i = start; i < (int)nums.size(); ++i) {
        path.push_back(nums[i]);
        subsetsDfs(nums, i + 1, path, res);            // i+1：每个元素最多用一次
        path.pop_back();
    }
}

vector<vector<int>> subsets(const vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> path;
    subsetsDfs(nums, 0, path, res);
    return res;
}

// ------------------------------------------------------------
// 3. 组合（LeetCode 77）：从 [1, n] 中选 k 个
//    剪枝：剩余可选个数不足 k - path.size() 时直接停
//    i 的上界 = n - (k - path.size()) + 1
//    Time O(C(n,k) · k) / Space O(k)
// ------------------------------------------------------------
void combineDfs(int n, int k, int start,
                vector<int>& path, vector<vector<int>>& res) {
    if ((int)path.size() == k) { res.push_back(path); return; }
    int need = k - (int)path.size();
    for (int i = start; i <= n - need + 1; ++i) {      // 剪枝就在这个上界里
        path.push_back(i);
        combineDfs(n, k, i + 1, path, res);
        path.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> path;
    combineDfs(n, k, 1, path, res);
    return res;
}

// ------------------------------------------------------------
// 4. 组合总和（LeetCode 39）：元素无重复，但可以重复选
//    重复选 -> 递归时传 i 而不是 i + 1
//    先排序，remain < candidates[i] 时后面更大，直接 break
// ------------------------------------------------------------
void combinationSumDfs(const vector<int>& cand, int start, int remain,
                       vector<int>& path, vector<vector<int>>& res) {
    if (remain == 0) { res.push_back(path); return; }
    for (int i = start; i < (int)cand.size(); ++i) {
        if (cand[i] > remain) break;                   // 排序后的剪枝
        path.push_back(cand[i]);
        combinationSumDfs(cand, i, remain - cand[i], path, res);   // i：可重复选
        path.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> path;
    combinationSumDfs(candidates, 0, target, path, res);
    return res;
}

// ------------------------------------------------------------
// 5. 组合总和 II（LeetCode 40）：元素有重复，每个只能用一次
//    去重关键：i > start && cand[i] == cand[i-1] -> 跳过同一层的重复分支
//    Time O(2^n · n) / Space O(n)
// ------------------------------------------------------------
void combinationSum2Dfs(const vector<int>& cand, int start, int remain,
                        vector<int>& path, vector<vector<int>>& res) {
    if (remain == 0) { res.push_back(path); return; }
    for (int i = start; i < (int)cand.size(); ++i) {
        if (cand[i] > remain) break;
        if (i > start && cand[i] == cand[i - 1]) continue;         // 同层去重
        path.push_back(cand[i]);
        combinationSum2Dfs(cand, i + 1, remain - cand[i], path, res);   // i+1：只用一次
        path.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> path;
    combinationSum2Dfs(candidates, 0, target, path, res);
    return res;
}

// ------------------------------------------------------------
// 6. 分割回文串（LeetCode 131）
//    「分割」也是回溯：枚举本次切下来的子串 s[start..i]
//    Time O(n · 2^n) / Space O(n)
// ------------------------------------------------------------
bool isPalindrome(const string& s, int l, int r) {
    while (l < r) if (s[l++] != s[r--]) return false;
    return true;
}

void partitionDfs(const string& s, int start,
                  vector<string>& path, vector<vector<string>>& res) {
    if (start == (int)s.size()) { res.push_back(path); return; }
    for (int i = start; i < (int)s.size(); ++i) {
        if (!isPalindrome(s, start, i)) continue;      // 不是回文，这个分支剪掉
        path.push_back(s.substr(start, i - start + 1));
        partitionDfs(s, i + 1, path, res);
        path.pop_back();
    }
}

vector<vector<string>> partitionPalindrome(const string& s) {
    vector<vector<string>> res;
    vector<string> path;
    partitionDfs(s, 0, path, res);
    return res;
}

// ------------------------------------------------------------
// 7. 单词搜索（LeetCode 79）：网格 DFS + 回溯
//    用原地改字符当 visited，回来时改回去（省一个 visited 数组）
//    Time O(m·n·3^L) / Space O(L)
// ------------------------------------------------------------
bool existDfs(vector<vector<char>>& board, const string& word, int i, int j, int k) {
    if (i < 0 || i >= (int)board.size() || j < 0 || j >= (int)board[0].size()) return false;
    if (board[i][j] != word[k]) return false;
    if (k == (int)word.size() - 1) return true;        // 最后一个字符也匹配上了

    char tmp = board[i][j];
    board[i][j] = '#';                                 // 做选择：标记已访问
    bool found = existDfs(board, word, i + 1, j, k + 1)
              || existDfs(board, word, i - 1, j, k + 1)
              || existDfs(board, word, i, j + 1, k + 1)
              || existDfs(board, word, i, j - 1, k + 1);
    board[i][j] = tmp;                                 // 撤销选择
    return found;
}

bool exist(vector<vector<char>>& board, const string& word) {
    for (int i = 0; i < (int)board.size(); ++i)
        for (int j = 0; j < (int)board[0].size(); ++j)
            if (existDfs(board, word, i, j, 0)) return true;
    return false;
}

// ------------------------------------------------------------
// 8. N 皇后（LeetCode 51）：逐行放置，列 / 两条对角线各开一个标记数组
//    同一条 "\" 对角线：row - col 为常数（+n 防负下标）
//    同一条 "/" 对角线：row + col 为常数
//    Time O(n!) / Space O(n)
// ------------------------------------------------------------
void solveNQueensDfs(int n, int row, vector<int>& cols,
                     vector<char>& usedCol, vector<char>& diag1, vector<char>& diag2,
                     vector<vector<string>>& res) {
    if (row == n) {                                    // 放满 n 行，构造棋盘
        vector<string> board(n, string(n, '.'));
        for (int r = 0; r < n; ++r) board[r][cols[r]] = 'Q';
        res.push_back(board);
        return;
    }
    for (int col = 0; col < n; ++col) {
        int d1 = row - col + n, d2 = row + col;
        if (usedCol[col] || diag1[d1] || diag2[d2]) continue;   // 剪枝
        cols[row] = col;
        usedCol[col] = diag1[d1] = diag2[d2] = true;
        solveNQueensDfs(n, row + 1, cols, usedCol, diag1, diag2, res);
        usedCol[col] = diag1[d1] = diag2[d2] = false;           // 撤销
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<int>  cols(n, 0);
    vector<char> usedCol(n, false), diag1(2 * n, false), diag2(2 * n, false);
    solveNQueensDfs(n, 0, cols, usedCol, diag1, diag2, res);
    return res;
}
