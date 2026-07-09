/*
【问题描述】
编写一个程序，从一个文件中读入单词（即：以空格或回车换行分隔的字符串），
并对单词进行排序，删除重复出现的单词，然后将结果输出到另一个文件中。

【输入形式】
源文件名和目标文件名在执行时作为程序命令行参数输入。例如若程序名为sort，
源文件名和目标文件名分别为sort.in和sort.out，则命令行为：sort sort.in sort.out。
程序将从当前目录下sort.in文件中读入单词。

【输出形式】
对单词进行排序，删除重复出现的单词，然后将结果输出到文件sort.out中。
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string inputFile, outputFile;

    // 提示用户输入文件名
    cout << "请输入源文件名: ";
    cin >> inputFile;
    cout << "请输入目标文件名: ";
    cin >> outputFile;

    // 打开输入文件
    ifstream fin(inputFile);
    //还有什么别的判断没打开方式？我怕有些电脑VS版本太低
    if (!fin.is_open()) {
        cout << "无法打开输入文件: " << inputFile << endl;
        return 1;
    }

    // 读取单词
    string words[1000];
    int count = 0;
    string word;

    while (fin >> word && count < 1000) {
        words[count++] = word;
    }
    fin.close();

    // 排序
    sort(words, words + count);

    // 打开输出文件
    ofstream fout(outputFile);
    if (!fout.is_open()) {
        cout << "无法打开输出文件: " << outputFile << endl;
        return 1;
    }

    // 去重并输出
    if (count > 0) {
        fout << words[0];
        for (int i = 1; i < count; i++) {
            if (words[i] != words[i - 1]) {
                fout << " " << words[i];
            }
        }
    }

    fout.close();
    cout << "处理完成！结果已保存到 " << outputFile << endl;

    return 0;
}