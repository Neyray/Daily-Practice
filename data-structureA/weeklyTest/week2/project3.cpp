//杨辉三角
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> function(int n) {
    vector<vector<int>> ans(n+1, vector<int>(n+1, 0));
    ans[0][0] = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                ans[i][j] = 1;
            }
            else {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> ans = function(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}