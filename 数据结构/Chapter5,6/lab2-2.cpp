/*
【问题描述】将稀疏矩阵进行转置，要求“按位就座”（对矩阵的三元组顺序表扫描一次）

【输入形式】从文件以三元组方式输入稀疏矩阵M

【输出形式】以文件形式输出M的转置矩阵，要求按照三元组形式输出

【要求】“按位就座”即只能对M的三元组顺序表扫描一次，就生成转置矩阵T

【样例输入】测试输入文件in.txt如下：                       

6 7 8

0 1 12

0 2 9

2 0 -3

2 5 14

3 2 24

4 1 18

5 0 15

5 3 -7

【样例输出】 输出到文件abc.out中，如下：

7 6 8

0 2 -3

0 5 15

1 0 12

1 4 18

2 0 9

2 3 24

3 5 -7

5 2 14
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Triple {
    int row;
    int col;
    int value;
};

struct SparseMatrix {
    int rows;//行
    int cols;//列
    int terms;//非零元素数量

    //data中存的都是非零元素
    vector<Triple> data;
};

SparseMatrix fastTranspose(SparseMatrix& M) {
    SparseMatrix T;
    T.rows = M.cols;
    T.cols = M.rows;
    T.terms = M.terms;
    T.data.resize(M.terms);

    vector<int> numCols(M.cols, 0);   // 每列非零元素个数
    vector<int> cpot(M.cols, 0);      // 每列起始位置

    // 统计每列元素个数
    for (int i = 0; i < M.terms; ++i)
        numCols[M.data[i].col]++;

    // 计算每一列第一个非零元素的起始位置
    cpot[0] = 0;
    for (int i = 1; i < M.cols; ++i)
        cpot[i] = cpot[i - 1] + numCols[i - 1];

    // 执行转置
    for (int i = 0; i < M.terms; ++i) {
        //是为了得到元素的相对位置
        int col = M.data[i].col;
        int pos = cpot[col];

        T.data[pos].row = M.data[i].col;  // 行列交换
        T.data[pos].col = M.data[i].row;
        T.data[pos].value = M.data[i].value;
        //虽然每次循环col的值在更新，但如果同一列中有两个以上的非零元素，那么就要更新，为同一列的下一元素预留位置
        //如果不是同一列那么更新的值就作废，也不会产生影响
        cpot[col]++;  
    }

    return T;
}

int main() {
    ifstream in("in.txt");
    ofstream out("abc.out");

    SparseMatrix M;
    in >> M.rows >> M.cols >> M.terms;
    M.data.resize(M.terms);

    //data的大小是非零元素的数量，其顺序是按照行优先
    for (int i = 0; i < M.terms; ++i)
        in >> M.data[i].row >> M.data[i].col >> M.data[i].value;

    SparseMatrix T = fastTranspose(M);

    // 输出转置结果
    out << T.rows << " " << T.cols << " " << T.terms << endl;
    for (auto& t : T.data)
        out << t.row << " " << t.col << " " << t.value << endl;

    in.close();
    out.close();
    return 0;
}