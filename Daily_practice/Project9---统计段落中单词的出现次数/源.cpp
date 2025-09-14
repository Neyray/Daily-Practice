#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <cctype>
#include <string>
using namespace std;

// 辅助函数：检查一个字符是否是字母
bool isWordChar(char c) {
    return isalnum(static_cast<unsigned char>(c));
}


// 提取单词并统计
void countWordsInFile(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);  // 输入文件流
    if (!inFile) {
        cerr << "无法打开输入文件 " << inputFile << endl;
        return;
    }

    unordered_map<string, int> wordCount;  // 用于存储单词和对应的出现次数
    string word;
    char ch;

    // 逐个字符读取文件内容
    while (inFile.get(ch)) {
        // 如果是字母或数字，累积到单词中
        if (isWordChar(ch)) {          
            word += tolower(ch);
        }
        else if (!word.empty()) {
            wordCount[word]++;
            word.clear();
        }
    }
    // 处理文件最后一个单词
    if (!word.empty()) {
        wordCount[word]++;
    }

    // 将结果写入输出文件
    ofstream outFile(outputFile);  // 输出文件流
    if (!outFile) {
        cerr << "无法打开输出文件 " << outputFile << endl;
        return;
    }

    // 输出统计结果
    for (const auto& entry : wordCount) {
        outFile << entry.first << ": " << entry.second << endl;
    }

    cout << "统计完成，结果已写入文件: " << outputFile << endl;
}

int main() {
    string inputFile, outputFile;

    cout << "请输入输入文件名: ";
    cin >> inputFile;
    cout << "请输入输出文件名: ";
    cin >> outputFile;

    // 调用函数统计单词出现次数
    countWordsInFile(inputFile, outputFile);

    return 0;
}
