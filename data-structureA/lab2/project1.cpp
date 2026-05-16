//约瑟夫序列，使用循环链表
//这道题需要特别注意head,tail的更新问题
//根本不需要管curr的位置，只需要每次循环m-1次就行了，大循环n次
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Node {
	int num;
	Node* next;

	Node() :num(0), next(NULL) {}
	Node(int n) :num(n), next(NULL) {}
};

class ClinkList {
public:
    Node* head;   // 指向第一个人，不是哨兵节点
    Node* tail;   // 指向最后一个人，方便尾插

    ClinkList() {
        //初始化选择NULL方便后面进行判断
        head = NULL;
        tail = NULL;
    }

    ~ClinkList() {
        if (head == NULL) return;

        Node* p = head->next;
        while (p != head) {
            Node* q = p->next;
            delete p;
            p = q;
        }

        delete head;
        head = NULL;
        tail = NULL;
    }

    void push(int n) {
        Node* curr = new Node(n);

        // 如果链表为空
        if (head == NULL) {
            head = curr;
            tail = curr;
            curr->next = curr;   // 自己指向自己，构成循环
        }
        else {
            tail->next = curr;
            curr->next = head;

            tail = curr;//更新tail的位置
        }
    }

    //关键是要更新head,tail的位置
    void Joseff(int m) {
        //数到m的人出列
        if (head == NULL || m <= 0)return;

        //curr和prev在循环外定义
        Node* curr = head;
        Node* prev = tail;

        //一直循环直到只有一个元素
        while (curr->next != curr) {
            for (int i = 1; i < m; ++i) {
                prev = curr;
                curr = curr->next;
            }
            //curr指向需要出队的人
            cout << curr->num << " ";

            prev->next = curr->next;//改变链表指向

            if (curr == head) {
                head = curr->next;
            }
            if (curr == tail) {
                tail = prev;
            }

            Node* del = curr;
            curr = curr->next;
            delete del;
        }
        //还剩下一个人
        cout << curr->num;

        //删除节点
        delete curr;
        head = NULL;
        tail = NULL;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    ClinkList cl;
    for (int i = 0; i < n; ++i) {
        cl.push(i + 1);
    }

    cl.Joseff(m);

    return 0;
}