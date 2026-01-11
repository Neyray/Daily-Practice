// lab10_1.cpp
// 使用deque重新实现实验9中的链表操作
#include <iostream>
#include <deque>
using namespace std;

int main() {
    // 创建两个deque容器，模拟链表A和B
    deque<int> A, B;

    // 向A中插入5个元素
    cout << "向链表A插入5个元素: ";
    for (int i = 1; i <= 5; i++) {
        A.push_back(i * 10);  // 插入10, 20, 30, 40, 50
        cout << i * 10 << " ";
    }
    cout << endl;

    // 向B中插入5个元素
    cout << "向链表B插入5个元素: ";
    for (int i = 6; i <= 10; i++) {
        B.push_back(i * 10);  // 插入60, 70, 80, 90, 100
        cout << i * 10 << " ";
    }
    cout << endl;

    // 将B中的元素加入到A的尾部
    cout << "将B中的元素加入到A的尾部..." << endl;
    A.insert(A.end(), B.begin(), B.end());

    // 显示合并后的A
    cout << "合并后的链表A: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    // 演示deque的其他操作（push_back, empty, pop_front）
    cout << "\n演示deque的其他操作:" << endl;

    // 检查是否为空
    if (!A.empty()) {
        cout << "deque A不为空，当前有" << A.size() << "个元素" << endl;
    }

    // 使用pop_front移除第一个元素
    cout << "移除第一个元素: " << A.front() << endl;
    A.pop_front();

    cout << "移除后A的第一个元素: " << A.front() << endl;
    cout << "移除后A的最后一个元素: " << A.back() << endl;

    // 使用push_back添加新元素
    A.push_back(110);
    cout << "添加新元素110后A的最后一个元素: " << A.back() << endl;

    // 显示最终结果
    cout << "\n最终A中的所有元素: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}