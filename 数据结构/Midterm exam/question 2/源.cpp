/*【问题描述】

有两个集合采用递增有序的整数单链表A、B存储，设计一个算法求两个集合交集C，C仍然用单链表存储，且递减有序。

【输入形式】

分别输入两行整数，每行整数以空格分隔，每行整数依次表示单链表 A 和单链表 B 的元素值，以输入结束符作为每行输入的结束标志。

【输出形式】

输出一行整数，这些整数为两个集合交集构成的单链表的元素值，元素之间以空格分隔。若没有交集，输出error

【样例输入1】

1 2 3

1 2 4 5

【样例输出1】

2 1

【样例输入2】

1 2 3

4 5

【样例输出2】

error

【类库使用要求】

不可以使用STL库函数，可以使用字符串STL处理输入。*/

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// 定义单链表节点
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// 单链表插入操作（头插法）
void insert(Node*& head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

// 打印链表
void printList(Node* head) {
    if (!head) {
        cout << "error" << endl;
        return;
    }
    Node* temp = head;
    //保证空格排列正确
    bool first = true;
    while (temp) {
        if (first) {
            cout << temp->data;
            first = false;
        }
        else {
            cout << " " << temp->data;
        }
        temp = temp->next;
    }
    cout << endl;
}

// 释放链表内存
void deleteList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// 从字符串构造单链表
Node* createListFromString(const string& str) {
    Node* head = nullptr;
    istringstream iss(str);
    int num;
    while (iss >> num) {
        // 为了保证递增排序
        if (!head || head->data >= num) {
            insert(head, num);
        }
        else {
            Node* temp = head;
            while (temp->next && temp->next->data < num) {
                temp = temp->next;
            }
            Node* newNode = new Node(num);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    return head;
}

// 求两个有序链表的交集
Node* getIntersection(Node* headA, Node* headB) {
    Node* intersectionHead = nullptr;
    while (headA && headB) {
        if (headA->data == headB->data) {
            if (!intersectionHead || intersectionHead->data != headA->data)
                //调用函数
                insert(intersectionHead, headA->data); // 插入到交集链表
            headA = headA->next;
            headB = headB->next;
        }
        else if (headA->data < headB->data) {
            headA = headA->next;
        }
        else {
            headB = headB->next;
        }
    }
    return intersectionHead;
}

int main() {
    string lineA, lineB;
    // 读取输入
    getline(cin, lineA);
    getline(cin, lineB);

    // 创建链表A和链表B
    Node* listA = createListFromString(lineA);
    Node* listB = createListFromString(lineB);

    // 获取交集链表
    Node* intersectionList = getIntersection(listA, listB);

    // 输出交集链表
    printList(intersectionList);

    // 释放内存
    deleteList(listA);
    deleteList(listB);
    deleteList(intersectionList);

    return 0;
}

