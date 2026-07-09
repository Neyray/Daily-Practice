/*
【问题描述】
"交叉引用生成器"（cross-referencer）是指具有如下功能的程序：
对输入的一篇文档，统计出现的所有单词及其所在行号。将其结果以规定格式输出。

【输入形式】
程序从文件crossin.txt读入一篇文档。该文档由若干行组成，每行中包含一系列单词。
行号由1开始计数。该文档中单词总量不超过200，每个单词长度最大不超过20个字符。

【输出形式】
将输入文档中所有出现的单词及其所在行号输出到文件crossout.txt中。
输出有若干行，每一行都是文档中出现的一个单词。按如下规格输出：
word:line1,line2, ... ,lineN

其中word是单词，后面紧跟一个冒号，然后是以逗号隔开的出现在的出现行号line1，line2，等等。
在该行上各字符紧密输出，不使用空格分隔。在输出时遵循以下规定：
1. 只输出所有由英文字母（包括连字符）构成的单词，数字或包含其它特殊字符的单词不用输出，
   而且连字符不能作为单词首字符。先输出大写A—Z开头的字符，再输出小写a—z开头的字符。
2. 各单词后面的行号从小到大排列。行号不重复打印，亦即如果一个单词在一行内多次出现，
   则只打印一次该行号。
3. 统计的单词不包括如下四个单词：a、an、the、and

【样例输入】
Alcatel provides end-to-end solutions.
It enables enterprises to deliver content to any type of user.
lcatel operates in 130 countries.
Alcatel focus on optimizing their service offerings and revenue streams.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

// 定义单词结构体
struct Word {
    string word;           // 存储单词内容
    int lines[200];        // 存储该单词出现的行号（最多200行）
    int lineCount;         // 记录该单词出现在多少行（行的数量）
};

// 判断是否是有效单词的函数
bool isValidWord(const string& w) {
    // 如果单词为空或以'-'开头，返回false
    if (w.empty() || w[0] == '-') return false;

    // 检查单词中的每个字符
    for (int i = 0; i < w.length(); i++) {
        // 如果字符不是字母也不是'-'，返回false
        if (!isalpha(w[i]) && w[i] != '-') return false;
    }

    // 排除特定的冠词和连词（小写形式）
    if (w == "a" || w == "an" || w == "the" || w == "and") return false;
    // 排除特定的冠词和连词（大写形式）
    if (w == "A" || w == "An" || w == "The" || w == "And") return false;

    return true;  // 通过所有检查，是有效单词
}

// 为单词添加行号的函数
void addLine(Word& w, int line) {
    // 遍历已有的行号，检查是否重复
    for (int i = 0; i < w.lineCount; i++) {
        if (w.lines[i] == line) return;  // 如果行号已存在，直接返回
    }
    // 添加新的行号，并增加行号计数
    w.lines[w.lineCount++] = line;
}

// 在单词数组中查找指定单词的函数
int findWord(Word words[], int count, const string& w) {
    // 遍历单词数组
    for (int i = 0; i < count; i++) {
        if (words[i].word == w) return i;  // 找到则返回索引
    }
    return -1;  // 未找到返回-1
}

int main() {
    // 打开输入文件和输出文件
    ifstream fin("crossin.txt");
    ofstream fout("crossout.txt");

    // 创建单词数组，最多存储200个不同的单词
    Word words[200];
    int wordCount = 0;  // 当前已存储的单词数量

    string line;        // 存储每一行的内容
    int lineNum = 0;    // 当前行号

    // 逐行读取文件
    while (getline(fin, line)) {
        lineNum++;  // 行号递增
        string currentWord = "";  // 当前正在构建的单词

        // 遍历当前行的每个字符
        for (int i = 0; i < line.length(); i++) {
            // 如果是字母或连字符，添加到当前单词
            if (isalpha(line[i]) || line[i] == '-') {
                currentWord += line[i];
            }
            // 如果遇到非单词字符（空格、标点等），说明一个单词结束
            else {
                // 如果当前单词不为空且是有效单词
                if (!currentWord.empty() && isValidWord(currentWord)) {
                    // 在已有单词中查找
                    int index = findWord(words, wordCount, currentWord);

                    if (index == -1) {  // 如果是新单词
                        // 将单词添加到数组
                        words[wordCount].word = currentWord;
                        words[wordCount].lineCount = 0;
                        addLine(words[wordCount], lineNum);  // 添加行号
                        wordCount++;  // 单词数量加1
                    }
                    else {  // 如果单词已存在
                        // 只需为该单词添加新的行号
                        addLine(words[index], lineNum);
                    }
                }
                currentWord = "";  // 重置当前单词
            }
        }

        // 处理行尾的最后一个单词（如果有）
        if (!currentWord.empty() && isValidWord(currentWord)) {
            int index = findWord(words, wordCount, currentWord);
            if (index == -1) {
                words[wordCount].word = currentWord;
                words[wordCount].lineCount = 0;
                addLine(words[wordCount], lineNum);
                wordCount++;
            }
            else {
                addLine(words[index], lineNum);
            }
        }
    }

    // 冒泡排序：大写字母开头的单词在前，小写字母开头的在后
    // 相同大小写的按字典序排列
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = i + 1; j < wordCount; j++) {
            bool needSwap = false;  // 是否需要交换

            // 如果i是大写开头，j是小写开头，不交换
            if (isupper(words[i].word[0]) && islower(words[j].word[0])) {
                needSwap = false;
            }
            // 如果i是小写开头，j是大写开头，交换
            else if (islower(words[i].word[0]) && isupper(words[j].word[0])) {
                needSwap = true;
            }
            // 如果大小写相同，按字典序比较
            else if (words[i].word > words[j].word) {
                needSwap = true;
            }

            // 执行交换
            if (needSwap) {
                Word temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    // 输出结果到文件
    for (int i = 0; i < wordCount; i++) {
        fout << words[i].word << ":";  // 输出单词

        // 输出该单词出现的所有行号，用逗号分隔
        for (int j = 0; j < words[i].lineCount; j++) {
            fout << words[i].lines[j];
            if (j < words[i].lineCount - 1) fout << ",";  // 最后一个行号后不加逗号
        }
        fout << endl;  // 换行
    }

    // 关闭文件
    fin.close();
    fout.close();

    return 0;
}