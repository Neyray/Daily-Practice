/*从数组中找出和为目标值的两个整数，并返回下标*/
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

vector<int> twoSum(vector<int>& nums,int target){
    int l=nums.size();
    vector<int>result;

    for(int i=0;i<l;++i){
        for(int j=i+1;j<l;++j){
            if(nums[i]+nums[j]==target){
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }

    return {-1,-1};
    
}

int main(){
    string line;
    ifstream inFile("in.txt");
    if(!inFile){
        cerr<<"找不到in.txt文件!";
    }

    getline(inFile,line);

    stringstream ss(line);
    int num;
    vector<int>nums;
    while(ss>>num){
        nums.push_back(num);
    }

    int target;
    inFile>>target;

    vector<int>result=twoSum(nums,target);

    cout<<result[0]<<" "<<result[1];

    return 0;
}