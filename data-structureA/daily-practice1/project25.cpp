//查找倒数第k个节点
//倒数第k，也就是正数第n-k（从0开始编号）
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

    //cout<<cnt;

    /*访问倒数第cnt个元素时，循环条件 ans < 0 在 ans = -1 时就已经满足，但此时 a = head（哑节点,NULL），a->next
     才是第一个节点,循环一次都不执行，直接输出 head->data，而 head 是哑节点，data = 0，结果错误
    
    int ans=-1;
    Node* a=head;
    while(a!=NULL && ans<cnt-k){
        ans++;
        a=a->next;
    }
    */
    
    int ans=0;
    Node* a=head->next;
    while(a!=NULL && ans<cnt-k){
        ans++;
        a=a->next;
    }

    if(a!=NULL){
        cout<<a->data;
        return 0;
    }
}