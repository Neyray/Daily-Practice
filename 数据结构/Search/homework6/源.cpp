/*【问题描述】

有一个含n（n<=200000）个整数的无序序列，采用链表的二路归并排序实现递增排序

【输入形式】

一行字符串，包含多个整数，每个数之间用空格分开。

【输出形式】

递增排序的结果，每个数之间用空格分开。

【样例输入】

9 4 7 6 2 5 8 1 3

【样例输出】

1 2 3 4 5 6 7 8 9

【样例说明】

测试数据的文件名为in.txt，输出文件名为out.txt

【评分标准】

该题目有10个测试用例，每通过一个测试用例得10分 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};

// 合并两个有序链表
Node* merge(Node* l1, Node* l2) {
    Node dummy(0);
    Node* tail = &dummy;
    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            //更新位置
            l1 = l1->next;
        }
        else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

// 链表归并排序
Node* mergeSort(Node* head) {
    if (!head || !head->next)
        return head;

    // 快慢指针找中点
    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* mid = slow->next;
    slow->next = nullptr;  // 断开链表

    Node* left = mergeSort(head);
    Node* right = mergeSort(mid);
    return merge(left, right);
}

int main() {
    // 读取输入文件
    ifstream inFile("in.txt");
    if (!inFile) {
        cerr << "无法打开输入文件 in.txt" << endl;
        return 1;
    }

    string line;
    getline(inFile, line);
    inFile.close();

    stringstream ss(line);
    int num;
    Node* head = nullptr;
    Node* tail = nullptr;

    // 构建链表
    while (ss >> num) {
        Node* newNode = new Node(num);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // 链表排序
    if (head) {
        head = mergeSort(head);
    }

    // 写入输出文件
    ofstream outFile("out.txt");
    if (!outFile) {
        cerr << "无法创建输出文件 out.txt" << endl;
        return 1;
    }

    Node* curr = head;
    while (curr) {
        outFile << curr->val;
        if (curr->next)
            outFile << " ";
        curr = curr->next;
    }
    outFile.close();

    // 释放链表内存
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}