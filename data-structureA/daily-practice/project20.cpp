//顺序表逆置
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>arr;

    for(int i=0;i<n;++i){
        int num;
        cin>>num;
        arr.push_back(num);
    }


    for(int i=0;i<n/2;++i){
        swap(arr[i],arr[n-1-i]);
    }

    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }


    return 0;
}