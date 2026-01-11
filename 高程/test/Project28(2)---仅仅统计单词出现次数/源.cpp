#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

struct Word {
    string w;
    int totalCount;
};

bool isValid(string word) {
    if (word.empty() || word[0] == '-') {
        return false;
    }
    for (int i = 0; i < word.length(); ++i) {
        if (!isalpha(word[i]) && word[i] != '-') {
            return false;
        }
    }
    if (word == "a" || word == "an" || word == "the" || word == "and"
        || word == "A" || word == "An" || word == "The" || word == "And") {
        return false;
    }
    return true;
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
        cerr << "error" << endl;
        return 1;
    }
    if (!fout) {
        cerr << "error" << endl;
        return 1;
    }

    Word word[200];
    int wordCount = 0;
    string line;

    while (getline(fin, line)) {
        string current = "";
        for (int i = 0; i < line.length(); ++i) {
            if (isalpha(line[i]) || line[i] == '-') {
                current += line[i];
            }
            else {
                if (isValid(current)) {
                    int index = findWord(word, wordCount, current);
                    if (index == -1) {
                        word[wordCount].w = current;
                        word[wordCount].totalCount = 1;
                        wordCount++;
                    }
                    else {
                        word[index].totalCount++;
                    }
                }
                current = "";
            }
        }

        // 处理行尾最后一个单词
        if (!current.empty() && isValid(current)) {
            int index = findWord(word, wordCount, current);
            if (index == -1) {
                word[wordCount].w = current;
                word[wordCount].totalCount = 1;
                wordCount++;
            }
            else {
                word[index].totalCount++;
            }
        }
    }

    // 排序：先大写A-Z，再小写a-z
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

    // 输出：单词:次数
    for (int i = 0; i < wordCount; ++i) {
        fout << word[i].w << ":" << word[i].totalCount << endl;
    }

    fin.close();
    fout.close();
    return 0;
}