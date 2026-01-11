/*【问题描述】

 使用动态内存分配生成动态数组，从键盘输入一个n*n矩阵，每次输入一行，使用指针实现函数的功能。

【输入形式】

 先输入n的值，再输入矩阵的第一行、第二行......

【输出形式】

 分别显示转置前和转置后的矩阵。
【样例输入】

 3

 1 2 3

 4 5 6

 7 8 9
【样例输出】

 

 1 2 3

 4 5 6

 7 8 9



 1 4 7

 2 5 8

 3 6 9
【样例说明】

元素之间用空格隔开
*/
#include <iostream>
using namespace std;

// 函数声明
void inputMatrix(int** matrix, int n);
void printMatrix(int** matrix, int n);
void transposeMatrix(int** matrix, int n);

int main() {
	int n;
	cin >> n;

	int** matrix = new int*[n];
	for (int i = 0; i < n; ++i) {
		matrix[i] = new int[n];
	}
	inputMatrix(matrix, n);

	printMatrix(matrix, n);
	//cout << endl;

	transposeMatrix(matrix, n);
	printMatrix(matrix, n);

	for (int i = 0; i < n; ++i) {
		delete[]matrix[i];
	}
	delete[]matrix;
	return 0;
}

void inputMatrix(int** matrix, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> *(*(matrix + i) + j);
		}
	}
}

void printMatrix(int** matrix, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << *(*(matrix + i) + j) << " ";
		}
		cout << endl;
	}
}

void transposeMatrix(int** matrix, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {  // 只遍历上三角部分
			swap(*(*(matrix + i) + j), *(*(matrix + j) + i));
		}
	}
}

