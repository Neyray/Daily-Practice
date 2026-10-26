// 单词搜索
// 回溯核心：选择 → 递归 → 撤销选择
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();

    vector<vector<bool>> used(m, vector<bool>(n, false));

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    function<bool(int, int, int)> dfs = [&](int x, int y, int k) {
        if (x < 0 || x >= m || y < 0 || y >= n) return false;

        if (used[x][y] || board[x][y] != word[k]) return false;

        // 只有匹配完才能返回，一直递归到底
        if (k == word.size() - 1) return true;

        used[x][y] = true;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 递归到底之后返回，即自底向上返回
            if (dfs(nx, ny, k + 1)) {
                used[x][y] = false;// 实际上是多此一举，因为这时候已经匹配成功了
                return true;// 匹配成功的结尾
            }
        }

        // 匹配失败，必须将used[x][y]设为未访问！去试别的方向
        used[x][y] = false;
        // 匹配失败的结尾
        return false;
    };


    // 由于所有位置都可能是开始位置，所以必须遍历
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dfs(i, j, 0))
                return true;
        }
    }

    return false;
}