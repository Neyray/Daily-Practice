//删除重复字符
#include <iostream>
#include <cstring>
using namespace std;

int DeleteSame(char* oldstr, char* newstr) {
    if (oldstr == nullptr || newstr == nullptr) {
        return 0;
    }

    int len = strlen(oldstr);
    if (len == 0) {
        newstr[0] = '\0';
        return 0;
    }

    // 记录字符是否已经出现过
    bool appeared[256] = { false };
    int newIndex = 0;
    int deleteCount = 0;

    // 遍历原字符串
    for (int i = 0; i < len; i++) {
        unsigned char ch = oldstr[i];

        // 如果字符第一次出现，添加到新字符串
        if (!appeared[ch]) {
            newstr[newIndex++] = ch;
            appeared[ch] = true;
        }
        else {
            // 字符重复出现，计数加1
            deleteCount++;
        }
    }

    // 添加字符串结束符
    newstr[newIndex] = '\0';

    return deleteCount;
}

int main() {
    char oldstr[50];  // 最长49个字符 + 结束符
    char newstr[50];

    // 读取输入
    cin.getline(oldstr, 50);

    // 调用函数
    int num = DeleteSame(oldstr, newstr);

    // 输出结果
    cout << newstr << " " << num << endl;

    return 0;
}