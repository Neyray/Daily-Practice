#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 输出结果
void printResult(const vector<int>& ans) {
    for (int i = 0; i < ans.size(); ++i) {
        if (i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}

// 递归 DFS：邻接矩阵版本
void DFS_recursive(int u, const vector<vector<int>>& matrix, vector<int>& visited, vector<int>& ans) {
    int n = matrix.size();

    visited[u] = 1;
    ans.push_back(u);

    for (int v = 0; v < n; ++v) {
        if (matrix[u][v] == 1 && visited[v] == 0) {
            DFS_recursive(v, matrix, visited, ans);
        }
    }
}

// 非递归 DFS：邻接矩阵版本，严格模拟递归过程
vector<int> DFS_nonrecursive(const vector<vector<int>>& matrix, int start) {
    int n = matrix.size();

    vector<int> visited(n, 0);
    vector<int> ans;
    stack<int> st;

    visited[start] = 1;
    ans.push_back(start);
    st.push(start);

    while (!st.empty()) {
        int u = st.top();

        bool found = false;

        // 按照顶点编号从小到大找邻接点
        for (int v = 0; v < n; ++v) {
            if (matrix[u][v] == 1 && visited[v] == 0) {
                visited[v] = 1;
                ans.push_back(v);
                st.push(v);

                found = true;
                break; // 找到一个就深入
            }
        }

        // 如果没有未访问邻接点，就回退
        if (!found) {
            st.pop();
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    int start;
    cin >> start;

    // 非递归 DFS
    vector<int> ans1 = DFS_nonrecursive(matrix, start);
    printResult(ans1);

    // 递归 DFS
    vector<int> visited(n, 0);
    vector<int> ans2;
    DFS_recursive(start, matrix, visited, ans2);
    printResult(ans2);

    return 0;
}