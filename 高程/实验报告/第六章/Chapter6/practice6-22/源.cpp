#include<iostream>
#include<string>
using namespace std;

void reverse(string& s, int start = 0, int end = -1)
{
    if (end == -1)  // 第一次调用时设置结束位置
        end = s.length() - 1;

    if (start >= end)  // 基线条件
        return;

    // 交换首尾字符
    swap(s[start], s[end]);

    // 递归处理子字符串
    reverse(s, start + 1, end - 1);
}



int main()
{
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Original string: " << str << endl;

    reverse(str,0,str.length()-1);
    cout << "Reversed string: " << str << endl;

    return 0;
}