#include <iostream>
using namespace std;

// 函数声明
void inputMatrix(int** matrix, int m, int n);
void printMatrix(int** matrix, int m, int n);
int** transposeMatrix(int** matrix, int m, int n);
int** multiplyMatrix(int** matrix1, int m, int n, int** matrix2, int p);

int main() {
    int m, n, p;

    cout << "请输入第一个矩阵的行数和列数: ";
    cin >> m >> n;

    // 分配第一个矩阵内存
    int** matrix1 = new int* [m];
    for (int i = 0; i < m; ++i) {
        matrix1[i] = new int[n];
    }

    // 输入第一个矩阵
    cout << "请输入" << m << "行" << n << "列的第一个矩阵:" << endl;
    inputMatrix(matrix1, m, n);

    cout << "\n请输入第二个矩阵的列数: ";
    cin >> p;

    // 分配第二个矩阵内存 (n行p列)
    int** matrix2 = new int* [n];
    for (int i = 0; i < n; ++i) {
        matrix2[i] = new int[p];
    }

    
    inputMatrix(matrix2, n, p);

  
    printMatrix(matrix1, m, n);


    printMatrix(matrix2, n, p);

    // 矩阵乘法
    int** result = multiplyMatrix(matrix1, m, n, matrix2, p);

    // 输出结果矩阵

    printMatrix(result, m, p);

    // 释放内存
    for (int i = 0; i < m; ++i) {
        delete[] matrix1[i];
    }
    delete[] matrix1;

    for (int i = 0; i < n; ++i) {
        delete[] matrix2[i];
    }
    delete[] matrix2;

    for (int i = 0; i < m; ++i) {
        delete[] result[i];
    }
    delete[] result;

    return 0;
}

void inputMatrix(int** matrix, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int** matrix, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << " ";
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

int** multiplyMatrix(int** matrix1, int m, int n, int** matrix2, int p) {
    // 创建结果矩阵，维度为 m×p
    int** result = new int* [m];
    for (int i = 0; i < m; ++i) {
        result[i] = new int[p];
    }

    // 矩阵乘法: result[i][j] = sum(matrix1[i][k] * matrix2[k][j])
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            result[i][j] = 0;  // 初始化为0
            for (int k = 0; k < n; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}