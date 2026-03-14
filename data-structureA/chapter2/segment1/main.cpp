#include <iostream>
#include "SqList.h"

// 包含模板函数的源文件以便编译器实例化
#include "deleteX.cpp"
#include "merge.cpp"
#include "move.cpp"

using namespace std;

int main() {
    cout << "========== 1. 测试基础与 deleteX ==========" << endl;
    SqList<int> L1;
    L1.add(1); L1.add(2); L1.add(3); L1.add(2); L1.add(4); L1.add(2);
    
    cout << "原始顺序表 L1: ";
    L1.display(); cout << endl;

    deletex2(L1, 2); // 使用修改后的 deletex2
    cout << "删除所有 2 之后: ";
    L1.display(); cout << endl;

    cout << "\n========== 2. 测试 moveX (基准划分) ==========" << endl;
    SqList<int> L2;
    // 构造一个无序表: 5 8 1 2 9 3
    L2.add(5); L2.add(8); L2.add(1); L2.add(2); L2.add(9); L2.add(3);
    
    cout << "原始顺序表 L2: ";
    L2.display(); cout << endl;
    
    moveX2(L2); // 使用修改后的双指针划分
    cout << "以首元素(5)为基准划分后: ";
    L2.display(); cout << endl;

    cout << "\n========== 3. 测试 merge (合并有序表) ==========" << endl;
    SqList<int> A, B, C;
    A.add(1); A.add(3); A.add(5); A.add(8);
    B.add(2); B.add(3); B.add(8); B.add(10); B.add(11);
    
    cout << "有序表 A: "; A.display(); cout << endl;
    cout << "有序表 B: "; B.display(); cout << endl;
    
    merge(A, B, C);
    cout << "合并后的表 C: ";
    C.display(); cout << endl;

    return 0;
}