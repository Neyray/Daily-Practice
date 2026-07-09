#include <iostream>
#include <vector>
#include <string>

using namespace std;

int compress(vector<char>& chars) {
    int write = 0, read = 0;

    while (read < chars.size()) {
        char currentChar = chars[read];
        int count = 0;

        // 计算当前字符的连续出现次数
        while (read < chars.size() && chars[read] == currentChar) {
            read++;
            count++;
        }

        // 写入当前字符
        chars[write++] = currentChar;

        // 如果字符出现次数大于1，则写入数字
        if (count > 1) {
            string countStr = to_string(count);
            for (char c : countStr) {
                chars[write++] = c;
            }
        }
    }

    return write;  // 返回新数组的长度
}

int main() {
    vector<char> chars1 = { 'a', 'a', 'b', 'b', 'c', 'c', 'c' };
    int len1 = compress(chars1);
    cout << "Compressed length: " << len1 << endl;
    for (int i = 0; i < len1; i++) {
        cout << chars1[i] << " ";
    }
    cout << endl;

    vector<char> chars2 = { 'a' };
    int len2 = compress(chars2);
    cout << "Compressed length: " << len2 << endl;
    for (int i = 0; i < len2; i++) {
        cout << chars2[i] << " ";
    }
    cout << endl;

    vector<char> chars3 = { 'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b' };
    int len3 = compress(chars3);
    cout << "Compressed length: " << len3 << endl;
    for (int i = 0; i < len3; i++) {
        cout << chars3[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
重点：不使用额外的数组或额外的大量内存。
你的算法并没有创建额外的大数组来存储数据，它直接在输入的 chars 数组中进行修改。
算法中没有使用与输入数据大小成比例的空间，因此不管输入数据有多大，你的额外空间总是固定的。
*/