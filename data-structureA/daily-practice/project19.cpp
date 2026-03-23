//顺序表去重
//保持相对顺序不变
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;

    unordered_map<int,bool>mp;
    vector<int>arr;
    for(int i=0;i<n;++i){
        int num;
        cin>>num;
        arr.push_back(num);
        mp[num]=false;
    }

    //mp里面存储了每个元素是否出现过
    vector<int>result;
    for(int i=0;i<n;++i){
        if(!mp[arr[i]]){
            result.push_back(arr[i]);
            mp[arr[i]]=true;
        }
        else{
            continue;
        }
    }

    for(int num:result){
        cout<<num<<" ";
    }

    return 0;
}