//串的模式匹配
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
            i++;j++;
            next[i]=j;
        }
        else{
            j=next[j];
        }
    }
    return next;
}

int research(string t,string s){
    int n=t.size();
    int m=s.size();

    vector<int>next=kmp(t);
    int ans=0;

    int i=0,j=0;
    while(i<m){
        if(j==-1 || s[i]==t[j]){
            i++;j++;
        }
        else{
            j=next[j];
        }

        if(j==n){
            ans++;
            j=next[j];
        }
    }
    return ans;
}

int main(){
    string t,s;
    cin>>t;
    cin>>s;

    cout<<research(t,s);

    return 0;
}