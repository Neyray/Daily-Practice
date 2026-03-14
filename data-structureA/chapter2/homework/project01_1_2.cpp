/*从数组中找出和为目标值的两个整数，并返回下标*/
#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

vector<int>twoSum(vector<int>& nums,int target){
    int n=nums.size();
    //元素：下标
    unordered_map<int,int>mp;
    for(int i=0;i<n;++i){
        int ans=target-nums[i];
        if(mp.count(ans)){
            return {mp[ans],i};
        }
        //只能放在判断逻辑的后面，因为如果放在前面，就会造成一个数据算两次的情况
        mp[nums[i]]=i;
    }
    return {-1,-1};
}

int main(){
    string line;
    ifstream inFile("in.txt");
    if(!inFile){
        cerr<<"找不到in.txt文件";
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