//1.主对角线元素求和
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;

    //初始化
    vector<vector<int>>matrix(m,vector<int>(n));
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            cin>>matrix[i][j];
        }
    }

    if(m!=n){
        cout<<"false";
        return -1;
    }
    else{
        int sum=0;
        for(int i=0;i<m;++i){
            sum+=matrix[i][i];
            sum+=matrix[i][n-1-i];
        }

        cout<<"true "<<sum;
        return 0;
    }
}