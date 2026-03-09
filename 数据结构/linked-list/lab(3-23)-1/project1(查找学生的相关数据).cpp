#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_set>
using namespace std;

//链表
struct LinkNode_SC {
    string Sno, Cno;
    int grade;
    LinkNode_SC* next;
    LinkNode_SC() :Sno(""), Cno(""), grade(0), next(NULL) {}
    LinkNode_SC(string s, string c, int g) :Sno(s), Cno(c), grade(g), next(NULL) {}
};

class Linklist_SC {
public:
    LinkNode_SC* head;
    Linklist_SC() {
        head = new LinkNode_SC();
    }
    ~Linklist_SC() {
        LinkNode_SC* pre, * p;
        pre = head;
        p = pre->next;
        while (p != NULL) {
            delete pre;
            pre = p;
            p = pre->next;
        }
        delete pre;
    }

    void insert(string sno, string cno, int grade) {
        LinkNode_SC* node = new LinkNode_SC(sno, cno, grade);
        //头插法
        /*node->next = head->next;
        head->next = node;*/

        //尾插法
        if (head->next == NULL) {
            head->next = node;
        }
        else {
            LinkNode_SC* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = node;
        }
    }
};

struct LinkNode_Stu {
    string sno, sname;
    int age;
    LinkNode_Stu* next;
    LinkNode_Stu() :sno(""), sname(""), age(0), next(NULL) {}
    LinkNode_Stu(string sno, string sname, int age) :sno(sno), sname(sname), age(age), next(NULL) {}
};

class Linklist_Stu {
public:
    LinkNode_Stu* head;
    Linklist_Stu() {
        head = new LinkNode_Stu();
    }
    ~Linklist_Stu() {
        LinkNode_Stu* pre, * p;
        pre = head;
        p = pre->next;
        while (p != NULL) {
            delete pre;
            pre = p;
            p = pre->next;
        }
        delete pre;
    }

    void insert(string sno, string sname, int age) {
        LinkNode_Stu* node = new LinkNode_Stu(sno, sname, age);
        //头插法
        /*node->next = head->next;
        head->next = node;*/
        //尾插法
        if (head->next == NULL) {
            head->next = node;
        }
        else {
            LinkNode_Stu* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = node;
        }
    }

    // 用学生姓名查找学号并存入哈希集合
    void findSnoByName(string name, unordered_set<string>& result) {
        LinkNode_Stu* p = head->next;
        while (p) {
            if (p->sname == name) {
                result.insert(p->sno);  // 使用集合避免重复
            }
            p = p->next;
        }
    }
};

int main() {
    ifstream inFiles("in.txt");
    if (!inFiles) {
        cerr << "无法打开文件 in.txt" << endl;
        return 1;
    }

    Linklist_SC scList;
    Linklist_Stu stuList;

    // 读取选课信息表
    int m;
    inFiles >> m;
    for (int i = 0; i < m; ++i) {
        string sno, cno;
        int grade;
        inFiles >> sno >> cno >> grade;
        scList.insert(sno, cno, grade);
    }

    // 读取学生信息表
    int n;
    inFiles >> n;
    for (int i = 0; i < n; ++i) {
        string sno, sname;
        int age;
        inFiles >> sno >> sname >> age;
        stuList.insert(sno, sname, age);
    }

    inFiles.close();

    string name;
    cin >> name;

    unordered_set<string> targetSnos;
    //把学生ID存入results容器中
    stuList.findSnoByName(name, targetSnos);

    if (targetSnos.empty()) {
        cerr << "找不到该生的相关信息" << endl;
        return 0;
    }

    // 查找选课记录
    LinkNode_SC* p = scList.head->next;
    bool found = false;
    while (p) {
        if (targetSnos.find(p->Sno) != targetSnos.end()) {  // 使用集合查找，O(1)
            cout << p->Sno << " " << name << " " << p->Cno << " " << p->grade << endl;
            found = true;
        }
        p = p->next;
    }

    if (!found) {
        cout << "没有找到相关选课信息" << endl;
    }

    return 0;
}
