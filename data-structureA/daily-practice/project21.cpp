//有序顺序表合并
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    vector<int>arr1,arr2;

    for(int i=0;i<m;++i){
        int num;
        cin>>num;
        arr1.push_back(num);
    }

    for(int j=0;j<n;++j){
        int num;
        cin>>num;
        arr2.push_back(num);
    }

    vector<int>result;
    int curr1=0,curr2=0;
    while(curr1<arr1.size() && curr2<arr2.size()){
        if(arr1[curr1]<=arr2[curr2]){
            result.push_back(arr1[curr1]);
            curr1++;
        }
        else{
            result.push_back(arr2[curr2]);
            curr2++;
        }
    }

    while(curr1<arr1.size()){
        result.push_back(arr1[curr1]);
        curr1++;
    }
    while(curr2<arr2.size()){
        result.push_back(arr2[curr2]);
        curr2++;
    }

    for(int num:result){
        cout<<num<<" ";
    }

    return 0;
}