//日志错误类型定位
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> kmp(string str){
    int n=str.size();
    vector<int>next(n+1);
    next[0]=-1;

    int i=0,j=-1;
    while(i<n){
        if(j==-1 || str[i]==str[j]){
            i++;
            j++;
            next[i]=j;
        }
        else{
            j=next[j];
        }
    }
    return next;
}

int research(string s,string t){
    int m=s.size();
    int n=t.size();

    vector<int>next=kmp(t);
    vector<int>ans;

    int i=0,j=0;
    while(i<m){
        //不要忘记考虑模式串从头开始匹配的情况！！！
        if(j==-1 || s[i]==t[j]){
            i++;
            j++;
        }
        else{
            j=next[j];
        }

        if(j==n){
            //从1开始计数，而不是下标
            ans.push_back(i-n+1);
        }
    }

    int length=ans.size();
    return ans[length-1];
}

int main(){
    string s,t;
    cin>>s;
    cin>>t;

    cout<<research(s,t);

    return 0;
}