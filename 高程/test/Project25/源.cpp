/*
【问题描述】
有一种加密方法：其使用一个字母串（可以含重复字母）作为密钥。假定密钥单词为feather，
则先去掉密钥单词中的重复字母得到fearthr，然后再按字母表中的其它字母以反序追加到fearthr的后面：

原始字母表：f e a t h r z y x w v u s q p o n m l k j i g d c b
加密字母表：f e a t h r z y x w v u s q p o n m l k j i g d c b

其中第一行为原始英文字母，第二行为对应加密字母。其它字符不进行加密。
编写一个程序，用这种密码加密文件。假定要加密的文件名为encrypt.txt及加密后的文件名为output.txt，
并假定输入文件中字母全为小写字母，并且输入密钥也全为小写字母。

【输入形式】
从标准输入中输入密钥串，并从文件encrypt.txt中读入要加密的内容。

【输出形式】
加密后结果输出到文件output.txt中。
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string key;
    cin >> key;

    // 构建加密字母表
    bool used[26] = { false };
    string encryptTable = "";

    // 先添加密钥中的字母（去重）
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!used[index]) {
            used[index] = true;
            encryptTable += key[i];
        }
    }

    // 反向添加剩余字母
    for (int i = 25; i >= 0; i--) {
        if (!used[i]) {
            encryptTable += (char)('a' + i);
        }
    }

    // 读取文件并加密，文件的具体操作？
    ifstream fin("encrypt.txt");
    ofstream fout("output.txt");

    string line;
    while (getline(fin, line)) {
        for (int i = 0; i < line.length(); i++) {
            if (line[i] >= 'a' && line[i] <= 'z') {
                int index = line[i] - 'a';
                fout << encryptTable[index];
            }
            else {
                fout << line[i];
            }
        }
        fout << endl;
    }

    fin.close();
    fout.close();

    return 0;
}