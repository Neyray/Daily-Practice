//查找倒数第k个节点
//必须手动实现链表结构。要求使用双指针法（快慢指针），只遍历链表一次。
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node():data(0),next(NULL){}
    Node(int d):data(d),next(NULL){}
};

int main(){
    int k;
    cin>>k;
    cin.ignore();

    string str;
    getline(cin,str);
    stringstream ss(str);

    Node* head=new Node();
    Node* p=head;

    string token;
    int cnt=0;
    //创建链表
    while(getline(ss,token,' ')){
        if(token=="-1")break;
        else{
            cnt++;
            Node* s=new Node(stoi(token));
            p->next=s;
            p=s;
        }
    }
    p->next=NULL;

    //查找倒数第k个元素
    if(k>cnt){
        cout<<"-1";
        return 0;
    }

    Node* fast=head->next;
    Node* slow=head->next;

    int count=0;
    //让fast先走k步
    while(fast!=NULL && count<k){
        fast=fast->next;
        count++;      //一定不要忘记自增Count！！！
    }

    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
    }

    cout<<slow->data;

    return 0;
}