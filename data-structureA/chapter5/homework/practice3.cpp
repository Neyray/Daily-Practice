//递归输出全排列
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void permute(vector<int>& nums, int start) {
    if (start == nums.size()) {
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0) cout << " ";
            cout << nums[i];
        }
        cout << "\n";
        return;
    }
    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]);
        permute(nums, start + 1);
        swap(nums[start], nums[i]); // 回溯
    }
}

int main() {
    vector<int> nums;
    int x;
    ifstream inFile("in.txt");
    if(!inFile){
        cerr<<"error";
        return -1;
    }

    while (inFile >> x) nums.push_back(x);
    permute(nums, 0);
    return 0;
}