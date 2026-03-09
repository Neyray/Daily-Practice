//对一个含n（n<=20000）个整数的递增有序表进行折半查找，输出查找成功或失败，并输出每次的查找序列
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    // 打开输入输出文件
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    int target;
    string line;
    vector<int> nums;

    // 读取需要查找的数
    getline(fin, line);
    stringstream ss1(line);
    ss1 >> target;

    // 读取有序表
    getline(fin, line);
    stringstream ss2(line);
    int num;
    while (ss2 >> num) {
        nums.push_back(num);
    }

    vector<int> seq; // 存储查找序列
    int left = 0, right = nums.size() - 1;
    bool found = false;

    // 折半查找
    while (left <= right) {
        int mid = left + (right - left) / 2;
        seq.push_back(nums[mid]); // 记录本次查找的数
        if (nums[mid] == target) {
            found = true;
            break;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    // 输出查找结果
    fout << (found ? "True" : "False") << endl;
    // 输出查找序列
    for (size_t i = 0; i < seq.size(); ++i) {
        if (i > 0) fout << " ";
        fout << seq[i];
    }
    fout << endl;

    fin.close();
    fout.close();
    return 0;
}