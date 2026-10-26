// N皇后
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;


vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));

    vector<bool> colUsed(n, false);
    vector<bool> diag1(2 * n - 1, false);
    vector<bool> diag2(2 * n - 1, false);

    function<void(int)> dfs = [&](int row) {
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            int d1 = row - col + n - 1;
            int d2 = row + col;

            if (colUsed[col] || diag1[d1] || diag2[d2])
                continue;

            // 选择：放置皇后
            board[row][col] = 'Q';
            colUsed[col] = true;
            diag1[d1] = true;
            diag2[d2] = true;

            // 递归：处理下一行
            dfs(row + 1);

            // 回溯：撤销选择
            board[row][col] = '.';
            colUsed[col] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    };

    dfs(0);
    return ans;
}