//查找---拉链法实现哈希表
//哈希表用拉链法后，结构不是一条总链表，而是很多个桶，每个桶后面挂一条链表
#include <iostream>
using namespace std;

const int M = 13;   // 哈希表长度，题目样例下取13可以保证无冲突

struct Node {
    int key;
    int value;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        next = NULL;
    }
};

class HashTable2 {
private:
    Node* table[M];
    int count;  // 哈希表中元素个数

public:
    HashTable2() {
        for (int i = 0; i < M; i++) {
            table[i] = NULL;
        }
        count = 0;
    }

    //hash(key) 的作用是决定这个关键字放到哪个桶里。
    int hash(int key) {
        return key % M;
    }

    void insert(int key, int value) {
        int index = hash(key);

        Node* newNode = new Node(key, value);

        // 头插法插入到对应链表
        newNode->next = table[index];
        table[index] = newNode;

        count++;
    }

    int ASL1() {
        if (count == 0) {
            return 0;
        }

        int sum = 0;

        for (int i = 0; i < M; i++) {
            Node* p = table[i];
            int pos = 1;

            while (p != NULL) {
                sum += pos;
                pos++;
                p = p->next;
            }
        }

        return sum / count;  // 向下取整
    }
};

int main() {
    int n;
    cin >> n;

    HashTable2 ht;

    for (int i = 0; i < n; i++) {
        int key, value;
        cin >> key >> value;
        ht.insert(key, value);
    }

    cout << ht.ASL1();

    return 0;
}