#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int left = 0, right = n - 1, top = 0, bottom = n - 1;
    int num = 1;

    while (left <= right && top <= bottom) {
        // 从左到右填充
        for (int i = left; i <= right; ++i) {
            matrix[top][i] = num++;
        }
        top++;

        // 从上到下填充
        for (int i = top; i <= bottom; ++i) {
            matrix[i][right] = num++;
        }
        right--;

        // 从右到左填充
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                matrix[bottom][i] = num++;
            }
            bottom--;
        }

        // 从下到上填充
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = num++;
            }
            left++;
        }
    }

    return matrix;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "请输入矩阵的大小 n (1 <= n <= 20): ";
    cin >> n;

    if (n < 1 || n > 20) {
        cout << "n 的值必须在 1 到 20 之间！" << endl;
        return 1;
    }

    vector<vector<int>> result = generateMatrix(n);
    printMatrix(result);

    return 0;
}
