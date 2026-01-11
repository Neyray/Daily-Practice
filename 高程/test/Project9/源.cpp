/*
【问题描述】
编程实现DeleteSame函数的功能。假设有如下的函数调用：num=DeleteSame(oldstr, newstr);
其中，oldstr是字符串，该函数删除字符串oldstr中重复出现的字符，只保留首次出现的各个字符，
将结果保存至字符串newstr，并且返回被删除的字符个数。

说明：
1.函数原型：int DeleteSame(char *oldstr, char *newstr);
2.字符串最长为49个字符。
*/

#include <iostream>
#include <cstring>
using namespace std;

int DeleteSame(char* oldstr, char* newstr) {
    int len = strlen(oldstr);
    int newIndex = 0;
    int deleteCount = 0;
    bool appeared[256] = { false }; // 标记字符是否出现过

    for (int i = 0; i < len; i++) {
        if (!appeared[(unsigned char)oldstr[i]]) {
            appeared[(unsigned char)oldstr[i]] = true;
            newstr[newIndex++] = oldstr[i];
        }
        else {
            deleteCount++;
        }
    }
    newstr[newIndex] = '\0';

    return deleteCount;
}

int main() {
    char oldstr[50], newstr[50];

    cout << "请输入字符串：";
    cin >> oldstr;

    int num = DeleteSame(oldstr, newstr);

    cout << "删除重复字符后的字符串：" << newstr << endl;
    cout << "删除的字符个数：" << num << endl;

    return 0;
}