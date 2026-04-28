#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

struct BTNode {
    char data;
    BTNode* lchild;
    BTNode* rchild;

    BTNode() : lchild(NULL), rchild(NULL) {}
    BTNode(char ch) : data(ch), lchild(NULL), rchild(NULL) {}
};

// 将 r 改为指针的引用 (BTNode*& r)，这样才能把构造好的根节点传回给调用者
// 将 str 改为 const string&，避免字符串复制开销
void createBTree(BTNode*& r, const string& str) {
    stack<BTNode*> st;
    BTNode* p = NULL;    // 初始化指针
    bool flag = true;    // 初始化标志位 (true代表左孩子，false代表右孩子)
    int i = 0;

    r = NULL; // 确保传入的根节点初始为空

    while (i < str.length()) {
        switch (str[i]) {
            case '(':
                st.push(p);      // p 成为接下来的子节点的父节点
                flag = true;     // 遇到 '(' 后，接下来的节点一定是左孩子
                break;
            case ')':
                st.pop();        // 栈顶节点的子树处理完毕，出栈
                break;
            case ',':
                flag = false;    // 遇到 ','，说明接下来的节点是栈顶节点的右孩子
                break;
            case ' ':            // 建议补充：忽略字符串中可能存在的空格
                break;
            default:
                p = new BTNode(str[i]); // 创建新节点
                if (r == NULL) {
                    r = p;       // 如果是第一个节点，将其作为根节点
                } else {
                    if (flag && !st.empty()) {
                        st.top()->lchild = p; // 作为栈顶节点的左孩子
                    } else if (!flag && !st.empty()) { // 加上 !flag 更严谨
                        st.top()->rchild = p; // 作为栈顶节点的右孩子
                    }
                }
                break;
        }
        i++;
    }
}

BTNode* FindNode(BTNode* b,char x){
    BTNode* p;
    if(b==NULL)return NULL;
    else if(b->data==x)return b;
    else{
        //在左子树查找
        p=FindNode(b->lchild,x);
        //找到了
        if(p!=NULL)return p;
        //返回在右子树查找的结果
        else return FindNode(b->rchild,x);
    }
}


int Height(BTNode* r){
    if(r==NULL)return 0;
    else{
        return max(Height(r->lchild),Height(r->rchild))+1;
    }
}

void DestoryBTree(BTNode* r){
    if(r!=NULL){
        DestoryBTree(r->lchild);
        DestoryBTree(r->rchild);
        delete r;
    }
}

