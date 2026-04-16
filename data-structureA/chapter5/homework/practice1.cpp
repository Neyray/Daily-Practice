//LeetCode59—螺旋矩阵II
//元素按顺时针顺序螺旋排列，测试数据存放在in.txt文件中
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

vector<vector<int>> generateMatrix(int n){
    vector<vector<int>>matrix(n,vector<int>(n,0));
    int top=0,bottom=n-1,left=0,right=n-1;
    int num=1;
    while(num<=n*n){
        for(int i=left;i<=right && num<=n*n;++i){
            matrix[top][i]=num;
            num++;
        }
        top++;

        for(int i=top;i<=bottom && num<=n*n;++i){
            matrix[i][right]=num;
            num++;
        }
        right--;

        for(int i=right;i>=left && num<=n*n;--i){
            matrix[bottom][i]=num;
            num++;
        }
        bottom--;

        for(int i=bottom;i>=top && num<=n*n;--i){
            matrix[i][left]=num;
            num++;
        }
        left++;
    }

    return matrix;
}

int main(){
    ifstream InFiles("in.txt");
    if(!InFiles){
        cerr<<"error"<<endl;
        return -1;
    }

    int n;
    InFiles>>n;

    vector<vector<int>>matrix=generateMatrix(n);
    //进行输出
    cout<<"["<<endl;
    for(int i=0;i<n;++i){
        cout<<"[";
        for(int j=0;j<n;++j){
            cout<<matrix[i][j];
            if(j<n-1){
                //j不是最后一个元素
                cout<<",";
            }
        }
        cout<<"]";

        if(i<n-1){
            cout<<",";
        }
        cout<<endl;
    }
    cout<<"]";

    return 0;
}