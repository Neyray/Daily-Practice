#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>
using namespace std;

struct Word {
    string w;
    int line[200];      // 行号
    int lineCount;      // 行的数量
    int totalCount;     // 单词出现的总次数（新增）
};

// 判断是否是有效单词的函数
bool isValidWord(const string& w) {
    if (w.empty() || w[0] == '-') return false;

    for (int i = 0; i < w.length(); i++) {
        if (!isalpha(w[i]) && w[i] != '-') return false;
    }

    // 排除特定的冠词和连词
    if (w == "a" || w == "an" || w == "the" || w == "and") return false;
    if (w == "A" || w == "An" || w == "The" || w == "And") return false;

    return true;
}

void addLine(Word& w, int line) {
    // 检查该行是否已记录
    bool lineExists = false;
    for (int i = 0; i < w.lineCount; ++i) {
        if (line == w.line[i]) {
            lineExists = true;
            break;
        }
    }

    // 如果是新行，添加到行号数组
    if (!lineExists) {
        w.line[w.lineCount] = line;
        w.lineCount++;
    }
}

int findWord(Word w[], int count, string str) {
    for (int i = 0; i < count; ++i) {
        if (w[i].w == str) {
            return i;
        }
    }
    return -1;
}

int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");

    if (!fin) {
        cerr << "error opening input file" << endl;
        return 1;
    }
    if (!fout) {
        cerr << "error opening output file" << endl;
        return 1;
    }

    Word word[200];
    int lineNum = 0;
    int wordCount = 0;
    string line;

    while (getline(fin, line)) {
        lineNum++;
        string currentWord = "";

        for (int i = 0; i <= line.length(); ++i) {
            // 如果是字母或连字符，继续构建单词
            if (i < line.length() && (line[i] == '-' || isalpha(line[i]))) {
                currentWord += line[i];
            }
            // 遇到分隔符或行尾，处理当前单词
            else if (!currentWord.empty()) {
                if (isValidWord(currentWord)) {
                    int index = findWord(word, wordCount, currentWord);

                    // 第一次出现
                    if (index == -1) {
                        word[wordCount].w = currentWord;
                        word[wordCount].lineCount = 0;
                        word[wordCount].totalCount = 1;  // 初始化出现次数为1
                        addLine(word[wordCount], lineNum);
                        wordCount++;
                    }
                    // 已经出现过
                    else {
                        word[index].totalCount++;  // 增加出现次数
                        addLine(word[index], lineNum);
                    }
                }
                currentWord = "";  // 重置当前单词
            }
        }
    }

    // 排序：先大写A-Z，再小写a-z，相同首字母按字典序
    for (int i = 0; i < wordCount - 1; ++i) {
        for (int j = i + 1; j < wordCount; ++j) {
            bool needSwap = false;

            if (isupper(word[i].w[0]) && islower(word[j].w[0])) {
                needSwap = false;
            }
            else if (islower(word[i].w[0]) && isupper(word[j].w[0])) {
                needSwap = true;
            }
            else if (word[i].w > word[j].w) {
                needSwap = true;
            }

            if (needSwap) {
                swap(word[i], word[j]);
            }
        }
    }

    // 输出结果：单词:行号列表 (出现次数)
    for (int i = 0; i < wordCount; ++i) {
        fout << word[i].w << ":";
        for (int j = 0; j < word[i].lineCount; ++j) {
            fout << word[i].line[j];
            if (j < word[i].lineCount - 1) {
                fout << ",";
            }
        }
        fout << " (" << word[i].totalCount << ")" << endl;  // 输出出现次数
    }

    fin.close();
    fout.close();

    return 0;
}