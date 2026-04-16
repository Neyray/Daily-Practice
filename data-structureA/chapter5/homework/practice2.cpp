//n皇后问题，两个皇后不能在同一行+同一列+斜线
//col[c]：第 c 列是否被占用
//diag1[row-c+n-1]：左上,右下对角线是否被占用（同一对角线 row-c 相同）
//diag2[row+c]：右上,左下对角线是否被占用（同一对角线 row+c 相同）
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int n, ans = 0;
vector<int> col, diag1, diag2;

void dfs(int row) {
    if (row == n) { ans++; return; }
    for (int c = 0; c < n; c++) {
        if (col[c] || diag1[row - c + n - 1] || diag2[row + c]) continue;
        col[c] = diag1[row - c + n - 1] = diag2[row + c] = 1;
        dfs(row + 1);
        col[c] = diag1[row - c + n - 1] = diag2[row + c] = 0;
    }
}

int main() {
    ifstream inFile("in.txt");
    inFile>>n;
    //cin >> n;
    col.assign(n, 0);
    diag1.assign(2 * n - 1, 0);
    diag2.assign(2 * n - 1, 0);
    dfs(0);
    cout << ans << endl;
}