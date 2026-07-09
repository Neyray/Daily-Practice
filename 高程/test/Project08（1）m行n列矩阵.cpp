#include <iostream>
using namespace std;

// 函数声明
void inputMatrix(int** matrix, int m, int n);
void printMatrix(int** matrix, int m, int n);
int** transposeMatrix(int** matrix, int m, int n);

int main() {
    int m, n;  // 行数和列数
    cout << "请输入矩阵的行数和列数: ";
    cin >> m >> n;

    // 分配原矩阵内存
    int** matrix = new int* [m];
    for (int i = 0; i < m; ++i) {
        matrix[i] = new int[n];
    }

    // 输入矩阵
    cout << "请输入" << m << "行" << n << "列的矩阵:" << endl;
    inputMatrix(matrix, m, n);

    // 输出原矩阵
    cout << "\n原矩阵:" << endl;
    printMatrix(matrix, m, n);

    // 转置矩阵
    int** transposed = transposeMatrix(matrix, m, n);

    // 输出转置矩阵
    cout << "\n转置矩阵:" << endl;
    printMatrix(transposed, n, m);

    // 释放内存
    for (int i = 0; i < m; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    for (int i = 0; i < n; ++i) {
        delete[] transposed[i];
    }
    delete[] transposed;

    return 0;
}

void inputMatrix(int** matrix, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];  // 使用数组下标形式，更清晰
        }
    }
}

void printMatrix(int** matrix, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";  // 使用数组下标形式
        }
        cout << endl;
    }
}

int** transposeMatrix(int** matrix, int m, int n) {
    // 创建转置矩阵，维度为 n×m
    int** transposed = new int* [n];
    for (int i = 0; i < n; ++i) {
        transposed[i] = new int[m];
    }

    // 进行转置
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }

    return transposed;
}