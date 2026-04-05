//判断链表是否有环
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int>val(n+1),nxt(n+1);

    for(int i=1;i<=n;++i){
        cin>>val[i]>>nxt[i];
    }

    int slow=1,fast=1;
    while(true){
        slow=nxt[slow];

        if(nxt[fast]==-1){cout<<"NO";return 0;}
        fast=nxt[fast];

        if(nxt[fast]==-1){cout<<"NO";return 0;}
        fast=nxt[fast];

        if(fast==slow){cout<<"YES";return 0;}
    }
}