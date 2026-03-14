/*判断整数是否是回文数列*/
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
using namespace std;

bool isPalindrome(int x){
    if(x<0)return false;
    if(x==0)return true;

    string str=to_string(x);

    int n=str.length();
    int i=0,j=n-1;

    //bool bl;
    while(i<=j){
        if(str[i]!=str[j]){
            return false;
        }
        i++;
        j--;
    }

    return true;
}

int main(){
    int x;
    ifstream inFile("in.txt");
    if(!inFile){
        cerr<<"找不到in.txt文件";
    }

    inFile>>x;

    if(isPalindrome(x)==true){
        cout<<"1";
    }
    else{
        cout<<"0";
    }

    return 0;
}