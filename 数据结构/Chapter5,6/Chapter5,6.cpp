#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;

// 输出矩阵
void disp(int A[MAX][MAX], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

// 将矩阵压缩存储到一维数组a中
void compression(int A[MAX][MAX], int n, int a[]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            int k = (i * (i + 1)) / 2 + j;
            a[k] = A[i][j];
        }
    }
}

// 获取压缩矩阵中元素的下标
int getk(int i, int j) {
    if (i >= j)
        return (i * (i + 1)) / 2 + j;
    else
        return (j * (j + 1)) / 2 + i;
}

// 矩阵乘法
void Mult(int a[], int b[], int C[MAX][MAX], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int s = 0;
            for (int k = 0; k < n; ++k) {
                // 获取压缩矩阵中的元素位置
                int k1 = getk(i, k);
                int k2 = getk(k, j);
                s += a[k1] * b[k2];
            }
            C[i][j] = s;
        }
    }
}

int main() {
    int n = 3;  // 矩阵大小
    int m = n * (n + 1) / 2;  // 压缩数组的元素数量
    int A[MAX][MAX] = { {1, 2, 3}, {2, 4, 5}, {3, 5, 6} };
    int B[MAX][MAX] = { {2, 1, 3}, {1, 5, 2}, {3, 2, 4} };
    int C[MAX][MAX];  // 用于存储A * B的结果
    int* a = new int[m];  // 存储A的压缩形式
    int* b = new int[m];  // 存储B的压缩形式

    // 输出原始矩阵A
    cout << "A:" << endl;
    disp(A, n);
    cout << "A压缩存储到a中:" << endl;
    compression(A, n, a);
    for (int i = 0; i < m; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    // 输出原始矩阵B
    cout << "B:" << endl;
    disp(B, n);
    cout << "B压缩存储到b中:" << endl;
    compression(B, n, b);
    for (int i = 0; i < m; ++i) {
        cout << b[i] << " ";
    }
    cout << endl;

    // 进行矩阵乘法
    cout << "C = A * B" << endl;
    Mult(a, b, C, n);

    // 输出结果矩阵C
    cout << "C:" << endl;
    disp(C, n);

    // 释放动态分配的内存
    delete[] a;
    delete[] b;

    return 0;
}
