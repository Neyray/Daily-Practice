//2.判断链串对称性---使用链串设计
#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode{
    char ch;
    ListNode* next;

    ListNode(char c):ch(c),next(NULL){}
};

class StringChain{
private:
    ListNode* head;
public:
    StringChain():head(NULL){}

    void build(const string& s){
        if(s.empty())return;

        //没有哨兵节点
        head=new ListNode(s[0]);
        ListNode* current=head;

        for(size_t i=1;i<s.length();++i){
            current->next=new ListNode(s[i]);
            current=current->next;
        }
    }

    bool isForm(){
        if(head==NULL)return false;
        //处理只有一个@的情况
        if(head->ch=='@' && head->next==NULL)return true;

        //找到@节点
        ListNode* p=head;
        while(p!=NULL && p->ch!='@'){
            p=p->next;
        }
        //如果p是NULL，说明没有@，直接退出
        if(p==NULL)return false;

        ListNode* curr1=head;
        ListNode* curr2=p->next;//curr2是@后面的第一个元素

        //开始比较
        while(curr2!=NULL && curr1!=NULL){
            if(curr1->ch != curr2->ch){
                return false;
            }
            else{
                curr1=curr1->next;
                curr2=curr2->next;
            }
        }
        if(curr1->ch=='@')return true;
        else return false;
    }
};

int main(){
    string s;
    getline(cin,s);

    StringChain chain;
    chain.build(s);

    if(chain.isForm()){
        cout<<"true";
    }
    else{
        cout<<"false";
    }

    return 0;
}