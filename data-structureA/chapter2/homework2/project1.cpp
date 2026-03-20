//根据K1，K2值将顺序表划分为三个部分
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> diverse(vector<int>& arr,int k1,int k2){
    int n=arr.size();
    //首先从左到右将小于k1的值放在左边
    int i=0;
    for(int j=0;j<n;++j){
        if(arr[j]<k1){
            swap(arr[j],arr[i]);
            i++;
        }
    }
    //这时的i-1是最后一个小于k1的元素

    int m=n-1;
    for(int k=n-1;k>=i;--k){
        if(arr[k]>=k2){
            swap(arr[k],arr[m]);
            m--;
        }
    }
    //这时的m+1是最后一个大于等于k2元素
    return {i-1,m+1};
}

int main(){
    int k1,k2;
    cin>>k1>>k2;

    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }

    vector<int>result=diverse(arr,k1,k2);
    cout<<result[0]<<" "<<result[1];

    return 0;
}