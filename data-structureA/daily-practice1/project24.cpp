//单链表基本操作-创建插入删除遍历

//需要前驱节点 → 从 head 出发；只需要节点本身 → 从 head->next 出发
//不要忘记自增节点！！！

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node() : data(0), next(NULL) {}
    Node(int d) : data(d), next(NULL) {}
};

class LinkList {
public:
    Node* head;

    LinkList() {
        head = new Node();
    }

    //实际上没有必要写成Node*格式，因为就是在修改head指针
    void createList(int n) {
        Node* p = head;
        for (int i = 1; i <= n; ++i) {
            Node* s = new Node(i);
            p->next = s;
            p = s;
        }
        p->next = NULL;
        //return head;
    }

    //！！！
    //对于正序插入、删除等需要前驱节点的操作，p要从head头节点开始遍历，不然第一个元素的前驱在哪呢？
    //！！！
    void insert(int k, int x) {
        Node* p = head;   // 从哑节点出发
        int cnt = 0;
        while (p->next != NULL && cnt < k - 1) {
            //临界条件是到第k-2个元素，进行移位后为第k-1个元素
            p = p->next;
            cnt++;
        }
        // 此时p是第k-1个节点（或链表末尾）
        Node* s = new Node(x);
        s->next = p->next;
        p->next = s;
    }

    void deleteElem(int k) {
        Node* p = head;   // 从哑节点出发
        int cnt = 0;
        while (p->next != NULL && cnt < k - 1) {
            p = p->next;
            cnt++;
        }
        if (p->next == NULL) return;  // 第k个节点不存在
        Node* q = p->next;
        p->next = q->next;
        delete q;
    }

    void print() {
        if (head->next == NULL) {
            cout << "EMPTY" << endl;
            return;
        }
        Node* p = head->next;
        while (p != NULL) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
};

int main() {
    int m;
    cin >> m;
    cin.ignore();

    LinkList lst;

    for (int i = 0; i < m; ++i) {
        string str;
        getline(cin, str);
        stringstream ss(str);
        string token;

        //建立一个数组来存储数据，不然遇到数字分不清是创建还是删除
        vector<string> input;
        while (getline(ss, token, ' ')) {

            //死记下来！！！
            //\r 导致 input[0] 变成 "CREATE\r"，匹配不上任何条件
            //！！！

            //去除/r
            if (!token.empty() && token.back() == '\r')
                token.pop_back();
            //跳过空token
            if (token.empty()) continue;

            input.push_back(token);
        }

        if (input.empty()) continue;  // 防止空行崩溃

        //读完这一行之后开始进行处理
        if (input[0] == "CREATE") {
            lst.createList(stoi(input[1]));
        }
        else if (input[0] == "INSERT") {
            lst.insert(stoi(input[1]), stoi(input[2]));
        }
        else if (input[0] == "DELETE") {
            lst.deleteElem(stoi(input[1]));
        }
        else if (input[0] == "PRINT") {
            lst.print();
        }
    }

    return 0;
}